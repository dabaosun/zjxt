///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SigninFrame.h"

///////////////////////////////////////////////////////////////////////////

SigninFrame::SigninFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(-1, -1), wxDefaultSize);

	wxBoxSizer* BoxSizer_Main;
	BoxSizer_Main = new wxBoxSizer(wxVERTICAL);

	BoxSizer_Main->SetMinSize(wxSize(1920, 1080));
	wxBoxSizer* bSizerTop;
	bSizerTop = new wxBoxSizer(wxVERTICAL);

	bSizerTop->SetMinSize(wxSize(-1, 146));

	bSizerTop->Add(0, 0, 0, 0, 5);

	wxBoxSizer* bSizerLogo;
	bSizerLogo = new wxBoxSizer(wxHORIZONTAL);

	m_bitmapLogo = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("resource/logo.png"), wxBITMAP_TYPE_ANY), wxPoint(30, -1), wxSize(84, 84), 0);
	m_bitmapLogo->SetBackgroundColour(wxColour(0, 74, 165));

	bSizerLogo->Add(m_bitmapLogo, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizerTop->Add(bSizerLogo, 1, wxEXPAND, 5);


	bSizerTop->Add(0, 0, 0, 0, 5);


	BoxSizer_Main->Add(bSizerTop, 0, wxEXPAND, 5);

	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer(wxVERTICAL);

	m_panelTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);
	wxBoxSizer* BoxSizer_Top;
	BoxSizer_Top = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizerCameraTop;
	bSizerCameraTop = new wxBoxSizer(wxVERTICAL);


	bSizerCameraTop->Add(0, 40, 0, wxEXPAND, 5);

	m_staticTextCemra = new wxStaticText(m_panelTop, wxID_ANY, wxT("实时图像区"), wxPoint(-1, -1), wxDefaultSize, 0);
	m_staticTextCemra->Wrap(-1);
	m_staticTextCemra->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextCemra->SetForegroundColour(wxColour(33, 33, 33));

	bSizerCameraTop->Add(m_staticTextCemra, 0, wxALL | wxEXPAND, 30);


	bSizerCameraTop->Add(0, 60, 0, wxEXPAND, 0);

	m_panelCamera = new wxPanel(m_panelTop, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer_Camera = new wxBoxSizer(wxVERTICAL);

	bSizer_Camera->SetMinSize(wxSize(640, 640));

	m_panelCamera->SetSizer(bSizer_Camera);
	m_panelCamera->Layout();
	bSizer_Camera->Fit(m_panelCamera);
	bSizerCameraTop->Add(m_panelCamera, 1, wxEXPAND | wxALL, 5);


	BoxSizer_Top->Add(bSizerCameraTop, 1, wxEXPAND, 5);


	BoxSizer_Top->Add(200, 0, 0, 0, 5);

	wxBoxSizer* bSizerIdentify;
	bSizerIdentify = new wxBoxSizer(wxVERTICAL);


	bSizerIdentify->Add(0, 40, 0, wxEXPAND, 5);

	m_staticTextIdentify = new wxStaticText(m_panelTop, wxID_ANY, wxT("实时图像区"), wxPoint(-1, -1), wxDefaultSize, 0);
	m_staticTextIdentify->Wrap(-1);
	m_staticTextIdentify->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIdentify->SetForegroundColour(wxColour(33, 33, 33));

	bSizerIdentify->Add(m_staticTextIdentify, 0, wxALL, 5);


	bSizerIdentify->Add(0, 60, 0, wxEXPAND, 5);

	wxStaticBoxSizer* StaticBoxSizer_Identify;
	StaticBoxSizer_Identify = new wxStaticBoxSizer(new wxStaticBox(m_panelTop, wxID_ANY, wxEmptyString), wxHORIZONTAL);

	wxBoxSizer* BoxSizer_IDInfoMain;
	BoxSizer_IDInfoMain = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* BoxSizer_IDInfoTop;
	BoxSizer_IDInfoTop = new wxBoxSizer(wxHORIZONTAL);

	wxFlexGridSizer* FlexGridSizer_IDInfoDetail;
	FlexGridSizer_IDInfoDetail = new wxFlexGridSizer(5, 2, 0, 0);
	FlexGridSizer_IDInfoDetail->AddGrowableCol(1);
	FlexGridSizer_IDInfoDetail->AddGrowableRow(4);
	FlexGridSizer_IDInfoDetail->SetFlexibleDirection(wxBOTH);
	FlexGridSizer_IDInfoDetail->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticTextName = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("姓名："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextName->Wrap(-1);
	m_staticTextName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextName->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextName, 0, wxALL, 5);

	m_textCtrlName = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));
	m_textCtrlName->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlName, 0, wxALL | wxEXPAND, 5);

	m_staticTextGender = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("性别："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextGender->Wrap(-1);
	m_staticTextGender->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextGender->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextGender, 0, wxALL, 5);

	wxBoxSizer* BoxSizer_Gender;
	BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);

	m_radioBtnMale = new wxRadioButton(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("男"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnMale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnMale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnMale, 0, wxALL | wxEXPAND, 5);

	m_radioBtnFemale = new wxRadioButton(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("女"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnFemale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnFemale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnFemale, 0, wxALL | wxEXPAND, 5);


	FlexGridSizer_IDInfoDetail->Add(BoxSizer_Gender, 1, wxEXPAND, 5);

	m_staticTextBirth = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("出生日期："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextBirth->Wrap(-1);
	m_staticTextBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextBirth->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextBirth, 0, wxALL, 5);

	m_textCtrlBirth = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlBirth->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlBirth, 0, wxALL | wxEXPAND, 5);

	m_staticTextIDNumber = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("身份证号："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextIDNumber->Wrap(-1);
	m_staticTextIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIDNumber->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextIDNumber, 0, wxALL, 5);

	m_textCtrlIDNumber = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlIDNumber->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlIDNumber, 0, wxALL | wxEXPAND, 5);

	m_staticTextAddr = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("地址："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAddr->Wrap(-1);
	m_staticTextAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextAddr->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextAddr, 0, wxALL, 5);

	m_textCtrlAddr = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP | wxTE_READONLY);
	m_textCtrlAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlAddr->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlAddr, 0, wxALL | wxEXPAND, 5);


	BoxSizer_IDInfoTop->Add(FlexGridSizer_IDInfoDetail, 1, wxEXPAND | wxSHAPED, 5);


	BoxSizer_IDInfoMain->Add(BoxSizer_IDInfoTop, 1, wxEXPAND, 5);


	StaticBoxSizer_Identify->Add(BoxSizer_IDInfoMain, 1, wxEXPAND, 5);

	wxGridSizer* GridSizer_IDImage;
	GridSizer_IDImage = new wxGridSizer(1, 1, 0, 0);

	GridSizer_IDImage->SetMinSize(wxSize(200, 200));
	StaticBitmap_IDImage = new wxStaticBitmap(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxBitmap(wxT("resource/logo.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(132, 163), 0);
	StaticBitmap_IDImage->SetMinSize(wxSize(132, 163));

	GridSizer_IDImage->Add(StaticBitmap_IDImage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	StaticBoxSizer_Identify->Add(GridSizer_IDImage, 1, wxEXPAND, 5);


	bSizerIdentify->Add(StaticBoxSizer_Identify, 1, wxEXPAND, 5);


	BoxSizer_Top->Add(bSizerIdentify, 1, wxEXPAND, 5);


	m_panelTop->SetSizer(BoxSizer_Top);
	m_panelTop->Layout();
	BoxSizer_Top->Fit(m_panelTop);
	bSizerMiddle->Add(m_panelTop, 1, wxEXPAND | wxALL, 5);

	m_panelButtom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizerProgress;
	bSizerProgress = new wxBoxSizer(wxVERTICAL);

	m_staticTextProgress = new wxStaticText(m_panelButtom, wxID_ANY, wxT("Loading"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	m_staticTextProgress->Wrap(-1);
	m_staticTextProgress->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("宋体")));
	m_staticTextProgress->SetForegroundColour(wxColour(0, 45, 135));

	bSizerProgress->Add(m_staticTextProgress, 1, wxALIGN_RIGHT | wxEXPAND | wxALL, 5);

	m_gaugeProgress = new wxGauge(m_panelButtom, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	m_gaugeProgress->SetValue(0);
	m_gaugeProgress->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bSizerProgress->Add(m_gaugeProgress, 1, wxALL | wxEXPAND, 5);


	m_panelButtom->SetSizer(bSizerProgress);
	m_panelButtom->Layout();
	bSizerProgress->Fit(m_panelButtom);
	bSizerMiddle->Add(m_panelButtom, 0, wxALL | wxEXPAND, 5);


	BoxSizer_Main->Add(bSizerMiddle, 1, wxEXPAND, 5);

	bSizerButtom = new wxBoxSizer(wxHORIZONTAL);

	bSizerButtom->SetMinSize(wxSize(-1, 77));

	bSizerButtom->Add(0, 0, 1, wxEXPAND, 5);


	BoxSizer_Main->Add(bSizerButtom, 0, wxEXPAND, 5);


	this->SetSizer(BoxSizer_Main);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));
	m_bitmapLogo->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackgroundLogo), NULL, this);
	m_bitmapLogo->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintLogo), NULL, this);
}

SigninFrame::~SigninFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));
	m_bitmapLogo->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackgroundLogo), NULL, this);
	m_bitmapLogo->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintLogo), NULL, this);

}
