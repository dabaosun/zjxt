#include "CustomStaticText.h"

BEGIN_EVENT_TABLE(CustomStaticText, wxStaticText)
EVT_ERASE_BACKGROUND(CustomStaticText::OnEraseBackground)
END_EVENT_TABLE()

bool CustomStaticText::HasTransparentBackground()
{
	return true;
}

void CustomStaticText::SetBg(wxBitmap* bg)
{
	bg_ = bg;
}

CustomStaticText::CustomStaticText()
{
	bg_ = NULL;
	SetBackgroundStyle(wxBG_STYLE_ERASE);
	SetForegroundColour(*wxWHITE);
	brush_ = new wxBrush(wxNullColour, wxBRUSHSTYLE_TRANSPARENT);
}

void CustomStaticText::OnEraseBackground(wxEraseEvent& event)
{
	wxRect rect = GetRect();
	if (last_rect_ != rect)
	{
		last_rect_ = rect;
		int height = bg_->GetHeight();
		int width = bg_->GetWidth();
		rect.height = (height < (rect.y + rect.height)) ? (height - rect.y) : rect.height;
		rect.width = (width < (rect.x + rect.width)) ? (width - rect.x) : rect.width;

		assert(bg_->GetHeight() >= (rect.y + rect.height));
		assert(bg_->GetWidth() >= (rect.x + rect.width));
		bg_cache_ = bg_->GetSubBitmap(
			wxRect(rect.x, rect.y, rect.width, rect.height));
	}
	event.GetDC()->DrawBitmap(bg_cache_, 0, 0);
}

WXHBRUSH CustomStaticText::DoMSWControlColor(WXHDC pDC, wxColour colBg, WXHWND hWnd)
{
	HDC hdc = (HDC)pDC;
	::SetTextColor(hdc, wxColourToRGB(GetForegroundColour()));
	return (WXHBRUSH)brush_->GetResourceHandle();
}

