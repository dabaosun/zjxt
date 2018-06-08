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
	//(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
		SigninMain* Frame = new SigninMain(0);
    	Frame->Show();
    	//Frame->ShowFullScreen(true);
    	SetTopWindow(Frame);
    }
    //*)	
    return wxsOK;

}
