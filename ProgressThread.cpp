#include "ProgressThread.h"

enum
{
	WORKER_EVENT = wxID_HIGHEST + 1
};


ProgressThread::ProgressThread(SigninMain *frame)
{
	m_frame = frame;
	m_count = 0;

}

ProgressThread::~ProgressThread()
{
}

void ProgressThread::OnExit()
{
}

wxThread::ExitCode ProgressThread::Entry()
{
	int tmp = 0;
	do
	{
		// check if we were asked to exit
		if (TestDestroy())
			break;

		// create any type of command event here
		wxThreadEvent event(wxEVT_THREAD, WORKER_EVENT);
		event.SetInt(tmp);
		event.SetString(m_message);

		// send in a thread-safe way
		wxQueueEvent(m_frame, event.Clone());

		wxMilliSleep(200);
		tmp = tmp++ >= 100 ? 100: tmp;
	} while (!m_frame->Cancelled() && (m_count < 100));

	wxThreadEvent eventEnd(wxEVT_THREAD, WORKER_EVENT);
	eventEnd.SetInt(100); // that's all
	eventEnd.SetString(m_message);
	wxQueueEvent(m_frame, eventEnd.Clone());

	std::this_thread::sleep_for(std::chrono::seconds(2));

	wxThreadEvent eventClose(wxEVT_THREAD, WORKER_EVENT);
	eventClose.SetInt(-1); 
	wxQueueEvent(m_frame, eventClose.Clone());

	return NULL;
}