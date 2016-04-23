
#include "TreeElementTexte.h"

mutex CTreeElementTexte::muTexteSize;

CTreeElementTexte::CTreeElementTexte()
{
	canUpdate = false;
	isClick = false;
	position = RENDERFONT_LEFT;
}

CTreeElementTexte& CTreeElementTexte::operator=(const CTreeElementTexte &other)
{
	visible = other.visible;
	xPos = other.xPos;
	yPos = other.yPos;
	numRow = other.numRow;
	numColumn = other.numColumn;
	themeTexte = other.themeTexte;
	canUpdate = other.canUpdate;
	isClick = other.isClick;
	libelle = other.libelle;
	position = other.position;
	return *this;
}

CTreeElementTexte::~CTreeElementTexte()
{

}

void CTreeElementTexte::SetTheme(CThemeTreeTexte * theme)
{
	themeTexte = *theme;
}

void CTreeElementTexte::MouseOver(wxDC * deviceContext, const int &x, const int &y)
{
	if (canUpdate)
        wxSetCursor(wxCursor(wxCURSOR_IBEAM));
	else
		wxSetCursor(wxCursor(wxCURSOR_HAND));
}

void CTreeElementTexte::SetLibelle(const wxString &libelle)
{
	this->libelle = libelle;
    
	wxSize size = GetSizeText();
	if (themeTexte.GetWidth() < size.x)
		themeTexte.SetWidth(size.x);

	if (themeTexte.GetHeight() < size.y)
		themeTexte.SetHeight(size.y);
    
}

wxSize CTreeElementTexte::GetSizeText()
{
    wxSize size;
    //muTexteSize.lock();
	wxFont font(themeTexte.font.GetFontSize(), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxMemoryDC dc;
	dc.SetFont(font);
	size = dc.GetTextExtent(libelle.c_str());
    //muTexteSize.unlock();
    return size;
}

void CTreeElementTexte::DrawText(wxDC * dc, const int &xPos, const int &yPos)
{
	wxFont font(themeTexte.font.GetFontSize(), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	dc->SetFont(font);
	dc->SetTextForeground(themeTexte.font.GetColorFont());
	dc->DrawText(libelle.c_str(), xPos, yPos);
}

void CTreeElementTexte::SetPosition(const int &position)
{
	this->position = position;
}

void CTreeElementTexte::DrawElement(wxDC * deviceContext, const int &x, const int &y)
{
	wxSize size = GetSizeText();

    
	int xPos = 0;
	int yPos = y + (themeTexte.GetHeight() - size.y) / 2;
	switch (position)
	{
	case RENDERFONT_LEFT:
		xPos = x;
		break;

	case RENDERFONT_CENTER:
		xPos = x + (themeTexte.GetWidth() - size.x) / 2;
		break;

	case RENDERFONT_RIGHT:
		xPos = x + themeTexte.GetWidth() - size.x;
		break;
	}


	DrawText(deviceContext, xPos, yPos);
}

void CTreeElementTexte::SetClick(const bool &value)
{
	isClick = value;
}