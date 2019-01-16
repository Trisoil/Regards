//
//  FiltreEffectWnd.cpp
//  Regards.libViewer
//
//  Created by figuinha jacques on 02/10/2015.
//  Copyright © 2015 figuinha jacques. All rights reserved.
//

#include "FiltreEffectWnd.h"
#include <FiltreEffet.h>
#include "InfoEffectWnd.h"
#include "CloudsEffectParameter.h"
#include "BrightAndContrastEffectParameter.h"
#include "FreeRotateEffectParameter.h"
#include "MotionBlurEffectParameter.h"
#include "LensFlareEffectParameter.h"
#include "SolarisationEffectParameter.h"
#include "PosterisationEffectParameter.h"
#include "PhotoFiltreEffectParameter.h"
#include "RgbEffectParameter.h"
#include "SwirlEffectParameter.h"
#include "GaussianBlurEffectParameter.h"
#include "BlurEffectParameter.h"
#include "SharpenMaskingParameter.h"
#include "BilateralEffectParameter.h"
#include "NlmeansEffectParameter.h"
#include "WaveEffectParameter.h"
#include "ClaheEffectParameter.h"
#include <LibResource.h>
#include <BitmapWndViewer.h>
#include <ShowBitmap.h>
#include <ShowVideo.h>
//#include <VideoControl.h>
#include "PreviewWnd.h"
#if defined(__WXMSW__)
#include "../include/window_id.h"
#include "../include/config_id.h"
#else
#include <window_id.h>
#include <config_id.h>
#endif
#include "PanelInfosWnd.h"
#include <FilterData.h>
using namespace Regards::Viewer;

CFiltreEffectScrollWnd::CFiltreEffectScrollWnd(wxWindow* parent, wxWindowID id, const CThemeScrollBar & themeScroll, const CThemeTree & themeTree)
: CWindowMain("CFiltreEffectScrollWnd",parent, id)
{
	bitmap = nullptr;
	numFiltre = 0;
    effectParameter = nullptr;
    filtreEffectScroll = nullptr;
    treeFiltreEffect = nullptr;
    filtreEffectOld = nullptr;
    filtreEffectScroll = new CScrollbarWnd(this, wxID_ANY);
    treeFiltreEffect = new CTreeWindow(filtreEffectScroll, wxID_ANY, themeTree);
    filtreEffectScroll->SetCentralWindow(treeFiltreEffect, themeScroll);
}

CFiltreEffectScrollWnd::~CFiltreEffectScrollWnd(void)
{
    if(treeFiltreEffect != nullptr)
        delete(treeFiltreEffect);
    
    if(filtreEffectScroll != nullptr)
        delete(filtreEffectScroll);
    
    if(filtreEffectOld != nullptr)
        delete(filtreEffectOld);
    
    if(effectParameter != nullptr)
       delete(effectParameter);

	if(bitmap != nullptr)
		delete bitmap;
}
void CFiltreEffectScrollWnd::UpdateScreenRatio()
{
    if(filtreEffectScroll != nullptr)
        filtreEffectScroll->UpdateScreenRatio();
    
    if(treeFiltreEffect != nullptr)
        treeFiltreEffect->UpdateScreenRatio();
    
    if(filtreEffectOld != nullptr)
        filtreEffectOld->UpdateScreenRatio();
    
}

void CFiltreEffectScrollWnd::Resize()
{
    filtreEffectScroll->SetSize(0,0,GetWindowWidth(),GetWindowHeight());
}

void CFiltreEffectScrollWnd::OnFiltreOk(const int &numFiltre, CInfoEffectWnd * historyEffectWnd)
{
	//wxWindow * mainWindow = this->FindWindowById(MAINVIEWERWINDOWID);
	CShowBitmap * showBitmap = (CShowBitmap *)this->FindWindowById(SHOWBITMAPVIEWERID);
    //CBitmapWndViewer * bitmapViewer = (CBitmapWndViewer *)this->FindWindowById(BITMAPWINDOWVIEWERID);
	
    if (showBitmap != nullptr)
    {
		CBitmapWndViewer * bitmapViewer = showBitmap->GetBitmapViewer();
		if(bitmapViewer != nullptr)
		{
			bitmapViewer->OnFiltreOk();
           if(CFiltreData::OnFiltreOk(numFiltre))
            {
                CRegardsBitmap * bitmap = bitmapViewer->GetBitmap(true);
                bitmapViewer->SetBitmapEffect(numFiltre, effectParameter);
                historyEffectWnd->AddModification(bitmap, CFiltreData::GetFilterLabel(numFiltre));
                if(bitmap != nullptr)
                    delete bitmap;
            }
		}
    }
}



