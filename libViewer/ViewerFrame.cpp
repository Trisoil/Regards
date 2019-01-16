#include "ViewerFrame.h"
#include "MainWindow.h"
#include "PertinenceValue.h"
#include <BitmapPrintout.h>
#include "ViewerParamInit.h"
#include "SQLRemoveData.h"
#include <PrintEngine.h>
#include <LibResource.h>
#if defined(__WXMSW__)
#include "../include/window_id.h"
#else
#include <window_id.h>
#endif
#include <wx/filename.h>
#include <wx/dirdlg.h>
#include <ConfigRegards.h>
#include "ViewerParamInit.h"
#include "ViewerThemeInit.h"
#include "ViewerParam.h"
#include "ViewerTheme.h"
#include <RegardsConfigParam.h>
#include <ParamInit.h>
#include <FileUtility.h>
#include <SQLRemoveData.h>
#include <SqlFindPhotos.h>
#include <SqlFindFolderCatalog.h>
#include <OpenCLDialog.h>
#include <FilterData.h>
using namespace std;
using namespace Regards::Print;
using namespace Regards::Control;
using namespace Regards::Viewer;
using namespace Regards::Sqlite;

#define TIMER_LOADPICTURE 2
#if !wxUSE_PRINTING_ARCHITECTURE
#error "You must set wxUSE_PRINTING_ARCHITECTURE to 1 in setup.h, and recompile the library."
#endif


// constants:
enum
{
	ID_Hello = 1,
	ID_Folder = 2,
	ID_Configuration = 3,
	ID_OpenCL = 4,
    ID_SIZEICONLESS = 5,
    ID_SIZEICONMORE = 6,
	ID_ERASEDATABASE = 7,
	ID_THUMBNAILRIGHT = 8,
	ID_THUMBNAILBOTTOM = 9,
	ID_FACEPERTINENCE = 10,
	ID_BOXFILTER=1001,
	ID_BILINEARFILTER=1002,
	ID_GAUSSIANFILTER=1003,
	ID_HAMMINGFILTER=1004,
	ID_CUBICFILTER=1005,
	ID_BLACKMANFILTER=1006,
	ID_QUADRATICFILTER=1007,
	ID_MITCHELLFILTER=1008,
	ID_TRIANGLEFILTER=1009,
	ID_SINCFILTER=1010,
	ID_BESSELFILTER=1011,
	ID_BLACKMANBESSELFILTER=1012,
	ID_BLACKMANSINCFILTER=1013,
	ID_LANCZOSFILTER=1014,
	ID_HERMITEFILTER=1015,
	ID_HANNINGFILTER=1016,
	ID_CATROMFILTER=1017,
	ID_VIDEO = 1018,
	ID_AUDIO = 1019,
	ID_SUBTITLE = 1020,
	WXPRINT_PAGE_SETUP,
	WXPRINT_PAGE_SETUP_PS,
#ifdef __WXMAC__
	WXPRINT_PAGE_MARGINS,
#endif
};

#include <ctype.h>
#include "wx/metafile.h"
#include "wx/print.h"
#include "wx/printdlg.h"
#include "wx/image.h"
#include "wx/accel.h"

#if wxUSE_POSTSCRIPT
#include "wx/generic/printps.h"
#include "wx/generic/prntdlgg.h"
#endif

#if wxUSE_GRAPHICS_CONTEXT
#include "wx/graphics.h"
#endif

#ifdef __WXMAC__
#include "wx/osx/printdlg.h"
#endif


#ifndef wxHAS_IMAGES_IN_RESOURCES
#ifdef __WXGTK__
#include "../Resource/sample.xpm"
#else
#include "../../Resource/sample.xpm"
#endif
#endif


bool CViewerFrame::viewerMode = true;

using namespace Regards::Viewer;

bool CViewerFrame::GetViewerMode()
{
    return viewerMode;
}

void CViewerFrame::SetViewerMode(const bool &mode)
{
    viewerMode = mode;
}

