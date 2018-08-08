///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 23 2018)
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
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
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
	wxPanel * m_panel4;
	wxBoxSizer* bSizerTop;
	wxBoxSizer* bSizer16;
	wxStaticText* m_staticTextCemra;
	wxPanel* m_panelCamera;
	wxBoxSizer* bSizer_Camera;
	wxBoxSizer* bSizer40;
	wxStaticText* m_staticTextIdentify;
	wxBoxSizer* bSizer41;
	wxStaticText* m_staticTextStep;
	wxBoxSizer* bSizer191;
	wxStaticText* m_staticTextName;
	wxBoxSizer* bSizer20;
	wxStaticText* m_staticTextGender;
	wxBoxSizer* bSizer21;
	wxStaticText* m_staticTextBirth;
	wxBoxSizer* bSizer30;
	wxBoxSizer* bSizer24;
	wxStaticText* m_Name;
	wxBoxSizer* BoxSizer_Gender;
	wxStaticText* m_Gender;
	wxBoxSizer* bSizer25;
	wxStaticText* m_Birth;
	wxStaticBitmap* StaticBitmap_IDImage;
	wxBoxSizer* bSizer33;
	wxStaticText* m_staticTextIDNumber;
	wxBoxSizer* bSizer34;
	wxStaticText* m_staticTextAddr;
	wxBoxSizer* bSizer27;
	wxStaticText* m_IDNumber;
	wxBoxSizer* bSizer29;
	wxStaticText* m_Addr;
	wxBoxSizer* bSizer42;
	wxStaticText* m_staticTextProgress;
	wxGauge* m_gaugeProgress;
	wxBoxSizer* bSizerButtom;

	// Virtual event handlers, overide them in your derived class
	virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
	virtual void OnEraseBackgroundPanel(wxEraseEvent& event) { event.Skip(); }


public:

	SigninFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Õ¢»ú×¢²áÏµÍ³"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = 0 | wxSIMPLE_BORDER | wxSTATIC_BORDER);

	virtual ~SigninFrame();

};

#endif //__SIGNINFRAME_H__
