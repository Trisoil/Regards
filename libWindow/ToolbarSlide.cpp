#include "ToolbarSlide.h"

#include <libResource.h>
#include <ClosedHandCursor.h>
#include "LoadingResource.h"
#include "WindowMain.h"
#include <wxSVG/SVGDocument.h>
#include <wx/sstream.h>
using namespace Regards::Window;

CToolbarSlide::CToolbarSlide(const CThemeSlider & themeSlider, CSliderInterface * eventInterface)
{
	CLoadingResource loadingResource;
	y = 0;
	this->eventInterface = eventInterface;
	this->themeSlider = themeSlider;
	positionButton = { 0, 0, 0, 0 };
	hCursorHand = CResourceCursor::GetClosedHand();
	mouseBlock = false;
	captureBall = false;
    if(isVector)
        buttonVector = CLibResource::GetVector(L"IDB_BOULESLIDER");
    else
        button = loadingResource.LoadImageResource(L"IDB_BOULESLIDER");
}

void CToolbarSlide::Resize(const int &tailleX, const int &tailleY)
{
	themeSlider.SetWidth(tailleX);
	themeSlider.SetHeight(tailleY);
}

wxImage CToolbarSlide::CreateFromSVG(const int & buttonWidth, const int & buttonHeight, const wxString &vector)
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

CToolbarSlide::~CToolbarSlide()
{
}

int CToolbarSlide::GetWidth()
{
	return themeSlider.GetWidth();

}

int CToolbarSlide::GetHeight()
{
	return themeSlider.GetHeight();
}

void CToolbarSlide::ZoomPos(const int &position)
{
	eventInterface->ZoomPos(position);
}

void CToolbarSlide::SetPosition(const int &iPos)
{
	this->position = iPos;
}

int CToolbarSlide::GetNbValue()
{
	return tabValue.size();
}

int CToolbarSlide::GetPosition()
{
	return position;
}

void CToolbarSlide::SetTabValue(vector<int> value)
{
	tabValue = value;
}

void CToolbarSlide::CalculZoomPosition(const int &x)
{
	float posX = x - positionSlider.x;
	float total = positionSlider.width;
	position = (posX / total) * tabValue.size();
}

void CToolbarSlide::ClickLeftPage(const int &x)
{
	//Click Top Triangle
	CalculZoomPosition(x);
	if (position >= tabValue.size())
		position = int(tabValue.size()) - 1;

	if (position < 0)
		position = 0;

	eventInterface->SlidePosChange(position, L"");
}

void CToolbarSlide::ClickRightPage(const int &x)
{
	if (position >= tabValue.size())
		position = int(tabValue.size()) - 1;

	if (position < 0)
		position = 0;

	eventInterface->SlidePosChange(position, L"");

	//Click Top Triangle
	CalculZoomPosition(x);
}

bool CToolbarSlide::FindCirclePos(wxWindow * window, const int &y, const int &x)
{
	wxWindowDC dc(window);
	wxSize renderLast = CWindowMain::GetSizeTexte(&dc, to_string(GetLastValue()), themeSlider.font);

	int posXButtonBegin = this->x + renderLast.x + positionButton.x;
	int posXButtonEnd = this->x + renderLast.x + positionButton.x + positionButton.width;
	
	if ((x >= posXButtonBegin && x <= posXButtonEnd) && (y >= positionButton.y && y <= (positionButton.y + positionButton.height)))
	{
		return true;
	}
	return false;
}

void CToolbarSlide::ClickElement(wxWindow * window, const int &x, const int &y)
{
	int xSlide = x;
	wxWindowDC dc(window);
	wxSize renderLast = CWindowMain::GetSizeTexte(&dc, to_string(GetLastValue()), themeSlider.font);

	int posXButtonBegin = this->x + renderLast.x + positionButton.x;
	int posXButtonEnd = this->x + renderLast.x + positionButton.x + positionButton.width;


	if (FindCirclePos(window, y, xSlide))
	{
		mouseBlock = true;
		window->CaptureMouse();
		wxSetCursor(hCursorHand);
		captureBall = true;
	}
	else if (xSlide > posXButtonEnd)
	{
		ClickRightPage(xSlide - (this->x + renderLast.x ));
	}
	else if (xSlide < posXButtonBegin)
	{
		ClickLeftPage(xSlide - (this->x + renderLast.x ));
	}
}

void CToolbarSlide::UnclickElement(wxWindow * window, const int &x, const int &y)
{
	if (captureBall)
	{
		mouseBlock = false;
		if (window->GetCapture())
			window->ReleaseMouse();
	}
}

bool CToolbarSlide::MouseOver(wxDC * deviceContext, const int &x, const int &y)
{
	if (mouseBlock)
	{
		wxSize renderLast = CWindowMain::GetSizeTexte(deviceContext, to_string(GetLastValue()), themeSlider.font);
		int xSlide = x - this->x - renderLast.x;
		if ((xSlide >= positionSlider.x && xSlide <= (positionSlider.x + positionSlider.width)))
		{
			::wxSetCursor(hCursorHand);
			CalculZoomPosition(xSlide);

			if (position >= tabValue.size())
				position = int(tabValue.size()) - 1;

			if (position < 0)
				position = 0;

			eventInterface->SlidePosChange(position, L"");

			return true;
		}
	}
	return false;
}

int CToolbarSlide::GetPositionValue()
{
	if (tabValue.size() > position)
		return tabValue.at(position);

	return -1;
}


