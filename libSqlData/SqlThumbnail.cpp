#include <header.h>
#include "SqlThumbnail.h"
#include "SqlLib.h"
#include "SqlEngine.h"
#include <RegardsBitmap.h>
#include <jpgd.h>
#include <wx/mstream.h>
using namespace jpgd;
using namespace Regards::Sqlite;

CSqlThumbnail::CSqlThumbnail()
	: CSqlExecuteRequest(L"RegardsDB")
{
	regardsBitmap = nullptr;
	type = 0;
	find = false;
}


CSqlThumbnail::~CSqlThumbnail()
{
}

CPictureData * CSqlThumbnail::GetJpegThumbnail(const wxString & path)
{
	type = 5;
	wxString fullpath = path;
	fullpath.Replace("'", "''");
	ExecuteRequest("SELECT thumbnail FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "'");
	return picture;
}

bool CSqlThumbnail::TestThumbnail(const wxString & path, const wxString &hash)
{
	type = 2;
	wxString fullpath(path);
	fullpath.Replace("'", "''");
	ExecuteRequest("SELECT FullPath FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "' and hash = '" + hash + "'");
	if (!find)
	{
		DeleteThumbnail(path);
	}
	return find;
}

bool CSqlThumbnail::TestThumbnail(const wxString & path)
{
	type = 2;
	wxString fullpath(path);
	fullpath.Replace("'", "''");
	ExecuteRequest("SELECT FullPath FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "'");
	if (!find)
	{
		DeleteThumbnail(path);
	}
	return find;
}



bool CSqlThumbnail::InsertThumbnail(const wxString & path, const uint8_t * zBlob, const int &nBlob, const int & width, const int &height, const wxString &hash)
{
	wxString fullpath = path;
	fullpath.Replace("'", "''");
	return ExecuteInsertBlobData("INSERT INTO PHOTOSTHUMBNAIL (FullPath, width, height, hash, thumbnail) VALUES('" + fullpath + "'," + to_string(width) + "," + to_string(height) + ",'" + hash + "', ? )", 4, zBlob, nBlob);
}

wxImage CSqlThumbnail::GetThumbnail(const wxString & path)
{
	type = 1;
	wxString fullpath = path;
	fullpath.Replace("'", "''");
	ExecuteRequest("SELECT FullPath, width, height, hash, thumbnail FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "'");
	return bitmap;
}

CRegardsBitmap * CSqlThumbnail::GetPictureThumbnail(const wxString & path, const int &typePicture)
{
	type = typePicture;
	wxString fullpath = path;
	fullpath.Replace("'", "''");
	ExecuteRequest("SELECT FullPath, width, height, hash, thumbnail FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "'");
	return regardsBitmap;
}

bool CSqlThumbnail::DeleteThumbnail(const wxString & path)
{
	wxString fullpath = path;
	fullpath.Replace("'", "''");
	return (ExecuteRequestWithNoResult("DELETE FROM PHOTOSTHUMBNAIL WHERE FullPath = '" + fullpath + "'") != -1) ? true : false;
}

bool CSqlThumbnail::DeleteThumbnail(const int & numPhoto)
{
	return (ExecuteRequestWithNoResult("DELETE FROM PHOTOSTHUMBNAIL WHERE FullPath in (SELECT FullPath FROM PHOTOS WHERE NumPhoto = " + to_string(numPhoto) + ")") != -1) ? true : false;
}

bool CSqlThumbnail::EraseThumbnail()
{
	return (ExecuteRequestWithNoResult("DELETE FROM PHOTOSTHUMBNAIL") != -1) ? true : false;
}

bool CSqlThumbnail::EraseFolderThumbnail(const int &numFolder)
{
	//return (ExecuteRequestWithNoResult("DELETE FROM PHOTOSTHUMBNAIL") != -1) ? true : false;
	return (ExecuteRequestWithNoResult("DELETE FROM PHOTOSTHUMBNAIL WHERE FullPath in (SELECT FullPath FROM PHOTOS WHERE NumFolderCatalog = " + to_string(numFolder) + ")") != -1) ? true : false;
}

int CSqlThumbnail::TraitementResult(CSqlResult * sqlResult)
{
	int nbResult = 0;
	while (sqlResult->Next())
	{
		int width;
		int height;
		wxString hash = "";
		wxString filename = "";

		switch (type)
		{
		case 4:
		case 3:
		case 1:
			for (auto i = 0; i < sqlResult->GetColumnCount(); i++)
			{

				switch (i)
				{
				case 0:
					filename = sqlResult->ColumnDataText(i);
					break;
				case 1:
					width = sqlResult->ColumnDataInt(i);
					break;
				case 2:
					height = sqlResult->ColumnDataInt(i);
					break;
				case 3:
					hash = sqlResult->ColumnDataText(i);
					break;
				case 4:
				{
					int size = sqlResult->ColumnDataBlobSize(i);
					if (size > 0)
					{		
						const int req_comps = 4;
						int actual_comps = 4;
						uint8_t * data = new uint8_t[size];
						sqlResult->ColumnDataBlob(i, (void * &)data, size);
						if (type == 1)
						{
							wxMemoryInputStream jpegStream(data, size);
							bitmap.LoadFile(jpegStream, wxBITMAP_TYPE_JPEG);
						}
						else if (type == 3)
						{
							uint8_t * dest = decompress_jpeg_image_from_memory(data, size, &width, &height, &actual_comps, req_comps);
							regardsBitmap = new CRegardsBitmap();
							regardsBitmap->SetBitmap(dest, width, height, false, true);
							regardsBitmap->SetFilename(filename);
							regardsBitmap->VertFlipBuf();
							regardsBitmap->ConvertToBgr();
							delete[] dest;

						}
						else if (type == 4)
						{
							uint8_t * dest = decompress_jpeg_image_from_memory(data, size, &width, &height, &actual_comps, req_comps);
							regardsBitmap = new CRegardsBitmap();
							regardsBitmap->SetBitmap(dest, width, height, false, true);
							regardsBitmap->SetFilename(filename);
							delete[] dest;
						}
						delete[] data;
					}
				}
				break;
				}
			}
			break;

		case 2:
			for (auto i = 0; i < sqlResult->GetColumnCount(); i++)
			{
				switch (i)
				{
				case 0:
					find = true;
					break;
				}
			}
			break;
		case 5:
			for (auto i = 0; i < sqlResult->GetColumnCount(); i++)
			{
				switch (i)
				{
				case 0:
					picture = new CPictureData();
					find = true;
					picture->size = sqlResult->ColumnDataBlobSize(i);
					if (picture->size > 0)
					{	
						
						picture->data = new uint8_t[picture->size+1];
						sqlResult->ColumnDataBlob(i, (void * &)picture->data, picture->size);
					}
					break;
				}
			}
			break;
		}

		nbResult++;
	}
	return nbResult;
};