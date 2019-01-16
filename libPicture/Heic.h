#pragma once
#ifdef LIBHEIC
class CRegardsBitmap;
class CxMemFile;

class CHeic
{
public:
	CHeic();
	~CHeic();
    static void Initx265Decoder();
    static void Uninitx265Decoder();
	static int GetNbFrame(const string &filename);
	static vector<CRegardsBitmap *> GetAllPicture(const string &filename, bool &isMasterSequence, int &delay);
	static CRegardsBitmap * GetPicture(const string &filename);
	static CRegardsBitmap * GetThumbnailPicture(const string &filename);
	static void GetPictureDimension(const string &filename, int &width, int &height);
	static void GetMetadata(const string &filename, uint8_t * & data, long & size);
private:
	static CRegardsBitmap * DecodeFrame(void * data, int length, void * externDecoder = nullptr);
	static void DecodePictureMultiThread(void * parameter);
};
#endif
