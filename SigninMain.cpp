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
	m_CameraView = new CameraView(this->m_panelCamera, wxID_ANY);
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	this->bSizer_Camera->Add(m_CameraView, 1, wxALL, 0);
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
	if (NULL != this->m_threadProgress) {
		this->m_threadProgress->Delete();
		if (!this->m_threadProgress->IsDetached()) {
			delete this->m_threadProgress;
		}
		this->m_threadProgress = NULL;
	}
	this->m_CertCard->CloseCertCardReader();
	this->m_CameraView->CloseCamera();

	this->m_CameraView->RemoveListener(this->m_CertCard);	
	this->m_CertCard->RemoveListener(this);
	
	delete m_CertCard;
	delete m_CameraView;

	Destroy();
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
	if (wxT("男") == wxString(info->gendar.get())) {
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
	std::unique_lock<std::mutex> lock(this->m_mtxProgress);
	do {

	} while (NULL != m_threadProgress);
	
	m_threadProgress = new ProgressThread(this);
	m_threadProgress->m_message = info;
	m_threadProgress->Run();
}

void SigninMain::EndProcess(int result, const std::string& info)
{
	if (NULL != m_threadProgress) {
		m_threadProgress->m_count = 100;
		m_threadProgress->m_message = info;
		this->m_threadProgress->Delete();
		if (!this->m_threadProgress->IsDetached()) {
			delete this->m_threadProgress;
		}
		this->m_threadProgress = NULL;
	}

	this->m_textCtrlName->SetLabelText("");
	this->m_textCtrlBirth->SetLabelText("");
	this->m_textCtrlAddr->SetLabelText("");
	this->m_textCtrlIDNumber->SetLabelText("");
	this->m_radioBtnFemale->SetValue(false);
	this->m_radioBtnMale->SetValue(false);

	wxClientDC dc(this->StaticBitmap_IDImage);
	dc.Clear();
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

void SigninMain::OnEraseBackground(wxEraseEvent& event)
{
	wxImage image;
	wxBitmap m_background;
	if (image.LoadFile(_T("./resource/background.png"), wxBITMAP_TYPE_PNG))
	{
		m_background = wxBitmap(image);
	}
	if (m_background.Ok())
	{
		wxSize sz = GetClientSize();
		wxRect rect(0, 0, sz.x, sz.y);

		if (event.GetDC())
		{
			TileBitmap(rect, *(event.GetDC()), m_background);
		}
		else
		{
			wxClientDC dc(this);

			TileBitmap(rect, dc, m_background);

		}
	}
	else {
		event.Skip(); // The official way of doing it
	}		
}

void SigninMain::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	PrepareDC(dc);

	wxImage image;
	wxBitmap logo;
	if (image.LoadFile(_T("./resource/logo.png"), wxBITMAP_TYPE_PNG))
	{
		image.SetMask(false);
		logo = wxBitmap(image);
	}
	int x = 30;
	int y = 40;
	dc.DrawBitmap(logo, x, y, true);

	wxPoint point_1(x + logo.GetSize().GetWidth() + 40,	y + (logo.GetSize().GetHeight() - 36) / 2);
	wxFont font_1(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("SourceHanSerifCN-Bold"));
	TileText(dc, "大学闸机注册系统", font_1, point_1);

	wxFont font_2(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI"));
	y = this->bSizerButtom->GetPosition().y;
	int offset = this->bSizerButtom->GetSize().GetHeight() / 2;
	wxPoint point_2(873, y + offset);
	TileText(dc, "联深泰科技有限公司", font_2, point_2);
}

bool SigninMain::TileBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap)
{
	int w = bitmap.GetWidth();
	int h = bitmap.GetHeight();

	int i, j;
	for (i = rect.x; i < rect.x + rect.width; i += w)
	{
		for (j = rect.y; j < rect.y + rect.height; j += h)
			dc.DrawBitmap(bitmap, i, j);
	}

	return true;
}
bool SigninMain::TileText( wxDC& dc, const wxString& text, wxFont& font, wxPoint& point)
{
	dc.SetFont(font);
	dc.SetTextForeground(wxColour(255, 255, 255));
	dc.DrawText(text, point);
	return true;
}