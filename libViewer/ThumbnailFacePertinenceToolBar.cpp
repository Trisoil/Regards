#include <header.h>
#include "ThumbnailFacePertinenceToolbar.h"
#include <ToolbarSlide.h>
#include <ToolbarTexte.h>
#include <LibResource.h>
#include "ListFace.h"
#include <window_id.h>
#include "ViewerParamInit.h"
#include "ViewerParam.h"
using namespace Regards::Viewer;

#define WM_REFRESHTHUMBNAIL 1023
#define WM_EXPORT 1024
#define WM_CALENDAR 1025
#define WM_GEOLOCALISE 1026

CThumbnailFacePertinenceToolBar::CThumbnailFacePertinenceToolBar(wxWindow* parent, wxWindowID id, const CThemeToolbar & theme)
	: CToolbarWindow(parent, id, theme)
{
	themeToolbar = theme;
    wxString pertinence = CLibResource::LoadStringFromResource(L"LBLPERTINENCELEVEL",1);//L"History";
    wxString zoomon = CLibResource::LoadStringFromResource(L"LBLZOOMON",1);
    wxString zoomoff = CLibResource::LoadStringFromResource(L"LBLZOOMOFF",1);

	
	CToolbarTexte * toolbarText = new CToolbarTexte(themeToolbar.texte);
	toolbarText->SetLibelle(pertinence);
	toolbarText->SetInactif();
    toolbarText->SetLibelleTooltip(pertinence);
	navElement.push_back(toolbarText);
	
	CToolbarButton * moins = new CToolbarButton(themeToolbar.button);
	moins->SetButtonResourceId(L"IDB_MINUS");
	moins->SetCommandId(WM_ZOOMOUT);
    moins->SetLibelleTooltip(zoomoff);
	navElement.push_back(moins);

	slide = new CToolbarSlide(themeToolbar.slider, this);
	navElement.push_back(slide);

	CToolbarButton * plus = new CToolbarButton(themeToolbar.button);
	plus->SetButtonResourceId(L"IDB_PLUS");
	plus->SetCommandId(WM_ZOOMON);
    plus->SetLibelleTooltip(zoomon);
	navElement.push_back(plus);

}

CThumbnailFacePertinenceToolBar::~CThumbnailFacePertinenceToolBar()
{
}

void CThumbnailFacePertinenceToolBar::ZoomOn()
{
	OnChangeValue();
	if (slide != nullptr)
	{
		int dwPos = slide->GetPosition();
		dwPos++;
		if (dwPos >= slide->GetNbValue())
			dwPos = slide->GetNbValue() - 1;
		SetTrackBarPosition(dwPos);
#ifdef __APPLE__
    this->CallRefresh(this);
#else
	this->FastRefresh(this);
#endif
	}
}

void CThumbnailFacePertinenceToolBar::ZoomOff()
{
	OnChangeValue();
	if (slide != nullptr)
	{
		int dwPos = slide->GetPosition();
		dwPos--;
		if (dwPos < 0)
			dwPos = 0;
		SetTrackBarPosition(dwPos);
#ifdef __APPLE__
    this->CallRefresh(this);
#else
	this->FastRefresh(this);
#endif
	}
}

void CThumbnailFacePertinenceToolBar::SetTabValue(vector<int> value)
{
	if (slide != nullptr)
		slide->SetTabValue(value);
}

void CThumbnailFacePertinenceToolBar::SetTrackBarPosition(const int &iPos)
{
	int positionTrackBar = iPos;
	if (slide != nullptr)
	{
		slide->SetPosition(positionTrackBar);
#ifdef __APPLE__
    this->CallRefresh(this);
#else
	this->FastRefresh(this);
#endif
	}
}

void CThumbnailFacePertinenceToolBar::SlidePosChange(const int &position, const wxString &key)
{
	/*
	CListFace * listFace = (CListFace *)this->FindWindowById(LISTFACEID);
	if (listFace != nullptr)
	{
		wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_THUMBNAILZOOMPOSITION);
		evt.SetExtraLong(position);
		listFace->GetEventHandler()->AddPendingEvent(evt);
	}
	*/
	OnChangeValue();
	


}

void  CThumbnailFacePertinenceToolBar::OnChangeValue()
{
	CViewerParam * viewerParam = (CViewerParam *)CViewerParamInit::getInstance();
	if(viewerParam != nullptr)
	{
		viewerParam->SetPertinenceValue((double)(slide->GetPositionValue()) / 100.0f);
	}

	CListFace * listFace = (CListFace *)this->FindWindowById(LISTFACEID);
	if(listFace != nullptr)
	{
		wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_THUMBNAILUPDATE);
		listFace->GetEventHandler()->AddPendingEvent(evt);
	}

	wxWindow * mainWindow = (wxWindow *)this->FindWindowById(MAINVIEWERWINDOWID);
	if(mainWindow != nullptr)
	{
		wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_CRITERIASHOWUPDATE);
		mainWindow->GetEventHandler()->AddPendingEvent(evt);
	}
	
}

void CThumbnailFacePertinenceToolBar::ZoomPos(const int &position)
{
	/*
	CListFace * listFace = (CListFace *)this->FindWindowById(LISTFACEID);
	if (listFace != nullptr)
	{
		wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_THUMBNAILZOOMPOSITION);
		evt.SetExtraLong(position);
		listFace->GetEventHandler()->AddPendingEvent(evt);
	}
	*/
	OnChangeValue();
}

void CThumbnailFacePertinenceToolBar::EventManager(const int &id)
{
	switch (id)
	{              
	case WM_ZOOMON:
		ZoomOn();
		break;

	case WM_ZOOMOUT:
		ZoomOff();
		break;

	}
}