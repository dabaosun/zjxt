/***************************************************************
* Name:      CertCard.h
* Purpose:   Read cert card info and handle the data.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __CERTCARD__
#define __CERTCARD__

#include <string>
#include <memory>
#include <map>
#include <list>
#include <thread>
#include <mutex>
#include "CertCardListener.h"
#include "../camera/CameraListener.h"

class CertCard : public ICameraListener
{
public:
	void RegisterListener(ICertCardListener * listener);
	void RemoveListener(ICertCardListener * listener);

	void UpdateCapture(const std::shared_ptr<cv::Mat> & capture);
	static CertCard* GetInstance() {
		return m_pInstance;
	};
	static std::string GetErrMsg(int errcode);

	int OpenCertCardReader();
	void CloseCertCardReader();
private:
	static CertCard* m_pInstance;
	static void thread_workd(CertCard* instance);
	CertCard();
	~CertCard();

	std::mutex m_mtxListeners;
	std::list<ICertCardListener*> m_listeners;
	std::unique_ptr<std::thread> m_thread;

	void NotifyCardAuthed(int result);
	void NotifyCardInfoUpdated(const std::shared_ptr<CertCardInfo>& info);
	void NofifyProcessStart(int result, const std::string& info);
	void NofityProcessEnd(int result, const std::string& info);
	void NotifyProgressUpdate(int progress, const std::string& info);

	bool HandleCardInfo(const std::shared_ptr<CertCardInfo>& info);
	void PopCapture(std::shared_ptr<cv::Mat>& capture);
	std::shared_ptr<cv::Mat> m_mat;
	std::mutex m_mtxMat;

	class Garbo

	{
	public:
		~Garbo()
		{
			if (CertCard::m_pInstance)
			{
				delete CertCard::m_pInstance;
			}
		}
	};

	static Garbo garbo;
};

#endif //__CERTCARD__