void CViewerFrame::OpenFile(const wxString &fileToOpen)
{
	FolderCatalogVector folderList;
	CSqlFindFolderCatalog folderCatalog;
	folderCatalog.GetFolderCatalog(&folderList, NUMCATALOGID);
    bool find = false;
    wxFileName filename(fileToOpen);
    wxString folder = filename.GetPath();

    for (CFolderCatalog folderlocal : folderList)
    {
        if (folder == folderlocal.GetFolderPath())
        {
            find = true;
            break;
        }
    }

    if (find)
        mainWindow->SetSelectFile(fileToOpen);
    else
    {
        //mainWindow->AddFolder(folder);
        wxString * newFolder = new wxString(folder);
        wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_SETFOLDER);
        evt.SetClientData(newFolder);
        mainWindow->OnAddFolder(evt);
        mainWindow->SetSelectFile(fileToOpen);
    }
}

CViewerFrame::CViewerFrame(const wxString& title, const wxPoint& pos, const wxSize& size, IMainInterface * mainInterface, const wxString &fileToOpen)
	: wxFrame(nullptr, wxID_ANY, title, pos, size, wxMAXIMIZE | wxDEFAULT_FRAME_STYLE)
{
	picture = nullptr;
	fullscreen = false;
	onExit = false;
	mainWindowWaiting = nullptr;
	SetIcon(wxICON(sample));

	viewerParam = new CViewerParam();
	CViewerParamInit::Initialize(viewerParam);

	viewerTheme = new CViewerTheme();
	CViewerThemeInit::Initialize(viewerTheme);

	this->mainInterface = mainInterface;

	FolderCatalogVector folderList;
	CSqlFindFolderCatalog folderCatalog;
	folderCatalog.GetFolderCatalog(&folderList, NUMCATALOGID);

	exitTimer = new wxTimer(this, wxTIMER_EXIT);
	Connect(wxTIMER_EXIT, wxEVT_TIMER, wxTimerEventHandler(CViewerFrame::CheckAllProcessEnd), nullptr, this);

	bool folderChange = false;

	//Test de la validité des répertoires
	for (CFolderCatalog folderlocal : folderList)
	{
		if (!wxDirExists(folderlocal.GetFolderPath()))
		{
			//Remove Folder
			CSQLRemoveData::DeleteFolder(folderlocal.GetNumFolder());
			folderChange = true;
		}
	}

	//Test de la validité des fichiers
	PhotosVector photoList;
	CSqlFindPhotos findphotos;
	findphotos.GetAllPhotos(&photoList);
	for (CPhotos photo : photoList)
	{
		if (!wxFileExists(photo.GetPath()))
		{
			//Remove Folder
			CSQLRemoveData::DeletePhoto(photo.GetId());
			folderChange = true;
		}
	}

	if (folderChange)
	{
		CViewerParam * viewerParam = (CViewerParam *)CViewerParamInit::getInstance();
		wxString sqlRequest = viewerParam->GetLastSqlRequest();

		CSqlFindPhotos sqlFindPhotos;
		sqlFindPhotos.SearchPhotos(sqlRequest);
	}


	//SetIcon(wxIcon(wxT("regards.xpm")));
	mainWindow = new CMainWindow(this, MAINVIEWERWINDOWID, this);
	
	//mainWindow->Show(true);
	//mainWindowWaiting->Show(false);
	//preview = nullptr;
	m_previewModality = wxPreviewFrame_AppModal;
	loadPictureTimer = new wxTimer(this, TIMER_LOADPICTURE);
	wxMenu *menuFile = new wxMenu;
	wxMenu *menuParameter = new wxMenu;
    
    /*
	wxMenu * menuInterpolation = new wxMenu;
	menuInterpolation->Append(ID_BOXFILTER, "Box Filter", "Box Filter");
	menuInterpolation->Append(ID_BILINEARFILTER, "Bilinear Filter", "Box Filter");
	menuInterpolation->Append(ID_GAUSSIANFILTER, "Gaussian Filter", "Gaussian Filter");
	menuInterpolation->Append(ID_HAMMINGFILTER, "Hamming Filter", "Hamming Filter");
	menuInterpolation->Append(ID_CUBICFILTER, "Cubic Filter", "Cubic Filter");
	menuInterpolation->Append(ID_BLACKMANFILTER, "Blackman Filter", "Blackman Filter");
	menuInterpolation->Append(ID_QUADRATICFILTER, "Quadratic Filter", "Quadratic Filter");
	menuInterpolation->Append(ID_MITCHELLFILTER, "Mitchell Filter", "Mitchell Filter");
	menuInterpolation->Append(ID_TRIANGLEFILTER, "Triangle Filter", "Triangle Filter");
	menuInterpolation->Append(ID_SINCFILTER, "Sinc Filter", "Sinc Filter");
	menuInterpolation->Append(ID_BESSELFILTER, "Bessel Filter", "Bessel Filter");
	menuInterpolation->Append(ID_BLACKMANBESSELFILTER, "Blackman Filter", "Blackman Filter");
	menuInterpolation->Append(ID_BLACKMANSINCFILTER, "Blackman Sinc Filter", "Blackman Sinc Filter");
	menuInterpolation->Append(ID_LANCZOSFILTER, "Lanczos Filter", "Lanczosc Filter");
	menuInterpolation->Append(ID_HERMITEFILTER, "Hermite Filter", "Hermite Filter");
	menuInterpolation->Append(ID_HANNINGFILTER, "Hanning Filter", "Hanning Filter");
	menuInterpolation->Append(ID_CATROMFILTER, "Catrom Filter", "Catrom Filter");
    */
    
    wxString labelDecreaseIconSize = CLibResource::LoadStringFromResource(L"labelDecreaseIconSize",1);//L"Decrease Icon Size";
    wxString labelDecreaseIconSize_link = CLibResource::LoadStringFromResource(L"labelDecreaseIconSize_link",1);//L"&Decrease Icon Size";
    wxString labelEnlargeIconSize = CLibResource::LoadStringFromResource(L"labelEnlargeIconSize",1);//L"Enlarge Icon Size";
    wxString labelEnlargeIconSize_link = CLibResource::LoadStringFromResource(L"labelEnlargeIconSize_link",1);//L"&Enlarge Icon Size";
    wxString labelConfiguration = CLibResource::LoadStringFromResource(L"labelConfiguration",1);//L"Configuration";
    wxString labelConfiguration_link = CLibResource::LoadStringFromResource(L"labelConfiguration_link",1);//L"&Configuration";
    wxString labelOpenCL = CLibResource::LoadStringFromResource(L"labelOpenCL",1);//L"OpenCL";
    wxString labelOpenCL_link = CLibResource::LoadStringFromResource(L"labelOpenCL_link",1);//L"&OpenCL";
    wxString labelEraseDataBase = CLibResource::LoadStringFromResource(L"labelEraseDataBase",1);//L"Erase Database";
    wxString labelEraseDataBase_link = CLibResource::LoadStringFromResource(L"labelEraseDataBase_link",1);//L"&Erase Database";
    wxString labelThumbnailRight = CLibResource::LoadStringFromResource(L"labelThumbnailRight",1);//L"Right Position";
    wxString labelThumbnailRight_link = CLibResource::LoadStringFromResource(L"labelThumbnailRight_link",1);//L"&Right Position";
    wxString labelThumbnailBottom = CLibResource::LoadStringFromResource(L"labelThumbnailBottom",1);//L"Bottom Position";
    wxString labelThumbnailBottom_link = CLibResource::LoadStringFromResource(L"labelThumbnailBottom_link",1);//L"&Bottom Position";
    wxString labelPageSetup = CLibResource::LoadStringFromResource(L"labelPageSetup",1);//L"Page setup";
    wxString labelPageSetup_link = CLibResource::LoadStringFromResource(L"labelPageSetup_link",1);//L"Page Set&up...";
    wxString labelPageMargins =CLibResource::LoadStringFromResource(L"labelPageMargins",1);// L"Page margins";
    wxString labelPageMargins_link = CLibResource::LoadStringFromResource(L"labelPageMargins_link",1);//L"Page margins...";
    wxString labelFile = CLibResource::LoadStringFromResource(L"labelFile",1);//L"&File";
    wxString labelParameter = CLibResource::LoadStringFromResource(L"labelParameter",1);//L"&Parameter";
    wxString labelSizeIcon = CLibResource::LoadStringFromResource(L"labelSizeIcon",1);//L"&Icon Size";
    wxString labelThumbnail = CLibResource::LoadStringFromResource(L"labelThumbnail",1);//L"&Thumbnail";
    wxString labelHelp = CLibResource::LoadStringFromResource(L"labelHelp",1);//L"&Help";
    
    wxMenu *menuSizeIcon = new wxMenu;
    menuSizeIcon->Append(ID_SIZEICONLESS, labelDecreaseIconSize_link, labelDecreaseIconSize);
    menuSizeIcon->Append(ID_SIZEICONMORE, labelEnlargeIconSize_link, labelEnlargeIconSize);
	menuParameter->Append(ID_Configuration, labelConfiguration_link, labelConfiguration);
	menuParameter->Append(ID_OpenCL, labelOpenCL_link, labelOpenCL);
    menuParameter->Append(ID_ERASEDATABASE, labelEraseDataBase_link, labelEraseDataBase);

	wxMenu *menuThumbnail = new wxMenu;
	menuThumbnail->Append(ID_THUMBNAILRIGHT, labelThumbnailRight_link, labelThumbnailRight);
	menuThumbnail->Append(ID_THUMBNAILBOTTOM, labelThumbnailBottom_link, labelThumbnailBottom);
	
	//wxMenu *menuFace = new wxMenu;
	//menuFace->Append(ID_FACEPERTINENCE, "&Face Pertinence", "Face Pertinence");

	//menuFile->Append(wxID_PRINT, wxT("&Print..."), wxT("Print"));
	menuFile->Append(WXPRINT_PAGE_SETUP, labelPageSetup_link, labelPageSetup);
#ifdef __WXMAC__
	menuFile->Append(WXPRINT_PAGE_MARGINS, labelPageMargins_link, labelPageMargins);
#endif
	//menuFile->Append(wxID_PREVIEW, wxT("Print Pre&view"), wxT("Preview"));
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
    menuHelp->Append(wxID_HELP);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, labelFile);
	menuBar->Append(menuParameter, labelParameter);
    menuBar->Append(menuSizeIcon, labelSizeIcon);
	menuBar->Append(menuThumbnail, labelThumbnail);
	//menuBar->Append(menuFace, "&Face");
	//menuBar->Append(menuVideoBar, "&Video");
	//menuBar->Append(menuInterpolation, "&Interpolation");
	menuBar->Append(menuHelp, labelHelp);
	SetMenuBar(menuBar);

	SetLabel(wxT("Regards Viewer"));
	Connect(wxEVT_SIZE, wxSizeEventHandler(CViewerFrame::OnSize));
	Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(CViewerFrame::OnClose));
	mainWindow->Bind(wxEVT_CHAR_HOOK, &CViewerFrame::OnKeyDown, this);
	


	if (fileToOpen != "")
	{
        OpenFile(fileToOpen);
	}
	else
	{
		
		if (folderList.size() == 0)
		{
			mainWindow->OpenFolder();
		}
	}
    
    mainInterface->HideAbout();
	Connect(TIMER_LOADPICTURE, wxEVT_TIMER, wxTimerEventHandler(CViewerFrame::OnTimerLoadPicture), nullptr, this);
}

