#ifndef __SigninMain__
#define __SigninMain__

/**
@file
Subclass of SigninFrame, which is generated by wxFormBuilder.
*/

#include "SigninFrame.h"
//// end generated include
#include <wx/progdlg.h>
#include "./camera/CameraView.h"
#include "./certcard/CertCardListener.h"

class ProgressThread;
/** Implementing SigninFrame */
class SigninMain : public SigninFrame, public ICertCardListener
{
	protected:
		CameraView * m_CameraView;

		// Handlers for SigninFrame events.
		void OnClose( wxCloseEvent& event );
		void OnMenuSelectionCamera( wxCommandEvent& event );
		void OnMenuSelectionCard(wxCommandEvent& event);
		void OnMenuSelectionExit( wxCommandEvent& event );
	public:
		/** Constructor */
		SigninMain( wxWindow* parent );
	//// end generated class members


public:
		bool Cancelled();
		bool m_cancelled;
		wxCriticalSection m_csCancelled;        // protects m_cancelled

		std::unique_ptr<wxProgressDialog> m_dlgProgress;
		std::unique_ptr<ProgressThread> m_threadProgress;

		void OnWorkerEvent(wxThreadEvent& event);
		void OnUpdateWorker(wxUpdateUIEvent& event);

		void UpdateCardAuthed(bool authed, const std::string& info);
		void UpdateCertCardInfo(const std::shared_ptr<CertCardInfo>& info);
		void StartProcess(int result, const std::string& info);
		void EndProcess(int result, const std::string& info);
		void UpdateProgressInfo(int progress, const std::string& info);
};

#endif // __SigninMain__
