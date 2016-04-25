#include "BitmapInfosGps.h"
#include <FileUtility.h>
#include <libResource.h>
#include <ConvertUtility.h>
#include <wx/dcbuffer.h>
#include <RegardsConfigParam.h>
#include <ParamInit.h>
#include <wx/sstream.h>
#include <LoadingResource.h>
#include <wxSVG/SVGDocument.h>
using namespace Regards::Window;
using namespace Regards::Internet;

CBitmapInfosGps::CBitmapInfosGps(wxWindow* parent, wxWindowID id, const CThemeBitmapInfos & theme)
	: CWindowMain(parent, id)
{
	bitmapInfosTheme = theme;
    Connect(wxEVT_PAINT, wxPaintEventHandler(CBitmapInfosGps::OnPaint));
}


void CBitmapInfosGps::SetInfos(const wxString &localisation, const wxString &latitude, const wxString &longitude)
{
    this->localisation = localisation;
    this->latitude = latitude;
    this->longitude = longitude;
}


CBitmapInfosGps::~CBitmapInfosGps()
{
	//delete fileGeolocalisation;
}

int CBitmapInfosGps::GetHeight()
{
	return bitmapInfosTheme.GetHeight();
}

void CBitmapInfosGps::UpdateScreenRatio()
{
    this->Refresh();
}

void CBitmapInfosGps::Resize()
{
	this->Refresh();
}

void CBitmapInfosGps::Redraw()
{
	wxWindowDC dc(this);
    DrawInformations(&dc);
}

void CBitmapInfosGps::DrawInformations(wxDC * dc)
{
    
    wxRect rc;
    rc.x = 0;
    rc.y = 0;
    rc.width = width;
    rc.height = height;
    FillRect(dc, rc, bitmapInfosTheme.colorBack);
    
    wxString refLat = "N";
    wxString refLong = "E";
    
    if(latitude[0] == '-')
        refLat = "S";
    
    if(longitude[0] == '-')
        refLong = "W";
    
    wxString message = L"Latitude : " + latitude + "-" + refLat + " - Longitude : " + longitude + "-" + refLong;
    
    wxSize size = GetSizeTexte(dc, localisation, bitmapInfosTheme.themeFont);
    wxSize sizeMessage = GetSizeTexte(dc, message, bitmapInfosTheme.themeFont);

    DrawTexte(dc, localisation, (width - size.x) / 2, ((height / 2) - size.y) / 2, bitmapInfosTheme.themeFont);

    DrawTexte(dc, message, (width - sizeMessage.x) / 2, (height / 2) + ((height / 2) - sizeMessage.y) / 2, bitmapInfosTheme.themeFont);

}

void CBitmapInfosGps::OnPaint(wxPaintEvent& event)
{
	wxBufferedPaintDC dc(this);
    DrawInformations(&dc);
}