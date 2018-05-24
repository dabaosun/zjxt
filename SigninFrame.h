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
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
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
	wxStatusBar* m_statusBar;
	wxMenuBar* m_menubar;
	wxMenu* m_menu1;

	// Virtual event handlers, overide them in your derived class
	virtual void OnClose(wxCloseEvent& event) { event.Skip(); }
	virtual void OnMenuSelectionCamera(wxCommandEvent& event) { event.Skip(); }
	virtual void OnMenuSelectionExit(wxCommandEvent& event) { event.Skip(); }


public:

	SigninFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Õ¢»ú×¢²áÏµÍ³"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1218, 768), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~SigninFrame();

};

#endif //__SIGNINFRAME_H__
