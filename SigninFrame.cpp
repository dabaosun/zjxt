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
	this->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

	wxBoxSizer* BoxSizer_Main;
	BoxSizer_Main = new wxBoxSizer(wxVERTICAL);

	m_panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer(wxVERTICAL);

	bSizerTop = new wxBoxSizer(wxVERTICAL);

	bSizerTop->SetMinSize(wxSize(-1, 100));

	bSizerTop->Add(0, 0, 0, 0, 5);

	bSizerLogo = new wxBoxSizer(wxHORIZONTAL);

	bSizerLogo->SetMinSize(wxSize(84, 84));

	bSizerTop->Add(bSizerLogo, 1, wxEXPAND, 5);


	bSizerTop->Add(0, 0, 0, 0, 5);


	bSizer341->Add(bSizerTop, 0, wxEXPAND, 5);

	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer(wxVERTICAL);

	m_panelMiddleTop = new wxPanel(m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);
	m_panelMiddleTop->Enable(false);

	wxBoxSizer* BoxSizer_PanelTop;
	BoxSizer_PanelTop = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizerCameraTop;
	bSizerCameraTop = new wxBoxSizer(wxHORIZONTAL);


	bSizerCameraTop->Add(20, 0, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer(wxVERTICAL);

	m_staticTextCemra = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("实时图像区"), wxPoint(-1, -1), wxDefaultSize, 0);
	m_staticTextCemra->Wrap(-1);
	m_staticTextCemra->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextCemra->SetForegroundColour(wxColour(33, 33, 33));

	bSizer16->Add(m_staticTextCemra, 0, wxALL, 5);


	bSizer19->Add(bSizer16, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer361;
	bSizer361 = new wxBoxSizer(wxVERTICAL);

	m_panelCamera = new wxPanel(m_panelMiddleTop, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
	m_panelCamera->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	m_panelCamera->SetMinSize(wxSize(640, 640));

	bSizer_Camera = new wxBoxSizer(wxVERTICAL);

	bSizer_Camera->SetMinSize(wxSize(640, 640));

	m_panelCamera->SetSizer(bSizer_Camera);
	m_panelCamera->Layout();
	bSizer_Camera->Fit(m_panelCamera);
	bSizer361->Add(m_panelCamera, 1, wxALL | wxEXPAND, 5);


	bSizer19->Add(bSizer361, 0, 0, 5);


	bSizer19->Add(0, 0, 1, wxEXPAND, 5);


	bSizerCameraTop->Add(bSizer19, 1, wxEXPAND, 5);


	BoxSizer_PanelTop->Add(bSizerCameraTop, 1, wxEXPAND, 5);


	BoxSizer_PanelTop->Add(30, 0, 0, 0, 5);

	wxBoxSizer* bSizerIdentify;
	bSizerIdentify = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer(wxVERTICAL);

	m_staticTextIdentify = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("身份证信息区"), wxPoint(-1, -1), wxDefaultSize, 0);
	m_staticTextIdentify->Wrap(-1);
	m_staticTextIdentify->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIdentify->SetForegroundColour(wxColour(33, 33, 33));

	bSizer17->Add(m_staticTextIdentify, 0, wxALL, 5);


	bSizerIdentify->Add(bSizer17, 0, wxEXPAND, 5);

	wxBoxSizer* bSizerIdentifyTop;
	bSizerIdentifyTop = new wxBoxSizer(wxHORIZONTAL);


	bSizerIdentifyTop->Add(20, 0, 0, wxEXPAND, 5);

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
	m_staticTextName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextName->SetForegroundColour(wxColour(33, 33, 33));

	bSizer191->Add(m_staticTextName, 1, wxALL, 5);


	bSizer22->Add(bSizer191, 1, wxEXPAND, 5);


	bSizer22->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer(wxVERTICAL);

	m_staticTextGender = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("性别："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextGender->Wrap(-1);
	m_staticTextGender->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextGender->SetForegroundColour(wxColour(33, 33, 33));

	bSizer20->Add(m_staticTextGender, 1, wxALL, 5);


	bSizer22->Add(bSizer20, 1, wxEXPAND, 5);


	bSizer22->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer(wxVERTICAL);

	m_staticTextBirth = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("出生日期："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextBirth->Wrap(-1);
	m_staticTextBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextBirth->SetForegroundColour(wxColour(33, 33, 33));

	bSizer21->Add(m_staticTextBirth, 1, wxALL, 5);


	bSizer22->Add(bSizer21, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer(wxVERTICAL);


	bSizer30->Add(0, 0, 1, wxEXPAND, 5);


	bSizer22->Add(bSizer30, 1, wxEXPAND, 5);


	FlexGridSizer_IDInfoDetail->Add(bSizer22, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer(wxVERTICAL);

	m_textCtrlName = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NOHIDESEL | wxTE_READONLY);
	m_textCtrlName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));
	m_textCtrlName->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlName->Enable(false);

	bSizer24->Add(m_textCtrlName, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	bSizer23->Add(bSizer24, 1, wxEXPAND, 5);


	bSizer23->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* BoxSizer_Gender;
	BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);

	m_radioBtnMale = new wxRadioButton(m_panelMiddleTop, wxID_ANY, wxT("男"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnMale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnMale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnMale, 1, wxALL | wxEXPAND, 5);

	m_radioBtnFemale = new wxRadioButton(m_panelMiddleTop, wxID_ANY, wxT("女"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnFemale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnFemale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnFemale, 1, wxALL | wxEXPAND, 5);


	bSizer23->Add(BoxSizer_Gender, 0, wxEXPAND, 5);


	bSizer23->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer(wxVERTICAL);

	m_textCtrlBirth = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlBirth->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlBirth->Enable(false);
	m_textCtrlBirth->SetMinSize(wxSize(192, -1));

	bSizer25->Add(m_textCtrlBirth, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	bSizer23->Add(bSizer25, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer(wxVERTICAL);


	bSizer31->Add(0, 0, 1, wxEXPAND, 5);


	bSizer23->Add(bSizer31, 1, wxEXPAND, 5);


	FlexGridSizer_IDInfoDetail->Add(bSizer23, 1, wxEXPAND, 5);


	BoxSizer_IDInfoMain->Add(FlexGridSizer_IDInfoDetail, 0, wxSHAPED, 5);


	fgSizer3->Add(BoxSizer_IDInfoMain, 0, 0, 5);

	wxGridSizer* GridSizer_IDImage;
	GridSizer_IDImage = new wxGridSizer(1, 1, 0, 0);

	StaticBitmap_IDImage = new wxStaticBitmap(m_panelMiddleTop, wxID_ANY, wxBitmap(wxT("resource/identify.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(-1, -1), 0);
	GridSizer_IDImage->Add(StaticBitmap_IDImage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);


	fgSizer3->Add(GridSizer_IDImage, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer18->Add(fgSizer3, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer(wxVERTICAL);

	m_staticTextIDNumber = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("身份证号："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextIDNumber->Wrap(-1);
	m_staticTextIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIDNumber->SetForegroundColour(wxColour(33, 33, 33));

	bSizer33->Add(m_staticTextIDNumber, 1, wxALL, 5);


	bSizer35->Add(bSizer33, 1, 0, 5);


	bSizer35->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer(wxVERTICAL);

	m_staticTextAddr = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("地址："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAddr->Wrap(-1);
	m_staticTextAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextAddr->SetForegroundColour(wxColour(33, 33, 33));

	bSizer34->Add(m_staticTextAddr, 1, wxALL, 5);


	bSizer35->Add(bSizer34, 0, 0, 5);


	bSizer32->Add(bSizer35, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer(wxVERTICAL);

	m_textCtrlIDNumber = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlIDNumber->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlIDNumber->Enable(false);
	m_textCtrlIDNumber->SetMinSize(wxSize(432, -1));

	bSizer27->Add(m_textCtrlIDNumber, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	bSizer36->Add(bSizer27, 1, wxEXPAND, 5);


	bSizer36->Add(0, 0, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer(wxVERTICAL);

	m_textCtrlAddr = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP | wxTE_READONLY);
	m_textCtrlAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlAddr->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlAddr->Enable(false);

	bSizer29->Add(m_textCtrlAddr, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	bSizer36->Add(bSizer29, 1, wxEXPAND, 5);


	bSizer32->Add(bSizer36, 1, 0, 5);


	bSizer18->Add(bSizer32, 0, wxEXPAND, 5);


	bSizerIdentifyTop->Add(bSizer18, 1, wxEXPAND, 5);


	bSizerIdentify->Add(bSizerIdentifyTop, 1, wxEXPAND, 5);


	BoxSizer_PanelTop->Add(bSizerIdentify, 1, wxEXPAND, 5);


	m_panelMiddleTop->SetSizer(BoxSizer_PanelTop);
	m_panelMiddleTop->Layout();
	BoxSizer_PanelTop->Fit(m_panelMiddleTop);
	bSizerMiddle->Add(m_panelMiddleTop, 1, wxEXPAND | wxALL, 5);

	m_panelMiddleButtom = new wxPanel(m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizerProgress;
	bSizerProgress = new wxBoxSizer(wxVERTICAL);

	m_staticTextProgress = new wxStaticText(m_panelMiddleButtom, wxID_ANY, wxT("Loading"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	m_staticTextProgress->Wrap(-1);
	m_staticTextProgress->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextProgress->SetForegroundColour(wxColour(0, 45, 93));

	bSizerProgress->Add(m_staticTextProgress, 1, wxALIGN_RIGHT | wxEXPAND | wxALL, 5);

	m_gaugeProgress = new wxGauge(m_panelMiddleButtom, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	m_gaugeProgress->SetValue(0);
	m_gaugeProgress->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bSizerProgress->Add(m_gaugeProgress, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	m_panelMiddleButtom->SetSizer(bSizerProgress);
	m_panelMiddleButtom->Layout();
	bSizerProgress->Fit(m_panelMiddleButtom);
	bSizerMiddle->Add(m_panelMiddleButtom, 0, wxALL | wxEXPAND, 5);


	bSizer341->Add(bSizerMiddle, 1, wxEXPAND, 5);

	bSizerButtom = new wxBoxSizer(wxHORIZONTAL);

	bSizerButtom->SetMinSize(wxSize(-1, 72));

	bSizerButtom->Add(0, 0, 1, wxEXPAND, 5);


	bSizer341->Add(bSizerButtom, 0, wxEXPAND, 5);


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
}

SigninFrame::~SigninFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));
	m_panel4->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackgroundPanel), NULL, this);
	m_panel4->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaintPanel), NULL, this);

}
