#pragma once
#include "TreeElement.h"
#include <TreeData.h>
#include "Tree.h"
#include "PositionElement.h"
#include "TreeElementTriangle.h"
#include "TreeElementSlide.h"
#include "TreeElementDelete.h"
#include "TreeElementTexte.h"
#include "TreeElementTexteClick.h"
#include "TreeElementCheckBox.h"
#include "TreeElementListBox.h"
#include "TreeElementSlideInterface.h"
#include "TreeElementControlInterface.h"

namespace Regards
{
	namespace Window
	{
		class CTreeControl : public CTreeElementSlideInterface
		{

		public:
			CTreeControl(){ nbRow = 0;};
			CTreeControl(CThemeTree * theme, CTreeElementControlInterface * interfaceControl);
			virtual ~CTreeControl();

			CTreeControl& operator=(const CTreeControl &other);

			virtual void SlidePosChange(CTreeElement * treeElement, const int &position, CTreeElementValue * value, const wxString &key) = 0;
			void GenerateWindowBitmap(wxDC * deviceContext, const int &width, const int &height, const int &posLargeur, const int &posHauteur);
			CPositionElement * FindElement(const int &x, const int &y);

			int GetWidth();
			int GetNbRow();
			int GetWidthRow(const int &numRow);

			virtual void MouseOver(wxDC * deviceContext, CPositionElement * element, const int &x, const int &y, const int& posLargeur, const int &posHauteur)
			{
				if (element != nullptr)
				{
					CTreeElement * treeElement = element->GetTreeElement();
					if (treeElement != nullptr)
						treeElement->MouseOver(deviceContext, x, y);
				}
			}

			virtual void MouseOut(wxDC * deviceContext, CPositionElement * element, const int &x, const int &y, const int& posLargeur, const int &posHauteur){};
			virtual void ClickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur){};
			virtual void UnclickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur){};
			virtual void DoubleClickOnElement(CPositionElement * element){};
			virtual void AfterDrawBitmap(){};
            virtual void UpdateScreenRatio() = 0;
		protected:
            
            wxColour GetBackgroundColour(const int &yPos);

			//Tree Window
			tree<CTreeData *>::iterator FindKey(const wxString & key, tree<CTreeData *>::iterator &parent);
			tree<CTreeData *>::iterator FindKey(const wxString & key);
			void EraseChildTree(tree<CTreeData *>::sibling_iterator &parent);
			void ClearData();

			CPositionElement * CreatePositionElement(const int &x, const int &y, const int &numColumn, const int &numRow, const int &width, const int &height, const int &type, CTreeElement * treeElement, CTreeData * treeData, const bool &dynamic = true);
			CPositionElement * GetElement(CTreeData * data, const int &typeElement);
			
			CTreeElementListBox * CreateListBoxElement(const int &width, const int &height, const vector<CMetadata> & value, const int &index, const wxString &exifKey);
            CTreeElementTexteClick * CreateTexteLinkElement(const int &width, const int &height, const wxString &libelle, const wxString &link, const int &linkType);
			CTreeElementDelete * CreateDeleteElement(const int &width, const int &height);
			CTreeElementTriangle * CreateTriangleElement(const int &width, const int &height, const bool &open);
			CTreeElementTexte * CreateTexteElement(const int &width, const int &height, const wxString &libelle);
			CTreeElementSlide * CreateSlideElement(const int &width, const int &height, CTreeElementValue * position, vector<CTreeElementValue *> * value, const wxString &exifKey);
			CTreeElementCheckBox * CreateCheckBoxElement(const int &width, const int &height, const bool &check);

			//Element de rendu pour l'arbre
			tree<CTreeData *> tr;
			PositionElementVector vectorPosElement;
			PositionElementVector vectorPosElementDynamic;

			CThemeTree themeTree;
			vector<int> rowWidth;
			int nbRow;
			CTreeElementControlInterface * eventControl;
		};
	}
}

