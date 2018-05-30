#include "BusinessWorker.h"
#include <wx/progdlg.h>

void thread_worked(BusinessWorker* worker);

std::mutex m_mtx;
std::condition_variable condition;
int cargo = 0;
bool shipment_available()
{
	return cargo != 0;
}
BusinessWorker::BusinessWorker()
{
	this->m_thread = std::make_unique<std::thread>(thread_worked,this);
}


BusinessWorker::~BusinessWorker()
{
}

void BusinessWorker::CertCardAuthed()
{

}

void BusinessWorker::UpdateCertCardInfo(std::shared_ptr<CertCardInfo> info)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	this->m_cardinfo = info;
}

void thread_worked(BusinessWorker* worker)
{
	while (true) {
		std::unique_lock<std::mutex> lock(m_mtx, std::defer_lock);
		if (lock.try_lock()) {
			if ((NULL != worker->m_capture) && (NULL != worker->m_cardinfo)) {
				//±È¶Ô
				continue;
			}
			if ((NULL == worker->m_capture) && (NULL != worker->m_cardinfo))
			{
	
				continue;
			}

			if ((NULL == worker->m_capture) && (NULL != worker->m_cardinfo))
			{
				//prompt camera info;
				continue;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}
