#pragma once
#include "OpenCLEffectVideo.h"
using namespace Regards::OpenCL;


namespace Regards
{
	namespace OpenCL
	{
		class COpenCLEffectVideoYUV : public COpenCLEffectVideo
		{
		public:

			COpenCLEffectVideoYUV(COpenCLContext * context);
			virtual ~COpenCLEffectVideoYUV();
			void SetMemoryData(uint8_t * bufferY, int sizeY, uint8_t * bufferU, int sizeU, uint8_t * bufferV, int sizeV, const int &width, const int &height, const int &lineSize, const int &format = 0);
			void InterpolationBicubic(const int &widthOut, const int &heightOut, const int &angle, const int &bicubic);
            void DeleteData();

		protected:
			int formatData;
			//Bitmap Memory Buffer
			COpenCLParameterByteArray * inputY;
			COpenCLParameterByteArray * inputU;
			COpenCLParameterByteArray * inputV;
			COpenCLParameterInt * paramLineSize;
		};

	}
}