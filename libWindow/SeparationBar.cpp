#include "SeparationBar.h"
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

using namespace Regards::Window;

CSeparationBar::CSeparationBar(IMoveWindow * moveWindow, wxWindow* parent, wxWindowID id, const CThemeSeparationBar & theme)
	: CWindowMain(parent, id)
{
	bSplitterMoving = false;
	horizontal = false;
	this->moveWindow = moveWindow;
	fastRender = false;
	Connect(wxEVT_PAINT, wxPaintEventHandler(CSeparationBar::OnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(CSeparationBar::OnMouseMove));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CSeparationBar::OnLButtonDown));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(CSeparationBar::OnLButtonUp));
	Connect(wxEVT_MOUSE_CAPTURE_LOST, wxMouseEventHandler(CSeparationBar::OnMouseCaptureLost));
    Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(CSeparationBar::OnMouseHover));
    Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(CSeparationBar::OnMouseLeave));

     
	this->theme = theme;
}

void CSeparationBar::SetHorizontal(const bool &horizontal)
{
	this->horizontal = horizontal;
}

void CSeparationBar::Resize()
{
	this->Refresh();
}

CSeparationBar::~CSeparationBar()
{
}


void CSeparationBar::OnMouseLeave(wxMouseEvent& event)
{

}

void CSeparationBar::OnMouseHover(wxMouseEvent& event)
{
    if (horizontal)
    {
        ::wxSetCursor(wxCursor(wxCURSOR_SIZENS));
    }
    else
    {
        ::wxSetCursor(wxCursor(wxCURSOR_SIZEWE));
        
    }
}

void CSeparationBar::OnMouseCaptureLost(wxMouseEvent& event)
{

}

void CSeparationBar::OnMouseMove(wxMouseEvent& event)
{    
	if (horizontal)
	{
		if (bSplitterMoving)
			moveWindow->SetNewPosition();

        ::wxSetCursor(wxCursor(wxCURSOR_SIZENS));
	}
	else
	{
		if (bSplitterMoving)
			moveWindow->SetNewPosition();

        ::wxSetCursor(wxCursor(wxCURSOR_SIZEWE));

	}
}

void CSeparationBar::SetFastRender(const bool &fast)
{
	fastRender = fast;
}

void CSeparationBar::OnLButtonDown(wxMouseEvent& event)
{
	if (moveWindow->OnLButtonDown())
	{
		if (horizontal)
            ::wxSetCursor(wxCursor(wxCURSOR_SIZENS));
		else
            ::wxSetCursor(wxCursor(wxCURSOR_SIZEWE));

		bSplitterMoving = true;
		CaptureMouse();
	}
}


void CSeparationBar::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);

	if (horizontal)
	{
		wxRect rc;
		rc.x = 0;
		rc.y = 0;
		rc.width = width;
		rc.height = height;
		dc.GradientFillLinear(rc, theme.secondColor, theme.firstColor, wxSOUTH);
	}
	else
	{
		wxRect rc;
		rc.x = 0;
		rc.y = 0;
		rc.width = width;
		rc.height = height;
		dc.GradientFillLinear(rc, theme.secondColor, theme.firstColor, wxEAST);
	}

}

void CSeparationBar::OnLButtonUp(wxMouseEvent& event)
{
	moveWindow->OnLButtonUp();
	if (bSplitterMoving)
	{
        if(HasCapture())
            ReleaseMouse();
		bSplitterMoving = false;
	}
}