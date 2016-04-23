
#include "Thumbnail.h"
//#include <omp.h>
#include <queue>
#include <deque>
#include <algorithm>    // std::find
#include <libResource.h>
#include <FileUtility.h>
#include <libPicture.h>
#include <wxmd5.h>
#include "ScrollbarHorizontalWnd.h"
#include "ScrollbarVerticalWnd.h"
#include "ScrollbarWnd.h"
#include <wx/dcbuffer.h>
#include "LoadingResource.h"
#include <wx/filename.h>
#include <chrono>
class EVENT_ICONEUPDATE;
using namespace Regards::Window;


#define TIMER_LOADING 4
const int CThumbnail::TabSize[] = { 50,100,150,200,250,300,350,400,450,500,550,600,650,700};
const int CThumbnail::Max = 14;
wxDEFINE_EVENT(EVENT_ICONEUPDATE, wxCommandEvent);
wxDEFINE_EVENT(EVENT_KILLICONETHREAD, wxCommandEvent);

#ifdef LOCALTHREAD
wxDEFINE_EVENT(wxEVT_COMMAND_MYTHREAD_COMPLETED, wxThreadEvent);
wxDEFINE_EVENT(wxEVT_COMMAND_MYTHREAD_UPDATE, wxThreadEvent);
wxDEFINE_EVENT(wxEVT_COMMAND_PAUSETHREAD, wxCommandEvent);


class MyThread : public wxThread
{
public:
    MyThread(CThumbnail *handler)
        : wxThread(wxTHREAD_DETACHED)
        { 
			m_pHandler = handler;
		};
    ~MyThread();
protected:
    virtual ExitCode Entry();
    CThumbnail *m_pHandler;
};

