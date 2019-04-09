#include "header.h"
#include "TreeWindow.h"
#include "ScrollbarWnd.h"
#include "ScrollbarHorizontalWnd.h"
#include "ScrollbarVerticalWnd.h"
#include <wx/dcbuffer.h>
using namespace Regards::Window;

CTreeWindow::CTreeWindow(wxWindow* parent, wxWindowID id, const CThemeTree & theme)
	: CWindowMain("CTreeWindow",parent, id)
{
	treeControl = nullptr;
	renderBitmap = nullptr;
	bitmapWidth = 0;
	bitmapHeight = 0;
	oldPosLargeur = 0;
	oldPosHauteur = 0;
	controlWidth = 0;
	controlHeight = 0;
	defaultPageSize = 50;
	defaultLineSize = 5;
	posHauteur = 0;
	posLargeur = 0;
	themeTree = theme;
	defaultPageSize = 50;
    
    //Buffer
    /*
    controlWidthBuffer = 0;
    controlHeightBuffer = 0;
    posLargeurBuffer = 0;
    posHauteurBuffer = 0;         
    widthBuffer = 0;
    heightBuffer = 0;     
    */
	defaultLineSize = themeTree.GetRowHeight();
	themeTree.themeTriangle.SetHeight(themeTree.GetRowHeight());
	themeTree.themeCheckbox.SetHeight(themeTree.GetRowHeight());
	themeTree.themeDelete.SetHeight(themeTree.GetRowHeight());
	themeTree.themeSlide.SetHeight(themeTree.GetRowHeight());
	themeTree.themeTexte.SetHeight(themeTree.GetRowHeight());
	Connect(wxEVT_PAINT, wxPaintEventHandler(CTreeWindow::OnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(CTreeWindow::OnMouseMove));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CTreeWindow::OnLButtonDown));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(CTreeWindow::OnLButtonUp));
	Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CTreeWindow::OnLDoubleClick));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CTreeWindow::OnMouseWheel));
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(CTreeWindow::OnKeyDown));
	Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(CTreeWindow::OnEraseBackground));
	Connect(wxEVT_MOUSE_CAPTURE_LOST, wxMouseEventHandler(CTreeWindow::OnMouseCaptureLost));
}

void CTreeWindow::UpdateElement(CTreeElement * treeElement)
{
    TRACE();
	wxWindowDC dc(this);
	int xPos = 0;
	if (treeElement->GetRow() > 0)
		xPos = treeControl->GetWidthRow(treeElement->GetRow() - 1);
	

	treeElement->DrawElement(&dc, treeElement->GetPosX() + xPos, treeElement->GetPosY());
    
    bufferUpdate = true; 
}

CTreeWindow::~CTreeWindow()
{
    TRACE();
}

int CTreeWindow::GetWidth()
{
    TRACE();
	return controlWidth;
}

