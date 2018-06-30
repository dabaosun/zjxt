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
	wxBoxSizer * bSizerTop;
	wxBoxSizer* bSizerLogo;
	wxPanel* m_panelMiddleTop;
	wxStaticText* m_staticTextCemra;
	wxPanel* m_panelCamera;
	wxBoxSizer* bSizer_Camera;
	wxStaticText* m_staticTextIdentify;
	wxStaticText* m_staticTextName;
	wxTextCtrl* m_textCtrlName;
	wxStaticText* m_staticTextGender;
	wxRadioButton* m_radioBtnMale;
	wxRadioButton* m_radioBtnFemale;
	wxStaticText* m_staticTextBirth;
	wxTextCtrl* m_textCtrlBirth;
	wxStaticBitmap* StaticBitmap_IDImage;
	wxStaticText* m_staticTextIDNumber;
	wxTextCtrl* m_textCtrlIDNumber;
	wxStaticText* m_staticTextAddr;
	wxTextCtrl* m_textCtrlAddr;
	wxPanel* m_panelMiddleButtom;
	wxStaticText* m_staticTextProgress;
	wxGauge* m_gaugeProgress;
	wxBoxSizer* bSizerButtom;

	// Virtual event handlers, overide them in your derived class
	virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
	virtual void OnEraseBackground(wxEraseEvent& event) { event.Skip(); }
	virtual void OnPaint(wxPaintEvent& event) { event.Skip(); }


public:

	SigninFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Õ¢»ú×¢²áÏµÍ³"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxCAPTION | wxCLOSE_BOX | wxSIMPLE_BORDER | wxSTATIC_BORDER | wxTAB_TRAVERSAL | wxTRANSPARENT_WINDOW);

	~SigninFrame();

};

#endif //__SIGNINFRAME_H__
