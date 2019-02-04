#pragma once
#include <EffectParameter.h>
#include <IFiltreEffet.h>
#include <OpenCLContext.h>

using namespace Regards::OpenCL;

class CImageLoadingFormat;
class CDecodeRawParameter;
class CDecodeRaw;
class CRegardsFloatBitmap;
class CRegardsBitmap;

class CFiltreEffet
{
public:
	CFiltreEffet(const CRgbaquad &backColor, wxWindow * parent, COpenCLContext * openCLContext, CImageLoadingFormat * bitmap);
	virtual ~CFiltreEffet();
	void GetRgbaBitmap(void * cl_image);
	//void SetBitmap(CRegardsBitmap * & pBitmap, int numLib);
	void SetBitmap(CImageLoadingFormat * bitmap);
	void SetPreview(const bool &value);
	//wxImage RenderEffectPreview(const int &numEffect, CEffectParameter * effectParameter){};
	int RenderEffect(const int &numEffect, CEffectParameter * effectParameter);
	int RenderEffectPreview(const int &numEffect, CEffectParameter * effectParameter);
	wxImage RenderEffectPreviewwxImage(const int &numEffect, CEffectParameter * effectParameter);
	int SharpenMasking(const float &sharpness);
	int HistogramLog();
	int HistogramNormalize();
	int HistogramEqualize();
    bool OpenCLHasEnoughMemory();
	int WaveFilter(int x, int y, short height, int scale, int radius);
	int NiveauDeGris();
	int NoirEtBlanc();
	int Sepia();
	int Soften();
	int Blur(const int &radius);
	int GaussianBlur(const int &radius, const int &boxSize);
	int Emboss();
	int SharpenStrong();
	int Sharpen();
	int Erode();
    int BestExposure(const float &tmoValue);
    int FilterKuwahara(const int &kernelSize);
    int FilterBilateral2DS(const float & sigma_s, const float & sigma_r);
	int Median();
	int Noise();
	int Dilate();
	int Negatif();
	int RedEye(const wxRect& rSelectionBox);
	int FiltreEdge();
	int FiltreMosaic();
	int FlipVertical();
	int FlipHorizontal();
	int Rotate90();
	int Rotate270();
	int MotionBlur(const double &radius, const double &sigma, const double &angle);
	int RotateFree(const double &angle);
	int PhotoFiltre(const CRgbaquad &clValue, const int &intensity);
	int BrightnessAndContrast(const double &brightness, const double &contrast);
	int RGBFilter(const int &red, const int &green, const int &blue);
	int CloudsFilter(const CRgbaquad &color1, const CRgbaquad &color2, const float &amplitude, const float &frequence, const int &octave, const int &intensity);
	int Swirl(const float &radius, const float &angle);
	int Contrast(const double &contrast, const uint8_t &offset);
	int Lightness(const double &factor);
	int Fusion(CRegardsBitmap * bitmapSecond, const float &pourcentage);
	int Posterize(const float &level, const float &gamma);
	int Solarize(const long &threshold);
	int ClaheFilter(int nBins, float clipLevel, int windowSize);
	int BilateralFilter(int fSize,  float sigmaX, float sigmaP);
	int NlmeansFilter(int fsize, int bsize, float sigma);
    int bm3d(const int & fSize);
	void Interpolation(const int &widthOut, const int &heightOut, const int &method, int flipH, int flipV, int angle);
	void Interpolation(const int &widthOut, const int &heightOut, const wxRect &rc, const int &method, int flipH, int flipV, int angle);

	int LensFlare(const int &iPosX, const int &iPosY, const int &iPuissance, const int &iType, const int &iIntensity, const int &iColor, const int &iColorIntensity);
   
    int GetLib();
	//void SetLib(const int &numLib);
	wxImage GetwxImage();
	CRegardsBitmap * GetBitmap(const bool &source);
    CRegardsFloatBitmap * GetFloatBitmap(const bool &source);
	IFiltreEffet * GetInstance()
	{
		return filtreEffet;
	};

    int GetWidth();

private:


	COpenCLContext * openCLContext;
	void CalculNewSize(const int32_t &x, const int32_t &y, const double &angle, int &width, int &height);
	//CRegardsBitmap * pBitmap;
	IFiltreEffet * filtreEffet;
	CRgbaquad backColor;
	int numLib;
	wxString filename;
    wxWindow * parent = nullptr;
	int width;
	int height;
	
};