void CViewerFrame::OnClose(wxCloseEvent& event)
{
    //onExit = true;
    //mainInterface->Close();
	Exit();
}

void CViewerFrame::OnTimerLoadPicture(wxTimerEvent& event)
{
	mainWindow->ImageSuivante();
	loadPictureTimer->Stop();
}

void CViewerFrame::OnHelp(wxCommandEvent& event)
{
    wxString helpFile = CFileUtility::GetResourcesFolderPath();
    helpFile.Append("//NoticeRegardsViewer.pdf");
    wxLaunchDefaultApplication(helpFile);
}

void CViewerFrame::CheckAllProcessEnd(wxTimerEvent& event)
{
	nbTime++;

	if(nbTime < 50)
	{
		for (CMasterWindow * window : CMasterWindow::listMainWindow)
		{
			if(!window->GetProcessEnd())
			{
				wxString message = window->GetWaitingMessage();
				mainWindowWaiting->SetTexte(message);
				exitTimer->Start(1000, wxTIMER_ONE_SHOT);
				return;
			}
		}
	}

	onExit = true;
	Exit();
}

void CViewerFrame::Exit()
{
    if(!onExit)
    {
		nbTime = 0;
		CWindowMain::SetEndProgram();
		mainWindowWaiting = new CWaitingWindow(this, wxID_ANY);
		mainWindow->Show(false);
		mainWindowWaiting->Show(true);
		mainWindowWaiting->SetSize(0, 0, mainWindow->GetWindowWidth(), mainWindow->GetWindowHeight());
		mainWindowWaiting->Refresh();

		exitTimer->Start(1000, wxTIMER_ONE_SHOT);
	}
	else
	{
        CViewerThemeInit::SaveTheme();
		mainInterface->Close();
		onExit = true;

    }
    

}

