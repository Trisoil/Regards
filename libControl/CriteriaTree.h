#pragma once
#include <theme.h>
#include <TreeWindow.h>
#include <TreeElementControlInterface.h>
#include <PositionElement.h>
#include <SqlPhotoCategorie.h>

class CTreeElementTriangle;
class CTreeElementTexte;

namespace Regards
{
	namespace Control
	{
		class CCriteriaTree : public Regards::Window::CTreeControl
		{
		public:

			CCriteriaTree(CThemeTree * theme, Regards::Window::CTreeElementControlInterface * interfaceControl);
			~CCriteriaTree(void){};
			void SetFile(const wxString & filename, const int &numPhotoId);
			wxString GetFilename();
            void UpdateScreenRatio();
            void CreateElement();
            void SlidePosChange(CTreeElement * treeElement, const int &position, CTreeElementValue * value, const wxString &key){};
		private:

			void MouseOver(wxDC * dc, CPositionElement * element, const int &x, const int &y, const int& posLargeur, const int &posHauteur);
			void ClickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur);	
			void CreateChildTree(tree<CTreeData *>::sibling_iterator &parent);  
			void AddTreeInfos(const wxString &exifKey, const wxString &exifValue, const int &index, tree<CTreeData *>::iterator &top, tree<CTreeData *>::iterator &child);
            
          

			int yPos;
			//int xMargePos;
			//int cxMax;
			//int cyMax;
			//int xMaxPos;
			//int xMaxPosValue;
			//int xMinPos;
			int rotation;
            int numPhotoId;
			wxString filename;
			int widthPosition;
			static PhotoCategorieVector photoCategorieVector;
            tree<CTreeData *>::iterator top;
            tree<CTreeData *>::iterator child;

		};

	}
}