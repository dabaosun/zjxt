/***************************************************************
 * Name:      frameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Created:   2018-04-19
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "frameApp.h"

//(*AppHeaders
#include "frameMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(frameApp);

bool frameApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	frameFrame* Frame = new frameFrame(0);
    	//Frame->Show();
    	Frame->ShowFullScreen(true);

    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
