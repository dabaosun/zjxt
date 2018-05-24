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
	this->SetSizeHints(wxSize(1024, 768), wxDefaultSize);

	wxBoxSizer* BoxSizer_Main;
	BoxSizer_Main = new wxBoxSizer(wxVERTICAL);

	m_panelTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* BoxSizer_Top;
	BoxSizer_Top = new wxBoxSizer(wxHORIZONTAL);

	StaticBoxSizer_Camera = new wxStaticBoxSizer(new wxStaticBox(m_panelTop, wxID_ANY, wxT("实时图像区")), wxVERTICAL);

	StaticBoxSizer_Camera->SetMinSize(wxSize(640, 480));

	BoxSizer_Top->Add(StaticBoxSizer_Camera, 1, wxEXPAND, 5);

	wxStaticBoxSizer* StaticBoxSizer_Identify;
	StaticBoxSizer_Identify = new wxStaticBoxSizer(new wxStaticBox(m_panelTop, wxID_ANY, wxT("身份证信息区")), wxHORIZONTAL);

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
	FlexGridSizer_IDInfoDetail->Add(m_staticTextName, 0, wxALL, 5);

	m_textCtrlName = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	FlexGridSizer_IDInfoDetail->Add(m_textCtrlName, 0, wxALL | wxEXPAND, 5);

	m_staticTextGender = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("性别："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextGender->Wrap(-1);
	FlexGridSizer_IDInfoDetail->Add(m_staticTextGender, 0, wxALL, 5);

	wxBoxSizer* BoxSizer_Gender;
	BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);

	m_radioBtnMale = new wxRadioButton(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("男"), wxDefaultPosition, wxDefaultSize, 0);
	BoxSizer_Gender->Add(m_radioBtnMale, 0, wxALL | wxEXPAND, 5);

	m_radioBtnFemale = new wxRadioButton(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("女"), wxDefaultPosition, wxDefaultSize, 0);
	BoxSizer_Gender->Add(m_radioBtnFemale, 0, wxALL | wxEXPAND, 5);


	FlexGridSizer_IDInfoDetail->Add(BoxSizer_Gender, 1, wxEXPAND, 5);

	m_staticTextBirth = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("出生日期："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextBirth->Wrap(-1);
	FlexGridSizer_IDInfoDetail->Add(m_staticTextBirth, 0, wxALL, 5);

	m_textCtrlBirth = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	FlexGridSizer_IDInfoDetail->Add(m_textCtrlBirth, 0, wxALL | wxEXPAND, 5);

	m_staticTextIDNumber = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("身份证号："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextIDNumber->Wrap(-1);
	FlexGridSizer_IDInfoDetail->Add(m_staticTextIDNumber, 0, wxALL, 5);

	m_textCtrlIDNumber = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	FlexGridSizer_IDInfoDetail->Add(m_textCtrlIDNumber, 0, wxALL | wxEXPAND, 5);

	m_staticTextAddr = new wxStaticText(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxT("地址："), wxDefaultPosition, wxDefaultSize, 0);
	m_staticTextAddr->Wrap(-1);
	FlexGridSizer_IDInfoDetail->Add(m_staticTextAddr, 0, wxALL, 5);

	m_textCtrlAddr = new wxTextCtrl(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	FlexGridSizer_IDInfoDetail->Add(m_textCtrlAddr, 0, wxALL | wxEXPAND, 5);


	BoxSizer_IDInfoTop->Add(FlexGridSizer_IDInfoDetail, 1, wxEXPAND | wxSHAPED, 5);


	BoxSizer_IDInfoMain->Add(BoxSizer_IDInfoTop, 1, wxEXPAND, 5);

	wxFlexGridSizer* FlexGridSizer_IDInfoButtom;
	FlexGridSizer_IDInfoButtom = new wxFlexGridSizer(3, 2, 0, 0);
	FlexGridSizer_IDInfoButtom->AddGrowableCol(1);
	FlexGridSizer_IDInfoButtom->AddGrowableRow(2);
	FlexGridSizer_IDInfoButtom->SetFlexibleDirection(wxBOTH);
	FlexGridSizer_IDInfoButtom->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);


	BoxSizer_IDInfoMain->Add(FlexGridSizer_IDInfoButtom, 1, wxEXPAND, 5);


	StaticBoxSizer_Identify->Add(BoxSizer_IDInfoMain, 1, wxEXPAND, 5);

	wxGridSizer* GridSizer_IDImage;
	GridSizer_IDImage = new wxGridSizer(1, 1, 0, 0);

	StaticBitmap_IDImage = new wxStaticBitmap(StaticBoxSizer_Identify->GetStaticBox(), wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0);
	GridSizer_IDImage->Add(StaticBitmap_IDImage, 0, wxALL | wxEXPAND, 5);


	StaticBoxSizer_Identify->Add(GridSizer_IDImage, 1, wxEXPAND, 5);


	BoxSizer_Top->Add(StaticBoxSizer_Identify, 1, wxEXPAND, 5);


	m_panelTop->SetSizer(BoxSizer_Top);
	m_panelTop->Layout();
	BoxSizer_Top->Fit(m_panelTop);
	BoxSizer_Main->Add(m_panelTop, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(BoxSizer_Main);
	this->Layout();
	m_statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);
	m_menubar = new wxMenuBar(0);
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItemCamera;
	m_menuItemCamera = new wxMenuItem(m_menu1, wxID_ANY, wxString(wxT("摄像头On/Off")), wxEmptyString, wxITEM_NORMAL);
	m_menu1->Append(m_menuItemCamera);

	wxMenuItem* m_menuItemExit;
	m_menuItemExit = new wxMenuItem(m_menu1, wxID_ANY, wxString(wxT("退出")), wxEmptyString, wxITEM_NORMAL);
	m_menu1->Append(m_menuItemExit);

	m_menubar->Append(m_menu1, wxT("操作"));

	this->SetMenuBar(m_menubar);


	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Connect(m_menuItemCamera->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SigninFrame::OnMenuSelectionCamera));
	this->Connect(m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SigninFrame::OnMenuSelectionExit));
}

SigninFrame::~SigninFrame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));
	this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SigninFrame::OnMenuSelectionCamera));
	this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SigninFrame::OnMenuSelectionExit));

}
