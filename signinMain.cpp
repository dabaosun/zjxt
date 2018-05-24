#include "SigninMain.h"

SigninMain::SigninMain( wxWindow* parent )
:
SigninFrame( parent )
{
	m_CameraView = new CameraView(this, wxID_ANY);
	m_CameraView->SetBackgroundColour(wxColour(wxT("#000000")));
	this->StaticBoxSizer_Camera->Add(m_CameraView, 1, wxALL | wxEXPAND | wxFIXED_MINSIZE, 0);

	this->Layout();
	this->Centre(wxBOTH);
}

void SigninMain::OnClose( wxCloseEvent& event )
{
// TODO: Implement OnClose
	m_CameraView->Stop();
	Destroy();

}

void SigninMain::OnMenuSelectionCamera( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelectionCamera
	if (m_CameraView->m_is_display)
	{
		m_CameraView->Stop();
	}
	else
	{
		m_CameraView->Start();
		Layout();
	}
}

void SigninMain::OnMenuSelectionExit( wxCommandEvent& event )
{
// TODO: Implement OnMenuSelectionExit
	Close(true);
}