wxThread::ExitCode MyThread::Entry()
{
    while (!TestDestroy())
    {
        // ... do a bit of work...
        //wxQueueEvent(m_pHandler, new wxThreadEvent(wxEVT_COMMAND_MYTHREAD_UPDATE));
		m_pHandler->BackgroundManager();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    // signal the event handler that this thread is going to be destroyed
    // NOTE: here we assume that using the m_pHandler pointer is safe,
    //       (in this case this is assured by the MyFrame destructor)
    wxQueueEvent(m_pHandler, new wxThreadEvent(wxEVT_COMMAND_MYTHREAD_COMPLETED));
    return (wxThread::ExitCode)0;     // success
}
MyThread::~MyThread()
{
    wxCriticalSectionLocker enter(m_pHandler->m_pThreadCS);
    // the thread is being destroyed; make sure not to leave dangling pointers around
    m_pHandler->m_pThread = NULL;
}
#endif

class CThreadLoadingBitmap
{
public:

	CThreadLoadingBitmap()
	{
	};
	~CThreadLoadingBitmap(){};

	int typeElement;
	int percent;
	wxString filename;
	int timePosition;
	int numIcone;
	int type = 0;
    CRegardsBitmap * bitmapIcone = nullptr;
	std::thread * thread = nullptr;
	CThumbnail * thumbnail = nullptr;
};

#define WM_NEWFOLDER 501
#define WM_DISPLAYPICTURE 502
#define WM_STOPPICTURELOAD 503
#define WM_UPDATESTATUSBAR 504
#define WM_LOADTHUMBNAIL 505

CIcone * CThumbnail::FindElement(const int &xPos, const int &yPos)
{
	for (CIcone * icone : pIconeList)
	{
		if (icone != nullptr)
		{
			wxRect rc = icone->GetPos();
			if ((rc.x < xPos && xPos < rc.width) && (rc.y < yPos && yPos < rc.height))
			{
				return icone;
			}
		}
	}

	return nullptr;
}


void CThumbnail::EraseThumbnail()
{
#ifdef LOCALTHREAD	
	DoPauseThread();
#endif	
    CSqlThumbnail sqlThumbnail;
	for (CIcone * pIcone : pIconeList)
	{
		CThumbnailData * pThumbnailData = pIcone->GetData();
		if (pThumbnailData != nullptr)
        {
			pThumbnailData->InitLoadState();
            wxString filename = pThumbnailData->GetFilename();
            sqlThumbnail.DeleteThumbnail(filename);
        }
	}
	thumbnailPos = 0;
    
#ifdef LOCALTHREAD
	DoResumeThread();
#endif	
}

void CThumbnail::GetSelectItem(vector<CThumbnailData *> &vectorData)
{
	//bool find = false;

	for (CIcone * pIcone : pIconeList)
	{
		if (pIcone != nullptr)
		{
			if (pIcone->IsChecked())
				vectorData.push_back(pIcone->GetData());
		}
	}

}

wxString CThumbnail::SetActifItem(const int &numItem)
{
	wxWindowDC winDC(this);

	if (numItem >= pIconeList.size())
		return L"";

	if (numSelect != NULL)
		numSelect->SetSelected(false);

	if (numActif != nullptr)
	{
		numActif->SetActive(false);
		numActif->RenderIcone(&winDC);
	}

	numActif = pIconeList.at(numItem);

	CScrollbarVerticalWnd * scrollV = scrollbar->GetVScrollbar();
	CScrollbarHorizontalWnd * scrollH = scrollbar->GetHScrollbar();
	if (!scrollV->IsMoving())
	{
		wxRect rect = numActif->GetPos();
		rect.x = posLargeur + rect.x;
		rect.y = posHauteur + rect.y;
		scrollV->SetPosition(rect.y); scrollV->Refresh();
		scrollH->SetPosition(rect.x); scrollH->Refresh();
        
        if(width < GetWidth())
            posLargeur = scrollH->GetPosition();
        
        if(height < GetHeight())
		posHauteur = scrollV->GetPosition();
		
	}

	numActif = pIconeList.at(numItem);

	if (numActif != nullptr)
	{
		numActif->SetActive(true);
		numActif->RenderIcone(&winDC);
	}

	this->Refresh();

	if (numActif->GetData() != NULL)
		return numActif->GetData()->GetFilename();

	return L"";
}

void CThumbnail::SetTheme(CThemeThumbnail * theme)
{
	themeThumbnail = *theme;
}

void CThumbnail::ZoomOn()
{
	positionSize++;
	if (positionSize > Max)
		positionSize = Max;

	int sizeIcone = TabSize[positionSize - 1];
	SetIconeSize(sizeIcone, sizeIcone);
	UpdateScroll();
	this->Refresh();
	//PostThreadMessage(dwThreadId, WM_UPDATE, 0, 0);
}

void CThumbnail::ZoomOff()
{
	positionSize--;
	if (positionSize < 1)
		positionSize = 1;

	int sizeIcone = TabSize[positionSize - 1];
	SetIconeSize(sizeIcone, sizeIcone);
	UpdateScroll();
	this->Refresh();
}

void CThumbnail::ZoomPosition(const int &position)
{
	positionSize = position+1;
	if (positionSize < 1)
		positionSize = 1;
	if (positionSize > Max)
		positionSize = Max;

	int sizeIcone = TabSize[positionSize - 1];
	SetIconeSize(sizeIcone, sizeIcone);
	UpdateScroll();
	this->Refresh();
}


CThumbnail::CThumbnail(wxWindow* parent, wxWindowID id, IStatusBarInterface * statusbar, const CThemeThumbnail & themeThumbnail)
	: CWindowMain(parent, id)
{
    //nbProcesseur = 4;//omp_get_num_procs();
	nbProcesseur = std::thread::hardware_concurrency();
	thumbnailSizeX = 0;
	thumbnailSizeY = 0;
	posHauteur = 0;
	posLargeur = 0;
	numActif = 0;
	positionYOld = 0;
	positionXOld = 0;
	nbLigneX = 0;
	nbLigneY = 0;
	positionSize = 4;
	
	numStartElement = 0;
	nbElementToShow = 0;
	isStoragePt = false;

	CreateBitmapFolder();
	defaultPageSize = 200;
	defaultLineSize = 200;

	this->statusbar = statusbar;
	this->themeThumbnail = themeThumbnail;
	Connect(wxEVT_IDLE, wxIdleEventHandler(CThumbnail::onIdle));
	Connect(wxEVT_PAINT, wxPaintEventHandler(CThumbnail::OnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(CThumbnail::OnMouseMove));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CThumbnail::OnLButtonDown));
	Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(CThumbnail::OnLDoubleClick));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(CThumbnail::OnMouseWheel));
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(CThumbnail::OnKeyDown));
	Connect(EVENT_ICONEUPDATE, wxCommandEventHandler(CThumbnail::UpdateRenderIcone));
	Connect(EVENT_KILLICONETHREAD, wxCommandEventHandler(CThumbnail::KillThreadIcone));
	//Connect(wxEVT_CLOSE, wxCloseEventHandler(CThumbnail::OnClose));
	