void CViewerFrame::OnKeyDown(wxKeyEvent& event)
{
	if (event.m_keyCode == WXK_ESCAPE && fullscreen)
	{
		mainWindow->SetScreen();
	}
	else
	{
		switch (event.GetKeyCode())
		{
			case WXK_ESCAPE:
			{
				mainWindow->SetScreen();
			}
			break;

			case WXK_PAGEUP:
			{
                printf("Image Suivante \n");
				mainWindow->ImageSuivante();
			}
			break;

			case WXK_PAGEDOWN:
			{
				mainWindow->ImagePrecedente();
			}
			break;


			case WXK_SPACE:
			{
                printf("Image Suivante \n");
				mainWindow->ImageSuivante();
				//if (!loadPictureTimer->IsRunning())
				//	loadPictureTimer->Start(10);
			}
			break;

			case WXK_END:
			{
				mainWindow->ImageFin();
			}
			break;

			case WXK_HOME:
			{
				mainWindow->ImageDebut();
			}
			break;

			case WXK_F5:
			{
				if (!fullscreen)
				{
					mainWindow->SetFullscreen();
					fullscreen = true;
				}
			}
			break;

		}
	}

	/*
	if (event.m_keyCode == WXK_ESCAPE && fullscreen)
	{
		mainWindow->SetScreen();
	}
	else if (event.m_keyCode == WXK_SPACE)
	{
		//mainWindow->ImageSuivante(); 
	}
	*/
	event.Skip();
}

