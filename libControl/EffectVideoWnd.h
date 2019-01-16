#pragma once
#include <TreeControl.h>
#include <EffectVideoParameter.h>
using namespace Regards::Window;

namespace Regards
{
	namespace Control
	{
		class CEffectVideoWnd : public CTreeControl
		{
		public:

			CEffectVideoWnd(CVideoEffectParameter * videoEffectParameter, CThemeTree * theme, CTreeElementControlInterface * interfaceControl);
			~CEffectVideoWnd(void);
			void Init();
			void SlidePosChange(CTreeElement * treeElement, const int &position, const int &value, const wxString &key);

		private:

			void CreateElement();
			void CreateChildTree(tree<CTreeData *>::sibling_iterator &parent);
			void UpdateElement();
			void UpdateChildTree(tree<CTreeData *>::sibling_iterator &parent);


			void AddTreeInfos(const wxString &exifKey, const int &position, const vector<int> & value, const int &index, tree<CTreeData *>::iterator &top, tree<CTreeData *>::iterator &child, const int &type);

			void MouseOver(wxDC * deviceContext, CPositionElement * element, const int &x, const int &y, const int& posLargeur, const int &posHauteur);
			void ClickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur);
			void UnclickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur);

			int yPos;
			int cxMax;
			int cyMax;
			int widthPosition;
			wxString effectMedianLevel;
			wxString effectSharpenLevel;
			wxString toneConstrastLevel;
			wxString toneExposureLevel;
			wxString toneBrightnessLevel;
			wxString colorBoostRed;
			wxString colorBoostGreen;
			wxString colorBoostBlue;

			CVideoEffectParameter * videoEffectParameter;
		};
	}
}