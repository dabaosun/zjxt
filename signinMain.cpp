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
	if (0 != Config::GetInstance()->LoadConfig()) {
		
	}

	this->Connect(WORKER_EVENT, wxEVT_THREAD, wxThreadEventHandler(SigninMain::OnWorkerEvent));
	m_CameraView = new CameraView(this, wxID_ANY);
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	this->StaticBoxSizer_Camera->Add(m_CameraView, 1, wxALL | wxEXPAND | wxFIXED_MINSIZE, 0);
	this->Layout();
	this->Centre(wxBOTH);

	this->m_CertCard = new CertCard();
	this->m_CertCard->RegisterListener(this);
	this->m_CameraView->RegisterListener(this->m_CertCard);
	this->GetCameraView()->OpenCamera();
	this->m_CertCard->OpenCertCardReader();
}

void SigninMain::OnClose( wxCloseEvent& event )
{	
	this->m_CertCard->CloseCertCardReader();
	this->m_CameraView->CloseCamera();

	this->m_CameraView->RemoveListener(this->m_CertCard);	
	this->m_CertCard->RemoveListener(this);
	
	delete m_CertCard;
	delete m_CameraView;
		
	if (NULL != this->m_threadProgress) {
		if (!this->m_threadProgress->IsDetached()) {
			this->m_threadProgress->Delete();
		}
		this->m_threadProgress = NULL;
	}

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
	int result = this->m_CertCard->OpenCertCardReader();
	if (0 != result) {
		std::string msg = this->m_CertCard->GetErrMsg(result);
	}
	else {
	}
}


void SigninMain::OnMenuSelectionExit( wxCommandEvent& event )
{
	// TODO: Implement OnMenuSelectionExit
	Close(true);
}

void SigninMain::OnActivateApp(wxActivateEvent& event)
{
	
}

bool SigninMain::Cancelled()
{
	wxCriticalSectionLocker lock(m_csCancelled);

	return m_cancelled;
}


void SigninMain::OnWorkerEvent(wxThreadEvent& event)
{
	int n = event.GetInt();
	wxString msg = event.GetString();
	this->m_staticTextProgress->SetLabelText(msg);
	this->m_gaugeProgress->SetValue(n);

	if (n == -1)
	{
		bool result = m_dlgProgress->Destroy();
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

void SigninMain::StartProcess(const std::string& info)
{
	if (NULL != m_threadProgress) {
		m_threadProgress->Delete();
		if (!m_threadProgress->IsDetached()) {
			delete m_threadProgress;
		}
		m_threadProgress = NULL;
	}

	if (NULL != m_dlgProgress) {
		m_dlgProgress->Destroy();
		m_dlgProgress = NULL;
	}
	m_dlgProgress = new wxProgressDialog(wxT("½ø¶È"), info, 100, this, wxPD_SMOOTH);
	m_cancelled = false;

	m_threadProgress = new ProgressThread(this);
	m_threadProgress->m_message = info;
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
	

	if (NULL != m_threadProgress) {
		this->m_threadProgress->Delete();
		if (!this->m_threadProgress->IsDetached()) {
			delete this->m_threadProgress;
		}
		this->m_threadProgress = NULL;

	}
	this->m_staticTextProgress->SetLabelText(info);
	this->m_gaugeProgress->SetValue(0);
}

void SigninMain::UpdateProgressInfo(int progress, const std::string& info)
{
	/*
	m_threadProgress->m_count = progress;
	m_threadProgress->m_message = info;
	*/
}

CameraView* SigninMain::GetCameraView()
{
	return this->m_CameraView;
}

SigninMain::~SigninMain()
{

}