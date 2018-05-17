/***************************************************************
 * Name:      SigninMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "SigninMain.h"
#include <wx/msgdlg.h>
#include <opencv2/opencv.hpp>
#include <wx/wx.h>
#include <opencv2/opencv.hpp>
//#include "util.h"
#include <string>

#include <wx/wx.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


//(*InternalHeaders(SigninFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/string.h>
#include <wx/textctrl.h>
//*)

using namespace cv;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SigninFrame)
const long SigninFrame::ID_STATICTEXT_NAME = wxNewId();
const long SigninFrame::ID_TEXTCTRL_NAME = wxNewId();
const long SigninFrame::ID_STATICTEXT_GENDER = wxNewId();
const long SigninFrame::ID_RADIOBUTTON_MALE = wxNewId();
const long SigninFrame::ID_RADIOBUTTON_FEMALE = wxNewId();
const long SigninFrame::ID_STATICTEXT_BIRTH = wxNewId();
const long SigninFrame::ID_TEXTCTRL_BIRTH = wxNewId();
const long SigninFrame::ID_STATICTEXT_IDNUMBER = wxNewId();
const long SigninFrame::ID_TEXTCTRL_IDNUMBER = wxNewId();
const long SigninFrame::ID_STATICTEXT_ADDRESS = wxNewId();
const long SigninFrame::ID_TEXTCTRL5 = wxNewId();
const long SigninFrame::ID_STATICBITMAP7 = wxNewId();
const long SigninFrame::ID_PANEL_TOP = wxNewId();
const long SigninFrame::ID_BUTTON_CHECK = wxNewId();
const long SigninFrame::ID_PANEL_Buttom = wxNewId();
const long SigninFrame::idMenuConnect = wxNewId();
const long SigninFrame::idMenuExit = wxNewId();
//*)

BEGIN_EVENT_TABLE(SigninFrame,wxFrame)
    //(*EventTable(SigninFrame)
    //*)
END_EVENT_TABLE()

wxImage wx_from_mat(Mat &img) {
    Mat im2;
    if(img.channels()==1){cvtColor(img,im2,CV_GRAY2RGB);}
	else if (img.channels() == 4) { cvtColor(img, im2, CV_BGRA2RGB);}
    else {cvtColor(img,im2,CV_BGR2RGB);}
	long imsize = im2.rows*im2.cols*im2.channels();
    wxImage wx(im2.cols, im2.rows,(unsigned char*)malloc(imsize), false);
	unsigned char* s=im2.data;
	unsigned char* d=wx.GetData();
	for (long i = 0; i < imsize; i++) { d[i] = s[i];}
    return wx;
}

SigninFrame::SigninFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SigninFrame)
    wxBoxSizer* BoxSizer_Buttom;
    wxBoxSizer* BoxSizer_Button;
    wxBoxSizer* BoxSizer_Gender;
    wxBoxSizer* BoxSizer_IDInfoMain;
    wxBoxSizer* BoxSizer_IDInfoTop;
    wxBoxSizer* BoxSizer_Main;
    wxBoxSizer* BoxSizer_Top;
    wxFlexGridSizer* FlexGridSizer_IDInfoButtom;
    wxFlexGridSizer* FlexGridSizer_IDInfoDetail;
    wxGridSizer* GridSizer_IDImage;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxStaticBoxSizer* StaticBoxSizer_Camera;
    wxStatusBar* StatusBar1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxFULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
    SetClientSize(wxSize(1156,544));
    SetMinSize(wxSize(-1,-1));
    BoxSizer_Main = new wxBoxSizer(wxVERTICAL);
    PanelTop = new wxPanel(this, ID_PANEL_TOP, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_TOP"));
    BoxSizer_Top = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer_Camera = new wxStaticBoxSizer(wxHORIZONTAL, PanelTop, _T("照片录入"));
    BoxSizer_Top->Add(StaticBoxSizer_Camera, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    StaticBoxSizer_Identify = new wxStaticBoxSizer(wxHORIZONTAL, PanelTop, _T("身份证信息"));
    BoxSizer_IDInfoMain = new wxBoxSizer(wxVERTICAL);
    BoxSizer_IDInfoTop = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer_IDInfoDetail = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer_IDInfoDetail->AddGrowableCol(1);
    FlexGridSizer_IDInfoDetail->AddGrowableRow(4);
    StaticText_Name = new wxStaticText(PanelTop, ID_STATICTEXT_NAME, _T("姓名："), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER, _T("ID_STATICTEXT_NAME"));
    FlexGridSizer_IDInfoDetail->Add(StaticText_Name, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Name = new wxTextCtrl(PanelTop, ID_TEXTCTRL_NAME, wxEmptyString, wxDefaultPosition, wxSize(190,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL_NAME"));
    FlexGridSizer_IDInfoDetail->Add(TextCtrl_Name, 1, wxALL|wxEXPAND, 5);
    StaticText_Gender = new wxStaticText(PanelTop, ID_STATICTEXT_GENDER, _T("性别："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_GENDER"));
    FlexGridSizer_IDInfoDetail->Add(StaticText_Gender, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer_Gender = new wxBoxSizer(wxHORIZONTAL);
    RadioButton_Male = new wxRadioButton(PanelTop, ID_RADIOBUTTON_MALE, _T("男"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_MALE"));
    BoxSizer_Gender->Add(RadioButton_Male, 1, wxALL|wxEXPAND, 5);
    RadioButton_Female = new wxRadioButton(PanelTop, ID_RADIOBUTTON_FEMALE, _T("女"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_FEMALE"));
    BoxSizer_Gender->Add(RadioButton_Female, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer_IDInfoDetail->Add(BoxSizer_Gender, 1, wxALL|wxEXPAND, 0);
    StaticText_Birth = new wxStaticText(PanelTop, ID_STATICTEXT_BIRTH, _T("出生日期："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_BIRTH"));
    FlexGridSizer_IDInfoDetail->Add(StaticText_Birth, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Birth = new wxTextCtrl(PanelTop, ID_TEXTCTRL_BIRTH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_BIRTH"));
    FlexGridSizer_IDInfoDetail->Add(TextCtrl_Birth, 1, wxALL|wxEXPAND, 5);
    StaticText_IDNumber = new wxStaticText(PanelTop, ID_STATICTEXT_IDNUMBER, _T("身份证号："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_IDNUMBER"));
    FlexGridSizer_IDInfoDetail->Add(StaticText_IDNumber, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    TextCtrl_IDNumber = new wxTextCtrl(PanelTop, ID_TEXTCTRL_IDNUMBER, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL_IDNUMBER"));
    FlexGridSizer_IDInfoDetail->Add(TextCtrl_IDNumber, 1, wxALL|wxEXPAND, 5);
    StaticText_Address = new wxStaticText(PanelTop, ID_STATICTEXT_ADDRESS, _T("地址："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_ADDRESS"));
    FlexGridSizer_IDInfoDetail->Add(StaticText_Address, 1, wxALL|wxEXPAND, 5);
    TextCtrl5 = new wxTextCtrl(PanelTop, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(199,125), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->SetMaxSize(wxSize(-1,200));
    FlexGridSizer_IDInfoDetail->Add(TextCtrl5, 1, wxALL|wxEXPAND, 5);
    BoxSizer_IDInfoTop->Add(FlexGridSizer_IDInfoDetail, 1, wxALL|wxEXPAND|wxSHAPED, 0);
    BoxSizer_IDInfoMain->Add(BoxSizer_IDInfoTop, 1, wxALL|wxEXPAND, 0);
    FlexGridSizer_IDInfoButtom = new wxFlexGridSizer(3, 2, 0, 0);
    FlexGridSizer_IDInfoButtom->AddGrowableCol(1);
    FlexGridSizer_IDInfoButtom->AddGrowableRow(2);
    BoxSizer_IDInfoMain->Add(FlexGridSizer_IDInfoButtom, 0, wxALL|wxEXPAND, 0);
    StaticBoxSizer_Identify->Add(BoxSizer_IDInfoMain, 1, wxALL|wxEXPAND, 0);
    GridSizer_IDImage = new wxGridSizer(1, 1, 0, 0);
    StaticBitmap_IDImage = new wxStaticBitmap(PanelTop, ID_STATICBITMAP7, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP7"));
    GridSizer_IDImage->Add(StaticBitmap_IDImage, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer_Identify->Add(GridSizer_IDImage, 1, wxALL|wxEXPAND, 0);
    BoxSizer_Top->Add(StaticBoxSizer_Identify, 1, wxALL|wxEXPAND, 5);
    PanelTop->SetSizer(BoxSizer_Top);
    BoxSizer_Top->Fit(PanelTop);
    BoxSizer_Top->SetSizeHints(PanelTop);
    BoxSizer_Main->Add(PanelTop, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
    BoxSizer_Buttom = new wxBoxSizer(wxVERTICAL);
    Panel_Buttom = new wxPanel(this, ID_PANEL_Buttom, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_Buttom"));
    BoxSizer_Button = new wxBoxSizer(wxHORIZONTAL);
    Button_Check = new wxButton(Panel_Buttom, ID_BUTTON_CHECK, _T("验证"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CHECK"));
    BoxSizer_Button->Add(Button_Check, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_Buttom->SetSizer(BoxSizer_Button);
    BoxSizer_Button->Fit(Panel_Buttom);
    BoxSizer_Button->SetSizeHints(Panel_Buttom);
    BoxSizer_Buttom->Add(Panel_Buttom, 1, wxALL|wxEXPAND, 0);
    BoxSizer_Main->Add(BoxSizer_Buttom, 0, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer_Main);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuConnect, _T("Connect"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuExit, _T("Exit\tAlt-F4"), _T("Exit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _T("&File"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, wxID_ANY, 0, _T("wxID_ANY"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer_Main);
    Layout();
    Center();

    Connect(idMenuExit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SigninFrame::OnQuit);
    //*)
    Connect(idMenuConnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SigninFrame::OnConnect);
    Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SigninFrame::OnClose));

    m_CameraView = new CameraView(this,ID_VIEW);
    m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
    StaticBoxSizer_Camera->Add(m_CameraView, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);

    Layout();
    Center();

    /*
     //From opencv to wx
     Mat imcv1 = imread("D:/1.jpg",IMREAD_UNCHANGED);
     Size dsize =Size(300,300);
     resize(imcv1,imcv1,dsize);
     //cv.resize(imcv1,imcv1,dsize);
     //string str = "Channels:";// + to_string(imcv1.channels());
     //putText(imcv1, str, Point(100, 100), FONT_HERSHEY_PLAIN, 4.0, CV_RGB(128, 0, 128), 4.0);
     wxBitmap imwx1 = wx_from_mat(imcv1);
     StaticBitmap1->SetBitmap(imwx1);
    */
}

SigninFrame::~SigninFrame()
{
    //(*Destroy(SigninFrame)
    //*)
}

void SigninFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SigninFrame::OnConnect(wxCommandEvent &event)
{
    if (m_CameraView->m_is_display)
    {
        m_CameraView->Stop();
    }
    else
    {
        m_CameraView->Start();
    }

}

void SigninFrame::OnQuit(wxCommandEvent &event)
{
    Close(true);
}

void SigninFrame::OnClose(wxCloseEvent &event)
{
    m_CameraView->Stop();
    Destroy();
}
