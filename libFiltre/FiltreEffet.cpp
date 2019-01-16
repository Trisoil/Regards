#include "FiltreEffet.h"
#include <math.h>
#include "FiltreEffetCPU.h"
#include "OpenCLEffect.h"
#include "InterpolationBicubic.h"
#include <DecodeRawPicture.h>
#include <LibResource.h>

#include "Rotate.h"
#include "RedEye.h"
#include <FilterData.h>
#include "Histogramme.h"
#include "InterpolationFilters.h"
#include "WaveFilter.h"
#include <ImageLoadingFormat.h>
#include <RegardsFloatBitmap.h>
#include <PiccanteFilter.h>
#if defined(__WXMSW__)
#include "../include/config_id.h"
#else
#include <config_id.h>
#endif

//BM3D
#include "utilities.h"
#include "bm3d.h"
#include <time.h>

#define YUV       0
#define YCBCR     1
#define OPP       2
#define RGB       3
#define DCT       4
#define BIOR      5
#define HADAMARD  6
#define NONE      7

using namespace Regards::FiltreEffet;
using namespace std;

/*
void CFiltreEffet::SetLib(const int &lib)
{
	numLib = lib;
}
*/

int CFiltreEffet::GetLib()
{
    return numLib;
}

///// LUT tables
#define LUTMAX 30.0
#define LUTMAXM1 29.0
#define LUTPRECISION 1000.0

#define MAX(i,j) ( (i)<(j) ? (j):(i) )
#define MIN(i,j) ( (i)<(j) ? (i):(j) )


int CFiltreEffet::RenderEffect(const int &numEffect, CEffectParameter * effectParameter)
{
    return CFiltreData::RenderEffect(numEffect,this,effectParameter);
}

int CFiltreEffet::FilterBilateral2DS(const float & sigma_s, const float & sigma_r)
{
    CRegardsFloatBitmap * test = filtreEffet->GetFloatBitmap(true);
    printf("Infos Float Bitmap Width : %d Height : %d \n",test->GetWidth(), test->GetHeight());
    CPiccanteFilter::FilterBilateral2DS(test,sigma_s,sigma_r);
    CImageLoadingFormat imageLoadFormat(true);
    imageLoadFormat.SetPicture(test);
    filtreEffet->SetBitmap(&imageLoadFormat);  
    return 0;
}

int CFiltreEffet::GetWidth()
{
    return width;
}

int CFiltreEffet::FilterKuwahara(const int &kernelSize)
{
    CRegardsFloatBitmap * test = filtreEffet->GetFloatBitmap(true);
    printf("Infos Float Bitmap Width : %d Height : %d \n",test->GetWidth(), test->GetHeight());
    CPiccanteFilter::FilterKuwahara(test,kernelSize);
    CImageLoadingFormat imageLoadFormat(true);
    imageLoadFormat.SetPicture(test);
    filtreEffet->SetBitmap(&imageLoadFormat);  
    return 0;     
}

int CFiltreEffet::bm3d()
{
        CRegardsFloatBitmap * pictureSource = filtreEffet->GetFloatBitmap(true);
        vector<float> img_noisy, img_basic, img_denoised;
        unsigned width, height, chnls;

        const char *_tau_2D_hard = "bior";
        const char *_tau_2D_wien = "dct";
        const char *_color_space = "rgb";
        const char *_patch_size = "0"; // >0: overrides default
        const char *_nb_threads = "0";
        const bool useSD_1 = 1;//pick_option(&argc, argv, "useSD_hard", NULL) != NULL;
        const bool useSD_2 = 1;//pick_option(&argc, argv, "useSD_wien", NULL) != NULL;
        const bool verbose = true;//pick_option(&argc, argv, "verbose", NULL) != NULL;

        clock_t tStart = clock();
        
        //! Check parameters
        const unsigned tau_2D_hard  = (strcmp(_tau_2D_hard, "dct" ) == 0 ? DCT :
                                     (strcmp(_tau_2D_hard, "bior") == 0 ? BIOR : NONE));
        if (tau_2D_hard == NONE)
        {
            cout << "tau_2d_hard is not known." << endl;
            return 0;
        }
        
        const unsigned tau_2D_wien  = (strcmp(_tau_2D_wien, "dct" ) == 0 ? DCT :
                                     (strcmp(_tau_2D_wien, "bior") == 0 ? BIOR : NONE));
        if (tau_2D_wien == NONE) {
            cout << "tau_2d_wien is not known." << endl;
             return 0;
        }
        
        const unsigned color_space  = (strcmp(_color_space, "rgb"  ) == 0 ? RGB   :
                                     (strcmp(_color_space, "yuv"  ) == 0 ? YUV   :
                                     (strcmp(_color_space, "ycbcr") == 0 ? YCBCR :
                                     (strcmp(_color_space, "opp"  ) == 0 ? OPP   : NONE))));
        if (color_space == NONE) {
            cout << "color_space is not known." << endl;
            return 0;
        }

        const int patch_size = atoi(_patch_size);
        if (patch_size < 0)
        {
          cout << "The patch_size parameter must not be negative." << endl;
          return 0;
        } 
        else 
        {
            const unsigned patch_size = (unsigned) patch_size;
        }
        
        const int nb_threads = atoi(_nb_threads);
        if (nb_threads < 0)
        {
            cout << "The nb_threads parameter must not be negative." << endl;
           return 0;
        } 
        else 
        {
            const unsigned nb_threads = (unsigned) nb_threads;
        }
        
        //! Load image
        bool returnValue = load_image(pictureSource, img_noisy, &width, &height, &chnls);           
        
        float fSigma = 10;//atof(argv[2]);

       //! Denoising
       if (run_bm3d(fSigma, img_noisy, img_basic, img_denoised, width, height, chnls,
                     useSD_1, useSD_2, tau_2D_hard, tau_2D_wien, color_space, patch_size,
                     nb_threads, verbose)
            != EXIT_SUCCESS)
            return 0;

       //! save noisy, denoised and differences images
       cout << endl << "Save images...";        
       printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   
       

}

