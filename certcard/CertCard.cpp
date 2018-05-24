#include "CertCard.h"
#include <HD_SDTapi_x64.h>


CertCard* CertCard::m_intance = new CertCard();

const std::map<int, std::string> errlist { { SHD_Connect_Error ,"�豸���Ӵ�" },
{ SHD_UnConnected, "�豸δ������" },
{ SHD_BadLoadDLL_Error, "(��̬��)����ʧ�� " },
{ SHD_Parameter_Error ,"(������̬���)������ " },
{ SHD_Request_Error , "Ѱ��ʧ�� " },
{ SHD_Select_Error ,"ѡ��ʧ�� " },
{ SHD_ReadBase_Error , "����ʧ��" },
{ SHD_ReadBaseFP_Error , "��ȡ׷����Ϣʧ��" },
{ SHD_ReadADD_Error ,"��ȡ׷����Ϣʧ��" },
{ SHD_Sam_Error ,"����ͨ��ʧ��" },
{ SHD_CheckSam_Error,"����ͨ��ʧ��" },
{ SHD_SamToFinger_Error ,"����ͨ��ģ�鲻֧�ֻ�ȡָ�� " },
{ SHD_OTHER_ERROR ,"�����쳣����" }
};

CertCard::CertCard()
{

}


CertCard::~CertCard()
{
	HD_CloseComm(1001);
}

CertCard* CertCard::GetInstance()
{
	return m_intance;
}

std::string CertCard::GetErrMsg(int errcode)
{
	std::map<int, std::string>::const_iterator found = errlist.find(errcode);
	if (errlist.end() == found) {
		return "δ���������";
	}
	
	return found->second;
}


void CertCard::RegisterObserver(std::shared_ptr<CertCardObserver>& observer)
{
	if (NULL != observer) {
		this->m_observers.push_back(observer.get());
	}
}

void CertCard::RemoveObserver(std::shared_ptr<CertCardObserver>& observer)
{
	if((NULL != observer) && (m_observers.size()>0))
	{
		this->m_observers.remove(observer.get());
	}
}


int CertCard::ConnectIdentifyCard(int port)
{
	HD_CloseComm(port);
	int result = HD_InitComm(port);
	if (0 == result) {
		//this->m_thread.reset(new std::thread(thread_workd, this));
	}
	return result;
}

void CertCard::NotifyCardAuthed()
{
	for (auto& elem : this->m_observers) {
		elem->CertCardAuthed();
	}
}

void CertCard::NotifyCardInfoUpdated(std::shared_ptr<CertCardInfo>& info)
{
	for (auto& elem : this->m_observers) {
		elem->UpdateCertCardInfo(info);
	}
}


void CertCard::thread_workd(std::shared_ptr<CertCard> certcard)
{
	while (true) {
		if (0 == HD_Authenticate(false)) {
			certcard->NotifyCardAuthed();
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

			if (HD_Read_BaseInfo(bmpdata.get(), name.get(), gendar.get(), nation.get(), 
				birth.get(), address.get(), certno.get(), department.get(), effectdata.get(), expire.get()))
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

				certcard->NotifyCardInfoUpdated(info);
			}

			
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

//HD_Read_ BaseInf
//int HD_Read_BaseInfo(char* pBmpData, char *pName, char *pSex, char *pNation, char *pBirth, char *pAddress, char *pCertNo, char *pDepartment, char *pEffectData, char *pExpire);