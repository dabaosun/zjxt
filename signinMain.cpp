#include "SigninMain.h"
#include <fstream>
#include "ProgressThread.h"
#include "./certcard/CertCard.h"

enum
{
	WORKER_EVENT = wxID_HIGHEST + 1, // this one gets sent from MyWorkerThread
	GUITHREAD_EVENT                  // this one gets sent from MyGUIThread
};

SigninMain::SigninMain( wxWindow* parent )
:
SigninFrame( parent )
{
	CertCard::GetInstance()->RegisterObserver(this);

	this->Connect(WORKER_EVENT, wxEVT_THREAD, wxThreadEventHandler(SigninMain::OnWorkerEvent));
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

void SigninMain::OnMenuSelectionCard(wxCommandEvent& event)
{
	int result = CertCard::GetInstance()->ConnectCertCard();
	if (0 != result) {
		std::string msg = CertCard::GetInstance()->GetErrMsg(result);
	}
	else {
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
		wxString msg = event.GetString();
		if (!m_dlgProgress->Update(n,msg))
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

void SigninMain::UpdateCardAuthed(bool authed, const std::string& info)
{
	//here, you can update status bar and so on.
}

void SigninMain::UpdateCertCardInfo(const std::shared_ptr<CertCardInfo>& info)
{
	this->m_textCtrlName->WriteText(info->name.get());
	this->m_textCtrlBirth->WriteText(info->birth.get());
	this->m_textCtrlAddr->WriteText(info->address.get());
	this->m_textCtrlIDNumber->WriteText(info->certno.get());
	wxClientDC dc(this->StaticBitmap_IDImage);
	wxImage img;
	img.SetData((unsigned char*)(info->bmpdata.get()));//.LoadFile("d:\\3.jpg");
	img.Rescale(200, 200);

	wxBitmap bitmap = wxBitmap(img);
	dc.DrawBitmap(bitmap, 0, 0);

}

void SigninMain::StartProcess(int result, const std::string& info)
{
	if (NULL != m_dlgProgress) {
		//ignore or throw exception.
		return;
	}
	m_threadProgress.reset(new ProgressThread(this));	
	if (m_threadProgress->Create() != wxTHREAD_NO_ERROR)
	{
		wxLogError(wxT("Can't create thread!"));
		return;
	}

	m_dlgProgress = std::make_unique<wxProgressDialog>(wxT("½ø¶È"), wxT("ÇëµÈ´ý..."), 100, this, wxPD_SMOOTH);

	// thread is not running yet, no need for crit sect
	m_cancelled = false;

	m_threadProgress->Run();
}

void SigninMain::EndProcess(int result, const std::string& info)
{
	if (NULL == m_dlgProgress) {
		//ignore or throw exception.
		return;
	}
	m_threadProgress->m_count = 100;
}

void SigninMain::UpdateProgressInfo(int progress, const std::string& info)
{
	m_threadProgress->m_count = progress;
	m_threadProgress->m_message = info;
}