#ifdef LOCALTHREAD	
	Connect(wxEVT_COMMAND_PAUSETHREAD, wxCommandEventHandler(CThumbnail::OnThreadPause));
    Connect(wxEVT_COMMAND_MYTHREAD_UPDATE, wxThreadEventHandler(CThumbnail::OnThreadUpdate));
    Connect(wxEVT_COMMAND_MYTHREAD_COMPLETED, wxThreadEventHandler(CThumbnail::OnThreadCompletion));
#endif
    loadingTimer = new wxTimer(this, TIMER_LOADING);
    Connect(TIMER_LOADING, wxEVT_TIMER, wxTimerEventHandler(CThumbnail::OnLoading), nullptr, this);
    
    wxString resourcePath = CFileUtility::GetResourcesFolderPath();
    m_animation = new wxAnimation(resourcePath + "/loading.gif");
	
	//DoStartThread();
	//DoPauseThread();

}
#ifdef LOCALTHREAD
void CThumbnail::OnThreadPause(wxCommandEvent& event)
{
	DoPauseThread();;
}

void CThumbnail::DoStartThread()
{
    m_pThread = new MyThread(this);
	m_pThread->Sleep(100);
	m_pThread->SetPriority(WXTHREAD_MIN_PRIORITY);
    if ( m_pThread->Run() != wxTHREAD_NO_ERROR )
    {
        wxLogError("Can't create the thread!");
        delete m_pThread;
        m_pThread = NULL;
    }
    // after the call to wxThread::Run(), the m_pThread pointer is "unsafe":
    // at any moment the thread may cease to exist (because it completes its work).
    // To avoid dangling pointers OnThreadExit() will set m_pThread
    // to NULL when the thread dies.
}

void CThumbnail::OnThreadCompletion(wxThreadEvent&)
{
    wxMessageOutputDebug().Printf("MYFRAME: MyThread exited!\n");
}
void CThumbnail::OnThreadUpdate(wxThreadEvent&)
{
    wxMessageOutputDebug().Printf("MYFRAME: MyThread update...\n");
	BackgroundManager();
	
}

void CThumbnail::DoResumeThread()
{
    // anytime we access the m_pThread pointer we must ensure that it won't
    // be modified in the meanwhile; since only a single thread may be
    // inside a given critical section at a given time, the following code
    // is safe:
    wxCriticalSectionLocker enter(m_pThreadCS);
    if (m_pThread)         // does the thread still exist?
    {
        // without a critical section, once reached this point it may happen
        // that the OS scheduler gives control to the MyThread::Entry() function,
        // which in turn may return (because it completes its work) making
        // invalid the m_pThread pointer
        if (m_pThread->IsPaused() )
		{
			if (m_pThread->Resume() != wxTHREAD_NO_ERROR )
				wxLogError("Can't Resume the thread!");
		}
    }	
}

