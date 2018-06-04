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
	do
	{
		// check if we were asked to exit
		if (TestDestroy())
			break;

		// create any type of command event here
		wxThreadEvent event(wxEVT_THREAD, WORKER_EVENT);
		event.SetInt(m_count);
		event.SetString(m_message);

		// send in a thread-safe way
		wxQueueEvent(m_frame, event.Clone());

		wxMilliSleep(200);
	} while (!m_frame->Cancelled() && (m_count < 100));

	wxThreadEvent event(wxEVT_THREAD, WORKER_EVENT);
	event.SetInt(-1); // that's all
	wxQueueEvent(m_frame, event.Clone());

	return NULL;
}