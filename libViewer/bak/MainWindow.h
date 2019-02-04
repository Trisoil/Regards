#pragma once
#include "Toolbar.h"
#include <StatusBarInterface.h>
#include "CentralWnd.h"
#include "FileUtility.h"
#include <EffectVideoParameter.h>
#include <mutex>
#include <chrono>
#include <thread>
#include <WindowMain.h>

using namespace Regards::Window;
using namespace std;

class CRegardsBitmap;
class CImageLoadingFormat;
class CFaceLoadData;

namespace Regards
{
	namespace Viewer
	{

		class CMainWindow;

		class CFolderFiles
		{
		public:
			vector<wxString> pictureFiles;
			wxString folderName;
		};
        
        class CThreadVideoData
        {
        public:
            
            CThreadVideoData()
            {
                mainWindow = nullptr;
            }
            
            ~CThreadVideoData()
            {
            }
            
            CMainWindow * mainWindow;
            wxString video;

        };

		class CThreadPictureData
		{
		public:

			CThreadPictureData()
			{
				mainWindow = nullptr;
				isVisible = false;
				myThread = nullptr;
                isThumbnail = false;
			}

			~CThreadPictureData()
			{
			}

			CMainWindow * mainWindow;
			wxString picture;
			bool isVisible;
            bool isThumbnail;
            thread * myThread;
		};
        
        class CBitmapReturn
        {
        public:
			CBitmapReturn()
			{
				bitmap = nullptr;
				isThumbnail = false;
				myThread = nullptr;
			};

            CImageLoadingFormat * bitmap;
            bool isThumbnail;
            thread * myThread;
        };

		class CWaitingWindow : public CWindowMain
		{
		public:
			CWaitingWindow(wxWindow* parent, wxWindowID id) : CWindowMain("CWaitingWindow",parent, id)
			{
				textToShow = "Please wait ...";
				wxString resourcePath = CFileUtility::GetResourcesFolderPath();
				//m_animation = new wxAnimation(resourcePath + "/loading.gif");
				m_animationCtrl = new wxAnimationCtrl(this, wxID_ANY);
				m_animationCtrl->Show(true);
				Connect(wxEVT_PAINT, wxPaintEventHandler(CWaitingWindow::OnPaint));

			#ifdef WIN32
				m_animationCtrl->LoadFile(resourcePath + "\\loading.gif");
			#else
				m_animationCtrl->LoadFile(resourcePath + "//loading.gif");
			#endif

				m_animationCtrl->SetBackgroundColour(wxColour("white"));
#ifdef __WXGTK__
                m_animationCtrl->Play();
#else                
				m_animationCtrl->Play(true);
#endif
			};

			~CWaitingWindow(){
				if (m_animationCtrl != nullptr)
					delete m_animationCtrl;
			};

			void Resize()
			{
				wxRect rcAffichageBitmap;

				rcAffichageBitmap.x = 0;
				rcAffichageBitmap.y = 0;
				rcAffichageBitmap.width = GetWindowWidth();
				rcAffichageBitmap.height = GetWindowHeight();

				if(m_animationCtrl->IsShown())
				{
					wxAnimation animation = m_animationCtrl->GetAnimation();
					wxSize animationSize = animation.GetSize();
        
					int xPos = rcAffichageBitmap.x + (GetWindowWidth() - animationSize.GetWidth()) / 2;
					int yPos = (GetWindowHeight() - animationSize.GetHeight()) / 2;
        
					m_animationCtrl->SetSize(xPos, yPos, animationSize.GetWidth(), animationSize.GetHeight());
				}
			};

			void SetTexte(const wxString &libelle)
			{
				textToShow = libelle;
				this->Refresh();
			}
			

		private:

			void OnPaint(wxPaintEvent& event)
			{
				CThemeFont font;
				wxPaintDC dc(this);
				//dc.SetBackgroundMode(wxTRANSPARENT);
				//dc.SetBackground(*wxTRANSPARENT_BRUSH);
				wxRect rc = GetRect();
				this->FillRect(&dc, rc, wxColour("white"));

				font.SetColorFont(wxColour("black"));
				wxSize size = CWindowMain::GetSizeTexte(&dc, textToShow, font);
				int xPos = (GetWindowWidth() - size.x) / 2;

				wxAnimation animation = m_animationCtrl->GetAnimation();
				wxSize animationSize = animation.GetSize();
				int yPos = (GetWindowHeight() - animationSize.GetHeight()) / 2;
				yPos -= size.y * 2;
				CWindowMain::DrawTexte(&dc, textToShow, xPos, yPos, font);

			}

			wxAnimationCtrl * m_animationCtrl;
			wxString textToShow;
		};