int CToolbarSlide::GetLastValue()
{
	if (tabValue.size() > 0)
		return tabValue.at(tabValue.size() - 1);

	return -1;
}

int CToolbarSlide::GetFirstValue()
{
	if (tabValue.size() > 0)
		return tabValue.at(0);

	return -1;
}

void CToolbarSlide::SetBackgroundBitmap(const wxBitmap & background)
{
	colorBackground = false;
	this->background = background;
}


void CToolbarSlide::CalculPositionButton()
{
	if (position > 0)
	{
		float pourcentage = (float)position / (float)tabValue.size();
		CalculPositionButton(positionSlider.x + int((float)(positionSlider.width) * pourcentage));
	}
	else
	{
		//int buttonWidth = button.GetWidth();
		CalculPositionButton(positionSlider.x);
	}
}

void CToolbarSlide::CalculPositionButton(const int &x)
{

    int buttonWidth = themeSlider.GetButtonWidth();
	int buttonHeight = themeSlider.GetButtonHeight();
	int xPos = x - (buttonWidth / 2);
	int yPos = positionSlider.y + (positionSlider.height - buttonHeight) / 2;

	positionButton.x = xPos;
	positionButton.width = buttonWidth;
	positionButton.y = yPos;
	positionButton.height = buttonHeight;
}



void CToolbarSlide::DrawShapeElement(wxDC * dc, const wxRect &rc)
{
	float pourcentage = 0.0;
	wxRect rcPast;
	rcPast.x = rc.x;
	rcPast.y = rc.y;

	if (position > 0)
	{
		pourcentage = (float)position / (float)tabValue.size();
		rcPast.width = (rc.width * pourcentage);
		rcPast.y = rc.y;
		rcPast.height = themeSlider.GetRectangleHeight();
		CWindowMain::FillRect(dc, rcPast, themeSlider.rectanglePast);
	}

	wxRect rcNext;
	rcNext.x = rcPast.x + rcPast.width;
	rcNext.width = rc.width - rcPast.width;
	rcNext.y = rc.y;
	rcNext.height = themeSlider.GetRectangleHeight();
	CWindowMain::FillRect(dc, rcNext, themeSlider.rectangleNext);
}

void CToolbarSlide::RenderSlide(wxDC * dc, const int &width, const int &height, const int &x, const int &y)
{
	wxBitmap bitmapBuffer = wxBitmap(width, height);
	wxMemoryDC memDC(bitmapBuffer);

	if (colorBackground)
	{
		wxRect rc;
		rc.x = 0;
		rc.width = width;
		rc.y = 0;
		rc.height = height;
		CWindowMain::FillRect(&memDC, rc, themeSlider.colorBack);
	}
	else
	{
		memDC.DrawBitmap(background, 0, 0);
	}

	positionSlider.x = 10;
	positionSlider.width = width - (positionSlider.x * 2);
	positionSlider.y = (height - themeSlider.GetRectangleHeight()) / 2;
	positionSlider.height = themeSlider.GetRectangleHeight();

	DrawShapeElement(&memDC, positionSlider);



	memDC.SelectObject(wxNullBitmap);

	dc->DrawBitmap(bitmapBuffer, x, y);
}

void CToolbarSlide::DrawButton(wxDC * deviceContext)
{
	//bool oldRender = true;

	wxBitmap bitmapBuffer = wxBitmap(themeSlider.GetWidth(), themeSlider.GetHeight());
	wxMemoryDC memDC(bitmapBuffer);


	wxRect rc;
	rc.x = 0;
	rc.width = themeSlider.GetWidth();
	rc.y = 0;
	rc.height = themeSlider.GetHeight();
	CWindowMain::FillRect(&memDC, rc, themeSlider.colorBack);

	//int first = GetFirstValue();
	//int last = GetLastValue();

	wxSize renderFirst = CWindowMain::GetSizeTexte(deviceContext, to_string(GetPositionValue()), themeSlider.font);
	wxSize renderLast = CWindowMain::GetSizeTexte(deviceContext, to_string(GetLastValue()), themeSlider.font);

	RenderSlide(&memDC, themeSlider.GetWidth() - (renderLast.x + renderLast.x), themeSlider.GetHeight(), renderLast.x, 0);

	int yMedium = (themeSlider.GetHeight() - renderFirst.y) / 2;
	CWindowMain::DrawTexte(&memDC, to_string(GetPositionValue()), 0, yMedium, themeSlider.font);

	yMedium = (themeSlider.GetHeight() - renderLast.y) / 2;
	CWindowMain::DrawTexte(&memDC, to_string(GetLastValue()), themeSlider.GetWidth() - renderLast.x, yMedium, themeSlider.font);

	memDC.SelectObject(wxNullBitmap);

	bitmapBuffer.SetMask(new wxMask(bitmapBuffer, themeSlider.colorBack));
	deviceContext->DrawBitmap(bitmapBuffer, x, y, true);

	CalculPositionButton();
    
    if(isVector)
    {
        if(!button.IsOk() || (button.GetWidth() != themeSlider.GetButtonWidth() || button.GetHeight() != themeSlider.GetButtonHeight()))
            button = CreateFromSVG(themeSlider.GetButtonWidth(), themeSlider.GetButtonHeight(), buttonVector);
        deviceContext->DrawBitmap(button, x + renderLast.x + positionButton.x, y + positionButton.y);
    }
    else
    {
        deviceContext->DrawBitmap(button.Rescale(themeSlider.GetButtonWidth(), themeSlider.GetButtonHeight()), x + renderLast.x + positionButton.x, y + positionButton.y);
    }
}
