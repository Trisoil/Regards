#include "CloudsFilter.h"
#include "CloudsEffectParameter.h"
#include <RegardsBitmap.h>
#include <LibResource.h>
#include <FilterData.h>

using namespace Regards::Viewer;

CCloudsFilter::CCloudsFilter()
{
    libelleCloudsFrequency = CLibResource::LoadStringFromResource(L"LBLCLOUDSFREQUENCY",1);
    libelleCloudsAmplitude = CLibResource::LoadStringFromResource(L"LBLCLOUDSAMPLITUDE",1);
    libelleCloudsColorFrontRed = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORFRONTRED",1);
    libelleCloudsColorFrontGreen = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORFRONTGREEN",1);
    libelleCloudsColorFrontBlue = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORFRONTBLUE",1);
    libelleCloudsColorBackRed = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORBACKRED",1);
    libelleCloudsColorBackGreen = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORBACKGREEN",1);
    libelleCloudsColorBackBlue = CLibResource::LoadStringFromResource(L"LBLCLOUDSCOLORBACKBLUE",1);
	libelleEffectIntensity  = CLibResource::LoadStringFromResource(L"LBLEFFECTINTENSITY",1);
}

CCloudsFilter::~CCloudsFilter()
{
    
}

int CCloudsFilter::GetTypeFilter()
{
    return IDM_FILTRE_CLOUDS;
}

void CCloudsFilter::Filter(CEffectParameter * effectParameter, CRegardsBitmap * source, IFiltreEffectInterface * filtreInterface)
{
    CCloudsEffectParameter * cloudsEffectParameter = (CCloudsEffectParameter *)effectParameter;
    
    vector<int> elementFreq;
    for (auto i = 0; i < 101; i++)
        elementFreq.push_back(i);
    
    vector<int> elementColor;
    for (auto i = 0; i < 256; i++)
        elementColor.push_back(i);
    
	filtreInterface->AddTreeInfos(libelleEffectIntensity, new CTreeElementValueInt(cloudsEffectParameter->transparency), &elementFreq);
    filtreInterface->AddTreeInfos(libelleCloudsFrequency, new CTreeElementValueInt( cloudsEffectParameter->frequence), &elementFreq);
    filtreInterface->AddTreeInfos(libelleCloudsAmplitude, new CTreeElementValueInt(cloudsEffectParameter->amplitude), &elementFreq);
    filtreInterface->AddTreeInfos(libelleCloudsColorFrontRed, new CTreeElementValueInt(cloudsEffectParameter->colorFront.GetRed()), &elementColor);
    filtreInterface->AddTreeInfos(libelleCloudsColorFrontGreen, new CTreeElementValueInt(cloudsEffectParameter->colorFront.GetGreen()), &elementColor);
    filtreInterface->AddTreeInfos(libelleCloudsColorFrontBlue, new CTreeElementValueInt(cloudsEffectParameter->colorFront.GetBlue()), &elementColor);
    filtreInterface->AddTreeInfos(libelleCloudsColorBackRed, new CTreeElementValueInt(cloudsEffectParameter->colorBack.GetRed()), &elementColor);
    filtreInterface->AddTreeInfos(libelleCloudsColorBackGreen, new CTreeElementValueInt(cloudsEffectParameter->colorBack.GetGreen()), &elementColor);
    filtreInterface->AddTreeInfos(libelleCloudsColorBackBlue, new CTreeElementValueInt(cloudsEffectParameter->colorBack.GetBlue()), &elementColor);
}

void CCloudsFilter::FilterChangeParam(CEffectParameter * effectParameter,  CTreeElementValue * valueData, const wxString &key)
{
    CCloudsEffectParameter * cloudsEffectParameter = (CCloudsEffectParameter *)effectParameter;
    
    CTreeElementValueInt * value = (CTreeElementValueInt *)valueData;
    //Video Parameter
    if (key == libelleEffectIntensity)
    {
        cloudsEffectParameter->transparency = value->GetValue();
    }
    else if (key == libelleCloudsFrequency)
    {
        cloudsEffectParameter->frequence = value->GetValue();
    }
    else if (key == libelleCloudsAmplitude)
    {
        cloudsEffectParameter->amplitude = value->GetValue();
    }
    else if (key == L"Clouds.Octaves")
    {
        cloudsEffectParameter->octave = value->GetValue();
    }
    else if (key == libelleCloudsColorFrontRed)
    {
        cloudsEffectParameter->colorFront = CRgbaquad(value->GetValue(), cloudsEffectParameter->colorFront.GetGreen(), cloudsEffectParameter->colorFront.GetBlue());
    }
    else if (key == libelleCloudsColorFrontGreen)
    {
        cloudsEffectParameter->colorFront = CRgbaquad(cloudsEffectParameter->colorFront.GetRed(), value->GetValue(), cloudsEffectParameter->colorFront.GetBlue());
    }
    else if (key == libelleCloudsColorFrontBlue)
    {
        cloudsEffectParameter->colorFront = CRgbaquad(cloudsEffectParameter->colorFront.GetRed(), cloudsEffectParameter->colorFront.GetGreen(), value->GetValue());
    }
    else if (key == libelleCloudsColorBackRed)
    {
        cloudsEffectParameter->colorBack = CRgbaquad(value->GetValue(), cloudsEffectParameter->colorBack.GetGreen(), cloudsEffectParameter->colorBack.GetBlue());
    }
    else if (key == libelleCloudsColorBackGreen)
    {
        cloudsEffectParameter->colorBack = CRgbaquad(cloudsEffectParameter->colorBack.GetRed(), value->GetValue(), cloudsEffectParameter->colorBack.GetBlue());
    }
    else if (key == libelleCloudsColorBackBlue)
    {
        cloudsEffectParameter->colorBack = CRgbaquad(cloudsEffectParameter->colorBack.GetRed(), cloudsEffectParameter->colorBack.GetGreen(), value->GetValue());
    }
}