int CFiltreEffet::BestExposure(const float &tmoValue)
{
    CRegardsFloatBitmap * test = filtreEffet->GetFloatBitmap(true);
    printf("Infos Float Bitmap Width : %d Height : %d \n",test->GetWidth(), test->GetHeight());
    CPiccanteFilter::BestExposure(test,tmoValue);
    CImageLoadingFormat imageLoadFormat(true);
    imageLoadFormat.SetPicture(test);
    filtreEffet->SetBitmap(&imageLoadFormat);    
    return 0;
}

int CFiltreEffet::WaveFilter(int x, int y, short height, int scale, int radius)
{
	filtreEffet->WaveFilter(x, y, height, scale,radius);
	return 0;
}

int CFiltreEffet::ClaheFilter(int nBins, float clipLevel, int windowSize)
{
	return filtreEffet->ClaheFilter(nBins, clipLevel, clipLevel);
}

int CFiltreEffet::BilateralFilter(int fSize,  float sigmaX, float sigmaP)
{
	return filtreEffet->BilateralFilter(fSize, sigmaX, sigmaP);
}
	
int CFiltreEffet::NlmeansFilter(int fsize, int bsize, float sigma)
{
	return filtreEffet->NlmeansFilter(fsize, bsize, sigma);
}

wxImage CFiltreEffet::RenderEffectPreviewwxImage(const int &numEffect, CEffectParameter * effectParameter)
{
	if(RenderEffectPreview(numEffect, effectParameter))
		return this->GetwxImage();
	return wxImage();
}

int CFiltreEffet::RenderEffectPreview(const int &numEffect, CEffectParameter * effectParameter)
{
	filtreEffet->SetPreviewMode(true);
    int value = CFiltreData::RenderEffect(numEffect,this, effectParameter, true);
	filtreEffet->SetPreviewMode(false);
	return value;
}

CFiltreEffet::CFiltreEffet(const CRgbaquad &backColor, COpenCLContext * openCLContext, CImageLoadingFormat * bitmap)
{
	filtreEffet = nullptr;
    this->backColor = backColor;
    this->numLib = LIBCPU;
	this->openCLContext = openCLContext;        
	filename = bitmap->GetFilename();
	width = bitmap->GetWidth();
	height = bitmap->GetHeight();
    if(openCLContext != nullptr)
    {
        if(OpenCLHasEnoughMemory())
        {
            filtreEffet = new COpenCLEffect(backColor, openCLContext, bitmap);
            this->numLib = LIBOPENCL;
        }
    }
    
    if( this->numLib == LIBCPU)
    {
        filtreEffet = new CFiltreEffetCPU(backColor, bitmap);
    }
}

bool CFiltreEffet::OpenCLHasEnoughMemory()
{
    if(openCLContext != nullptr)
    {
        uint64_t memsizeMax = openCLContext->GetMaxMemoryAllocable();
        if(memsizeMax > width * height * 4 * sizeof(float))
            return true;
    }
    return false;
}

void CFiltreEffet::SetBitmap(CImageLoadingFormat * bitmap)
{
    if (filtreEffet != nullptr)
        filtreEffet->SetBitmap(bitmap);
}

CFiltreEffet::~CFiltreEffet()
{
       
	if (filtreEffet != nullptr)
		delete(filtreEffet);

}

void CFiltreEffet::GetRgbaBitmap(void * cl_image)
{
	filtreEffet->GetRgbaBitmap(cl_image);
}

int CFiltreEffet::RedEye(const wxRect& rSelectionBox)
{
	filtreEffet->RedEye(rSelectionBox);
	return 0;
}

