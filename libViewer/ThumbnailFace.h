#pragma once
#include <ThumbnailVertical.h>
#include "InfosSeparationBarFace.h"
#include <FaceFilePath.h>
using namespace Regards::Control;

#define SHOW_ALL 0
#define SHOW_BYYEAR 1
#define SHOW_BYMONTH 2
#define SHOW_BYDAY 3
#define SHOW_BYLOCALISATION 4

class CFaceName;

namespace Regards
{
	namespace Viewer
	{
		class CMainFrame;

		class CThumbnailFace : public CThumbnailVertical
		{
		public:
			CThumbnailFace(wxWindow* parent, wxWindowID id, IStatusBarInterface * statusBarInterface, const CThemeThumbnail & themeThumbnail, const bool &testValidity);
			virtual ~CThumbnailFace(void);
			void Init();
            void SetActifItem(const int &numItem, const bool &move); 
			void MoveFace(const wxString &faceName);

		protected:
			void ResizeThumbnail();
			void ResizeThumbnailWithVScroll();
			void MoveIcone(const int &numElement, const int &numFace);
		private:
  
			void AddSeparatorBar(const wxString &libelle, const CFaceName & faceName, const std::vector<CFaceFilePath> & listPhotoFace, int &nbElement);
			CIcone * FindElementWithVScroll(const int &xPos, const int &yPos);
			void OnPictureClick(CThumbnailData * data);
			CIcone * FindIcone(const int &photoId);
			void FindOtherElement(wxDC * dc, const int &x, const int &y);
			CIcone * FindElement(const int &xPos, const int &yPos);
			CInfosSeparationBar * FindSeparatorElement(const int &xPos, const int &yPos);
			void RenderIconeWithVScroll(wxDC * dc);
			void UpdateScrollWithVScroll();
			void DeleteEmptyFace();
			void SortSeparator(CInfosSeparationBar * infosSeparationBar);

			InfosSeparationBarVector listSeparator;
			int nbElement;
			int barseparationHeight;
			int widthThumbnail;
			int heightThumbnail;
		};
	}
}


