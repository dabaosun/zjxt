
#ifndef DHSTATICTEXT_H_
#define DHSTATICTEXT_H_

#include "./DhStaticText.h"
#include "wx/wx.h"
#include "wx/msw/private.h"

class DhStaticText :public wxStaticText
{
	DECLARE_EVENT_TABLE()
public:
	DhStaticText();
	virtual ~DhStaticText() {}
	wxBitmap * bg_;
	virtual bool HasTransparentBackground();
	void SetBg(wxBitmap* bg);
protected:
	void OnEraseBackground(wxEraseEvent& event);
	virtual WXHBRUSH DoMSWControlColor(WXHDC pDC, wxColour colBg, WXHWND hWnd);

private:
	wxBrush * brush_;

	wxRect last_rect_;
	wxBitmap bg_cache_;
};

#endif /* DHSTATICTEXT_H_ */
