/***************************************************************
 * Name:      SigninApp.h
 * Purpose:   Defines Application Class
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef SIGNINAPP_H
#define SIGNINAPP_H

#include <wx/app.h>
#include <wx/snglinst.h>

class SigninApp : public wxApp
{
	private:
		wxSingleInstanceChecker * m_checker;
    public:
        virtual bool OnInit();
};

#endif // SIGNINAPP_H
