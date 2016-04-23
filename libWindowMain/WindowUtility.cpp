#include "WindowUtility.h"
using namespace Regards::Window;
void CWindowUtility::FillRect(wxDC * dc, const wxRect &rc, const wxColour &color)
{
	wxBrush brush(color, wxSOLID);
	dc->SetBrush(brush);
	dc->SetPen(wxPen(color, 1)); // 10-pixels-thick pink outline
	dc->DrawRectangle(rc);
	dc->SetPen(wxNullPen);
	dc->SetBrush(wxNullBrush);
}

void CWindowUtility::DrawTexte(wxDC * dc, const wxString &libelle, const int &xPos, const int &yPos, CThemeFont font)
{
    try
    {
        int fontSize = font.GetFontSize();
        wxColour color = font.GetColorFont();
        wxFont _font(fontSize, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        dc->SetFont(_font);
        //dc->SetBackgroundMode(wxSOLID);
        dc->SetTextForeground(color);
        dc->DrawText(libelle.c_str(), xPos, yPos);
        dc->SetFont(wxNullFont);
    }
    catch(...)
    {
        
    }
}

wxSize CWindowUtility::GetSizeTexte(wxDC * dc, const wxString &libelle, CThemeFont font)
{
	wxSize size;
	wxFont _font(font.GetFontSize(), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	dc->SetFont(_font);
	size = dc->GetTextExtent(libelle.c_str());
	dc->SetFont(wxNullFont);
	return size;
};