void CViewerFrame::SetFullscreen()
{
	fullscreen = true;
	this->ShowFullScreen(true);
	mainWindow->SetFullscreenMode();
}

void CViewerFrame::SetScreen()
{
	fullscreen = false;
	this->ShowFullScreen(false);
}

void CViewerFrame::SetWindowTitle(const wxString &libelle)
{
	SetLabel(libelle);
}

CViewerFrame::~CViewerFrame()
{
	if(picture != nullptr)
		delete picture;

	if (exitTimer->IsRunning())
		exitTimer->Stop();

	delete exitTimer;

	if (loadPictureTimer->IsRunning())
		loadPictureTimer->Stop();

	delete(loadPictureTimer);

	if (mainWindow != nullptr)
		delete(mainWindow);

	if(mainWindowWaiting != nullptr)
		delete(mainWindowWaiting);

	if (viewerTheme != nullptr)
		delete(viewerTheme);

	viewerParam->SaveFile();


	if (viewerParam != nullptr)
		delete(viewerParam);

    
    if(!onExit)
        Exit();
}

void CViewerFrame::SetText(const int &numPos, const wxString &libelle)
{
	if (mainWindow != nullptr)
		mainWindow->SetText(numPos, libelle);
}

void CViewerFrame::SetRangeProgressBar(const int &range)
{
	if (mainWindow != nullptr)
		mainWindow->SetRangeProgressBar(range);
}

