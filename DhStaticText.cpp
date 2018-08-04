#include "./DhStaticText.h"

BEGIN_EVENT_TABLE(DhStaticText, wxStaticText)
EVT_ERASE_BACKGROUND(DhStaticText::OnEraseBackground)
END_EVENT_TABLE()

bool DhStaticText::HasTransparentBackground()
{
	return true;
}

void DhStaticText::SetBg(wxBitmap* bg)
{
	bg_ = bg;
}

DhStaticText::DhStaticText()
{
	bg_ = NULL;
	SetBackgroundStyle(wxBG_STYLE_ERASE);
	SetForegroundColour(*wxWHITE);
	brush_ = new wxBrush(wxNullColour, wxBRUSHSTYLE_TRANSPARENT);
}

void DhStaticText::OnEraseBackground(wxEraseEvent& event)
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

WXHBRUSH DhStaticText::DoMSWControlColor(WXHDC pDC, wxColour colBg, WXHWND hWnd)
{
	HDC hdc = (HDC)pDC;
	::SetTextColor(hdc, wxColourToRGB(GetForegroundColour()));
	return (WXHBRUSH)brush_->GetResourceHandle();
}

