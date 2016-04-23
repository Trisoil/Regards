#pragma once
#include <FolderCatalog.h>
#include "SqlExecuteRequest.h"
#include "SqlResult.h"

namespace Regards
{
	namespace Sqlite
	{
		class CSqlFindFolderCatalog : public CSqlExecuteRequest
		{
		public:
			CSqlFindFolderCatalog();
			~CSqlFindFolderCatalog();
			bool GetFolderCatalog(FolderCatalogVector * catalogfolderVector, const int &numCatalog);
			int GetNbFolderCatalog(const int &numCatalog);

		private:

			int TraitementResult(CSqlResult * sqlResult);
			FolderCatalogVector * m_catalogFolderVector;
			int nbCatalog;
			int typeRequest;
		};
	}
}

