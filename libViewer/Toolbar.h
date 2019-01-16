#pragma once
#include <ToolbarWindow.h>
using namespace Regards::Window;

class CRegardsBitmap;

namespace Regards
{
	namespace Viewer
	{
		class CToolbar : public CToolbarWindow
		{
		public:
			CToolbar(wxWindow* parent, wxWindowID id, const CThemeToolbar & theme);
			~CToolbar();

		private:

			void EventManager(const int &id);

		};
	}
}