void CViewerFrame::SetPosProgressBar(const int &position)
{
	if (mainWindow != nullptr)
		mainWindow->SetPosProgressBar(position);
}

void CViewerFrame::OnConfiguration(wxCommandEvent& event)
{
	CRegardsConfigParam * regardsParam = (CRegardsConfigParam*)CParamInit::getInstance();
	int pictureSize = regardsParam->GetFaceDetectionPictureSize();
	ConfigRegards configFile(this);
	configFile.ShowModal();
	if (configFile.IsOk())
	{
		int newPictureSize = regardsParam->GetFaceDetectionPictureSize();
		if(pictureSize != newPictureSize)
		{
			//Suppression de toutes les Faces
			CSQLRemoveData::DeleteFaceDatabase();
            mainWindow->OnFacePertinence();
			

			wxWindow * window = this->FindWindowById(CRITERIAFOLDERWINDOWID);
			if (window)
			{
				wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_UPDATECRITERIA);
				evt.SetExtraLong(0);
				window->GetEventHandler()->AddPendingEvent(evt);
			}
		}
	}
}

void CViewerFrame::OnOpenCLConfiguration(wxCommandEvent& event)
{
	OpenCLDialog configFile(this);
	configFile.ShowModal();
	if (configFile.IsOk())
	{
        wxString labelRestart = CLibResource::LoadStringFromResource(L"labelRestart",1);//L"&Thumbnail";
        wxString labelInformations = CLibResource::LoadStringFromResource(L"labelInformations",1);//L"&Help";
		CRegardsConfigParam * config = CParamInit::getInstance();
		if (config != nullptr)
		{
			config->SetOpenCLPlatformIndex(configFile.GetDeviceIndex());
			config->SetOpenCLPlatformName(configFile.GetPlatformName());
		}
        wxMessageBox(labelRestart,labelInformations);
	}
}



void CViewerFrame::OnIconSizeLess(wxCommandEvent& event)
{
    float ratio = 1.0;
    CRegardsConfigParam * config = CParamInit::getInstance();
    if(config != nullptr)
    {
        ratio = config->GetIconSizeRatio();
        if(ratio > 1.0)
            ratio = ratio - 0.25;
        config->SetIconSizeRatio(ratio);
        
        mainWindow->UpdateScreenRatio();
        //this->FastRefresh(this);
    }
    
}

void CViewerFrame::OnIconSizeMore(wxCommandEvent& event)
{
    float ratio = 1.0;
    CRegardsConfigParam * config = CParamInit::getInstance();
    if(config != nullptr)
    {
        ratio = config->GetIconSizeRatio();
        if(ratio < 2.0)
            ratio = ratio + 0.25;
        config->SetIconSizeRatio(ratio);
        
        mainWindow->UpdateScreenRatio();
        //this->FastRefresh(this);
    }
}

void CViewerFrame::OnExit(wxCommandEvent& event)
{
    //onExit = true;
    //mainInterface->Close();
	Exit();

}
void CViewerFrame::OnAbout(wxCommandEvent& event)
{
	mainInterface->ShowAbout();
}

void CViewerFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

void CViewerFrame::PrintPreview(CRegardsBitmap * imageToPrint)
{
	// Pass two printout objects: for preview, and possible printing.
	wxPrintData * g_printData = CPrintEngine::GetPrintData();
	wxPrintDialogData printDialogData(*g_printData);

	if(picture != nullptr)
		delete picture;

	this->picture = imageToPrint;
	wxPrintPreview * preview = new wxPrintPreview(new CBitmapPrintout(picture), new CBitmapPrintout(picture), &printDialogData);
	if (!preview->IsOk())
	{
		delete preview;
		wxLogError(wxT("There was a problem previewing.\nPerhaps your current printer is not set correctly?"));
		return;
	}

    wxString picture_print_label = CLibResource::LoadStringFromResource(L"PicturePrintPreview",1);
	wxPreviewFrame *frame =
		new wxPreviewFrame(preview, this, picture_print_label, wxPoint(100, 100), wxSize(600, 650));
	frame->Centre(wxBOTH);
	frame->InitializeWithModality(m_previewModality);
	frame->Show();
}

