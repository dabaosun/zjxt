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
#include "./statictext/CustomStaticText.h"

enum
{
	WORKER_EVENT = wxID_HIGHEST + 1, // this one gets sent from MyWorkerThread
	GUITHREAD_EVENT                  // this one gets sent from MyGUIThread
};
void SigninMain::ReplaceStaticText(wxBitmap* background, wxStaticText** replaced, wxSizer* sizer) {
	CustomStaticText* obj = new CustomStaticText();
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

	this->Connect(WORKER_EVENT, wxEVT_THREAD, wxThreadEventHandler(SigninMain::OnWorkerEvent));
	
	m_CameraView = new CameraView(this->m_panelCamera, wxID_ANY);
	m_CameraView->SetSize(wxSize(640, 480));
	m_CameraView->SetMinSize(wxSize(640, 480));
	m_CameraView->SetMaxSize(wxSize(640, 480));
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	m_CameraView->Layout();
	bSizer_Camera->Add(m_CameraView, 1, wxALL , 0);

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
			m_Top = new wxBitmap(image);
			if (m_Top->IsOk()) {
				break;
			}
		}
	} while (1 > 0);

	do
	{
		if (image.LoadFile(_T("./resource/buttom.png"), wxBITMAP_TYPE_PNG))
		{
			wxSize sz = this->m_panel4->GetClientSize();
			image.Rescale(sz.GetWidth(), buttom);
			image.SetMask(false);
			m_Buttom = new wxBitmap(image);
			if (m_Buttom->IsOk())
			{
				break;

			}
		}
	} while (1 > 0);

	do
	{
		if (image.LoadFile(_T("./resource/middle.png"), wxBITMAP_TYPE_PNG))
		{
			wxSize sz = this->m_panel4->GetClientSize();
			image.Rescale(sz.GetWidth(), middle);
			image.SetMask(false);
			m_Middle = new wxBitmap(image);
			if (m_Middle->IsOk())
			{
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

	this->m_CameraView->RemoveListener(this->m_CertCard);
	this->m_CertCard->RemoveListener(this);

	this->m_CertCard->CloseCertCardReader();
	this->m_CameraView->CloseCamera();
	
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

	this->m_staticTextStep->SetLabel("（"+msg+"）");

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
		this->m_staticTextProgress->SetLabel("Loading");
	}
	else {
		this->m_staticTextProgress->SetLabel("");
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
	this->m_Name->SetLabel(info->name.get());
	this->m_Birth->SetLabel(info->birth.get());
	this->m_Addr->SetLabel(info->address.get());
	this->m_IDNumber->SetLabel(info->certno.get());
	this->m_Gender->SetLabel(info->gendar.get());
	
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

	this->m_Name->SetLabel("");
	this->m_Birth->SetLabel("");
	this->m_Addr->SetLabel("");
	this->m_IDNumber->SetLabel("");
	this->m_Gender->SetLabel("");

	wxClientDC dc(this->StaticBitmap_IDImage);
	dc.Clear();

	wxImage img;
	img.LoadFile(Config::GetInstance()->GetPwd() + "./resource/identify.png");
	img.Rescale(132, 163);
	wxBitmap bitmap = wxBitmap(img);
	dc.DrawBitmap(bitmap, 0, 0);

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	this->m_staticTextStep->SetForegroundColour(wxColour(33, 33, 33));
	this->m_staticTextStep->SetLabel("（请刷身份证）");
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

void SigninMain::m_panel4OnPaint(wxPaintEvent& event)
{
	wxBufferedPaintDC dc(this->m_panel4);
	int top = 146;
	int buttom = 72;
	int middle = 1080 - top - buttom;
	dc.DrawBitmap(*m_Top, 0, 0);
	dc.DrawBitmap(*m_Middle, 0, top);
	dc.DrawBitmap(*m_Buttom, 0, top + middle);
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