wxImage CFiltreEffet::GetwxImage()
{
	return filtreEffet->GetwxImage();
}

CRegardsBitmap * CFiltreEffet::GetBitmap(const bool &source)
{
	return filtreEffet->GetBitmap(source);
}

 CRegardsFloatBitmap * CFiltreEffet::GetFloatBitmap(const bool &source)
 {
     return filtreEffet->GetFloatBitmap(source);
 }

int CFiltreEffet::HistogramLog()
{
	filtreEffet->HistogramLog();
	return 0;
}

int CFiltreEffet::HistogramNormalize()
{
	filtreEffet->HistogramNormalize();
    return 0;
}

int CFiltreEffet::HistogramEqualize()
{
	filtreEffet->HistogramEqualize();
	return 0;
}

int CFiltreEffet::LensFlare(const int &iPosX, const int &iPosY, const int &iPuissance, const int &iType, const int &iIntensity, const int &iColor, const int &iColorIntensity)
{
	int value = filtreEffet->LensFlare(iPosX, height - iPosY, iPuissance, iType, iIntensity, iColor, iColorIntensity);
	return value;
}

int CFiltreEffet::SharpenMasking(const float &sharpness)
{
	return filtreEffet->SharpenMasking(sharpness);
}

void CFiltreEffet::Interpolation(const int &widthOut, const int &heightOut, const int &method, int flipH, int flipV, int angle)
{
#ifdef _CALCU_DIFF_TIME
	LARGE_INTEGER start_time;
	LARGE_INTEGER end_time;
#endif
	filtreEffet->Interpolation(widthOut, heightOut, method, flipH, flipV, angle);

#ifdef _CALCU_DIFF_TIME
#if defined(WIN32) && defined(_DEBUG)
	::QueryPerformanceCounter((LARGE_INTEGER*)&end_time);
	float gm_diffTime = (float)(((double)end_time.QuadPart - (double)start_time.QuadPart) / 1000000);
	wxString data = to_string(gm_diffTime);
	OutputDebugString(L"cuda time : " + data + "\n");

#endif
#endif
}

void CFiltreEffet::Interpolation(const int &widthOut, const int &heightOut, const wxRect &rc, const int &method, int flipH, int flipV, int angle)
{
#ifdef _CALCU_DIFF_TIME
	LARGE_INTEGER start_time;
	LARGE_INTEGER end_time;
#endif
	filtreEffet->Interpolation(widthOut, heightOut, rc, method, flipH, flipV, angle);

#ifdef _CALCU_DIFF_TIME
	::QueryPerformanceCounter((LARGE_INTEGER*)&end_time);
	float gm_diffTime = (float)(((double)end_time.QuadPart - (double)start_time.QuadPart) / 1000000);
	wxString data = to_string(gm_diffTime);
	OutputDebugString(L"cuda time : " + data + "\n");

#endif
}

//---------------------------------------------------------------------
//Effet RGB 
//---------------------------------------------------------------------
int CFiltreEffet::RGBFilter(const int &red, const int &green, const int &blue)
{
	return filtreEffet->RGBFilter(red, green, blue);
}

int CFiltreEffet::Posterize(const float &level, const float &gamma)
{
	return filtreEffet->Posterize(level, gamma);
}

int CFiltreEffet::Solarize(const long &threshold)
{
	return filtreEffet->Solarize(threshold);
}
//---------------------------------------------------------------------
//Effet Clouds 
//---------------------------------------------------------------------
int CFiltreEffet::CloudsFilter(const CRgbaquad &color1, const CRgbaquad &color2, const float &amplitude, const float &frequence, const int &octave, const int &intensity)
{
	int value = filtreEffet->CloudsFilter(color1, color2, amplitude, frequence, octave, intensity);
	return value;
}

//---------------------------------------------------------------------
//Effet Swirl 
//---------------------------------------------------------------------
int CFiltreEffet::Swirl(const float &radius, const float &angle)
{
	return filtreEffet->Swirl(radius, angle);
}

