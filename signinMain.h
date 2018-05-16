/***************************************************************
 * Name:      SigninMain.h
 * Purpose:   Defines Application Frame
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef SIGNINMAIN_H
#define SIGNINMAIN_H

#include "camera/CameraView.h"

//(*Headers(SigninFrame)
#include <wx/frame.h>
class wxBoxSizer;
class wxButton;
class wxFlexGridSizer;
class wxGridSizer;
class wxMenu;
class wxMenuBar;
class wxPanel;
class wxRadioButton;
class wxStaticBitmap;
class wxStaticBoxSizer;
class wxStaticText;
class wxStatusBar;
class wxTextCtrl;
//*)
#define ID_CAMERA_CONNECT 101
#define ID_VIEW 102
class SigninFrame: public wxFrame
{
    public:
        CameraView* m_view;
        void OnConnect(wxCommandEvent &event);
        void OnQuit(wxCommandEvent &event);
        void OnClose(wxCloseEvent &event);
        SigninFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SigninFrame();

    private:

        //(*Handlers(SigninFrame)
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(SigninFrame)
        static const long ID_STATICTEXT_NAME;
        static const long ID_TEXTCTRL_NAME;
        static const long ID_STATICTEXT_GENDER;
        static const long ID_RADIOBUTTON_MALE;
        static const long ID_RADIOBUTTON_FEMALE;
        static const long ID_STATICTEXT_BIRTH;
        static const long ID_TEXTCTRL_BIRTH;
        static const long ID_STATICTEXT_IDNUMBER;
        static const long ID_TEXTCTRL_IDNUMBER;
        static const long ID_STATICTEXT_ADDRESS;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICBITMAP7;
        static const long ID_PANEL_TOP;
        static const long ID_BUTTON_CHECK;
        static const long ID_PANEL_Buttom;
        static const long idMenuConnect;
        static const long idMenuExit;
        //*)

        //(*Declarations(SigninFrame)
        wxButton* Button_Check;
        wxMenuItem* MenuItem3;
        wxPanel* PanelTop;
        wxPanel* Panel_Buttom;
        wxRadioButton* RadioButton_Female;
        wxRadioButton* RadioButton_Male;
        wxStaticBitmap* StaticBitmap_IDImage;
        wxStaticBoxSizer* StaticBoxSizer_Identify;
        wxStaticText* StaticText_Address;
        wxStaticText* StaticText_Birth;
        wxStaticText* StaticText_Gender;
        wxStaticText* StaticText_IDNumber;
        wxStaticText* StaticText_Name;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl_Birth;
        wxTextCtrl* TextCtrl_IDNumber;
        wxTextCtrl* TextCtrl_Name;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SIGNINMAIN_H
