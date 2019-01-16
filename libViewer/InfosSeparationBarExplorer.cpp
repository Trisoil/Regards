#include "InfosSeparationBarExplorer.h"
#include <LoadingResource.h>
#include <WindowMain.h>
#include <wxSVG/SVGDocument.h>
#include <wx/sstream.h>
#include <LibResource.h>
using namespace Regards::Window;
using namespace Regards::Viewer;


CInfosSeparationBarExplorer::~CInfosSeparationBarExplorer(void)
{
	
}

bool CInfosSeparationBarExplorer::GetSelected()
{
	return isSelected;
}

CInfosSeparationBarExplorer::CInfosSeparationBarExplorer(const CThemeInfosSeparationBar &theme)
	: CInfosSeparationBar(theme)
{
	libelleSelectAll = CLibResource::LoadStringFromResource(L"LBLSelectAll", 1);
	isSelected = false;
    checkOnVector = CLibResource::GetVector(L"IDB_CHECKBOX_ON");
    checkOffVector = CLibResource::GetVector(L"IDB_CHECKBOX_OFF");

}

wxImage CInfosSeparationBarExplorer::CreateFromSVG(const int & buttonWidth, const int & buttonHeight, const wxString &vector)
{
    wxImage img;
    if(vector.size() > 0)
    {
        wxStringInputStream memBuffer(vector);
        wxSVGDocument svgDoc;
        svgDoc.Load(memBuffer);
        img = svgDoc.Render(buttonWidth,buttonHeight,NULL,true,true);
        
    }
    else
    {
        img.Create(buttonWidth, buttonHeight);
    }
    return img;
}

void CInfosSeparationBarExplorer::OnClick(const int &x, const int &y)
{
	if ((rcSelect.x < x && x < (rcSelect.x + rcSelect.width)) && (rcSelect.y < y && y < (rcSelect.y + rcSelect.height)))
	{
		isSelected = !isSelected;
	}
}


void CInfosSeparationBarExplorer::RenderIcone(wxDC * deviceContext, const int &posLargeur, const int &posHauteur)
{
	RenderTitle(deviceContext);
    int x = 0;
    int y = 0;

	if (!bitmapCheckOn.IsOk() || (bitmapCheckOn.GetHeight() != theme.GetCheckboxHeight() || bitmapCheckOn.GetWidth() != theme.GetCheckboxWidth()))
    {
        bitmapCheckOn = CreateFromSVG(theme.GetCheckboxWidth(), theme.GetCheckboxHeight(), checkOnVector);
        bitmapCheckOn = bitmapCheckOn.ConvertToDisabled();
    }
        
	if (!bitmapCheckOff.IsOk() ||  (bitmapCheckOff.GetHeight() != theme.GetCheckboxHeight() || bitmapCheckOff.GetWidth() != theme.GetCheckboxWidth()))
    {
        bitmapCheckOff = CreateFromSVG(theme.GetCheckboxWidth(), theme.GetCheckboxHeight(), checkOffVector);
        bitmapCheckOff = bitmapCheckOff.ConvertToDisabled();
    }
    
	int xPos = x;
	int yPos = y + (theme.GetHeight() - bitmapCheckOn.GetHeight());
    
	rcSelect.x = _xPos + xPos + posLargeur;
	rcSelect.y = _yPos + yPos + posHauteur;
	rcSelect.width = bitmapCheckOn.GetWidth();
	rcSelect.height = bitmapCheckOn.GetHeight();

    if (isSelected)
        deviceContext->DrawBitmap(bitmapCheckOn, xPos, yPos);
    else
        deviceContext->DrawBitmap(bitmapCheckOff, xPos, yPos);
    
    wxSize size = CWindowMain::GetSizeTexte(deviceContext, libelleSelectAll, theme.themeFont);
    
    xPos = xPos + 5 + bitmapCheckOn.GetWidth();
    yPos = y + (theme.GetHeight() - size.y) - (bitmapCheckOn.GetHeight() - size.y) / 2;
    
    CWindowMain::DrawTexte(deviceContext, libelleSelectAll, xPos, yPos + posHauteur, theme.themeFont);


}