void CViewerFrame::OnEraseDatabase(wxCommandEvent& event)
{
    wxString erasedatabase = CLibResource::LoadStringFromResource(L"EraseDatabase",1);
    wxString informations = CLibResource::LoadStringFromResource(L"labelInformations",1);
	if (wxMessageBox(erasedatabase, informations, wxYES_NO | wxICON_WARNING) == wxYES)
	{
		CSQLRemoveData::DeleteCatalog(1);
		if (mainWindow != nullptr)
		{
			wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_REFRESHFOLDER);
			mainWindow->GetEventHandler()->AddPendingEvent(evt);
		}

		CListFace * listFace = (CListFace *)this->FindWindowById(LISTFACEID);
		if(listFace != nullptr)
		{
			wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, wxEVENT_THUMBNAILREMOVE);
			listFace->GetEventHandler()->AddPendingEvent(evt);
		}
	}
}

void CViewerFrame::OnPageSetup(wxCommandEvent& WXUNUSED(event))
{
	wxPrintData * g_printData = CPrintEngine::GetPrintData();
	wxPageSetupDialogData * g_pageSetupData = CPrintEngine::GetPageSetupDialogData();
	(*g_pageSetupData) = *g_printData;

	wxPageSetupDialog pageSetupDialog(this, g_pageSetupData);
	pageSetupDialog.ShowModal();

	(*g_printData) = pageSetupDialog.GetPageSetupDialogData().GetPrintData();
	(*g_pageSetupData) = pageSetupDialog.GetPageSetupDialogData();
}

void CViewerFrame::OnFacePertinence(wxCommandEvent& event)
{
	CViewerParam * viewerParam = (CViewerParam *)CViewerParamInit::getInstance();
	double pertinence = 0.0;
	if(viewerParam != nullptr)
	{
		pertinence = viewerParam->GetPertinenceValue();
		PertinenceValue configFile(this);
		configFile.SetValue(pertinence);
		configFile.ShowModal();
		if (configFile.IsOk())
		{
			viewerParam->SetPertinenceValue(configFile.GetValue());
			mainWindow->OnFacePertinence();
		}
	}
}

void CViewerFrame::OnThumbnailBottom(wxCommandEvent& event)
{
	mainWindow->OnThumbnailBottom();
}

void CViewerFrame::OnThumbnailRight(wxCommandEvent& event)
{
	mainWindow->OnThumbnailRight();
}

void CViewerFrame::BoxFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(BOXFILTER);
}
void CViewerFrame::BilinearFilter(wxCommandEvent& event)
{
	mainWindow->SetFilterInterpolation(BILINEARFILTER);
}
void CViewerFrame::GaussianFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(GAUSSIANFILTER);
}
void CViewerFrame::HammingFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(HAMMINGFILTER);
}
void CViewerFrame::CubicFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(CUBICFILTER);
}
void CViewerFrame::BlackmanFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(BLACKMANFILTER);
}
void CViewerFrame::QuadraticFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(QUADRATICFILTER);
}
void CViewerFrame::MitchellFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(MITCHELLFILTER);
}
void CViewerFrame::TriangleFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(TRIANGLEFILTER);
}
void CViewerFrame::SincFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(SINCFILTER);
}
void CViewerFrame::BesselFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(BESSELFILTER);
}
void CViewerFrame::BlackmanBesselFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(BLACKMANBESSELFILTER);
}
void CViewerFrame::BlackmanSincFilter(wxCommandEvent& event){

	mainWindow->SetFilterInterpolation(BLACKMANSINCFILTER);
}
void CViewerFrame::LanczosFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(LANCZOSFILTER);
}
void CViewerFrame::HermiteFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(HERMITEFILTER);
}
void CViewerFrame::HanningFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(HANNINGFILTER);
}
void CViewerFrame::CatromFilter(wxCommandEvent& event){
	mainWindow->SetFilterInterpolation(CATROMFILTER);
}

