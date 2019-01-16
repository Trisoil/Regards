#pragma once

#include <queue>
#include <deque>
using namespace std;

class CRegardsBitmap;

#define TYPEPHOTO 1
#define TYPECATALOG 2
#define TYPECATEGORIE 3
#define TYPECRITERIA 4
#define TYPEFOLDER 5
#define TYPEVIDEO 6
#define TYPEFACE 7
#define SQLITE 1

class CImageLoadingFormat;

class CThumbnailData
{
public:
	CThumbnailData(const wxString & filename);
	virtual ~CThumbnailData(void);

	virtual int GetType() = 0;

	void SetNumPhotoId(const int &id);
	int GetNumPhotoId();

	void SetNumElement(const int &iNumElement);
	int GetNumElement();

	wxString GetFilename();
	void SetFilename(const wxString &filename);

	virtual void SetBitmap(CImageLoadingFormat * bitmap) = 0;
	virtual wxImage GetwxImage() = 0;

	void SetTypeElement(const int &typeElement);
	int GetTypeElement();

	void SetNumCatalog(const int &numCatalog);
	int GetNumCatalog();

	void SetNumCategorie(const int &numCategorie);
	int GetNumCategorie();

	void SetNumParent(const int &numParent);
	int GetNumParent();

	void SetKey(const wxString &key);
	wxString GetKey();

	bool IsLoading();
	void SetIsLoading(const bool &isLoading);

	bool IsProcess();
	void SetIsProcess(const bool &isProcess);

	bool IsLoad();
	void InitLoadState()
	{
		pictureLoad = false;
		pictureLoading = false;
	}

	int GetPercent();
	void SetPercent(const int &percent);

	void SetTimePosition(const int &timePosition);
	int GetTimePosition();
	wxString GetTimePositionLibelle();
    
    virtual int GetNbFrame()
    {
        return 1;
    }
    
    virtual int GetNumFrame()
    {
        return numFrame;
    }
    
    virtual void SetNumFrame(const int &numFrame)
    {
        this->numFrame = numFrame;
    }

protected:

	virtual bool TestBitmap() = 0;
	int numCatalog;
	bool pictureLoad;
	bool pictureLoading;
	wxString filename;
	int numElement;
	int numPhotoId;
	wxString folder;
	wxString key;
	wxString libelleTimePosition;
	int numCategorie;
	int numParent;
	int typeElement;
	int timePosition;
	int percent;
	bool isProcess;
    int numFrame = 0;

};

typedef std::vector<CThumbnailData *> ThumbnailDataVector;
typedef deque<CThumbnailData *, allocator<CThumbnailData *> > DequeueThumbnailData;
typedef queue<CThumbnailData *, DequeueThumbnailData> QueueThumbnailData;