/***************************************************************
* Name:      CertCard.cpp
* Purpose:   Read cert card info and handle the data.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "CertCard.h"
#include <HDstdapi.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <direct.h>
#include <wx/process.h>
#include <wx/txtstrm.h>

#include "../detector/Detector.h"
#include "../config/Config.h"
#include "../imgstorage/ImgStorage.h"
#include "../dataserver/DataServer.h"

const std::map<int, std::string> errlist{ { -1 ,"设备连接错" },
{ SHD_UnConnected, "设备未建立连" },
{ SHD_BadLoadDLL_Error, "(动态库)加载失败 " },
{ SHD_Parameter_Error ,"(发给动态库的)参数错 " },
{ SHD_Request_Error , "寻卡失败 " },
{ SHD_Select_Error ,"选卡失败 " },
{ SHD_ReadBase_Error , "读卡失败" },
{ SHD_ReadBaseFP_Error , "读取追加信息失败" },
{ SHD_ReadADD_Error ,"读取追加信息失败" },
{ SHD_Sam_Error ,"管理通信失败" },
{ SHD_CheckSam_Error,"检验通信失败" },
{ SHD_SamToFinger_Error ,"管理通信模块不支持获取指纹 " },
{ SHD_OTHER_ERROR ,"其他异常错误" }
};

CertCard::CertCard()
{
	m_hSubProcess = NULL;
	m_bNeedexit = false;

	const std::string& pwd = Config::GetInstance()->GetPwd();
	std::string errorfile(pwd);

	errorfile.append("/error.log");

	errorlog.open(errorfile, std::ios::out);
}

CertCard::~CertCard()
{
	if (errorlog.is_open()) {
		errorlog.flush();
		errorlog.close();
	}
}

std::string CertCard::GetErrMsg(int errcode)
{
	std::map<int, std::string>::const_iterator found = errlist.find(errcode);
	if (errlist.end() == found) {
		return "未定义错误码";
	}

	return found->second;
}


void CertCard::RegisterListener(ICertCardListener * listener)
{
	if (NULL != listener) {
		std::unique_lock<std::mutex> lck(this->m_mtxListeners);
		this->m_listeners.push_back(listener);
	}
}

void CertCard::RemoveListener(ICertCardListener * listener)
{
	if ((NULL != listener) && (m_listeners.size() > 0))
	{
		std::unique_lock<std::mutex> lck(this->m_mtxListeners);
		this->m_listeners.remove(listener);
	}
}

int CertCard::OpenCertCardReader()
{
	int port = Config::GetInstance()->GetData().certcard.port;
#ifndef _WIN64
	HD_CloseComm(port);
	int result = HD_InitComm(port);
	if (0 != result) {
		return result;
	}
#endif // !_WIN64

	this->m_hSubProcess = NULL;
	this->m_bNeedexit = false;
	this->m_thread = new std::thread(thread_workd, this);
	return 0;
}

void CertCard::CloseCertCardReader()
{
	if (NULL != this->m_thread) {
		auto threadid = m_thread->native_handle();
#ifdef _WIN64
		if (NULL != this->m_hSubProcess) {
			TerminateProcess(this->m_hSubProcess, -1);
		}
#endif // _WIN64
		m_bNeedexit = true;
		TerminateThread(threadid, -1);
		WaitForSingleObject(threadid, 1000);
		m_thread = NULL;
	}

#ifndef _WIN64
	HD_CloseComm(Config::GetInstance()->GetData().certcard.port);
#endif // !_WIN64

}

void CertCard::NotifyCardAuthed(int result)
{
	bool authed = 0 == result ? true : false;
	std::string info = this->GetErrMsg(result);
	for (auto& elem : this->m_listeners) {
		elem->UpdateCardAuthed(authed, info);
	}
}

void CertCard::NotifyCardInfoUpdated(const std::shared_ptr<CertCardInfo>& info)
{
	for (auto& elem : this->m_listeners) {
		elem->UpdateCertCardInfo(info);
	}
}

void CertCard::NofifyProcessStart(const std::string& info)
{
	for (auto& elem : this->m_listeners) {
		elem->StartProcess(info);
	}
}

void CertCard::NofityProcessEnd(int result, const std::string& info)
{
	for (auto& elem : this->m_listeners) {
		elem->EndProcess(result, info);
	}
}

void CertCard::NotifyProgressUpdate(int progress, const std::string& info)
{
	for (auto& elem : this->m_listeners) {
		elem->UpdateProgressInfo(progress, info);
	}
}

void CertCard::thread_workd(CertCard* instance)
{
#ifdef _WIN64
	HANDLE ghJob = CreateJobObject(NULL, NULL);
	JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };

	// Configure all child processes associated with the job to terminate when the
	jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
	SetInformationJobObject(ghJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli));

	while (true) {
		if (instance->m_bNeedexit) {
			return;
		}
		
		PROCESS_INFORMATION pi;
		STARTUPINFO si;
		si.cb = sizeof(STARTUPINFO);
		si.lpReserved = NULL;
		si.lpDesktop = NULL;
		si.lpTitle = NULL;
		si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_HIDE;
		si.cbReserved2 = NULL;
		si.lpReserved2 = NULL;

		instance->RecordLog("call hdconsole process.");

		string process = Config::GetInstance()->GetPwd() + "hdconsole.exe";
		size_t size = process.length();
		wchar_t *tmp = new wchar_t[size + 1];
		MultiByteToWideChar(CP_ACP, 0, process.c_str(), size, tmp, size * sizeof(wchar_t));
		tmp[size] = 0;
		BOOL ret = CreateProcess(NULL, tmp, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
		delete[] tmp;

		DWORD dwExitCode;
		if (ret)
		{
			if (ghJob) {
				AssignProcessToJobObject(ghJob, pi.hProcess);
			}

			if (instance->m_bNeedexit) {
				return;
			}

			CloseHandle(pi.hThread);
			instance->m_hSubProcess = pi.hProcess;
			WaitForSingleObject(pi.hProcess, INFINITE);
			GetExitCodeProcess(pi.hProcess, &dwExitCode);
			CloseHandle(pi.hProcess);
			instance->m_hSubProcess = NULL;

			if (0 == dwExitCode)
			{
				string datafile = Config::GetInstance()->GetPwd() + "data.txt";
				string certcardbmp = Config::GetInstance()->GetPwd() + "certcard.bmp";

				ifstream datain(datafile, ios::in);
				ifstream bmpin(certcardbmp, ios::in | ios::binary);
				if (datain.is_open() && bmpin.is_open())
				{
					std::shared_ptr<char> name(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> gendar(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> nation(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> birth(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> address(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> certno(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> department(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> effectdata(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> expire(new char[256], std::default_delete<char[]>());
					std::shared_ptr<char> bmpdata(new char[77725], std::default_delete<char[]>());

					datain.getline(name.get(), 256);
					datain.getline(gendar.get(), 256);
					datain.getline(nation.get(), 256);
					datain.getline(birth.get(), 256);
					datain.getline(address.get(), 256);
					datain.getline(certno.get(), 256);
					datain.getline(department.get(), 256);
					datain.getline(effectdata.get(), 256);
					datain.getline(expire.get(), 256);
					datain.close();

					bmpin.read(bmpdata.get(), 77725);
					bmpin.close();

					std::shared_ptr<CertCardInfo> info = std::make_shared<CertCardInfo>();
					info->name = name;
					info->gendar = gendar;
					info->nation = nation;
					info->birth = birth;
					info->address = address;
					info->certno = certno;
					info->department = department;
					info->effectdata = effectdata;
					info->expire = expire;
					info->bmpdata = bmpdata;

					if (instance->m_bNeedexit) {
						return;
					}

					//Notify listeners
					instance->RecordLog("Notify to update card info.");
					instance->NotifyCardInfoUpdated(info);

					if (instance->m_bNeedexit) {
						return;
					}
					//Handle 
					instance->RecordLog("Handle card info.");
					instance->HandleCardInfo(info);
				}
			}
			else {
				if (instance->m_bNeedexit) {
					return;
				}
				if (-1 != dwExitCode) {
					char tmp[256];
					memset(tmp, 0, 256);
					sprintf_s(tmp, "hdconsole exit code : %d ", dwExitCode);
					instance->RecordLog(tmp);
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
#else
	while (true) {
		if (instance->m_bNeedexit) {
			return;
		}
		int result = HD_Authenticate();
		instance->NotifyCardAuthed(result);

		if (0 == result) {
			std::shared_ptr<char> name(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> gendar(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> nation(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> birth(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> address(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> certno(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> department(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> effectdata(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> expire(new char[256], std::default_delete<char[]>());
			std::shared_ptr<char> bmpdata(new char[77725], std::default_delete<char[]>());

			//result = HD_Read_BaseInfo(bmpdata.get(), name.get(), gendar.get(), nation.get(),
			//	birth.get(), address.get(), certno.get(), department.get(), effectdata.get(), expire.get());
			std::string pwd = Config::GetInstance()->GetPwd();
			std::string bmpfile(pwd + "/certcard.bmp");
			result = HD_Read_BaseInfo(bmpfile.c_str(), bmpdata.get(), name.get(), gendar.get(), nation.get(), birth.get(), address.get(), certno.get(), department.get(), effectdata.get(), expire.get());
			if (0 == result)
			{
				std::shared_ptr<CertCardInfo> info = std::make_shared<CertCardInfo>();
				info->name = name;
				info->gendar = gendar;
				info->nation = nation;
				info->birth = birth;
				info->address = address;
				info->certno = certno;
				info->department = department;
				info->effectdata = effectdata;
				info->expire = expire;
				info->bmpdata = bmpdata;

				//Notify listeners
				instance->NotifyCardInfoUpdated(info);

				//Handle
				instance->HandleCardInfo(info);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
#endif // _WIN64

}

bool CertCard::HandleCardInfo(const std::shared_ptr<CertCardInfo>& info)
{
	this->NofifyProcessStart("正在处理中");
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto elapsed = end - start;
	do
	{
		std::shared_ptr<cv::Mat> capture;
		this->PopCapture(capture);
		if (NULL != capture)
		{
			float score;
			bool result;

			this->RecordLog("start to detect and compare.");
			result = Detector::GetInstance()->DetectAndComparseWithSDK(capture, info->bmpdata, 77725, score);
			this->RecordLog("finish to detect and compare.");

			if (result && score >= Config::GetInstance()->GetData().camera.threshold)
			{
				//passed
				//save mat to local image
				std::string localImg = Config::GetInstance()->GetPwd() + info->certno.get() + ".jpg";
				if (imwrite(localImg, *capture)) {
					//upload image to remote file sever
					std::string remoteurl;
					this->RecordLog("upload file.");
					int code = ImgStorage::GetInstance()->UploadFile(localImg, remoteurl);
					if (0 == code)
					{
						//update data info to remote server by http request.
						this->RecordLog("upload data.");
						code = DataServer::GetInstance()->UploadData(info->certno.get(), remoteurl);
						if (0 == code) {
							this->NofityProcessEnd(100, "注册成功");
							return true;
						}
						else {
							char tmp[256];
							memset(tmp, 0, 256);
							sprintf_s(tmp, "transfer data failed : %d ", code);
							this->RecordLog(tmp);
						}
					}
					else {
						char tmp[256];
						memset(tmp, 0, 256);
						sprintf_s(tmp, "upload file failed : %d ", code);
						this->RecordLog(tmp);
					}
				}
			}
			else {
				char tmp[256];
				memset(tmp, 0, 256);
				sprintf_s(tmp, "face compare failed, result: %d , score: %f, thredhold: %f",
					result, score, Config::GetInstance()->GetData().camera.threshold);
				this->RecordLog(tmp);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		end = chrono::steady_clock::now();
		elapsed = end - start;

	} while (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < Config::GetInstance()->GetData().camera.elapsed);

	this->NofityProcessEnd(100, "注册失败");
	return false;
}

void CertCard::UpdateCapture(const std::shared_ptr<cv::Mat> & capture)
{
	std::lock_guard<std::mutex> lck(this->m_mtxMat);
	std::shared_ptr<cv::Mat> mat = capture;
	this->m_mat = mat;
}

void CertCard::PopCapture(std::shared_ptr<cv::Mat>& capture)
{
	std::lock_guard<std::mutex> lck(this->m_mtxMat);
	capture = this->m_mat;
	this->m_mat.reset();

}

void CertCard::RecordLog(const std::string msg)
{
	if (errorlog.is_open()) {
		time_t timep;
		time(&timep);
		char tmp[64];
		strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
		errorlog << tmp << "--" << msg << std::endl;
	}
}