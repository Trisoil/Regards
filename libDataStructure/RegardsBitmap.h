// IBitmap.h: interface for the CRegardsBitmap class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#include "RGBAQuad.h"
#define DEPTHDEFO 32
#define SIZE_PATH 1024


class CRegardsBitmap
{
public:

	CRegardsBitmap(const int &iWidth, const int &iHeight, const int &iDepth = 32);
	CRegardsBitmap();
	virtual ~CRegardsBitmap();

	CRegardsBitmap& operator=(const CRegardsBitmap& other);

	void ReadFile(const wxString &filename);
	void WriteFile(const wxString &filename);
	
#ifdef WIN32

	void SaveToBmp(const wxString &filename);

#endif

	bool IsValid();

	//Gestion Exif
	bool RotateExif(const int & orientation = 0);
	bool RotateRawExif(const int & orientation= 0);
    //bool RotateAppleExif(const int & orientation = 0);

	//Rotation
	bool Rotation90();

	//Flip
	bool HorzFlipBuf();
	bool VertFlipBuf();

	//wxBitmap GetwxBitmap();

	wxString GetFilename();
	void SetFilename(const wxString & szFilename);

    CRgbaquad GetColorValue(const int &x, const int &y) const;
	CRgbaquad * GetPtColorValue(const int &x, const int &y);
	void SetColorValue(const int &x, const int &y, const CRgbaquad &color);
    void SetAlphaValue(const int &value);
	void SetBitmap(uint8_t * m_bBuffer, const unsigned int &bmWidth, const unsigned int &bmHeight, const bool &m_bFlip = false, const bool &copy = true);
	void SetBitmap(CRgbaquad * m_bBuffer, const unsigned int &bmWidth, const unsigned int &bmHeight, const bool &m_bFlip = false);
	void SetBitmap(const int &iWidth, const int &iHeight, const int &iDepth = 32);

	uint8_t * GetPtBitmap();
	long GetBitmapSize();

	const long GetWidthSize();
	const int GetBitmapWidth();
	const int GetBitmapHeight();
	const short GetBitmapDepth();
	void ConvertToBgr();
	inline int GetPosition(const int &x, const int &y) const;

	//Crop
	CRegardsBitmap * CropBitmap(const int &xPos, const int &yPos, const int &width, const int &height);

	//Background Color
	void SetBackgroundColor(const CRgbaquad &m_cValue);

	//Insertion d'une image Bitmap
	int InsertBitmap(CRegardsBitmap * CRegardsBitmap, int xPos, int yPos, const bool &withalpha = true);
	int InsertwxImage(const wxImage & bitmap, int xPos, int yPos);
	int InsertBitmapWithoutAlpha(CRegardsBitmap * picture, int xPos, int yPos);

	//Fusion de deux images Bitmap
	int FusionBitmap(CRegardsBitmap * nextPicture, const float &pourcentage);

	int SetColorTranspBitmap(const CRgbaquad & Transp);
	void SetBackgroundBitmap(CRegardsBitmap * background, const int &xStart = 0, const int &yStart = 0);
	int SetValueToTranspColor(const CRgbaquad & backgroundValue);

	/*
	const bool GetNeedRotate();
	void SetNeedRotate(const bool & needRotate);
	*/

	int GetOrientation();
	void SetOrientation(const int &orientation);

protected:
	
	//HBITMAP GetFlipBitmap(const BOOL &bLateral);
	
	wxString filename;
	int m_iWidth;
	int m_iHeight;
	long m_lSize;
	short m_sDepth;
	bool transparent;
	uint8_t * data;
	int orientation;
	//bool needRotate;

};


