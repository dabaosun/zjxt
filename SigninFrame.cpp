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

	bSizerLogo->SetMinSize(wxSize(84, 84));

	bSizerTop->Add(bSizerLogo, 1, wxEXPAND, 5);


	bSizerTop->Add(0, 0, 0, 0, 5);


	BoxSizer_Main->Add(bSizerTop, 0, wxEXPAND, 5);


	BoxSizer_Main->Add(0, 20, 1, wxEXPAND, 5);

	wxBoxSizer* bSizerMiddle;
	bSizerMiddle = new wxBoxSizer(wxVERTICAL);

	m_panelMiddleTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);
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

	bSizer16->Add(m_staticTextCemra, 0, wxALL | wxEXPAND, 5);


	bSizer19->Add(bSizer16, 1, wxEXPAND, 5);

	m_panelCamera = new wxPanel(m_panelMiddleTop, wxID_ANY, wxDefaultPosition, wxSize(680, 680), wxTAB_TRAVERSAL);
	m_panelCamera->SetMinSize(wxSize(680, 680));

	bSizer_Camera = new wxBoxSizer(wxVERTICAL);

	bSizer_Camera->SetMinSize(wxSize(640, 640));

	m_panelCamera->SetSizer(bSizer_Camera);
	m_panelCamera->Layout();
	bSizer19->Add(m_panelCamera, 2, wxEXPAND | wxALL, 5);


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

	bSizer17->Add(m_staticTextIdentify, 0, wxALL | wxEXPAND, 5);


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

	wxBoxSizer* BoxSizer_IDInfoTop;
	BoxSizer_IDInfoTop = new wxBoxSizer(wxHORIZONTAL);

	wxFlexGridSizer* FlexGridSizer_IDInfoDetail;
	FlexGridSizer_IDInfoDetail = new wxFlexGridSizer(3, 2, 0, 0);
	FlexGridSizer_IDInfoDetail->AddGrowableCol(1);
	FlexGridSizer_IDInfoDetail->AddGrowableRow(2);
	FlexGridSizer_IDInfoDetail->SetFlexibleDirection(wxBOTH);
	FlexGridSizer_IDInfoDetail->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticTextName = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("姓名："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextName->Wrap(-1);
	m_staticTextName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextName->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextName, 1, wxALL, 5);

	m_textCtrlName = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NOHIDESEL | wxTE_READONLY);
	m_textCtrlName->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));
	m_textCtrlName->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlName->Enable(false);

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlName, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);

	m_staticTextGender = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("性别："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextGender->Wrap(-1);
	m_staticTextGender->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextGender->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextGender, 1, wxALL, 5);

	wxBoxSizer* BoxSizer_Gender;
	BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);

	m_radioBtnMale = new wxRadioButton(m_panelMiddleTop, wxID_ANY, wxT("男"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnMale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnMale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnMale, 0, wxALL | wxEXPAND, 5);

	m_radioBtnFemale = new wxRadioButton(m_panelMiddleTop, wxID_ANY, wxT("女"), wxDefaultPosition, wxDefaultSize, 0 | wxTRANSPARENT_WINDOW);
	m_radioBtnFemale->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_radioBtnFemale->SetForegroundColour(wxColour(33, 33, 33));

	BoxSizer_Gender->Add(m_radioBtnFemale, 0, wxALL | wxEXPAND, 5);


	FlexGridSizer_IDInfoDetail->Add(BoxSizer_Gender, 1, wxEXPAND, 5);

	m_staticTextBirth = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("出生日期："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextBirth->Wrap(-1);
	m_staticTextBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextBirth->SetForegroundColour(wxColour(33, 33, 33));

	FlexGridSizer_IDInfoDetail->Add(m_staticTextBirth, 1, wxALL, 5);

	m_textCtrlBirth = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlBirth->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlBirth->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlBirth->Enable(false);

	FlexGridSizer_IDInfoDetail->Add(m_textCtrlBirth, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	BoxSizer_IDInfoTop->Add(FlexGridSizer_IDInfoDetail, 1, wxEXPAND | wxSHAPED, 5);


	BoxSizer_IDInfoMain->Add(BoxSizer_IDInfoTop, 1, wxEXPAND, 5);


	fgSizer3->Add(BoxSizer_IDInfoMain, 1, wxEXPAND, 5);

	wxGridSizer* GridSizer_IDImage;
	GridSizer_IDImage = new wxGridSizer(1, 1, 0, 0);

	StaticBitmap_IDImage = new wxStaticBitmap(m_panelMiddleTop, wxID_ANY, wxBitmap(wxT("resource/identify.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(-1, -1), 0);
	GridSizer_IDImage->Add(StaticBitmap_IDImage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);


	fgSizer3->Add(GridSizer_IDImage, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer18->Add(fgSizer3, 1, wxEXPAND, 5);

	wxFlexGridSizer* fgSizer31;
	fgSizer31 = new wxFlexGridSizer(2, 2, 0, 0);
	fgSizer31->AddGrowableCol(1);
	fgSizer31->AddGrowableRow(1);
	fgSizer31->SetFlexibleDirection(wxBOTH);
	fgSizer31->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	m_staticTextIDNumber = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("身份证号："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextIDNumber->Wrap(-1);
	m_staticTextIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextIDNumber->SetForegroundColour(wxColour(33, 33, 33));

	fgSizer31->Add(m_staticTextIDNumber, 1, wxALL, 5);

	m_textCtrlIDNumber = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
	m_textCtrlIDNumber->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlIDNumber->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlIDNumber->Enable(false);

	fgSizer31->Add(m_textCtrlIDNumber, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);

	m_staticTextAddr = new wxStaticText(m_panelMiddleTop, wxID_ANY, wxT("地址："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAddr->Wrap(-1);
	m_staticTextAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_staticTextAddr->SetForegroundColour(wxColour(33, 33, 33));

	fgSizer31->Add(m_staticTextAddr, 1, wxALL, 5);

	m_textCtrlAddr = new wxTextCtrl(m_panelMiddleTop, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CHARWRAP | wxTE_READONLY);
	m_textCtrlAddr->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Microsoft YaHei UI")));
	m_textCtrlAddr->SetForegroundColour(wxColour(33, 33, 33));
	m_textCtrlAddr->Enable(false);

	fgSizer31->Add(m_textCtrlAddr, 1, wxEXPAND | wxTOP | wxBOTTOM, 5);


	bSizer18->Add(fgSizer31, 0, wxEXPAND, 5);


	bSizerIdentifyTop->Add(bSizer18, 1, wxEXPAND, 5);


	bSizerIdentify->Add(bSizerIdentifyTop, 1, wxEXPAND, 5);


	BoxSizer_PanelTop->Add(bSizerIdentify, 1, wxEXPAND, 5);


	m_panelMiddleTop->SetSizer(BoxSizer_PanelTop);
	m_panelMiddleTop->Layout();
	BoxSizer_PanelTop->Fit(m_panelMiddleTop);
	bSizerMiddle->Add(m_panelMiddleTop, 1, wxEXPAND | wxALL, 5);

	m_panelMiddleButtom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* bSizerProgress;
	bSizerProgress = new wxBoxSizer(wxVERTICAL);

	m_staticTextProgress = new wxStaticText(m_panelMiddleButtom, wxID_ANY, wxT("Loading"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
	m_staticTextProgress->Wrap(-1);
	m_staticTextProgress->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("宋体")));
	m_staticTextProgress->SetForegroundColour(wxColour(0, 45, 135));

	bSizerProgress->Add(m_staticTextProgress, 1, wxALIGN_RIGHT | wxEXPAND | wxALL, 5);

	m_gaugeProgress = new wxGauge(m_panelMiddleButtom, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	m_gaugeProgress->SetValue(0);
	m_gaugeProgress->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	bSizerProgress->Add(m_gaugeProgress, 1, wxALL | wxEXPAND, 5);


	m_panelMiddleButtom->SetSizer(bSizerProgress);
	m_panelMiddleButtom->Layout();
	bSizerProgress->Fit(m_panelMiddleButtom);
	bSizerMiddle->Add(m_panelMiddleButtom, 0, wxALL | wxEXPAND, 5);


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
}

SigninFrame::~SigninFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Disconnect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(SigninFrame::OnEraseBackground));
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(SigninFrame::OnPaint));

}
