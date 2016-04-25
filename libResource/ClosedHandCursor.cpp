#include "ClosedHandCursor.h"

#ifndef __APPLE__

	static char down_mask[] = {
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0x1F, 0xFF, 0xFF,
		0xFF, 0x03, 0xFE, 0xFF,
		0xFF, 0x03, 0xF8, 0xFF,
		0xFF, 0x03, 0xF0, 0xFF,
		0xFF, 0x03, 0xC0, 0xFF,
		0xFF, 0x03, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0x7F, 0x00, 0x80, 0xFF,
		0xFF, 0x00, 0x80, 0xFF,
		0xFF, 0x00, 0xC0, 0xFF,
		0xFF, 0x00, 0xC0, 0xFF,
		0xFF, 0x00, 0xC0, 0xFF,
		0xFF, 0x01, 0xC0, 0xFF,
		0xFF, 0x01, 0xE0, 0xFF,
		0xFF, 0x03, 0xE0, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF };

	static char down_bits[] = {
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0xE0, 0x00, 0x00,
		0x00, 0x3C, 0x01, 0x00,
		0x00, 0x24, 0x07, 0x00,
		0x00, 0x24, 0x09, 0x00,
		0x00, 0x24, 0x39, 0x00,
		0x00, 0x24, 0x69, 0x00,
		0x80, 0x27, 0x49, 0x00,
		0x80, 0x24, 0x49, 0x00,
		0x80, 0x04, 0x48, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x80, 0x00, 0x40, 0x00,
		0x00, 0x01, 0x40, 0x00,
		0x00, 0x01, 0x20, 0x00,
		0x00, 0x01, 0x20, 0x00,
		0x00, 0x03, 0x20, 0x00,
		0x00, 0x02, 0x20, 0x00,
		0x00, 0x02, 0x10, 0x00,
		0x00, 0xFC, 0x1F, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00 };
#endif

wxCursor CResourceCursor::GetClosedHand()
	{
#ifndef __APPLE__
		wxBitmap down_bitmap(down_bits, 32, 32);
		wxBitmap down_mask_bitmap(down_mask, 32, 32);
		down_bitmap.SetMask(new wxMask(down_mask_bitmap));
		wxImage down_image = down_bitmap.ConvertToImage();
		down_image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, 6);
		down_image.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, 14);
		wxCursor down_cursor = wxCursor(down_image);
        return down_cursor;
		
#else
        
        return wxCursor(wxCURSOR_CLOSED_HAND);
        
#endif

		
	}
