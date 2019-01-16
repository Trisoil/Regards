#pragma once
#include "Icone.h"
#include <ThumbnailData.h>
#include <Photos.h>
class CRegardsBitmap;
class CThumbnailData;


namespace Regards
{
	namespace Window
	{
		class CInfosSeparationBar
		{
		public:
			CInfosSeparationBar(const CThemeInfosSeparationBar &theme);
			virtual ~CInfosSeparationBar(void);

			inline bool operator== (const CInfosSeparationBar &n1);

            const wxString & GetTitle()
            {
                return title;
            }
			void Clear();
			void SetTitle(const wxString &title);
			void SetWindowPos(const int &x, const int &y);
			void SetWidth(const int &width);
			virtual void OnClick(const int &x, const int &y);
			int GetXPos();
			int GetYPos();
			const int & GetWidth();
			const int & GetHeight();
			wxRect GetPos();
            void Render(wxDC * dc, const int &posLargeur, const int &posHauteur);
			
			
			vector<int> listElement;

		protected:
            virtual void RenderIcone(wxDC * dc, const int &posLargeur, const int &posHauteur);
			void RenderTitle(wxDC * dc);

			int _xPos;
			int _yPos;
			int width;

			CThemeInfosSeparationBar theme;
			
			wxString title;
			wxRect titleRectPos;
			
		};
		typedef std::vector<CInfosSeparationBar *> InfosSeparationBarVector;

	}
}