int CTreeWindow::GetHeight()
{
    TRACE();
	return controlHeight;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void CTreeWindow::TestMaxX()
{
    TRACE();
	long xValue = GetWidth() - GetWindowWidth();

	if (posLargeur >= xValue)
		posLargeur = xValue;

	if (posLargeur < 0)
		posLargeur = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void CTreeWindow::TestMaxY()
{
    TRACE();
	long yValue = GetHeight() - GetWindowHeight();

	if (posHauteur >= yValue)
		posHauteur = yValue;

	if (posHauteur < 0)
		posHauteur = 0;
}


void CTreeWindow::OnKeyDown(wxKeyEvent& event)
{
    TRACE();
	bool update = false;
    
    
    switch (event.m_keyCode)
    {
    case WXK_UP:
        this->MoveTop(); 
        update = true;
        break;
    case WXK_LEFT:
        this->MoveLeft();
        update = true;
        break;
    case WXK_DOWN:
        this->MoveBottom();
        update = true;
        break;
    case WXK_RIGHT:
        this->MoveRight();
        update = true;
        break;

    }

    if(update)
    {
        bufferUpdate = true;
        this->FastRefresh(this);
    }

}

void CTreeWindow::OnMouseWheel(wxMouseEvent& event)
{	
    
    TRACE();
    
    bool update = false;

#ifdef __APPLE__
    
    if (event.m_wheelRotation == 1)
    {
        this->MoveTop();
         update = true;         
    }
    else if (event.m_wheelRotation == -1)
    {
         update = true;
         this->MoveBottom();
    }
        
    
#else
    
    if (event.m_wheelRotation == 120)
    {
        this->MoveTop();
         update = true;         
    }
    else
    {
         update = true;
         this->MoveBottom();
    }
    
#endif

    if(update)
    {
        bufferUpdate = true;
        this->FastRefresh(this);
    }


}

void CTreeWindow::DrawBackgroundRectangle(wxDC * deviceContext, const int &y, const int &rowHeight, const wxColour &color)
{
    TRACE();
	wxRect rc;
	rc.x = 0;
	rc.width = GetWindowWidth();
	rc.y = y;
    rc.height = y + rowHeight;//themeTree.GetRowHeight();
	deviceContext->GradientFillLinear(rc, color, color);

}

void CTreeWindow::CalculControlSize()
{
    TRACE();
	if (treeControl != nullptr)
	{
		controlWidth = treeControl->GetWidth();
		controlHeight = treeControl->GetNbRow() * themeTree.GetRowHeight();
		//scrollbar->SetControlSize(controlWidth, controlHeight);
	}

}

wxColour CTreeWindow::GetBackgroundColour(const int &yPos)
{
    TRACE();
    int moduloValue = yPos % (themeTree.GetRowHeight() * 2);
    if(moduloValue < themeTree.GetRowHeight())
        return themeTree.bgColorOne;

    return themeTree.bgColorTwo;
}

void CTreeWindow::GenerateBackgroundBitmap(wxDC * deviceContext, const int &posLargeur, const int &posHauteur)
{
    TRACE();
    int yMaxPos = posHauteur;//-(posHauteur % themeTree.GetRowHeight());
	//bool style = true;
    int diff = themeTree.GetRowHeight() - posHauteur % themeTree.GetRowHeight();


	if (yMaxPos < (GetWindowHeight() + posHauteur))
	{
		while (yMaxPos < (GetWindowHeight() + posHauteur))
		{
			DrawBackgroundRectangle(deviceContext, yMaxPos - posHauteur, diff, GetBackgroundColour(yMaxPos));
			yMaxPos += diff;
            diff = themeTree.GetRowHeight();
		}
	}
}

void CTreeWindow::Resize()
{
    TRACE();
	//UpdateTreeControl();
    bufferUpdate = true;
    this->FastRefresh(this);
}

void CTreeWindow::OnMouseMove(wxMouseEvent& event)
{
    TRACE();
	if (treeControl == nullptr)
		return;

	int xPos = event.GetX();
	int yPos = event.GetY();

    wxWindowDC dc(this);
    try
    {
        CPositionElement * element = treeControl->FindElement(xPos + posLargeur, yPos + posHauteur);
        if (element != nullptr)
        {
            treeControl->MouseOver(&dc, element, xPos, yPos, posLargeur, posHauteur);
        }
        else
        {
            treeControl->MouseOut(&dc, element, xPos, yPos, posLargeur, posHauteur);
            ::wxSetCursor(wxCursor(*wxSTANDARD_CURSOR));
        }
    }
    catch (...)
    {

    }

}

void CTreeWindow::OnLButtonUp(wxMouseEvent& event)
{
    TRACE();
    
	if (treeControl == nullptr)
		return;

	int xPos = event.GetX();
	int yPos = event.GetY();

    CPositionElement * element = treeControl->FindElement(xPos + posLargeur, yPos + posHauteur);
    if (element != nullptr)
    {
        treeControl->UnclickOnElement(element, this, xPos, yPos, posLargeur, posHauteur);
        bufferUpdate = true;
    }
    else
    {
        //SetCursor(IDC_ARROW);
        ::wxSetCursor(wxCursor(*wxSTANDARD_CURSOR));
    }
}

void CTreeWindow::OnLButtonDown(wxMouseEvent& event)
{
    TRACE();
    
	if (treeControl == nullptr)
		return;

	SetFocus();

	int xPos = event.GetX();
	int yPos = event.GetY();

    CPositionElement * element = treeControl->FindElement(xPos + posLargeur, yPos + posHauteur);
    if (element != nullptr)
    {
        treeControl->ClickOnElement(element, this, xPos, yPos, posLargeur, posHauteur);
        bufferUpdate = true;
    }
    else
    {
        //SetCursor(IDC_ARROW);
        ::wxSetCursor(wxCursor(*wxSTANDARD_CURSOR));
    }
    
}

void CTreeWindow::OnLDoubleClick(wxMouseEvent& event)
{
    TRACE();
    
	if (treeControl == nullptr)
		return;

	int xPos = event.GetX();
	int yPos = event.GetY();

    CPositionElement * element = treeControl->FindElement(xPos + posLargeur, yPos + posHauteur);
    if (element != nullptr)
    {
        treeControl->DoubleClickOnElement(element);
        bufferUpdate = true;
    }
    else
    {
        ::wxSetCursor(wxCursor(*wxSTANDARD_CURSOR));
    }
    
}

void CTreeWindow::UpdateTreeControl()
{
    TRACE();
    printf("CTreeWindow::UpdateTreeControl \n");
    bufferUpdate = true;
	CalculControlSize();
	this->FastRefresh(this);
}

void CTreeWindow::UpdateScreenRatio()
{
    TRACE();
    printf("CTreeWindow::UpdateScreenRatio \n");
    //bufferUpdate = true;
    if(this->treeControl != nullptr)
        this->treeControl->UpdateScreenRatio();
    //this->FastRefresh(this);
}


void CTreeWindow::SetTreeControl(CTreeControl * treeControl)
{
    TRACE();
    printf("CTreeWindow::SetTreeControl \n");
	this->treeControl = treeControl;
    bufferUpdate = true;          
	this->FastRefresh(this);
}

void CTreeWindow::OnPaint(wxPaintEvent& event)
{
    TRACE();
    int width = GetWindowWidth();
    int height = GetWindowHeight();
    if(width == 0 || height == 0)
        return;

    
    printf("CTreeWindow::OnPaint \n");
    
	CalculControlSize();

	wxPaintDC dc(this);
	
	if (controlWidth < GetWindowWidth())
	{
		controlWidth = GetWindowWidth();
		posLargeur = 0;
	}

	if (controlHeight < GetWindowHeight())
	{
		controlHeight = GetWindowHeight();
		posHauteur = 0;
	}

	if ((posLargeur + GetWindowWidth()) > controlWidth)
	{
		posLargeur = controlWidth - GetWindowWidth();
	}

	if ((posHauteur + GetWindowHeight()) > controlHeight)
	{
		posHauteur = controlHeight - GetWindowHeight();
	}

    if(bufferUpdate || oldPosLargeur != posLargeur || oldPosHauteur != posHauteur)
    {
        printf("CTreeWindow::OnPaint bufferUpdate \n");
         
        wxBitmap background = wxBitmap(width, height);

        wxMemoryDC memDC(background);

        GenerateBackgroundBitmap(&memDC, posLargeur, posHauteur);
        if (treeControl != nullptr)
            treeControl->GenerateWindowBitmap(&memDC, width, height, posLargeur, posHauteur);

        if (treeControl != nullptr)
            treeControl->AfterDrawBitmap();

        memDC.SelectObject(wxNullBitmap);

        dc.DrawBitmap(background, 0, 0);

        backgroundBuffer = background;

        bufferUpdate = false;  
        
        oldPosLargeur = posLargeur;
        oldPosHauteur = posHauteur; 

        scrollbar->SetControlSize(controlWidth, controlHeight);
        scrollbar->SetPosition(posLargeur, posHauteur);
       
    }
    else
    {
        printf("CTreeWindow::OnPaint not bufferUpdate \n");
        dc.DrawBitmap(backgroundBuffer, 0, 0);     
    }

  

}
