#include "header.h"
#include "SqlExecuteRequest.h"
#include "SqlLib.h"
#include "SqlEngine.h"
#include <LibResource.h>
using namespace Regards::Sqlite;

CSqlExecuteRequest::CSqlExecuteRequest(const wxString & databaseName)
{
	useTransaction = false;
	this->databaseName = databaseName;
}


CSqlExecuteRequest::~CSqlExecuteRequest()
{
}


bool CSqlExecuteRequest::ExecuteInsertBlobData(const wxString &requestSQL, const int &numCol, const void * zBlob, const int &nBlob)
{
//	int nbResult = 0;			// Error code reporting

	if (useTransaction)
	{
		CSqlResult sqlResult;
		bool hr = _sqlLibTransaction->ExecuteSQLBlobInsert(requestSQL, numCol, zBlob, nBlob, &sqlResult);

		if (hr)
		{
			_sqlLibTransaction->Release();
			return hr;
		}
	}
	else
	{

		CSqlResult sqlResult;
		CSqlLib * _sqlLib = CSqlEngine::getInstance(databaseName);
		_sqlLib->lock();
		bool hr = _sqlLib->ExecuteSQLBlobInsert(requestSQL, numCol, zBlob, nBlob, &sqlResult);

		if (hr)
		{
			_sqlLib->Release();
			_sqlLib->unlock();
			return hr;
		}
		_sqlLib->unlock();
	}
	return false;
}

//-------------------------------------------------------------------------------------------------
// Execution d'une requete qui n'attend pas de résultat
//-------------------------------------------------------------------------------------------------
int CSqlExecuteRequest::ExecuteRequestWithNoResult(const wxString &requestSQL)
{
  //  wxString query;
    //query.append(requestSQL.begin(), requestSQL.end());
    
	int nbResult = 0;			// Error code reporting
	if (useTransaction)
	{
		nbResult = _sqlLibTransaction->ExecuteSQLWithNoResult(requestSQL);
	}
	else
	{
		CSqlLib * _sqlLib = CSqlEngine::getInstance(databaseName);
        if(_sqlLib != nullptr)
        {
            _sqlLib->lock();
            nbResult = _sqlLib->ExecuteSQLWithNoResult(requestSQL);
            _sqlLib->unlock();
        }
	}
	return nbResult;
}

void CSqlExecuteRequest::BeginTransaction()
{
	_sqlLibTransaction = CSqlEngine::getInstance(databaseName);
	_sqlLibTransaction->BeginTransaction();
	_sqlLibTransaction->lock();
	useTransaction = true;
}

void CSqlExecuteRequest::CommitTransection()
{
	_sqlLibTransaction->CommitTransection();
	useTransaction = false;
	_sqlLibTransaction->unlock();
}

int64_t CSqlExecuteRequest::GetLastId()
{
	int64_t value;
	if (useTransaction)
	{
		value = _sqlLibTransaction->GetLastId();
	}
	else
	{
		CSqlLib * _sqlLib = CSqlEngine::getInstance(databaseName);
        if(_sqlLib != nullptr)
        {
            _sqlLib->lock();
            value = _sqlLib->GetLastId();
            _sqlLib->unlock();
        }
		else
		{
            wxString database_error = CLibResource::LoadStringFromResource(L"DatabaseCorrupt",1);
			wxMessageBox(database_error);
			exit(1);
		}
    
	}
	return value;
}

int CSqlExecuteRequest::ExecuteRequest(const wxString &requestSQL)
{
	int nbResult = 0;			// Error code reporting

	if (useTransaction)
	{
		CSqlResult sqlResult;
		bool hr = _sqlLibTransaction->ExecuteSQLSelect(requestSQL, &sqlResult);

		if (hr)
		{
			nbResult = TraitementResult(&sqlResult);
			_sqlLibTransaction->Release();
			return nbResult;
		}
	}
	else
	{

		CSqlResult sqlResult;
		CSqlLib * _sqlLib = CSqlEngine::getInstance(databaseName);
        if(_sqlLib != nullptr)
        {
            _sqlLib->lock();
            bool hr = _sqlLib->ExecuteSQLSelect(requestSQL, &sqlResult);

            if (hr)
            {
                nbResult = TraitementResult(&sqlResult);
                _sqlLib->Release();
                _sqlLib->unlock();
                return nbResult;
            }
            _sqlLib->unlock();
        }
	}
	return 0;
}