//---------------------------------------------------------------------
//Lumière et Contraste 
//---------------------------------------------------------------------
int CFiltreEffet::BrightnessAndContrast(const double &brightness, const double &contrast)
{
	return filtreEffet->BrightnessAndContrast(brightness, contrast);
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
int CFiltreEffet::NiveauDeGris()
{
	try
	{
		return filtreEffet->NiveauDeGris();
	}
	catch(...)
	{

	}
	return -1;
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
int CFiltreEffet::NoirEtBlanc()
{
	try
	{
		return filtreEffet->NoirEtBlanc();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Sepia()
{
	try
	{
		return filtreEffet->Sepia();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Soften()
{
	try
	{
		return filtreEffet->Soften();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Blur(const int &radius)
{
	try
	{
		return filtreEffet->Blur(radius);
	}
	catch(...)
	{

	}
	return -1;
}


//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::GaussianBlur(const int &radius, const int &boxsize)
{
	try
	{
		return filtreEffet->GaussianBlur(radius, boxsize);
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Emboss()
{
	try
	{
		return filtreEffet->Emboss();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::SharpenStrong()
{
	try
	{
		return filtreEffet->SharpenStrong();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Sharpen()
{
	try
	{
		return filtreEffet->Sharpen();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Erode()
{
	try
	{
		return filtreEffet->Erode();
	}
	catch(...)
	{

	}
	return -1;
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Median()
{
	return filtreEffet->Median();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Noise()
{
	return filtreEffet->Noise();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Dilate()
{
	return filtreEffet->Dilate();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Negatif()
{
	return filtreEffet->Negatif();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Contrast(const double &contrast,const uint8_t & offset)
{
	return filtreEffet->Contrast(contrast, offset);
}

int CFiltreEffet::Lightness(const double &factor)
{
	return filtreEffet->Lightness(factor);
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::FiltreEdge()
{
	return filtreEffet->FiltreEdge();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::FiltreMosaic()
{
	return filtreEffet->FiltreMosaic();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::FlipVertical()
{
	return filtreEffet->FlipVertical();
}
//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::FlipHorizontal()
{
	return filtreEffet->FlipHorizontal();
}

void CFiltreEffet::SetPreview(const bool &value)
{
	filtreEffet->SetPreviewMode(value);
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::MotionBlur(const double &radius, const double &sigma, const double &angle)
{
	//return filtreEffet->MotionBlur(radius, sigma, angle);
	int puissance = (int)((float)(width / 2) * ((float)sigma / 100.0f));
	int value = filtreEffet->MotionBlur(radius, puissance, angle);
	return value;
}


void CFiltreEffet::CalculNewSize(const int32_t &x, const int32_t &y, const double &angle, int &width, int &height)
{
	double dAngle = angle;
	if (dAngle > 90.0 && dAngle < 180.0)
	{
		dAngle = 180.0 - angle;
	}
	else if (dAngle > 180.0  && dAngle < 270.0)
	{
		dAngle = angle - 180.0;
	}
	else if (dAngle > 270.0 && dAngle < 360.0)
	{
		dAngle = 360.0 - angle;

	}
	else if (dAngle == 90.0 || dAngle == 270.0)
	{
		width = y;
		height = x;
		return;
	}
	else if (dAngle == 180.0 || dAngle == 360.0 || dAngle == 0.0)
	{
		width = x;
		height = y;
		return;
	}


	float radians = dAngle * 0.017453292519943;
	float cosine = cos(radians);
	float sine = sin(radians);
	width = x * cosine + y * sine;
	height = x * sine + y * cosine;
}


//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::RotateFree(const double &angle)
{
	int widthOut;
	int heightOut;
	CalculNewSize(width, height, angle, widthOut, heightOut);
	return filtreEffet->RotateFree(angle, widthOut, heightOut);
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::PhotoFiltre(const CRgbaquad &clValue, const int &intensity)
{
	return filtreEffet->PhotoFiltre(clValue, intensity);
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Rotate90()
{
	return filtreEffet->Rotate90();
}

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
int CFiltreEffet::Rotate270()
{
	return filtreEffet->Rotate270();
}

//----------------------------------------------------------------------------
//Fusion de deux bitmaps
//----------------------------------------------------------------------------
int CFiltreEffet::Fusion(CRegardsBitmap * bitmapSecond, const float &pourcentage)
{
	return filtreEffet->Fusion(bitmapSecond, pourcentage);
}

/*
void CFiltreEffet::SetBitmap(CImageLoadingFormat * bitmap, int numLib)
{
	if(bitmap != nullptr && bitmap->IsOk())
	{
		filename = bitmap->GetFilename();
		width = bitmap->GetWidth();
		height = bitmap->GetHeight();

		if(filtreEffet != filtreEffetCPU)
		{
			filtreEffet->SetBitmap(bitmap);
		}
	}
}

void CFiltreEffet::SetBitmap(CRegardsBitmap * & pBitmap, int numLib)
{
	filename = pBitmap->GetFilename();
	width = pBitmap->GetBitmapWidth();
	height = pBitmap->GetBitmapHeight();


	if(numLib == 0)
	{
		if(filtreEffet != filtreEffetCPU)
		{
			filtreEffet->SetBitmap(pBitmap);
			filtreEffetCPU->SetBitmap(pBitmap);
		}
		else
		{
			filtreEffetCPU->SetBitmap(pBitmap);
		}
	}
	else if(numLib == LIBCPU)
	{
		filtreEffetCPU->SetBitmap(pBitmap);
	}
	else
	{
		filtreEffet->SetBitmap(pBitmap);
	}
}
*/