int CFiltreEffectScrollWnd::GetNumFiltre()
{
	return numFiltre;
}

void CFiltreEffectScrollWnd::ApplyEffect(const int &numItem, CInfoEffectWnd * historyEffectWnd, CPanelInfosWnd * panelInfos, const wxString &filename, const int & isVideo)
{
	numFiltre = numItem;
	if(!isVideo)
	{
		CPreviewWnd * previewWindow = (CPreviewWnd *)this->FindWindowById(PREVIEWVIEWERID);
		CShowBitmap * showBitmap = (CShowBitmap *)this->FindWindowById(SHOWBITMAPVIEWERID);


    
		if (showBitmap != nullptr)
		{
			CBitmapWndViewer * bitmapViewer = showBitmap->GetBitmapViewer();
			bitmapViewer->ApplyEffect(numItem);
			CFiltreEffect * filtreEffect = new CFiltreEffect(bitmapViewer, treeFiltreEffect->GetTheme(), treeFiltreEffect);
        
			if (bitmapViewer != nullptr)
			{
				int typeData = CFiltreData::TypeApplyFilter(numItem);

				switch (typeData)
				{
					case 1:
					{
						if (previewWindow != nullptr)
							previewWindow->ShowValidationToolbar(true, numItem);
                    
						bitmapViewer->SetTool(numItem);
						bitmapViewer->SetBitmapPreviewEffect(numItem);

					}
					break;

					case 2:
					{
						if(effectParameter != nullptr)
							delete(effectParameter);

						if(bitmap != nullptr)
							delete bitmap;
						bitmap = nullptr;

						effectParameter = CFiltreData::GetEffectPointer(numItem);
						bitmapViewer->SetBitmapPreviewEffect(numItem, effectParameter);

						bitmap = bitmapViewer->GetBitmap(true);

						filtreEffect->Init(effectParameter, bitmap, filename, numItem);
						if (previewWindow != nullptr)
							previewWindow->ShowValidationToolbar(true, numItem);
						panelInfos->ShowFiltre(CFiltreData::GetFilterLabel(numItem));
						treeFiltreEffect->SetTreeControl(filtreEffect);
                       if(filtreEffectOld != nullptr)
                            delete(filtreEffectOld);
						filtreEffectOld = filtreEffect;
						break;
					}

					default:
						{
							CRegardsBitmap * bitmap = bitmapViewer->GetBitmap(true);
							bitmapViewer->SetBitmapEffect(numItem, nullptr);
							bitmapViewer->OnFiltreOk();
							historyEffectWnd->AddModification(bitmap, CFiltreData::GetFilterLabel(numItem));
							if(bitmap != nullptr)
								delete bitmap;
						}
						break;
				}
			}
		}
	 }
	else
	{
		CShowVideo * showVideo = (CShowVideo *)this->FindWindowById(SHOWVIDEOVIEWERID);
		//CVideoControl * videoControl = showVideo->GetVideoControl();
		CFiltreEffect * filtreEffect = new CFiltreEffect(showVideo, treeFiltreEffect->GetTheme(), treeFiltreEffect);
		switch (numItem)
		{
			case IDM_FILTRE_VIDEO:
			{
				if(effectParameter != nullptr)
					delete(effectParameter);
				effectParameter = showVideo->GetParameter();
				showVideo->SetVideoPreviewEffect(effectParameter);
				filtreEffect->Init(effectParameter, nullptr, filename, numItem);
				panelInfos->ShowFiltre(CFiltreData::GetFilterLabel(numItem));
				treeFiltreEffect->SetTreeControl(filtreEffect);
				delete(filtreEffectOld);
				filtreEffectOld = filtreEffect;
				break;
			}

			case IDM_FILTRE_AUDIOVIDEO:
			{
				if(effectParameter != nullptr)
					delete(effectParameter);
				effectParameter = showVideo->GetParameter();
				showVideo->SetVideoPreviewEffect(effectParameter);
				filtreEffect->Init(effectParameter, nullptr, filename, numItem);
				panelInfos->ShowFiltre(CFiltreData::GetFilterLabel(numItem));
				treeFiltreEffect->SetTreeControl(filtreEffect);
				delete(filtreEffectOld);
				filtreEffectOld = filtreEffect;
				break;
			}
		}
	}
   
}


CFiltreEffect * CFiltreEffectScrollWnd::GetFiltreEffect()
{
	return filtreEffectOld;
}