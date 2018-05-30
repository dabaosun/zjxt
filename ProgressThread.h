#ifndef __PROGRESSHTREAD_H__
#define __PROGRESSHTREAD_H__

#include <wx/thread.h>
#include "SigninMain.h"

class ProgressThread : public wxThread
{
public:
	ProgressThread(SigninMain *frame);
	virtual ~ProgressThread();

	// thread execution starts here
	virtual void *Entry();


	// called when the thread exits - whether it terminates normally or is
	// stopped with Delete() (but not when it is Kill()ed!)
	virtual void OnExit();

public:
	SigninMain *m_frame;
	unsigned m_count;
};

#endif //__PROGRESSHTREAD_H__