#ifdef __WXMAC__
void CViewerFrame::OnPageMargins(wxCommandEvent& WXUNUSED(event))
{
    wxPrintData * g_printData = CPrintEngine::GetPrintData();
    wxPageSetupDialogData * g_pageSetupData = CPrintEngine::GetPageSetupDialogData();
    (*g_pageSetupData) = *g_printData;

	wxMacPageMarginsDialog pageMarginsDialog(this, g_pageSetupData);
	pageMarginsDialog.ShowModal();

	(*g_printData) = pageMarginsDialog.GetPageSetupDialogData().GetPrintData();
	(*g_pageSetupData) = pageMarginsDialog.GetPageSetupDialogData();
}
#endif

wxBEGIN_EVENT_TABLE(CViewerFrame, wxFrame)
EVT_MENU(ID_Hello, CViewerFrame::OnHello)
EVT_MENU(wxID_HELP, CViewerFrame::OnHelp)
EVT_MENU(ID_Configuration, CViewerFrame::OnConfiguration)
EVT_MENU(ID_OpenCL, CViewerFrame::OnOpenCLConfiguration)
EVT_MENU(ID_SIZEICONLESS, CViewerFrame::OnIconSizeLess)
EVT_MENU(ID_SIZEICONMORE, CViewerFrame::OnIconSizeMore)
EVT_MENU(ID_THUMBNAILBOTTOM, CViewerFrame::OnThumbnailBottom)
EVT_MENU(ID_THUMBNAILRIGHT, CViewerFrame::OnThumbnailRight)
EVT_MENU(ID_FACEPERTINENCE, CViewerFrame::OnFacePertinence)
EVT_MENU(ID_ERASEDATABASE, CViewerFrame::OnEraseDatabase)
EVT_MENU(wxID_ABOUT, CViewerFrame::OnAbout)
EVT_MENU(WXPRINT_PAGE_SETUP, CViewerFrame::OnPageSetup)
EVT_MENU(wxID_EXIT, CViewerFrame::OnExit)
EVT_MENU(ID_BOXFILTER, CViewerFrame::BoxFilter)
EVT_MENU(ID_BILINEARFILTER,CViewerFrame::BilinearFilter)
EVT_MENU(ID_GAUSSIANFILTER,CViewerFrame::GaussianFilter)
EVT_MENU(ID_HAMMINGFILTER,CViewerFrame::HammingFilter)
EVT_MENU(ID_CUBICFILTER,CViewerFrame::CubicFilter)
EVT_MENU(ID_BLACKMANFILTER,CViewerFrame::BlackmanFilter)
EVT_MENU(ID_QUADRATICFILTER,CViewerFrame::QuadraticFilter)
EVT_MENU(ID_MITCHELLFILTER,CViewerFrame::MitchellFilter)
EVT_MENU(ID_TRIANGLEFILTER,CViewerFrame::TriangleFilter)
EVT_MENU(ID_SINCFILTER,CViewerFrame::SincFilter)
EVT_MENU(ID_BESSELFILTER,CViewerFrame::BesselFilter)
EVT_MENU(ID_BLACKMANBESSELFILTER,CViewerFrame::BlackmanBesselFilter)
EVT_MENU(ID_BLACKMANSINCFILTER,CViewerFrame::BlackmanSincFilter)
EVT_MENU(ID_LANCZOSFILTER,CViewerFrame::LanczosFilter)
EVT_MENU(ID_HERMITEFILTER,CViewerFrame::HermiteFilter)
EVT_MENU(ID_HANNINGFILTER,CViewerFrame::HanningFilter)
EVT_MENU(ID_CATROMFILTER,CViewerFrame::CatromFilter)
#ifdef __WXMAC__
	EVT_MENU(WXPRINT_PAGE_MARGINS, CViewerFrame::OnPageMargins)
#endif
wxEND_EVENT_TABLE()

