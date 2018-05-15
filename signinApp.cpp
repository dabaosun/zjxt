/***************************************************************
 * Name:      signinApp.cpp
 * Purpose:   Code for Application Class
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "signinApp.h"

//(*AppHeaders
#include "signinMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(signinApp);

bool signinApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	signinFrame* Frame = new signinFrame(0);
    	//Frame->Show();
    	Frame->ShowFullScreen(true);

    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
