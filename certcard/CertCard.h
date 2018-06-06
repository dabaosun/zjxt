#ifndef __CERTCARD__
#define __CERTCARD__

#include <string>
#include <memory>
#include <map>
#include <list>
#include <thread>
#include <mutex>
#include "CertCardObserver.h"
#include "../camera/CameraObserver.h"

class CertCard : public ICameraObserver
{
public:
	void RegisterObserver(CertCardObserver* observer);
	void RemoveObserver(CertCardObserver* observer);


	void UpdateCapture(const std::shared_ptr<cv::Mat>& capture);
	static CertCard* GetInstance();
	static std::string GetErrMsg(int errcode);
	~CertCard();

	int ConnectCertCard();
private:
	static CertCard *m_intance;
	static void thread_workd(CertCard* instance);
	CertCard();

	std::mutex m_mtxObservers;
	std::list<CertCardObserver*> m_observers;
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


};

#endif //__CERTCARD__