		class CMainWindow : public CWindowMain
		{
		public:
			CMainWindow(wxWindow* parent, wxWindowID id, IStatusBarInterface * statusBarViewer);
			~CMainWindow();
            void UpdateScreenRatio();
			void StartDiaporama();
			void StopDiaporama();
			void ImageSuivante();
			void ImagePrecedente();
			void ImageFin();
			void ImageDebut();
			void Reload();
			void SetFullscreen();
			void SetFullscreenMode();
			void SetScreen();
			void TransitionEnd();
			void VideoEnd();
			bool OpenFolder();
			bool IsFullscreen();
			void ShowToolbar();
			void SetIsNeedToCheck(const bool &check);
			void Exit();
			void OnShowToolbar(wxCommandEvent& event);
			void SetText(const int &numPos, const wxString &libelle);
			void SetRangeProgressBar(const int &range);
			void SetPosProgressBar(const int &position);
			void SetVideoPos(wxCommandEvent& event);
			void AddFolder(const wxString &folder);
			void OnThumbnailBottom();
			void OnThumbnailRight();
			void SetFilterInterpolation(const int &filter);
			void OnAddFolder(wxCommandEvent& event);
			void OnFacePertinence();
			void SetSelectFile(const wxString &filename);
			bool GetProcessEnd();

		private:


			void OnStatusSetText(wxCommandEvent& event);
			void OnSetRangeProgressBar(wxCommandEvent& event);
			void OnSetValueProgressBar(wxCommandEvent& event);

			void InitPictures(wxCommandEvent& event);
			void PictureClick(wxCommandEvent& event);
			void PictureClickMove(wxCommandEvent& event);
			void PictureVideoClick(wxCommandEvent& event);
			void ChangeTypeAffichage(wxCommandEvent& event);
            void CriteriaChange(wxCommandEvent& event);
			void RefreshPictureList(wxCommandEvent& event);
			void ShowPicture(wxCommandEvent& event);
			void EndPictureThread(wxCommandEvent& event);
			void OnVideoEnd(wxCommandEvent& event);
            void OnVideoStart(wxCommandEvent& event);
			
			void OnRemoveFolder(wxCommandEvent& event);
			void OnTimerDiaporama(wxTimerEvent& event);
			void OnTimerRefresh(wxTimerEvent& event);
			void OnPictureClick(wxCommandEvent& event);
            void RefreshPicture(wxCommandEvent& event);
			void Md5Checking(wxCommandEvent& event);
			void FacePhotoAdd(wxCommandEvent& event);
			void AddFacePhoto(wxCommandEvent& event);
			void RefreshCriteriaPictureList(wxCommandEvent& event);
			void FaceInfosUpdate(wxCommandEvent& event);
			void FaceClick(wxCommandEvent& event);
            void RefreshTimer(wxCommandEvent& event);
            void Resize();
			
			void ProcessIdle();
			void OnIdle(wxIdleEvent& evt);

			static void LoadingNewPicture(CThreadPictureData * pictureData);
			static void CheckMD5(void * param);
			static void FacialRecognition(void * param);

			void CheckRenderVideo();
			void CheckRenderEffect();
			void CheckRenderPreview();
			void CheckRenderTransition();

			void SetPicture(CImageLoadingFormat * bitmap, const bool &isThumbnail);
			void LoadingPicture(const wxString &filenameToShow);
			void LoadPicture(const int &numElement);
			void LoadPictureInThread(const wxString &filename, const bool &load = false);
			void UpdateInfos(CImageLoadingFormat * bitmap);
			void ExecuteRegardsShop(const wxString &filename);
            void LoadThumbnail(const wxString &filename);
			bool fullscreen ;
			CFaceLoadData * faceData;
			wxGauge * progressBar;
			wxStatusBar * statusBar;
			CToolbar * toolbar;
			CCentralWnd * centralWnd;
			wxTimer * diaporamaTimer;
			wxTimer * refreshTimer;
			IStatusBarInterface * statusBarViewer;

			wxRect posWindow;
			wxString filename;
			bool startDiaporama;
			thread * threadloadPicture;
			//thread * threadMD5;
			//thread * threadFacePhoto;
			mutex muPicture;
			int nbProcessMD5;
			int nbProcessFacePhoto;
            
			CPictureData * LoadPictureToJpeg(const wxString &filename, bool &pictureOK, const int &resizeWidth = 0, const int &resizeHeight = 0);
			float CalculPictureRatio(const int &pictureWidth, const int &pictureHeight, const int &widthOutput, const int &heightOutput);
            wxString GetFilePath(const int &numElement);
            void FindFileIndex(const wxString & filename);
            void OnLoadPicture();
            
			PhotosVector pictures;
			//int nbElement = 0;
			int numElement;
			wxString firstFileToShow;
			bool showToolbar;
			CViewerParam * viewerParam;
            bool multithread;
            bool needToReload;
            wxString filenameTimer;
			int typeAffichage;
			bool updateCriteria;
			bool updateFolder;
			bool updatePicture;
			bool refreshFolder;
			int numElementTraitement;
			bool start;
			bool criteriaSendMessage;
			wxString photoCancel;
			bool videoStart;
			bool sendMessageVideoStop;
			bool loadPicture;
			bool processLoadPicture;
			bool loadFacePicture;

		};
	}

}