void CThumbnail::DoPauseThread()
{
    // anytime we access the m_pThread pointer we must ensure that it won't
    // be modified in the meanwhile; since only a single thread may be
    // inside a given critical section at a given time, the following code
    // is safe:
    wxCriticalSectionLocker enter(m_pThreadCS);
    if (m_pThread)         // does the thread still exist?
    {
        // without a critical section, once reached this point it may happen
        // that the OS scheduler gives control to the MyThread::Entry() function,
        // which in turn may return (because it completes its work) making
        // invalid the m_pThread pointer
        if (m_pThread->Pause() != wxTHREAD_NO_ERROR )
            wxLogError("Can't pause the thread!");
    }
}
#endif

void CThumbnail::CreateBitmapFolder()
{
	CLoadingResource loadingResource;
	bitmapPhoto = loadingResource.LoadBmpResource("IDB_PHOTO");
	if (bitmapPhoto.IsOk())
	{
#if _DEBUG
		OutputDebugString(L"Erreur CreateBitmapFolder IDB_PHOTO  not valid \n");
#endif
	}
}

CThumbnail::~CThumbnail()
{
#ifdef LOCALTHREAD
	wxCriticalSectionLocker enter(m_pThreadCS);
	if (m_pThread)         // does the thread still exist?
	{
		wxMessageOutputDebug().Printf("MYFRAME: deleting thread");
		if (m_pThread->Delete() != wxTHREAD_NO_ERROR )
			wxLogError("Can't delete the thread!");
	}
    
	// exit from the critical section to give the thread
	// the possibility to enter its destructor
	// (which is guarded with m_pThreadCS critical section!)
    while (1)
    {
        { // was the ~MyThread() function executed?
            wxCriticalSectionLocker enter(m_pThreadCS);
            if (!m_pThread) break;
        }
        // wait for thread completion
        wxThread::This()->Sleep(1);
    }
#endif
    
    delete m_animation;

	while (nbProcess > 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
		

	EraseThumbnailList();

}

int CThumbnail::GetWidth()
{
	return thumbnailSizeX;
}

int CThumbnail::GetHeight()
{
	return thumbnailSizeY;
}

int CThumbnail::GetIconeHeight()
{
	return themeThumbnail.themeIcone.GetHeight();
}

int CThumbnail::GetIconeWidth()
{
	return themeThumbnail.themeIcone.GetWidth();
}

void CThumbnail::EraseThumbnailList()
{
	for (CIcone * pIcone : pIconeList)
	{
        while(pIcone->IsLock())
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
		delete(pIcone);
	}
	pIconeList.clear();

}

void CThumbnail::SetIconeSize(const int &width, const int &height)
{
	themeThumbnail.themeIcone.SetWidth(width);
	themeThumbnail.themeIcone.SetHeight(height);
    
    ResizeThumbnail();
}

void CThumbnail::UpdateBitmapIcone(const int &thumbnailPos, CRegardsBitmap * bitmap)
{
	if (bitmap != nullptr)
	{
		if (thumbnailPos < pIconeList.size())
		{
			CIcone * icone = pIconeList.at(thumbnailPos);
			if (icone != nullptr)
			{
				CThumbnailData * pThumbnailData = icone->GetData();

				if (pThumbnailData != nullptr)
				{
					pThumbnailData->SetBitmap(bitmap);
					//UpdateRenderIcone(icone);
					wxCommandEvent event(EVENT_ICONEUPDATE);
					event.SetClientData(icone);
					wxPostEvent(this, event);
				}
			}
		}
	}
}

void CThumbnail::UpdateVideoIcone(const int &thumbnailPos, CRegardsBitmap * bitmap, const int &timePosition)
{
	if (bitmap != nullptr)
	{
		if (thumbnailPos < pIconeList.size())
		{
			CIcone * icone = pIconeList.at(thumbnailPos);
			if (icone != nullptr)
			{
				CThumbnailData * pThumbnailData = icone->GetData();
				if (pThumbnailData != nullptr)
				{
					pThumbnailData->SetBitmap(bitmap);
					pThumbnailData->SetTimePosition(timePosition);
					//UpdateRenderIcone(icone);
					wxCommandEvent event(EVENT_ICONEUPDATE);
					event.SetClientData(icone);
					wxPostEvent(this, event);
				}      
			}
		}
	}
}

void CThumbnail::BackgroundManager()
{
    bool thumbnailLoad = false;

	if (pIconeList.size() == 0 || threadDataProcess == false)
	{
		//DoPauseThread();
		//wxCommandEvent event(wxEVT_COMMAND_PAUSETHREAD);
		//wxPostEvent(this, event);
		return;
	}
	if (thumbnailPos < pIconeList.size())
	{
		CLibPicture libPicture;
		CSqlThumbnail sqlThumbnail;
		CIcone * icone = pIconeList.at(thumbnailPos);
		if (icone != nullptr)
		{
			if (!icone->IsPictureLoad())
			{
				CThumbnailData * pThumbnailData = icone->GetData();

				if (pThumbnailData != nullptr)
				{
					wxString filename = pThumbnailData->GetFilename();
					//int percent = pThumbnailData->GetPercent();
					int type = pThumbnailData->GetType();
					bool isLoad = pThumbnailData->IsLoad();

					bool result = false;
					if (type == 2)
					{
						wxMD5 md5;
						wxString md5file = md5.GetFileMD5(filename);
						result = sqlThumbnail.TestThumbnail(filename, md5file);
                        
					}
					else
						result = isLoad;

					if (!result)
					{
						muThreadMain.lock();

						if (threadMain == nullptr)
						{
							CThreadLoadingBitmap * pLoadBitmap = new CThreadLoadingBitmap();
							pLoadBitmap->timePosition = pThumbnailData->GetTimePosition();
							pLoadBitmap->percent = pThumbnailData->GetPercent();
							pLoadBitmap->typeElement = pThumbnailData->GetTypeElement();
							pLoadBitmap->filename = pThumbnailData->GetFilename();
							pLoadBitmap->thumbnail = this;
							pLoadBitmap->thread = nullptr;
							pLoadBitmap->numIcone = thumbnailPos;
							pLoadBitmap->type = 1;
							//pLoadBitmap->thread = new std::thread(LoadPicture, (void *)pLoadBitmap);
							threadMain = new std::thread(LoadPicture, pLoadBitmap);
							//pLoadBitmap->thread =
                            
                            thumbnailLoad = true;
						}

						muThreadMain.unlock();
					}
                    else
                        thumbnailLoad = true;
				}
			}
		}


        if(thumbnailLoad)
        {
            wxString message = L"Folder Processing " + to_string(thumbnailPos + 1) + L"/" + to_string(pIconeList.size());
            if (statusbar != nullptr)
            {
                statusbar->SetText(2, message);
                statusbar->SetRangeProgressBar(pIconeList.size());
                statusbar->SetPosProgressBar(thumbnailPos + 1);
            }

            //wsprintf(message, L"Folder Processing %d / %d", thumbnailPos + 1, pIconeList.size());
            //statusBar->SetText(2, message);
            //statusBar->SetRangeProgressBar(pIconeList.size());
            //statusBar->SetPosProgressBar(thumbnailPos + 1);

            thumbnailPos++;
        }
	}	
}

void CThumbnail::onIdle(wxIdleEvent& evt)
{
#ifdef LOCALTHREAD	
	return;
#else
	BackgroundManager();
#endif
}

void CThumbnail::LoadPicture(void * param)
{
	CLibPicture libPicture;
	CThreadLoadingBitmap * threadLoadingBitmap = (CThreadLoadingBitmap *)param;
    if(threadLoadingBitmap == nullptr)
        return;
    
	CThumbnail * thumbnail = threadLoadingBitmap->thumbnail;


	if (threadLoadingBitmap->typeElement == TYPEVIDEO)
	{
        threadLoadingBitmap->bitmapIcone = libPicture.LoadVideoThumbnail(threadLoadingBitmap->filename, threadLoadingBitmap->percent, threadLoadingBitmap->timePosition);
	}
	else
		threadLoadingBitmap->bitmapIcone = libPicture.LoadThumbnail(threadLoadingBitmap->filename);

    /*
	if (bitmapIcone != nullptr && thumbnail != nullptr)
	{
		CIcone * icone = thumbnail->pIconeList.at(threadLoadingBitmap->numIcone);
		if (icone != nullptr)
		{
			CThumbnailData * pThumbnailData = icone->GetData();
			if (pThumbnailData->GetTypeElement() == TYPEVIDEO)
				pThumbnailData->SetTimePosition(threadLoadingBitmap->timePosition);

			pThumbnailData->SetBitmap(bitmapIcone);
			//thumbnail->UpdateRenderIcone(icone);
			wxCommandEvent event(EVENT_ICONEUPDATE);
			event.SetClientData(icone);
			wxPostEvent(threadLoadingBitmap->thumbnail, event);
		}
	}


	if (bitmapIcone != nullptr)
	{
		delete(bitmapIcone);
		bitmapIcone = nullptr;
	}
    */
    
    
	wxCommandEvent event(EVENT_ICONEUPDATE);
	event.SetClientData(threadLoadingBitmap);
	wxPostEvent(threadLoadingBitmap->thumbnail, event);

}

void CThumbnail::OnMouseMove(wxMouseEvent& event)
{
    bool needtoRedraw = false;

        int xPos = event.GetX();
        int yPos = event.GetY();
        
        ::wxSetCursor(wxCursor(wxCURSOR_HAND));
        CIcone * pBitmapIcone = FindElement(xPos, yPos);
        
        
        if (numActif != nullptr)
        {
            if (pBitmapIcone != numActif)
            {
                numActif->SetActive(false);
                needtoRedraw = true;
            }
            
        }
        
        if (pBitmapIcone != nullptr)
        {
            if (pBitmapIcone->GetState() != ACTIFICONE)
            {
                numActif = pBitmapIcone;
                pBitmapIcone->SetActive(true);
                needtoRedraw = true;
            }
        }
        


    
    if(needtoRedraw)
        this->Refresh();
    

}

void CThumbnail::RenderBitmap(wxDC * deviceContext, CIcone * pBitmapIcone)
{
	if (pBitmapIcone == nullptr)
		return;

	if (nbProcess < nbProcesseur)
    {
        CThumbnailData * pThumbnailData = pBitmapIcone->GetData();
        if (pThumbnailData != nullptr)
        {
            if (!pThumbnailData->IsLoad() && !pThumbnailData->IsLoading())
            {
                pThumbnailData->SetIsLoading(true);
                int numIcone = pBitmapIcone->GetNumElement();
                CIcone * icone = pIconeList.at(numIcone);
                if (icone != nullptr)
                {
                    CThumbnailData * pThumbnailData = icone->GetData();
                    if (pThumbnailData != nullptr)
                    {
                        CThreadLoadingBitmap * pLoadBitmap = new CThreadLoadingBitmap();
                        pLoadBitmap->timePosition = pThumbnailData->GetTimePosition();
                        pLoadBitmap->percent = pThumbnailData->GetPercent();
                        pLoadBitmap->typeElement = pThumbnailData->GetTypeElement();
                        pLoadBitmap->filename = pThumbnailData->GetFilename();
                        pLoadBitmap->numIcone = numIcone;
                        pLoadBitmap->thumbnail = this;
                        pLoadBitmap->thread = new std::thread(LoadPicture, (void *)pLoadBitmap);
                        nbProcess++;
                        //listThread.push_back(thread);
                    }
                }
            }
        }
    }
        
    pBitmapIcone->RenderIcone(deviceContext);
}

void CThumbnail::UpdateScreenRatio()
{
    for (CIcone * pIcone : pIconeList)
    {
        pIcone->DestroyCache();
    }
    this->Resize();
}

void CThumbnail::OpenFileViewer(const wxString &filename)
{
	//ShellExecute(m_hWnd, L"open", filename.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void CThumbnail::OnLDoubleClick(wxMouseEvent& event)
{

		CThumbnailData * pThumbnailData = nullptr;


		int xPos = event.GetX();
		int yPos = event.GetY();

		CIcone * pBitmapIcone = FindElement(xPos, yPos);
		if (pBitmapIcone != nullptr)
		{
			pThumbnailData = pBitmapIcone->GetData();
			if (pThumbnailData != nullptr)
			{
				switch (pThumbnailData->GetTypeElement())
				{
					case TYPEPHOTO:
					{
						OpenFileViewer(pThumbnailData->GetFilename());
					}
					break;
				}
			}
		}


}

void CThumbnail::OnLButtonDown(wxMouseEvent& event)
{
	wxWindowDC winDC(this);
	this->SetFocus();
	int xPos = event.GetX();
	int yPos = event.GetY();

		if (numSelect != nullptr)
		{
			numSelect->SetSelected(false);
			numSelect->RenderIcone(&winDC);
		}

		CIcone * pBitmapIcone = FindElement(xPos, yPos);
		if (pBitmapIcone != nullptr)
		{
			numSelect = pBitmapIcone;
            pBitmapIcone->OnClick(xPos, yPos);
            //
            OnPictureClick(pBitmapIcone->GetData());
            pBitmapIcone->SetSelected(true);
            pBitmapIcone->RenderIcone(&winDC);
		}
		else
		{
			FindOtherElement(&winDC, xPos, yPos);
		}


}




void CThumbnail::OnLoading(wxTimerEvent& event)
{
    stepLoading += 1;
    if (stepLoading == m_animation->GetFrameCount())
        stepLoading = 0;

    loadingIcone->SetPictureLoading(m_animation->GetFrame(stepLoading));
    this->Refresh();
}

void CThumbnail::StartLoadingPicture(const int &numItem)
{
    if(loadingIcone != nullptr)
       loadingIcone->StopLoadingPicture();
    
    if (numItem >= pIconeList.size())
        return;

    
    loadingIcone = pIconeList.at(numItem);
    
    stepLoading = 0;
    showLoadingBitmap = true;
    
    loadingTimer->Start(50);
    loadingIcone->StartLoadingPicture();
}

void CThumbnail::StopLoadingPicture()
{
    if(loadingIcone != nullptr)
    {
        loadingIcone->StopLoadingPicture();
    }
    
    showLoadingBitmap = false;
    if (loadingTimer->IsRunning())
        loadingTimer->Stop();
    
    this->Refresh();
}

void CThumbnail::OnPaint(wxPaintEvent& event)
{
    wxBufferedPaintDC dc(this);
    wxRect rc;
    rc.x = 0;
    rc.y = 0;
    rc.width = width;
    rc.height = height;

    UpdateScroll();
    FillRect(&dc, rc, themeThumbnail.colorBack);
    RenderIcone(&dc);

    

}

void CThumbnail::Resize()
{
	CalculControlSize();
	this->Refresh();
}

void CThumbnail::CalculControlSize()
{
	controlWidth = GetWidth();
	controlHeight = GetHeight();
	scrollbar->SetControlSize(controlWidth, controlHeight);
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void CThumbnail::TestMaxX()
{
	long xValue = GetWidth() - width;

	if (posLargeur >= xValue)
		posLargeur = xValue;

	if (posLargeur < 0)
		posLargeur = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void CThumbnail::TestMaxY()
{
	long yValue = GetHeight() - height;

	if (posHauteur >= yValue)
		posHauteur = yValue;

	if (posHauteur < 0)
		posHauteur = 0;
}


void CThumbnail::OnKeyDown(wxKeyEvent& event)
{


		switch (event.m_keyCode)
		{
		case WXK_UP:
			this->MoveTop();
			break;
		case WXK_LEFT:
			this->MoveLeft();
			break;
		case WXK_DOWN:
			this->MoveBottom();
			break;
		case WXK_RIGHT:
			this->MoveRight();
			break;

		}

}

void CThumbnail::OnMouseWheel(wxMouseEvent& event)
{

    
#ifdef __APPLE__
    
    if (event.m_wheelRotation == 1)
        this->MoveTop();
    else if (event.m_wheelRotation == -1)
        this->MoveBottom();
    
#else
    
    if (event.m_wheelRotation == 120)
        this->MoveTop();
    else
        this->MoveBottom();
    
#endif
    

}



void CThumbnail::InitScrollingPos()
{
    if(posHauteur < 0)
        posHauteur = 0;
    
    if(posLargeur < 0)
        posLargeur = 0;
}

void CThumbnail::UpdateRenderIcone(wxCommandEvent& event)
{
    CThreadLoadingBitmap * threadLoadingBitmap = (CThreadLoadingBitmap *)event.GetClientData();
    
    if(threadDataProcess != false && threadLoadingBitmap != nullptr)
    {
        
        if (threadLoadingBitmap->bitmapIcone != nullptr)
        {
            CIcone * icone = pIconeList.at(threadLoadingBitmap->numIcone);
            if (icone != nullptr)
            {
                CThumbnailData * pThumbnailData = icone->GetData();
                if (pThumbnailData != nullptr)
                {
                    if (pThumbnailData->GetTypeElement() == TYPEVIDEO)
                        pThumbnailData->SetTimePosition(threadLoadingBitmap->timePosition);
                    
                    pThumbnailData->SetBitmap(threadLoadingBitmap->bitmapIcone);
                    
                    //wxWindowDC winDC(this);
                    pThumbnailData->SetIsLoading(false);
                    
                    wxFileName filename(pThumbnailData->GetFilename());
                    wxString file = filename.GetFullName();
                    wxString info = L"Render : " + file;
                    if (statusbar != nullptr)
                        statusbar->SetText(1, info);
                    
                    icone->DestroyCache();
                    
                    wxWindowDC winDC(this);
                    icone->RenderIcone(&winDC);
                }
            }
        }
    }
    
    if (threadLoadingBitmap->bitmapIcone != nullptr)
    {
        delete(threadLoadingBitmap->bitmapIcone);
        threadLoadingBitmap->bitmapIcone = nullptr;
    }
    
    if (threadLoadingBitmap->type == 0)
    {
        if (threadLoadingBitmap->thread != nullptr)
        {
            if (threadLoadingBitmap->thread->joinable())
                threadLoadingBitmap->thread->join();
            
            delete threadLoadingBitmap->thread;
            
            threadLoadingBitmap->thread = nullptr;
        }
    }
    else
    {
        muThreadMain.lock();
        
        if (threadMain->joinable())
            threadMain->join();
        
        delete threadMain;
        
        threadMain = nullptr;
        
        muThreadMain.unlock();
    }
    
    if (threadLoadingBitmap->type == 0)
        nbProcess--;
    
    if (threadLoadingBitmap != nullptr)
    {
        delete threadLoadingBitmap;
        threadLoadingBitmap = nullptr;
    }
}

void CThumbnail::KillThreadIcone(wxCommandEvent& event)
{
	CThreadLoadingBitmap * threadLoadingBitmap = (CThreadLoadingBitmap *)event.GetClientData();

	if (threadLoadingBitmap->type == 0)
	{
		if (threadLoadingBitmap->thread != nullptr)
		{
			if (threadLoadingBitmap->thread->joinable())
				threadLoadingBitmap->thread->join();

			delete threadLoadingBitmap->thread;

			threadLoadingBitmap->thread = nullptr;
		}
	}
	else
	{
		muThreadMain.lock();

		if (threadMain->joinable())
			threadMain->join();

		delete threadMain;

		threadMain = nullptr;

		muThreadMain.unlock();
	}

	if (threadLoadingBitmap->type == 0)
		nbProcess--;
	
	if (threadLoadingBitmap != nullptr)
	{
		delete threadLoadingBitmap;
		threadLoadingBitmap = nullptr;
	}


}