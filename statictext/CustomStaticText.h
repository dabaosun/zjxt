
#ifndef CUSTOMSTATICTEXT_H_
#define CUSTOMSTATICTEXT_H_

#include "wx/wx.h"
#include "wx/msw/private.h"

class CustomStaticText :public wxStaticText
{
	DECLARE_EVENT_TABLE()
public:
	CustomStaticText();
	virtual ~CustomStaticText() {}
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

#endif /* CUSTOMSTATICTEXT_H_ */
