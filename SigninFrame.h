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
	wxStaticText* m_staticTextCemra;
	wxPanel* m_panelCamera;
	wxBoxSizer* bSizer_Camera;
	wxStaticText* m_staticTextIdentify;
	wxStaticText* m_staticTextStep;
	wxStaticText* m_staticTextName;
	wxStaticText* m_staticTextGender;
	wxStaticText* m_staticTextBirth;
	wxStaticText* m_Name;
	wxStaticText* m_Gender;
	wxStaticText* m_Birth;
	wxStaticBitmap* StaticBitmap_IDImage;
	wxStaticText* m_staticTextIDNumber;
	wxStaticText* m_staticTextAddr;
	wxStaticText* m_IDNumber;
	wxStaticText* m_Addr;
	wxStaticText* m_staticTextProgress;
	wxGauge* m_gaugeProgress;
	wxBoxSizer* bSizerButtom;

	// Virtual event handlers, overide them in your derived class
	virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
	virtual void OnEraseBackground(wxEraseEvent& event) { event.Skip(); }
	virtual void OnPaint(wxPaintEvent& event) { event.Skip(); }
	virtual void OnEraseBackgroundPanel(wxEraseEvent& event) { event.Skip(); }
	virtual void OnPaintPanel(wxPaintEvent& event) { event.Skip(); }
	virtual void OnPaintStaticText(wxPaintEvent& event) { event.Skip(); }


public:

	SigninFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Õ¢»ú×¢²áÏµÍ³"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = 0 | wxSIMPLE_BORDER | wxSTATIC_BORDER);

	~SigninFrame();

};

#endif //__SIGNINFRAME_H__
