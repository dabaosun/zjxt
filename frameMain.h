/***************************************************************
 * Name:      frameMain.h
 * Purpose:   Defines Application Frame
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef FRAMEMAIN_H
#define FRAMEMAIN_H

//(*Headers(frameFrame)
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

class frameFrame: public wxFrame
{
    public:

        frameFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~frameFrame();

    private:

        //(*Handlers(frameFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(frameFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICBITMAP4;
        static const long ID_STATICBITMAP5;
        static const long ID_STATICBITMAP6;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICBITMAP7;
        static const long ID_PANEL1;
        static const long ID_BUTTON1;
        static const long ID_PANEL2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)

        //(*Declarations(frameFrame)
        wxButton* Button1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxRadioButton* RadioButton1;
        wxRadioButton* RadioButton2;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxStaticBitmap* StaticBitmap5;
        wxStaticBitmap* StaticBitmap6;
        wxStaticBitmap* StaticBitmap7;
        wxStaticBoxSizer* StaticBoxSizer2;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FRAMEMAIN_H
