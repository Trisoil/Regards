// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole DLLPICTURE_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// DLLPICTURE_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#pragma once

class CxImage;
class CRegardsBitmap;
class CVideoThumbnail;
class CImageLoadingFormat;
class CImageVideoThumbnail;

class CLibPicture
{

public:

    CLibPicture();
    virtual ~CLibPicture();

    void DefineSVGSize(const int &width, const int &height);
    bool HasThumbnail(const wxString &filename);
    
	int TestImageFormat(const wxString & szFileName);
	bool TestIsVideo(const wxString & szFileName);
	bool TestIsPicture(const wxString & szFileName);
    bool TestIsAnimation(const wxString & szFileName);
	int GetPictureDimensions(const  wxString & fileName, int & width, int & height, int & rotation);
	CImageLoadingFormat * LoadPicture(const  wxString & szFileName,const bool &isThumbnail = false);
	int SavePicture(const  wxString & fileName, CRegardsBitmap * bitmap);
	int GetMetadata(const wxString &filename, uint8_t * & data, long & size);
	//CRegardsBitmap * LoadThumbnailOnlyFromPicture(const  wxString & fileName, int &returnValue);
	vector<CImageVideoThumbnail *> LoadDefaultVideoThumbnail(const  wxString & szFileName);
	CImageLoadingFormat * LoadThumbnail(const  wxString & szFileName, const bool &fromExifOnly = false);
	vector<CImageVideoThumbnail *> LoadAllVideoThumbnail(const  wxString & szFileName);
	CImageLoadingFormat * LoadVideoThumbnail(const  wxString & szFileName, const int &percent, int &timePosition);

	//CRegardsBitmap * LoadThumbnailFromBuffer(uint8_t * data, size_t size, const char * ext, const int &orientation);
	bool TestIsExifCompatible(const wxString &filename);
	int SavePictureOption(const int &format, int &option, int &quality);
	int SavePicture(const  wxString & fileName, CRegardsBitmap * bitmap,const int &option, const int &quality);

	//-----------------------------------------------------------------------
	//Fonction de conversion
	//-----------------------------------------------------------------------
	CxImage * ConvertwxImageToCxImage(const wxImage & image);
	CRegardsBitmap * ConvertCXImageToRegardsBitmap(CxImage * image);
	CRegardsBitmap * ConvertCXImageToScaleRegardsBitmap(CxImage * image, const int &width, const int &height);
	CxImage * ConvertRegardsBitmapToCXImage(CRegardsBitmap * bitmap);
	CRegardsBitmap * ConvertCXImageToRegardsBitmap(CxImage * image, const int &orientation);
	CRegardsBitmap * ConvertwxImageToRegardsBitmap(const wxImage & image);
	CRegardsBitmap * ConvertCXImageToScaleRegardsBitmapBGR(CxImage * image, const int &width, const int &height);
	CRegardsBitmap * ConvertCXImageToScaleRegardsBitmapCRgbaquad(CxImage * image, const int &width, const int &height);
	wxImage * ConvertRegardsBitmapToWXImage(CRegardsBitmap * image, const bool &loadAlpha = false);
	static float CalculPictureRatio(const int &pictureWidth, const int &pictureHeight, const int &width, const int &height);
	void LoadAllVideoThumbnail(const  wxString & szFileName, vector<CImageVideoThumbnail *> * listThumbnail);
    static void Initx265Decoder();
    static void Uninitx265Decoder();    
    
#ifdef LIBBPG
#if defined(WIN32) && not defined(__MINGW32__)
#else
    static void LoadBpgDll();
    static void UnloadBpgDll();
#endif
#endif
    
private:

    float clamp(float val, float minval, float maxval);
	uint8_t * readfile(const wxString & fileName, size_t&size);
	void writefile(const wxString & fileName, uint8_t * data, size_t & size);
	//-----------------------------------------------------------------------------
	//Liste des fonctions de la DLL
	//-----------------------------------------------------------------------------
	int TestExtension(const wxString & ext);
#ifdef LIBRAW
	CImageLoadingFormat * LoadThumbnailFromRawPicture(const wxString & szFilename, const int &width, const int &height, int &returnValue);
#endif
	
    int svgWidth;
    int svgHeight;
    
    
#ifdef LIBBPG
#if defined(WIN32) && not defined(__MINGW32__)
#else
    static void * lib_handle;
#endif
#endif
    
    
};
