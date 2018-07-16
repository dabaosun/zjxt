///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 13 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SIGNINFRAME_H__
#define __SIGNINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gauge.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SigninFrame
///////////////////////////////////////////////////////////////////////////////
class SigninFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel4;
		wxBoxSizer* bSizerTop;
		wxBoxSizer* bSizerLogo;
		wxPanel* m_panel5;
		wxPanel* m_panelMiddleTop;
		wxStaticText* m_staticTextCemra;
		wxPanel* m_panelCamera;
		wxBoxSizer* bSizer_Camera;
		wxStaticText* m_staticTextIdentify;
		wxStaticText* m_staticTextStep;
		wxStaticText* m_staticTextName;
		wxStaticText* m_staticTextGender;
		wxStaticText* m_staticTextBirth;
		wxTextCtrl* m_textCtrlName;
		wxRadioButton* m_radioBtnMale;
		wxRadioButton* m_radioBtnFemale;
		wxTextCtrl* m_textCtrlBirth;
		wxStaticBitmap* StaticBitmap_IDImage;
		wxStaticText* m_staticTextIDNumber;
		wxStaticText* m_staticTextAddr;
		wxTextCtrl* m_textCtrlIDNumber;
		wxTextCtrl* m_textCtrlAddr;
		wxPanel* m_panelMiddleButtom;
		wxStaticText* m_staticTextProgress;
		wxGauge* m_gaugeProgress;
		wxBoxSizer* bSizerButtom;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnEraseBackground( wxEraseEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnEraseBackgroundPanel( wxEraseEvent& event ) { event.Skip(); }
		virtual void OnPaintPanel( wxPaintEvent& event ) { event.Skip(); }
		
	
	public:
		
		SigninFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("闸机注册系统"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = 0|wxBORDER_SIMPLE|wxBORDER_STATIC );
		
		~SigninFrame();
	
};

#endif //__SIGNINFRAME_H__
