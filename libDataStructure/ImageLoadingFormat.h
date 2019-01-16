#pragma once
#define TYPE_IMAGE_CXIMAGE 0
#define TYPE_IMAGE_WXIMAGE 1
#define TYPE_IMAGE_REGARDSIMAGE 2
#define TYPE_IMAGE_REGARDSFLOATIMAGE 3
#define TYPE_IMAGE_REGARDSJPEGIMAGE 4
class CRegardsFloatBitmap;
class CRegardsBitmap;
class CRegardsJpegPicture;
class CxImage;
class wxImage;

class CImageLoadingFormat
{
public:
    
	CImageLoadingFormat(const bool &memoryDelete = true);
	~CImageLoadingFormat();
	void DestroyJpegData(uint8_t * data, const int & compressMethod);
	void SaveToJpeg(const wxString &filename);
	
	void SetPicturToJpeg(CRegardsBitmap * image);
	CxImage * GetCxImage(const bool &copy = true);
	wxImage * GetwxImage(const bool &copy = true);
	CRegardsBitmap * GetRegardsBitmap(const bool &copy = true);
	CRegardsFloatBitmap * GetFloatBitmap(const bool &copy = true);

	uint8_t * GetJpegData(unsigned long & outputsize, int &compressMethod);
	
	int Resize(const int &width, const int &height, const int &method);
    void Flip();
	void Mirror();
	void Rotate90();
	int GetWidth();
	int GetHeight();
	int GetOrientation();
	wxString GetFilename();
	int GetFormat();

	void SetOrientation(const int &orientation);
	void SetFilename(const wxString &filename);

	void SetPicture(CRegardsBitmap * image, const bool &convertToRGB24 = false);
	void SetPicture(CxImage * image);
	void SetPicture(wxImage * image);
	void SetPicture(CRegardsFloatBitmap * image);
	bool IsOk();
	void ConvertToRGB24(const bool &convert);
	void ConvertToBGR(const bool &convert);
	void ApplyExifOrientation(const int &exifMethod = 0);

protected:


	float CalculPictureRatio(const int &pictureWidth, const int &pictureHeight);
    uint8_t * CompressRegardsBitmapToJpeg(unsigned char * buffer, int width, int height, unsigned long & outputsize);
    CRegardsBitmap * _image;
	CxImage * _cxImage;
	wxImage * _wxImage;
	CRegardsFloatBitmap * _floatImage;
	CRegardsJpegPicture * _jpegImage;
    int format;
	wxString filename;
	int orientation;
	bool convertToRGB24;
	bool memoryDelete;
	bool convertToBGR;
};
