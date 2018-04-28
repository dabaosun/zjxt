/***************************************************************
 * Name:      frameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "frameMain.h"
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


//(*InternalHeaders(frameFrame)
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

//(*IdInit(frameFrame)
const long frameFrame::ID_STATICBITMAP1 = wxNewId();
const long frameFrame::ID_STATICBITMAP2 = wxNewId();
const long frameFrame::ID_STATICBITMAP3 = wxNewId();
const long frameFrame::ID_STATICBITMAP4 = wxNewId();
const long frameFrame::ID_STATICBITMAP5 = wxNewId();
const long frameFrame::ID_STATICBITMAP6 = wxNewId();
const long frameFrame::ID_STATICTEXT2 = wxNewId();
const long frameFrame::ID_TEXTCTRL2 = wxNewId();
const long frameFrame::ID_STATICTEXT3 = wxNewId();
const long frameFrame::ID_RADIOBUTTON1 = wxNewId();
const long frameFrame::ID_RADIOBUTTON2 = wxNewId();
const long frameFrame::ID_STATICTEXT4 = wxNewId();
const long frameFrame::ID_TEXTCTRL3 = wxNewId();
const long frameFrame::ID_STATICTEXT5 = wxNewId();
const long frameFrame::ID_TEXTCTRL4 = wxNewId();
const long frameFrame::ID_STATICTEXT6 = wxNewId();
const long frameFrame::ID_TEXTCTRL5 = wxNewId();
const long frameFrame::ID_STATICBITMAP7 = wxNewId();
const long frameFrame::ID_PANEL1 = wxNewId();
const long frameFrame::ID_BUTTON1 = wxNewId();
const long frameFrame::ID_PANEL2 = wxNewId();
const long frameFrame::idMenuQuit = wxNewId();
const long frameFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(frameFrame,wxFrame)
    //(*EventTable(frameFrame)
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

frameFrame::frameFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(frameFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStatusBar* StatusBar1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxFULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
    SetClientSize(wxSize(1156,544));
    SetMinSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _T("照片录入"));
    GridSizer1 = new wxGridSizer(0, 3, 0, 0);
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticBitmap1->SetMaxSize(wxSize(300,200));
    GridSizer1->Add(StaticBitmap1, 1, wxALL|wxEXPAND, 5);
    StaticBitmap2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
    GridSizer1->Add(StaticBitmap2, 1, wxALL|wxEXPAND, 5);
    StaticBitmap3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxNullBitmap, wxDefaultPosition, wxSize(138,206), wxSIMPLE_BORDER, _T("ID_STATICBITMAP3"));
    GridSizer1->Add(StaticBitmap3, 1, wxALL|wxEXPAND, 5);
    StaticBitmap4 = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP4"));
    GridSizer1->Add(StaticBitmap4, 1, wxALL|wxEXPAND, 5);
    StaticBitmap5 = new wxStaticBitmap(Panel1, ID_STATICBITMAP5, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP5"));
    GridSizer1->Add(StaticBitmap5, 1, wxALL|wxEXPAND, 5);
    StaticBitmap6 = new wxStaticBitmap(Panel1, ID_STATICBITMAP6, wxNullBitmap, wxDefaultPosition, wxSize(172,138), wxSIMPLE_BORDER, _T("ID_STATICBITMAP6"));
    GridSizer1->Add(StaticBitmap6, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 0);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _T("身份证信息"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer1 = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableRow(4);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _T("姓名："), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxNO_BORDER, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(190,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _T("性别："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _T("男"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    BoxSizer6->Add(RadioButton1, 1, wxALL|wxEXPAND, 5);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _T("女"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    BoxSizer6->Add(RadioButton2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(BoxSizer6, 1, wxALL|wxEXPAND, 0);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _T("出生日期："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxEXPAND, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _T("身份证号："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer1->Add(TextCtrl4, 1, wxALL|wxEXPAND, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _T("地址："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(StaticText6, 1, wxALL|wxEXPAND, 5);
    TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(199,125), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl5->SetMaxSize(wxSize(-1,200));
    FlexGridSizer1->Add(TextCtrl5, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxSHAPED, 0);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 0);
    FlexGridSizer2 = new wxFlexGridSizer(3, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    FlexGridSizer2->AddGrowableRow(2);
    BoxSizer3->Add(FlexGridSizer2, 0, wxALL|wxEXPAND, 0);
    StaticBoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
    GridSizer2 = new wxGridSizer(1, 1, 0, 0);
    StaticBitmap7 = new wxStaticBitmap(Panel1, ID_STATICBITMAP7, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP7"));
    GridSizer2->Add(StaticBitmap7, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2->Add(GridSizer2, 1, wxALL|wxEXPAND, 0);
    BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 0);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel2, ID_BUTTON1, _T("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer7->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer7);
    BoxSizer7->Fit(Panel2);
    BoxSizer7->SetSizeHints(Panel2);
    BoxSizer4->Add(Panel2, 1, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _T("Quit\tAlt-F4"), _T("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _T("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _T("About\tF1"), _T("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem2->Enable(false);
    MenuBar1->Append(Menu2, _T("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, wxID_ANY, 0, _T("wxID_ANY"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&frameFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&frameFrame::OnAbout);
    //*)

     //From opencv to wx
     Mat imcv1 = imread("D:/1.jpg",IMREAD_UNCHANGED);
     Size dsize =Size(300,300);
     resize(imcv1,imcv1,dsize);
     //cv.resize(imcv1,imcv1,dsize);
     //string str = "Channels:";// + to_string(imcv1.channels());
     //putText(imcv1, str, Point(100, 100), FONT_HERSHEY_PLAIN, 4.0, CV_RGB(128, 0, 128), 4.0);
     wxBitmap imwx1 = wx_from_mat(imcv1);
     StaticBitmap1->SetBitmap(imwx1);
}

frameFrame::~frameFrame()
{
    //(*Destroy(frameFrame)
    //*)
}

void frameFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void frameFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void frameFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}
