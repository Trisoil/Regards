#pragma once

#define JPEGOUTPUT 1
#define BITMAPOUTPUT 2

class CxMemFile;

class CRegardsRaw
{
public:
	CRegardsRaw();
	~CRegardsRaw();

	static void GetDimensions(const string & fileName, int & width, int & height);
	static CxMemFile * GetThumbnail(const string & fileName, int &outputFormat);
};

