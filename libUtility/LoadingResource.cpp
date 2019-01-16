#include "LoadingResource.h"
#include <RegardsBitmap.h>
#include <LibResource.h>

CRegardsBitmap * CLoadingResource::LoadRegardsBmpResource(const wxString & resourceName)
{
	CLibResource libResource;
	CPictureData * data = libResource.LoadBitmapFromResource(resourceName);
	CRegardsBitmap * bitmap = new CRegardsBitmap();
	bitmap->SetBitmap(data->data, data->width, data->height);
	delete data;
	return bitmap;
}

wxImage CLoadingResource::LoadImageResource(const wxString & resourceName)
{
	CRegardsBitmap * bitmap = LoadRegardsBmpResource(resourceName);
	wxImage out = ConvertTowxImageRGB(bitmap);
	delete bitmap;
	return out;
}

wxImage CLoadingResource::ConvertTowxImageRGB(CRegardsBitmap * bitmap)
{
	int width = bitmap->GetBitmapWidth();
	int height = bitmap->GetBitmapHeight();
	//int widthSrcSize = width * 4;
	unsigned char * data = bitmap->GetPtBitmap();
	//int posData = 0;
	//int posDataOut = 0;
	//int posAlpha = 0;
	wxImage anImage(width, height, false);
	unsigned char * dataOut = anImage.GetData();
    int size = width*height;
    //bitmap->VertFlipBuf();
    
	if (data != nullptr)
	{
#pragma omp parallel for
		for (auto i = 0; i < size; ++i)
		{
			int y = i / width;
			int x = i - (y * width);
			int positionInput = ((height - y - 1) * width + x) << 2;
			int position = i * 3;

			dataOut[position] = data[positionInput + 2];
			dataOut[position + 1] = data[positionInput + 1];
			dataOut[position + 2] = data[positionInput];
		}

	}
    
    return anImage;
}