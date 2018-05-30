#include "SigninMain.h"
#include "ProgressThread.h"
enum
{
	WORKER_EVENT = wxID_HIGHEST + 1,   // this one gets sent from MyWorkerThread
	GUITHREAD_EVENT                  // this one gets sent from MyGUIThread
};

SigninMain::SigninMain( wxWindow* parent )
:
SigninFrame( parent )
{
	this->Connect(WORKER_EVENT, wxEVT_THREAD, wxThreadEventHandler(SigninMain::OnWorkerEvent));
	this->Connect(m_menuItemCard->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SigninMain::OnStartWorker));
	m_CameraView = new CameraView(this, wxID_ANY);
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	this->StaticBoxSizer_Camera->Add(m_CameraView, 1, wxALL | wxEXPAND | wxFIXED_MINSIZE, 0);

	this->Layout();
	this->Centre(wxBOTH);

}

void SigninMain::OnClose( wxCloseEvent& event )
{
// TODO: Implement OnClose
	m_CameraView->Stop();
	Destroy();

}

void SigninMain::OnMenuSelectionCamera( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelectionCamera
	if (m_CameraView->m_is_display)
	{
		m_CameraView->Stop();
	}
	else
	{
		m_CameraView->Start();
		Layout();
	}
}

void SigninMain::OnMenuSelectionExit( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelectionExit
	Close(true);
}

bool SigninMain::Cancelled()
{
	wxCriticalSectionLocker lock(m_csCancelled);

	return m_cancelled;
}


void SigninMain::OnWorkerEvent(wxThreadEvent& event)
{
	int n = event.GetInt();
	if (n == -1)
	{
		m_dlgProgress->Destroy();
		m_dlgProgress.reset();

		// the dialog is aborted because the event came from another thread, so
		// we may need to wake up the main event loop for the dialog to be
		// really closed
		wxWakeUpIdle();
	}
	else
	{
		if (!m_dlgProgress->Update(n))
		{
			wxCriticalSectionLocker lock(m_csCancelled);

			m_cancelled = true;
		}
	}
}

void SigninMain::OnUpdateWorker(wxUpdateUIEvent& event)
{
	event.Enable(m_dlgProgress == NULL);
}


void SigninMain::OnStartWorker(wxCommandEvent& WXUNUSED(event))
{
	ProgressThread *thread = new ProgressThread(this);

	if (thread->Create() != wxTHREAD_NO_ERROR)
	{
		wxLogError(wxT("Can't create thread!"));
		return;
	}

	m_dlgProgress = std::make_unique<wxProgressDialog>(wxT("Progress dialog"),	wxT("Wait until the thread terminates or press [Cancel]"),100,this, wxPD_SMOOTH);

	// thread is not running yet, no need for crit sect
	m_cancelled = false;

	thread->Run();
}