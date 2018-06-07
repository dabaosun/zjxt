/***************************************************************
 * Name:      SigninApp.cpp
 * Purpose:   Code for Application Class
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "SigninApp.h"

//(*AppHeaders
#include "SigninMain.h"
#include <wx/image.h>
//*)
#include "./certcard/CertCard.h"
#include "./config/Config.h"

IMPLEMENT_APP(SigninApp);

bool SigninApp::OnInit()
{
	if (0 == Config::GetInstance()->LoadConfig()) {
		return false;
	}
	if (0 == CertCard::GetInstance()->OpenCertCardReader()) {
		return false;
	}
	SigninMain* Frame = NULL;
	//(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new SigninMain(0);
    	Frame->Show();
    	//Frame->ShowFullScreen(true);
    	SetTopWindow(Frame);
    }
    //*)

	CertCard::GetInstance()->RegisterListener(Frame);
	Frame->GetCameraView()->RegisterListener(CertCard::GetInstance());
	Frame->GetCameraView()->OpenCamera();
	
    return wxsOK;

}
