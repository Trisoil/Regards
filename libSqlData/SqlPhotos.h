#pragma once
#include "SqlExecuteRequest.h"
#include "SqlResult.h"
#include <Criteria.h>

namespace Regards
{
	namespace Sqlite
	{
		class CSqlPhotos : public CSqlExecuteRequest
		{
		public:
			CSqlPhotos(CSqlLib * _sqlLibTransaction = nullptr, const bool &useTransaction = 0);
			~CSqlPhotos();
			bool InsertPhoto(const wxString & filepath, const int64_t &idFolder);
			int64_t GetPhotoId(const wxString & filepath, const int64_t &idFolder);
			int64_t GetOrInsertPhoto(const wxString & filepath, const int64_t &idFolder);
			bool DeletePhoto(const int64_t &numPhoto);
			bool DeletePhotoFolder(const int64_t &idFolder);
			bool DeletePhotoCatalog(const int64_t &idCatalog);
			bool UpdatePhotoCriteria(const int64_t &numPhoto);
			int GetCriteriaInsert(const wxString & filepath);
			void GetPhotoCriteria(CriteriaVector * criteriaVector, const wxString & filepath);

		private:

			int TraitementResult(CSqlResult * sqlResult);
			int64_t photoId;
			int typeResult = 0;
			CriteriaVector * criteriaVector = nullptr;
		};
	}
}
