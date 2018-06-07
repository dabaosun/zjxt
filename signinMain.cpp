/***************************************************************
* Name:      SigninMain.cpp
* Purpose:   App's main frame with GUI.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#include "SigninMain.h"
#include <fstream>
#include "ProgressThread.h"
#include "./certcard/CertCard.h"
#include "./config/Config.h"

enum
{
	WORKER_EVENT = wxID_HIGHEST + 1, // this one gets sent from MyWorkerThread
	GUITHREAD_EVENT                  // this one gets sent from MyGUIThread
};

SigninMain::SigninMain( wxWindow* parent ) : SigninFrame( parent )
{

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
	m_CameraView->CloseCamera();
	Destroy();

}

void SigninMain::OnMenuSelectionCamera( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelectionCamera
	if (m_CameraView->m_is_display)
	{
		m_CameraView->CloseCamera();
	}
	else
	{
		m_CameraView->OpenCamera();
		Layout();
	}
}

void SigninMain::OnMenuSelectionCard(wxCommandEvent& event)
{
	int result = CertCard::GetInstance()->OpenCertCardReader();
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
		bool result = m_dlgProgress->Destroy();
		delete m_dlgProgress;
		m_dlgProgress = NULL;

		// the dialog is aborted because the event came from another thread, so
		// we may need to wake up the main event loop for the dialog to be
		// really closed
		wxWakeUpIdle();
	}
	else
	{
		wxString msg = event.GetString();
		if (NULL != m_dlgProgress) {
			if (!m_dlgProgress->Update(n, msg))
			{
				wxCriticalSectionLocker lock(m_csCancelled);

				m_cancelled = true;
			}
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
	this->m_textCtrlName->SetLabelText(info->name.get());
	this->m_textCtrlBirth->SetLabelText(info->birth.get());
	this->m_textCtrlAddr->SetLabelText(info->address.get());
	this->m_textCtrlIDNumber->SetLabelText(info->certno.get());
	this->m_radioBtnFemale->SetValue(false);
	this->m_radioBtnMale->SetValue(false);
	if (wxT("ÄÐ") == wxString(info->gendar.get())) {
		this->m_radioBtnMale->SetValue(true);
	}
	else {
		this->m_radioBtnFemale->SetValue(true);
	}
	wxClientDC dc(this->StaticBitmap_IDImage);
	wxImage img;
	img.LoadFile(Config::GetInstance()->GetPwd() + "certcard.bmp");
	//img.SetData((unsigned char*)(info->bmpdata.get()));
	img.Rescale(204, 252);

	wxBitmap bitmap = wxBitmap(img);
	dc.DrawBitmap(bitmap, 0, 0);

}

void SigninMain::StartProcess(int result, const std::string& info)
{
	if (NULL != m_dlgProgress) {
		//ignore or throw exception.
		return;
	}
	m_threadProgress = new ProgressThread(this);
	if (m_threadProgress->Create() != wxTHREAD_NO_ERROR)
	{
		wxLogError(wxT("Can't create thread!"));
		return;
	}

	m_dlgProgress = new wxProgressDialog(wxT("½ø¶È"), info, 100, this, wxPD_SMOOTH);

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
	m_threadProgress->m_message = info;
}

void SigninMain::UpdateProgressInfo(int progress, const std::string& info)
{
	m_threadProgress->m_count = progress;
	m_threadProgress->m_message = info;
}

CameraView* SigninMain::GetCameraView()
{
	return this->m_CameraView;
}
