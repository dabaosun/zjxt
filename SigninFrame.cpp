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
	this->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));

	wxBoxSizer* BoxSizer_Main;
	BoxSizer_Main = new wxBoxSizer(wxVERTICAL);

	m_panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel4->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));

	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer(wxVERTICAL);

	bSizerTop = new wxBoxSizer(wxVERTICAL);

	bSizerTop->SetMinSize(wxSize(-1, 146));

	bSizerTop->Add(0, 0, 0, 0, 0);

	bSizerLogo = new wxBoxSizer(wxHORIZONTAL);

	bSizerLogo->SetMinSize(wxSize(84, 84));

	bSizerTop->Add(bSizerLogo, 1, wxEXPAND, 0);


	bSizerTop->Add(0, 0, 0, 0, 0);


	bSizer341->Add(bSizerTop, 0, wxEXPAND, 0);

	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer(wxVERTICAL);

	bSizerMiddle->SetMinSize(wxSize(-1, 862));

	bSizerMiddle->Add(0, 104, 0, 0, 0);

	m_panelMiddleTop = new wxPanel(m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);
	m_panelMiddleTop->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_panelMiddleTop->Enable(false);

	wxBoxSizer* BoxSizer_PanelTop;
	BoxSizer_PanelTop = new wxBoxSizer(wxHORIZONTAL);


	BoxSizer_PanelTop->Add(104, 0, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer362;
	bSizer362 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizerCameraTop;
	bSizerCameraTop = new wxBoxSizer(wxHORIZONTAL);

	bSizerCameraTop->SetMinSize(wxSize(640, -1));
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer(wxHORIZONTAL);

	bSizer16->SetMinSize(wxSize(640, -1));

	bSizer16->Add(242, 0, 0, 0, 5);

	m_staticTextCemra = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("实时图像区"), wxPoint(346, 250), wxDefaultSize, 0);
	m_staticTextCemra->Wrap(-1);
	m_staticTextCemra->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextCemra->SetForegroundColour(wxColour(33, 33, 33));

	bSizer16->Add(m_staticTextCemra, 0, wxALL, 5);


	bSizer19->Add(bSizer16, 0, wxEXPAND, 5);


	bSizer19->Add(0, 47, 0, 0, 5);

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer(wxVERTICAL);

	bSizer38->SetMinSize(wxSize(640, 480));
	m_panelCamera = new wxPanel(m_panelMiddleTop, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
	m_panelCamera->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_panelCamera->SetBackgroundColour(wxColour(0, 0, 0));
	m_panelCamera->SetMinSize(wxSize(640, 480));

	bSizer_Camera = new wxBoxSizer(wxVERTICAL);

	bSizer_Camera->SetMinSize(wxSize(640, 480));

	m_panelCamera->SetSizer(bSizer_Camera);
	m_panelCamera->Layout();
	bSizer_Camera->Fit(m_panelCamera);
	bSizer38->Add(m_panelCamera, 0, wxALL, 0);


	bSizer19->Add(bSizer38, 1, wxEXPAND, 0);


	bSizerCameraTop->Add(bSizer19, 1, wxEXPAND, 5);


	bSizer362->Add(bSizerCameraTop, 1, wxEXPAND, 0);


	BoxSizer_PanelTop->Add(bSizer362, 1, wxEXPAND, 0);


	BoxSizer_PanelTop->Add(246, 0, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizerIdentify;
	bSizerIdentify = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer(wxHORIZONTAL);

	bSizer17->SetMinSize(wxSize(609, -1));

	bSizer17->Add(188, 0, 0, 0, 0);

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer(wxVERTICAL);

	m_staticTextIdentify = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("身份证信息区"), wxPoint(1196, 250), wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_staticTextIdentify->Wrap(-1);
	m_staticTextIdentify->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIdentify->SetForegroundColour(wxColour(33, 33, 33));

	bSizer40->Add(m_staticTextIdentify, 1, wxALL | wxEXPAND, 0);


	bSizer17->Add(bSizer40, 0, wxALIGN_CENTER_VERTICAL, 0);

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer(wxHORIZONTAL);

	m_staticTextStep = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("（请刷身份证）"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_staticTextStep->Wrap(-1);
	m_staticTextStep->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));

	bSizer41->Add(m_staticTextStep, 1, wxALL | wxEXPAND, 0);


	bSizer17->Add(bSizer41, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 0);


	bSizerIdentify->Add(bSizer17, 0, 0, 0);


	bSizerIdentify->Add(0, 115, 0, wxEXPAND, 0);

	wxBoxSizer* bSizerIdentifyTop;
	bSizerIdentifyTop = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer(wxVERTICAL);

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
	fgSizer3->AddGrowableCol(1);
	fgSizer3->AddGrowableRow(0);
	fgSizer3->SetFlexibleDirection(wxBOTH);
	fgSizer3->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	wxBoxSizer* BoxSizer_IDInfoMain;
	BoxSizer_IDInfoMain = new wxBoxSizer(wxVERTICAL);

	wxFlexGridSizer* FlexGridSizer_IDInfoDetail;
	FlexGridSizer_IDInfoDetail = new wxFlexGridSizer(1, 2, 0, 0);
	FlexGridSizer_IDInfoDetail->AddGrowableCol(0);
	FlexGridSizer_IDInfoDetail->AddGrowableRow(0);
	FlexGridSizer_IDInfoDetail->SetFlexibleDirection(wxBOTH);
	FlexGridSizer_IDInfoDetail->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer(wxVERTICAL);

	m_staticTextName = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("姓名："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextName->Wrap(-1);
	m_staticTextName->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextName->SetForegroundColour(wxColour(33, 33, 33));

	bSizer191->Add(m_staticTextName, 1, wxALL | wxEXPAND, 0);


	bSizer22->Add(bSizer191, 0, 0, 0);


	bSizer22->Add(0, 45, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer(wxVERTICAL);

	m_staticTextGender = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("性别："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextGender->Wrap(-1);
	m_staticTextGender->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextGender->SetForegroundColour(wxColour(33, 33, 33));

	bSizer20->Add(m_staticTextGender, 1, wxALL | wxEXPAND, 0);


	bSizer22->Add(bSizer20, 0, 0, 0);


	bSizer22->Add(0, 45, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer(wxVERTICAL);

	m_staticTextBirth = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("出生日期："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextBirth->Wrap(-1);
	m_staticTextBirth->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextBirth->SetForegroundColour(wxColour(33, 33, 33));

	bSizer21->Add(m_staticTextBirth, 1, wxALL | wxEXPAND, 0);


	bSizer22->Add(bSizer21, 0, 0, 0);

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer(wxVERTICAL);


	bSizer30->Add(0, 45, 0, 0, 0);


	bSizer22->Add(bSizer30, 0, 0, 0);


	FlexGridSizer_IDInfoDetail->Add(bSizer22, 0, 0, 0);

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer(wxVERTICAL);

	m_Name = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_Name->Wrap(-1);
	m_Name->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_Name->SetForegroundColour(wxColour(33, 33, 33));
	m_Name->SetMinSize(wxSize(179, -1));

	bSizer24->Add(m_Name, 1, wxALL | wxEXPAND, 0);


	bSizer23->Add(bSizer24, 0, wxEXPAND, 0);


	bSizer23->Add(0, 45, 0, 0, 0);

	wxBoxSizer* BoxSizer_Gender;
	BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);

	m_Gender = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_Gender->Wrap(-1);
	m_Gender->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_Gender->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_Gender, 1, wxALL | wxEXPAND, 0);


	bSizer23->Add(BoxSizer_Gender, 0, wxEXPAND, 0);


	bSizer23->Add(0, 45, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer(wxVERTICAL);

	m_Birth = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_Birth->Wrap(-1);
	m_Birth->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_Birth->SetForegroundColour(wxColour(33, 33, 33));

	bSizer25->Add(m_Birth, 1, wxALL | wxEXPAND, 0);


	bSizer23->Add(bSizer25, 1, wxEXPAND, 0);

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer(wxVERTICAL);


	bSizer31->Add(0, 45, 1, wxEXPAND, 0);


	bSizer23->Add(bSizer31, 0, wxEXPAND, 0);


	FlexGridSizer_IDInfoDetail->Add(bSizer23, 0, 0, 0);


	BoxSizer_IDInfoMain->Add(FlexGridSizer_IDInfoDetail, 0, wxSHAPED, 0);


	fgSizer3->Add(BoxSizer_IDInfoMain, 1, wxEXPAND, 0);

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer(wxVERTICAL);

	StaticBitmap_IDImage = new wxStaticBitmap(m_panelMiddleTop, wxID_ANY, wxBitmap(wxT("resource/identify.png"), wxBITMAP_TYPE_ANY), wxPoint(1469, 387), wxSize(-1, -1), 0);
	StaticBitmap_IDImage->SetMinSize(wxSize(132, 163));

	bSizer44->Add(StaticBitmap_IDImage, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 0);


	fgSizer3->Add(bSizer44, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 0);


	bSizer18->Add(fgSizer3, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer(wxVERTICAL);

	m_staticTextIDNumber = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("身份证号："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextIDNumber->Wrap(-1);
	m_staticTextIDNumber->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIDNumber->SetForegroundColour(wxColour(33, 33, 33));

	bSizer33->Add(m_staticTextIDNumber, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 0);


	bSizer35->Add(bSizer33, 1, 0, 0);


	bSizer35->Add(0, 45, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer(wxVERTICAL);

	m_staticTextAddr = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("地址："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAddr->Wrap(-1);
	m_staticTextAddr->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextAddr->SetForegroundColour(wxColour(33, 33, 33));

	bSizer34->Add(m_staticTextAddr, 0, wxALL, 0);


	bSizer35->Add(bSizer34, 1, 0, 0);


	bSizer32->Add(bSizer35, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer(wxVERTICAL);

	m_IDNumber = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_IDNumber->Wrap(-1);
	m_IDNumber->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_IDNumber->SetForegroundColour(wxColour(33, 33, 33));

	bSizer27->Add(m_IDNumber, 1, wxALL | wxEXPAND, 0);


	bSizer36->Add(bSizer27, 1, wxEXPAND, 0);


	bSizer36->Add(0, 45, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer(wxHORIZONTAL);

	m_Addr = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	m_Addr->Wrap(-1);
	m_Addr->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_Addr->SetForegroundColour(wxColour(33, 33, 33));
	m_Addr->SetMinSize(wxSize(458, -1));

	bSizer29->Add(m_Addr, 1, wxALL | wxEXPAND, 0);


	bSizer36->Add(bSizer29, 1, wxEXPAND, 0);


	bSizer32->Add(bSizer36, 1, wxEXPAND, 0);


	bSizer18->Add(bSizer32, 0, wxEXPAND, 0);


	bSizerIdentifyTop->Add(bSizer18, 1, wxEXPAND, 0);


	bSizerIdentify->Add(bSizerIdentifyTop, 1, wxEXPAND, 0);


	bSizer37->Add(bSizerIdentify, 1, wxEXPAND, 0);


	BoxSizer_PanelTop->Add(bSizer37, 1, wxEXPAND, 0);


	BoxSizer_PanelTop->Add(320, 0, 0, 0, 0);


	m_panelMiddleTop->SetSizer(BoxSizer_PanelTop);
	m_panelMiddleTop->Layout();
	BoxSizer_PanelTop->Fit(m_panelMiddleTop);
	bSizerMiddle->Add(m_panelMiddleTop, 1, wxEXPAND | wxALL, 0);

	m_panelMiddleButtom = new wxPanel(m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);
	m_panelMiddleButtom->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));

	wxBoxSizer* bSizerProgress;
	bSizerProgress = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer(wxVERTICAL);

	bSizer42->SetMinSize(wxSize(-1, 18));
	m_staticTextProgress = new wxStaticText(m_panelMiddleButtom, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 18), wxALIGN_RIGHT);
	m_staticTextProgress->Wrap(-1);
	m_staticTextProgress->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextProgress->SetForegroundColour(wxColour(0, 45, 93));

	bSizer42->Add(m_staticTextProgress, 0, wxALL | wxALIGN_RIGHT, 0);


	bSizerProgress->Add(bSizer42, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer(wxVERTICAL);

	m_gaugeProgress = new wxGauge(m_panelMiddleButtom, wxID_ANY, 100, wxDefaultPosition, wxSize(-1, 8), wxGA_HORIZONTAL);
	m_gaugeProgress->SetValue(0);
	m_gaugeProgress->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_gaugeProgress->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	m_gaugeProgress->SetMinSize(wxSize(-1, 8));

	bSizer43->Add(m_gaugeProgress, 0, wxTOP | wxBOTTOM | wxEXPAND, 0);


	bSizerProgress->Add(bSizer43, 1, wxEXPAND, 0);


	m_panelMiddleButtom->SetSizer(bSizerProgress);
	m_panelMiddleButtom->Layout();
	bSizerProgress->Fit(m_panelMiddleButtom);
	bSizerMiddle->Add(m_panelMiddleButtom, 0, wxALL | wxEXPAND, 0);


	bSizer341->Add(bSizerMiddle, 1, wxEXPAND, 0);

	bSizerButtom = new wxBoxSizer(wxHORIZONTAL);

	bSizerButtom->SetMinSize(wxSize(-1, 72));

	bSizerButtom->Add(0, 0, 1, wxEXPAND, 0);


	bSizer341->Add(bSizerButtom, 0, wxEXPAND, 0);


	m_panel4->SetSizer(bSizer341);
	m_panel4->Layout();
	bSizer341->Fit(m_panel4);
	BoxSizer_Main->Add(m_panel4, 1, wxEXPAND | wxALL, 0);


	this->SetSizer(BoxSizer_Main);
	this->Layout();
	BoxSizer_Main->Fit(this);

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));
	m_panel4->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackgroundPanel), NULL, this);
	m_panel4->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintPanel), NULL, this);
	m_staticTextCemra->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextIdentify->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextStep->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextName->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextGender->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextBirth->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Name->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Gender->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Birth->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextIDNumber->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextAddr->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_IDNumber->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Addr->Connect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
}

SigninFrame::~SigninFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));
	m_panel4->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackgroundPanel), NULL, this);
	m_panel4->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintPanel), NULL, this);
	m_staticTextCemra->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextIdentify->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextStep->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextName->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextGender->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextBirth->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Name->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Gender->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Birth->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextIDNumber->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_staticTextAddr->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_IDNumber->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);
	m_Addr->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintStaticText), NULL, this);

}
