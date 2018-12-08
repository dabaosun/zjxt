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
#include <ostream>
#include <fstream>
#include <stdio.h>  
#include "CertCardListener.h"
#include "../camera/CameraListener.h"

class CertCard : public ICameraListener
{
public:
	CertCard();
	~CertCard();

	void RegisterListener(ICertCardListener * listener);
	void RemoveListener(ICertCardListener * listener);

	void UpdateCapture(const std::shared_ptr<cv::Mat> & capture);
	static std::string GetErrMsg(int errcode);

	int OpenCertCardReader();
	void CloseCertCardReader();
private:
	static void thread_workd(CertCard* instance);

	std::mutex m_mtxListeners;
	std::list<ICertCardListener*> m_listeners;
	std::thread* m_thread;

	void NotifyCardAuthed(int result);
	void NotifyCardInfoUpdated(const std::shared_ptr<CertCardInfo>& info);
	void NofifyProcessStart(const std::string& info);
	void NofityProcessEnd(int result, const std::string& info);
	void NotifyProgressUpdate(int progress, const std::string& info);

	bool HandleCardInfo(const std::shared_ptr<CertCardInfo>& info);
	void PopCapture(std::shared_ptr<cv::Mat>& capture);
	void RecordLog(const std::string msg);
	std::shared_ptr<cv::Mat> m_mat;
	std::mutex m_mtxMat;
	std::ofstream errorlog;

	void * m_hSubProcess;
	bool m_bNeedexit;
};

#endif //__CERTCARD__