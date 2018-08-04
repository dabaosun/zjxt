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
#include "./DhStaticText.h"

enum
{
	WORKER_EVENT = wxID_HIGHEST + 1, // this one gets sent from MyWorkerThread
	GUITHREAD_EVENT                  // this one gets sent from MyGUIThread
};
void SigninMain::ReplaceStaticText(wxBitmap* background, wxStaticText** replaced, wxSizer* sizer) {
	DhStaticText* obj = new DhStaticText();
	obj->Create((*replaced)->GetParent(), wxID_ANY, (*replaced)->GetLabel(), 
		(*replaced)->GetPosition(), (*replaced)->GetSize(),(*replaced)->GetAlignment());
	obj->SetMinSize((*replaced)->GetMinSize());
	obj->SetPosition((*replaced)->GetPosition());
	obj->SetBg(background);
	obj->Wrap(-1);
	wxFont font = (*replaced)->GetFont();
	obj->SetFont(wxFont(font.GetPointSize(), font.GetFamily(), font.GetStyle(), font.GetWeight(), false, wxT("Microsoft YaHei")));
	obj->SetForegroundColour((*replaced)->GetForegroundColour());
	obj->SetSize((*replaced)->GetSize());
	sizer->Add(obj, 0, wxALL, 0);
	delete *replaced;
	*replaced = obj;
}
SigninMain::SigninMain( wxWindow* parent ) : SigninFrame( parent )
{
	if (0 != Config::GetInstance()->LoadConfig()) {
		
	}
	//this->bSizerTop->SetMinSize(-1, this->GetSize().GetHeight()*10/100);
	//this->bSizerButtom->SetMinSize(-1, this->GetSize().GetHeight() - this->GetSize().GetHeight() * 82 / 100);

	this->Connect(WORKER_EVENT, wxEVT_THREAD, wxThreadEventHandler(SigninMain::OnWorkerEvent));
	
	m_CameraView = new CameraView(this->m_panelCamera, wxID_ANY);
	m_CameraView->SetSize(wxSize(640, 480));
	m_CameraView->SetMinSize(wxSize(640, 480));
	m_CameraView->SetMaxSize(wxSize(640, 480));
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	//m_CameraView->SetSizer(bSizer_Camera);
	m_CameraView->Layout();
	bSizer_Camera->Add(m_CameraView, 1, wxALL , 0);

	//this->bSizer_Camera->Add(m_CameraView, 1, wxALL, 0);
	//this->bSizer_Camera->Fit(m_CameraView);
	//this->m_panelCamera->Layout();

	wxImage image;
	do {
		if (image.LoadFile(_T("./resource/middle.png"), wxBITMAP_TYPE_PNG)) {
			image.SetMask(false);
			image.Rescale(1920, 1080);
			bg_ = new wxBitmap(image);
			if (bg_->IsOk()){
				break;
			}
		}
	} while (1 > 0);

	
	ReplaceStaticText(bg_, &m_staticTextCemra, bSizer16);
	ReplaceStaticText(bg_, &m_staticTextIdentify, bSizer40);
	ReplaceStaticText(bg_, &m_staticTextStep, bSizer41);
	ReplaceStaticText(bg_, &m_staticTextName, bSizer191);
	ReplaceStaticText(bg_, &m_staticTextGender, bSizer20);
	ReplaceStaticText(bg_, &m_staticTextBirth, bSizer21);
	ReplaceStaticText(bg_, &m_Name, bSizer24);
	ReplaceStaticText(bg_, &m_Gender, BoxSizer_Gender);
	ReplaceStaticText(bg_, &m_Birth, bSizer25);
	ReplaceStaticText(bg_, &m_staticTextIDNumber, bSizer33);
	ReplaceStaticText(bg_, &m_staticTextAddr, bSizer34);
	ReplaceStaticText(bg_, &m_IDNumber, bSizer27);
	ReplaceStaticText(bg_, &m_Addr, bSizer29);
	ReplaceStaticText(bg_, &m_staticTextProgress, bSizer42);

	this->Layout();
	this->Centre(wxBOTH);

	this->m_CertCard = new CertCard();
	this->m_CertCard->RegisterListener(this);
	this->m_CameraView->RegisterListener(this->m_CertCard);
	this->m_CameraView->OpenCamera();
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

	this->m_staticTextStep->SetLabelText("（"+msg+"）");

	if ("正在处理中" == msg) {
		this->m_staticTextStep->SetForegroundColour(wxColour(33, 33, 33));
	}

	if ("注册失败" == msg) {
		this->m_staticTextStep->SetForegroundColour(wxColour(226, 62, 49));
	}

	if ("注册成功" == msg) {
		this->m_staticTextStep->SetForegroundColour(wxColour(43, 111, 143));
	}

	if ("请刷身份证" == msg) {
		this->m_staticTextStep->SetForegroundColour(wxColour(33, 33, 33));
	}

	if ("正在处理中" == msg) {
		this->m_staticTextProgress->SetLabelText("Loading");
	}
	else {
		this->m_staticTextProgress->SetLabelText("");
	}
	
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
	this->m_Name->SetLabelText(info->name.get());
	this->m_Birth->SetLabelText(info->birth.get());
	this->m_Addr->SetLabelText(info->address.get());
	this->m_IDNumber->SetLabelText(info->certno.get());
	this->m_Gender->SetLabelText(info->gendar.get());
	
	wxClientDC dc(this->StaticBitmap_IDImage);
	dc.Clear();

	wxImage img;
	img.LoadFile(Config::GetInstance()->GetPwd() + "certcard.bmp");	
	img.Rescale(132, 163);
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

	this->m_Name->SetLabelText("");
	this->m_Birth->SetLabelText("");
	this->m_Addr->SetLabelText("");
	this->m_IDNumber->SetLabelText("");
	this->m_Gender->SetLabelText("");

	wxClientDC dc(this->StaticBitmap_IDImage);
	dc.Clear();

	wxImage img;
	img.LoadFile(Config::GetInstance()->GetPwd() + "./resource/identify.png");
	img.Rescale(132, 163);
	wxBitmap bitmap = wxBitmap(img);
	dc.DrawBitmap(bitmap, 0, 0);
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

void SigninMain::OnEraseBackgroundPanel(wxEraseEvent& event)
{
	wxImage image;
	wxBitmap m_background;
	int top = 146;
	int buttom = 72;
	int middle = 1080 - top - buttom;
	
	//image.Clear();
	do
	{
		if (image.LoadFile(_T("./resource/top.png"), wxBITMAP_TYPE_PNG))
		{
			wxSize sz = this->m_panel4->GetClientSize();

			image.SetMask(false);
			image.Rescale(sz.GetWidth(), top);
			m_background = wxBitmap(image);

			if (m_background.IsOk())
			{
				wxRect rect(0, 0, sz.x, top);

				if (event.GetDC())
				{
					TileBitmap(rect, *(event.GetDC()), m_background);
				}
				else
				{
					wxClientDC dc(this->m_panel4);
					TileBitmap(rect, dc, m_background);
				}
				break;
			}
			else {
				event.Skip(); // The official way of doing it
			}
			continue;
		}
	} while (1 > 0);
	


	image.Clear();
	do
	{
		if (image.LoadFile(_T("./resource/buttom.png"), wxBITMAP_TYPE_PNG))
		{
			wxSize sz = this->m_panel4->GetClientSize();
			image.Rescale(sz.GetWidth(), buttom);
			image.SetMask(false);
			m_background = wxBitmap(image);

			if (m_background.IsOk())
			{
				wxRect rect(0, sz.y - buttom, sz.x, buttom);

				if (event.GetDC())
				{
					TileBitmap(rect, *(event.GetDC()), m_background);
				}
				else
				{
					wxClientDC dc(this->m_panel4);
					TileBitmap(rect, dc, m_background);
				}
				break;
			}
			else {
				event.Skip(); // The official way of doing it
			}
			continue;
		}
	} while (1 > 0);


	do {
		image.Clear();
		if (image.LoadFile(_T("./resource/middle.png"), wxBITMAP_TYPE_PNG))
		{
			wxSize sz = this->m_panel4->GetClientSize();
			image.Rescale(sz.GetWidth(), sz.y - top - buttom);
			image.SetMask(false);

			m_background = wxBitmap(image);
			if (m_background.IsOk())
			{
				wxRect rect(0, top, sz.x, sz.y - top - buttom);

				if (event.GetDC())
				{
					TileBitmap(rect, *(event.GetDC()), m_background);
				}
				else
				{
					wxClientDC dc(this->m_panel4);
					TileBitmap(rect, dc, m_background);
				}
				break;
			}
			else {
				event.Skip(); // The official way of doing it
			}
			continue;
		}
	} while (1 > 0);

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
