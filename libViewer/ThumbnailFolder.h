#pragma once
#include <ThumbnailVertical.h>
#include "InfosSeparationBarExplorer.h"
using namespace Regards::Control;

#define SHOW_ALL 0
#define SHOW_BYYEAR 1
#define SHOW_BYMONTH 2
#define SHOW_BYDAY 3
#define SHOW_BYLOCALISATION 4

namespace Regards
{
	namespace Viewer
	{
		class CMainFrame;

		class CThumbnailFolder : public CThumbnailVertical
		{
		public:
			CThumbnailFolder(wxWindow* parent, wxWindowID id, IStatusBarInterface * statusBarInterface, const CThemeThumbnail & themeThumbnail, const bool &testValidity);
			virtual ~CThumbnailFolder(void);
			void Init(PhotosVector * photoVector, const int &typeAffichage = SHOW_ALL);
            void SetActifItem(const int &numItem, const bool &move);  
		protected:
			void ResizeThumbnail();
			void ResizeThumbnailWithVScroll();
			void ResizeThumbnailWithoutVScroll();
		private:
            
			void SetListeFile(PhotosVector * photoVector);
			void ShowByMonth(PhotosVector* photoVector, int &nbElement);
			void ShowByYear(PhotosVector * photoVector, int &nbElement);
			void ShowByLocalisation(PhotosVector * photoVector, int &nbElement);
			void ShowByDay(PhotosVector * photoVector, int &nbElement);
			void AddSeparatorBar(const wxString &libelle, PhotosVector * photoVector, int &nbElement);
			CIcone * FindElementWithVScroll(const int &xPos, const int &yPos);
			void OnPictureClick(CThumbnailData * data);
			CIcone * FindIcone(const int &photoId);
			void FindOtherElement(wxDC * dc, const int &x, const int &y);
			CIcone * FindElement(const int &xPos, const int &yPos);
			CInfosSeparationBar * FindSeparatorElement(const int &xPos, const int &yPos);
			void RenderIconeWithVScroll(wxDC * dc);
			void RenderIconeWithoutVScroll(wxDC * deviceContext);
			int Dayofweek(const int & d, const int & m, const int & y);
			void UpdateScrollWithVScroll();
			void InitTypeAffichage(PhotosVector * photoVector, const int &typeAffichage);
			PhotosVector GetPhotoByCriteria(PhotosVector * photoVector, const wxString & criteria, int &index);
			PhotosVector GetPhotoByLocalisation(PhotosVector * photoVector, const wxString & criteria, const wxString & localisation, int &index);
			
			
			InfosSeparationBarVector listSeparator;

			int barseparationHeight;
			int widthThumbnail;
			int heightThumbnail;
		};
	}
}


