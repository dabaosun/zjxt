#ifndef __CERTCARD__
#define __CERTCARD__

#include <string>
#include <memory>
#include <map>
#include <list>
#include <thread>
#include "CertCardObserver.h"

class CertCard
{
public:
	void RegisterObserver(std::shared_ptr<CertCardObserver>& observer);
	void RemoveObserver(std::shared_ptr<CertCardObserver>& observer);
	void NotifyCardAuthed();
	void NotifyCardInfoUpdated(std::shared_ptr<CertCardInfo>& info);

	static CertCard* GetInstance();
	static std::string GetErrMsg(int errcode);
	~CertCard();

	int ConnectIdentifyCard(int port);
private:
	static CertCard *m_intance;
	static void thread_workd();
	CertCard();
	std::list<CertCardObserver*> m_observers;
	std::unique_ptr<std::thread> m_thread;



};

#endif //__CERTCARD__