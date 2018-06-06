#include "CertCard.h"
#include <HD_SDTapi_x64.h>
#include <fstream>
#include <direct.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include "../detector/Detector.h"
#include "../config/Config.h"
#include "../imgstorage/ImgStorage.h"

CertCard* CertCard::m_intance = new CertCard();

const std::map<int, std::string> errlist { { SHD_Connect_Error ,"设备连接错" },
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

}

CertCard::~CertCard()
{
	HD_CloseComm(Config::GetInstance()->GetData().certcard.port);
}

CertCard* CertCard::GetInstance()
{
	return m_intance;
}

std::string CertCard::GetErrMsg(int errcode)
{
	std::map<int, std::string>::const_iterator found = errlist.find(errcode);
	if (errlist.end() == found) {
		return "未定义错误码";
	}
	
	return found->second;
}


void CertCard::RegisterObserver(CertCardObserver* observer)
{
	if (NULL != observer) {
		std::unique_lock<std::mutex> lck(this->m_mtxObservers);
		this->m_observers.push_back(observer);
	}
}

void CertCard::RemoveObserver(CertCardObserver* observer)
{
	if((NULL != observer) && (m_observers.size()>0))
	{
		std::unique_lock<std::mutex> lck(this->m_mtxObservers);
		this->m_observers.remove(observer);
	}
}

int CertCard::ConnectCertCard()
{
	int port = Config::GetInstance()->GetData().certcard.port;
	/*
	HD_CloseComm(port);
	int result = HD_InitComm(port);
	if (0 == result) {
		this->m_thread=std::make_unique<std::thread>(thread_workd,this);
	}
	*/
	this->m_thread = std::make_unique<std::thread>(thread_workd, this);

	return 0;
}

void CertCard::NotifyCardAuthed(int result)
{
	bool authed = 0 == result? true: false;
	std::string info = this->GetErrMsg(result);
	for (auto& elem : this->m_observers) {
		elem->UpdateCardAuthed(authed,info);
	}
}

void CertCard::NotifyCardInfoUpdated(std::shared_ptr<CertCardInfo> info)
{
	for (auto& elem : this->m_observers) {
		elem->UpdateCertCardInfo(info);
	}
}

void CertCard::NofifyProcessStart(int result, std::string info)
{
	for (auto& elem : this->m_observers) {
		elem->StartProcess(result, info);
	}
}

void CertCard::NofityProcessEnd(int result, std::string info)
{
	for (auto& elem : this->m_observers) {
		elem->EndProcess(result, info);
	}
}

void CertCard::NotifyProgressUpdate(int progress, std::string info)
{
	for (auto& elem : this->m_observers) {
		elem->UpdateProgressInfo(progress, info);
	}
}

void CertCard::thread_workd(CertCard* instance)
{
	while (true) {
		/*
		int result = HD_Authenticate(true);
		GetInstance()->NotifyCardAuthed(result);

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
			
			result = HD_Read_BaseInfo(bmpdata.get(), name.get(), gendar.get(), nation.get(),
				birth.get(), address.get(), certno.get(), department.get(), effectdata.get(), expire.get());
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

				//Notify observers
				instance->NotifyCardInfoUpdated(info);

				//Handle 
				instance->HandleCardInfo(info);
			}
		}
		*/
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

		char pwd[256];
		memset(pwd, 0, 256);
		_getcwd(pwd, sizeof(pwd));

		string filename(pwd);
		filename.append("./hdconsole.exe");
		size_t size = filename.length();
		wchar_t *tmp = new wchar_t[size + 1];
		MultiByteToWideChar(CP_ACP, 0, filename.c_str(),size, tmp, size * sizeof(wchar_t));
		tmp[size] = 0;
		BOOL ret = CreateProcess(NULL, tmp, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
		DWORD dwExitCode;
		if (ret)
		{
			CloseHandle(pi.hThread);
			WaitForSingleObject(pi.hProcess, INFINITE);
			GetExitCodeProcess(pi.hProcess, &dwExitCode);
			CloseHandle(pi.hProcess);
		}
		delete[] tmp;

		/*
		char *buffer = getcwd(NULL,0);
		int result = system("./hdconsole.exe");
		if (0 == result) {
			std::ifstream in("./data.txt", std::ios::in);
			char buffer[256];
			memset(buffer, 0, 256);
			while (!in.eof())
			{
				in.getline(buffer, 256);
				printf_s("%s\n", buffer, 256);
			}
		}
		*/
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

bool CertCard::HandleCardInfo(std::shared_ptr<CertCardInfo> info)
{
	this->NofifyProcessStart(0, "正在处理中。。。");
	std::shared_ptr<cv::Mat> capture;
	this->PopCapture(capture);
	if (NULL != capture)
	{
		float score;
		bool result;
		result = Detector::GetInstance()->DetectAndComparseWithSDK(capture, info->bmpdata, 77725, score);

		if (result && score >= Config::GetInstance()->GetData().camera.threshold)
		{
			//passed
			//save mat to local image
			char localImg[256];
			memset(localImg, 0, 256);
			sprintf(localImg, "./%s.jpg", info->certno.get());
			imwrite(localImg, *capture);

			//upload image to remote file sever
			std::string remoteurl;
			int code = ImgStorage::GetInstance()->UploadFile(localImg, remoteurl);
			if (0 == code)
			{
				//update data info to remote server by http request.

			}
		}
		else
		{
			
		}
	}
	this->NofityProcessEnd(0, "结束。");

	return false;
}

void CertCard::UpdateCapture(std::shared_ptr<cv::Mat> capture)
{
	std::lock_guard<std::mutex> lck(this->m_mtxMat);
	this->m_mat = capture;
}

void CertCard::PopCapture(std::shared_ptr<cv::Mat>& capture)
{
	std::lock_guard<std::mutex> lck(this->m_mtxMat);
	capture = this->m_mat;
	this->m_mat.reset();

}
//HD_Read_ BaseInf
//int HD_Read_BaseInfo(char* pBmpData, char *pName, char *pSex, char *pNation, char *pBirth, char *pAddress, char *pCertNo, char *pDepartment, char *pEffectData, char *pExpire);