#pragma once
#include <IFiltreEffet.h>
#include "OpenCLContext.h"
#include "OpenCLProgram.h"
#include "OpenCLParameter.h"
#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

using namespace Regards::OpenCL;
class CRegardsBitmap;

namespace Regards
{
	namespace OpenCL
	{

		class COpenCLFilter
		{
		public:

			COpenCLFilter(COpenCLContext * context);

			void SetFlag(const bool &useMemory)
			{
				flag = useMemory ? CL_MEM_USE_HOST_PTR : CL_MEM_COPY_HOST_PTR;
			};

			virtual ~COpenCLFilter();

			COpenCLProgram * GetProgram(const wxString &numProgram);
			cl_mem FiltreConvolution(const wxString &functionName, cl_mem inputData, int width, int height);
			cl_mem MotionBlurCompute(const vector<double> & kernelMotion, const vector<wxPoint> & offsets, const int &size, cl_mem inputData, int width, int height);
			cl_mem bilat2(int fSize,  float sigmaX, float sigmaP, cl_mem inputData, int width, int height);
			cl_mem run2d(const int & FSIZE, const int & BSIZE,const float & SIGMA, cl_mem inputData, int width, int height);
			cl_mem bilateral_filter(const int & radius, const int & preserve, cl_mem inputData, int width, int height);
			cl_mem SharpenMasking(const float &sharpness, cl_mem inputData, int width, int height);
			cl_mem PhotoFiltre(const CRgbaquad &clValue, const int &intensity, cl_mem inputData, int width, int height);
			cl_mem RGBFilter(const int &red, const int &green, const int &blue, cl_mem inputData, int width, int height);
			cl_mem FiltreMosaic(cl_mem inputData, int width, int height);
			cl_mem Blur(const int &radius, cl_mem inputData, int width, int height);
			cl_mem BoxBlur(const int &coeff, const wxString &functionName, cl_mem inputData, int width, int height, bool noDeleteData = false);
			cl_mem ErodeDilate(const wxString &functionName, cl_mem inputData, int width, int height);
			cl_mem Posterize(const float &level, const float &gamma, cl_mem inputData, int width, int height);
			cl_mem Solarize(const long &threshold, cl_mem inputData, int width, int height);
			cl_mem Median(cl_mem inputData, int width, int height);
			cl_mem Noise(cl_mem inputData, int width, int height);
			cl_mem Flip(const wxString &functionName, cl_mem inputData, int width, int height);
			cl_mem Swirl(const float &radius, const float &angle, cl_mem inputData, int width, int height);
			cl_mem BrightnessAndContrast(const double &brightness, const double &contrast, cl_mem inputData, int width, int height);
			cl_mem ColorEffect(const wxString &functionName, cl_mem inputData, int width, int height);
			cl_mem Rotate(const wxString &functionName, const int &widthOut, const int &heightOut, const double &angle, cl_mem inputData, int width, int height);
			cl_mem Interpolation(const int &widthOut, const int &heightOut, const int &method, cl_mem inputData, int width, int height, int flipH, int flipV, int angle);
			cl_mem Interpolation(const int &widthOut, const int &heightOut, const wxRect &rc, const int &method, cl_mem inputData, int width, int height, int flipH, int flipV, int angle);
			cl_mem Fusion(cl_mem inputData, cl_mem secondPictureData, const float &pourcentage, int width, int height);

		protected:

			
			cl_mem_flags  flag;
			COpenCLContext * context;
		};

	}
}