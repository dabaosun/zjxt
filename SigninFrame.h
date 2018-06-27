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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
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
	wxPanel * m_panelTop;
	wxPanel* m_panel4;
	wxStaticBitmap* m_bitmap2;
	wxStaticText* m_staticText8;
	wxStaticBoxSizer* StaticBoxSizer_Camera;
	wxStaticText* m_staticTextName;
	wxTextCtrl* m_textCtrlName;
	wxStaticText* m_staticTextGender;
	wxRadioButton* m_radioBtnMale;
	wxRadioButton* m_radioBtnFemale;
	wxStaticText* m_staticTextBirth;
	wxTextCtrl* m_textCtrlBirth;
	wxStaticText* m_staticTextIDNumber;
	wxTextCtrl* m_textCtrlIDNumber;
	wxStaticText* m_staticTextAddr;
	wxTextCtrl* m_textCtrlAddr;
	wxStaticBitmap* StaticBitmap_IDImage;
	wxStaticText* m_staticTextProgress;
	wxGauge* m_gaugeProgress;
	wxStaticText* m_staticText7;

	// Virtual event handlers, overide them in your derived class
	virtual void OnClose(wxCloseEvent& event) { event.Skip(); }


public:

	SigninFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("բ��ע��ϵͳ"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1920, 1080), long style = wxCAPTION | wxCLOSE_BOX | wxSIMPLE_BORDER | wxSTATIC_BORDER | wxTAB_TRAVERSAL);

	~SigninFrame();

};

#endif //__SIGNINFRAME_H__
