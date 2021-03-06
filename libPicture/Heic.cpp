#include <header.h>
#include "Heic.h"
#ifdef LIBHEIC
#include <RegardsBitmap.h>
#include <cstdint>
#include <heifreader.h>
#include <thread>
#include <de265.h>
#include "yuv420.h"
#include "yuv422.h"

using namespace std;
using namespace HEIF;

typedef struct x265Frame
{
	uint64_t memoryBufferSize;
	uint8_t * _memoryBuffer;
	CRegardsBitmap * picture;
	wxString filename;
};

CHeic::CHeic()
{
}


CHeic::~CHeic()
{
}

void CHeic::Initx265Decoder()
{
    de265_multithread_init();
}

void CHeic::Uninitx265Decoder()
{
    de265_multithread_uninit();
}

static uint8_t* convert_to_8bit(const uint8_t* data, int width, int height,
	int pixelsPerLine, int bit_depth)
{
	const uint16_t* data16 = (const uint16_t*)data;
	uint8_t* out = new uint8_t[pixelsPerLine*height];

	for (auto y = 0; y<height; y++) {
		for (auto x = 0; x<width; x++) {
			out[y*pixelsPerLine + x] = *(data16 + y*pixelsPerLine + x) >> (bit_depth - 8);
		}
	}

	return out;
}


CRegardsBitmap * GetRGBPicture(const de265_image * img)
{
	int width = de265_get_image_width(img, 0);
	int height = de265_get_image_height(img, 0);

	int chroma_width = de265_get_image_width(img, 1);
	int chroma_height = de265_get_image_height(img, 1);

	de265_chroma chroma = de265_get_chroma_format(img);

	int frame_width = width;
	int frame_height = height;
	
	frame_width &= ~7;
	frame_height &= ~7;

	CRegardsBitmap * picture = nullptr;
	int stride, chroma_stride;
	const uint8_t* yOrigin = de265_get_image_plane(img, 0, &stride);
	const uint8_t* cbOrigin = de265_get_image_plane(img, 1, &chroma_stride);
	const uint8_t* crOrigin = de265_get_image_plane(img, 2, NULL);

	int bpp_y = (de265_get_bits_per_pixel(img, 0) + 7) / 8;
	int bpp_c = (de265_get_bits_per_pixel(img, 1) + 7) / 8;
	int ppl_y = stride / bpp_y;
	int ppl_c = chroma_stride / bpp_c;

	uint8_t* y16 = NULL;
	uint8_t* cb16 = NULL;
	uint8_t* cr16 = NULL;
	int bd;

	if ((bd = de265_get_bits_per_pixel(img, 0)) > 8) {
		y16 = convert_to_8bit(yOrigin, width, height, ppl_y, bd); yOrigin = y16;
	}

	if (chroma != de265_chroma_mono) {
		if ((bd = de265_get_bits_per_pixel(img, 1)) > 8) {
			cb16 = convert_to_8bit(cbOrigin, chroma_width, chroma_height, ppl_c, bd); cbOrigin = cb16;
		}
		if ((bd = de265_get_bits_per_pixel(img, 2)) > 8) {
			cr16 = convert_to_8bit(crOrigin, chroma_width, chroma_height, ppl_c, bd); crOrigin = cr16;
		}
	}



	switch (chroma)
	{
	case de265_chroma_420:
		{

			uint8_t * _y = new uint8_t[frame_width * frame_height];
			uint8_t * _cb = new uint8_t[frame_width * frame_height / 4];
			uint8_t * _cr = new uint8_t[frame_width * frame_height / 4];
			picture = new CRegardsBitmap(frame_width, frame_height);
			if (stride == frame_width && chroma_stride == frame_width / 2) {

				// fast copy

				memcpy(_y, yOrigin, frame_width * frame_height);
				memcpy(_cb, cbOrigin, frame_width * frame_height / 4);
				memcpy(_cr, crOrigin, frame_width * frame_height / 4);
			}
			else {
				// copy line by line, because sizes are different

				for (auto y = 0; y<frame_height; y++)
				{
					memcpy(_y + y*frame_width, yOrigin + stride*y, frame_width);
				}

				for (auto y = 0; y<frame_height / 2; y++)
				{
					memcpy(_cb + y*frame_width / 2, cbOrigin + chroma_stride*y, frame_width / 2);
					memcpy(_cr + y*frame_width / 2, crOrigin + chroma_stride*y, frame_width / 2);
				}
			}
			yuv420p_to_rgb32(_y, _cb, _cr, picture->GetPtBitmap(), frame_width, frame_height);
			delete[] _y;
			delete[] _cb;
			delete[] _cr;
		}
		break;
	case de265_chroma_422:
		{

			uint8_t * dataYUV = new uint8_t[frame_width * 2 * frame_height];
			picture = new CRegardsBitmap(frame_width, frame_height);

			for (auto y = 0; y<frame_height; y++)
			{
				unsigned char* p = dataYUV + y*frame_width * 2;

				const unsigned char* Yp = yOrigin + y*stride;
				const unsigned char* Up = cbOrigin + y*chroma_stride;
				const unsigned char* Vp = crOrigin + y*chroma_stride;

				for (auto x = 0; x<frame_width; x += 2) {
					*p++ = Yp[x];
					*p++ = Up[x / 2];
					*p++ = Yp[x + 1];
					*p++ = Vp[x / 2];
				}
			}

			yuv422p_to_rgb32(dataYUV, picture->GetPtBitmap(), frame_width, frame_height);
			delete[] dataYUV;

		}
		break;
	case de265_chroma_444:
		{
			uint8_t * _y = new uint8_t[frame_width * frame_height];
			uint8_t * _cb = new uint8_t[frame_width * frame_height / 4];
			uint8_t * _cr = new uint8_t[frame_width * frame_height / 4];

			for (auto y = 0; y < frame_height; y++)
			{
				unsigned char* p = _y + y*frame_width;
				memcpy(p, yOrigin + y*stride, frame_width);
			}

			for (auto y = 0; y < frame_height; y += 2)
			{
				unsigned char* u = _cb + y / 2 * frame_width / 2;
				unsigned char* v = _cr + y / 2 * frame_width / 2;

				for (auto x = 0; x < frame_width; x += 2) {
					u[x / 2] = (U[y   *chroma_stride + x] + U[y   *chroma_stride + x + 1] +
						U[(y + 1)*chroma_stride + x] + U[(y + 1)*chroma_stride + x + 1]) / 4;
					v[x / 2] = (V[y   *chroma_stride + x] + V[y   *chroma_stride + x + 1] +
						V[(y + 1)*chroma_stride + x] + V[(y + 1)*chroma_stride + x + 1]) / 4;

					//u[x/2] = U[y*chroma_stride + x];
					//v[x/2] = V[y*chroma_stride + x];
				}
			}
			yuv420p_to_rgb32(_y, _cb, _cr, picture->GetPtBitmap(), frame_width, frame_height);
			delete[] _y;
			delete[] _cb;
			delete[] _cr;
		}
		break;
	case de265_chroma_mono:
		{
			uint8_t * _y = new uint8_t[frame_width * frame_height];
			uint8_t * _cb = new uint8_t[frame_width * frame_height / 4];
			uint8_t * _cr = new uint8_t[frame_width * frame_height / 4];
			if (stride == frame_width) {

				// fast copy

				memcpy(_y, yOrigin, frame_width * frame_height);
			}
			else {
				// copy line by line, because sizes are different

				for (auto y = 0; y<frame_height; y++)
				{
					memcpy(_y + y*frame_width, yOrigin + stride*y, frame_width);
				}
			}

			// clear chroma planes

			memset(_cb, 0x80, frame_width * frame_height / 4);
			memset(_cr, 0x80, frame_width * frame_height / 4);

			yuv420p_to_rgb32(_y, _cb, _cr, picture->GetPtBitmap(), frame_width, frame_height);
			delete[] _y;
			delete[] _cb;
			delete[] _cr;
		}
		break;
	}

	

	delete[] y16;
	delete[] cb16;
	delete[] cr16;

	return picture;
}



CRegardsBitmap * CHeic::DecodeFrame(void * data, int length, void * externDecoder)
{
	CRegardsBitmap * picture = nullptr;
	de265_error err = de265_error::DE265_OK;
	de265_decoder_context * decoderContext = nullptr;
	if (decoderContext == nullptr)
		decoderContext = de265_new_decoder();
	else
		decoderContext = (de265_decoder_context *)externDecoder;

	err = de265_push_data(decoderContext, data, length, 0, NULL);
	if (err == de265_error::DE265_OK)
	{
		int check_hash = 1;
		int stop = 1;
		int quiet = 0;
		err = de265_flush_data(decoderContext);
		if (err == DE265_OK)
		{
			int more = 1;
			while (more)
			{
				more = 0;

				// decode some more
				try
				{
					err = de265_decode(decoderContext, &more);
				}
				catch (...)
				{
					break;
				}
				if (err != DE265_OK) {
					if (quiet <= 1)
						fprintf(stderr, "ERROR: %s\n", de265_get_error_text(err));

					if (check_hash && err == DE265_ERROR_CHECKSUM_MISMATCH)
						stop = 1;
					more = 0;
					break;
				}

				// show available images

				const de265_image* img = de265_get_next_picture(decoderContext);
				if (img)
				{
                    picture = GetRGBPicture(img);
                    picture->VertFlipBuf();
                    picture->ConvertToBgr();                    
					more = 0;
				}

				// show warnings

				for (;;) {
					de265_error warning = de265_get_warning(decoderContext);
					if (warning == DE265_OK) {
						break;
					}

					if (quiet <= 1)
						fprintf(stderr, "WARNING: %s\n", de265_get_error_text(warning));
				}
			}
		}
	}
	err = de265_free_decoder(decoderContext);

	return picture;
}

vector<CRegardsBitmap *> DecodePictureList(de265_decoder_context * decoderContext, const string &filename)
{
	vector<CRegardsBitmap *> listPicture;
	de265_error err = de265_error::DE265_OK;

	int check_hash = 1;
	int stop = 1;
	int quiet = 0;
	err = de265_flush_data(decoderContext);
	if (err == DE265_OK)
	{
		int more = 1;
		while (more)
		{
			more = 0;

			// decode some more
			try
			{
				err = de265_decode(decoderContext, &more);
			}
			catch (...)
			{
				break;
			}
			if (err != DE265_OK) {
				if (quiet <= 1)
					fprintf(stderr, "ERROR: %s\n", de265_get_error_text(err));

				if (check_hash && err == DE265_ERROR_CHECKSUM_MISMATCH)
					stop = 1;
				more = 0;
				break;
			}

			// show available images

			const de265_image* img = de265_get_next_picture(decoderContext);
			if (img)
			{
				CRegardsBitmap * picture = GetRGBPicture(img);
				picture->SetFilename(filename);
				picture->VertFlipBuf();
				picture->ConvertToBgr();
				picture->RotateExif(0);

				listPicture.push_back(picture);
			}

			// show warnings

			for (;;) {
				de265_error warning = de265_get_warning(decoderContext);
				if (warning == DE265_OK) {
					break;
				}

				if (quiet <= 1)
					fprintf(stderr, "WARNING: %s\n", de265_get_error_text(warning));
			}
		}
	}
	return listPicture;
}

vector<CRegardsBitmap *> CHeic::GetAllPicture(const string &filename, bool &isMasterSequence, int &delay)
{
	vector<CRegardsBitmap *> listPicture;
    auto* reader = Reader::Create();
    Array<uint32_t> itemIds;

    // Input file available from https://github.com/nokiatech/heif_conformance
    if (reader->initialize(filename.c_str()) == ErrorCode::OK)
    {
        de265_error err = de265_error::DE265_OK;
        de265_decoder_context * decoderContext = de265_new_decoder();
        FileInformation info;
        if (reader->getFileInformation(info) != ErrorCode::OK)
        {
            goto END;
        }

        if (info.trackInformation.size > 0)
        {
            // Print information for every track read
            for (const auto& trackProperties : info.trackInformation)
            {
                const auto sequenceId = trackProperties.trackId;
                //cout << "Track ID " << sequenceId << endl;  // Context ID corresponds to the track ID

                if (trackProperties.features & TrackFeatureEnum::IsMasterImageSequence)
                {
                    isMasterSequence = true;
                    //cout << "This is a master image sequence." << endl;
                }

                if (trackProperties.features & TrackFeatureEnum::IsThumbnailImageSequence)
                {
                    // Assume there is only one type track reference, so check reference type and master track ID(s) from
                    // the first one.
                    isMasterSequence = false;
                    const auto tref = trackProperties.referenceTrackIds[0];
                    //cout << "Track reference type is '" << tref.type.value << "'" << endl;
                    //cout << "This is a thumbnail track for track ID ";
                    for (const auto masterTrackId : tref.trackIds)
                    {
                        //cout << masterTrackId << endl;
                    }
                }

                Array<TimestampIDPair> timestamps;
                reader->getItemTimestamps(sequenceId, timestamps);
                //cout << "Sample timestamps:" << endl;
                for (const auto& timestamp : timestamps)
                {
					delay = timestamp.timeStamp;
                    //cout << " Timestamp=" << timestamp.timeStamp << "ms, sample ID=" << timestamp.itemId << endl;
                }

                for (const auto& sampleProperties : trackProperties.sampleProperties)
                {
                    // A sample might have decoding dependencies. The simplest way to handle this is just to always ask and
                    // decode all dependencies.
                    Array<SequenceImageId> itemsToDecode;
                    reader->getDecodeDependencies(sequenceId, sampleProperties.sampleId, itemsToDecode);
                    for (auto dependencyId : itemsToDecode)
                    {
                        uint64_t size       = 1024 * 1024;
                        uint8_t* sampleData = new uint8_t[size];
                        reader->getItemDataWithDecoderParameters(sequenceId, dependencyId, sampleData, size);

                        //err = de265_push_data(decoderContext, sampleData, size, 0, NULL);
                        CRegardsBitmap * bitmapSrc = DecodeFrame(sampleData, size);
                        if (bitmapSrc != nullptr)
                        {
                            bitmapSrc->SetFilename(filename);
                            listPicture.push_back(bitmapSrc);
                        }

                        delete[] sampleData;
                    }
                    // Store or show the image...
                }
                
            }
        }
    }
    else
    {
        
        cout << "Can't find input file: " << filename << ". "
             << "Please download it from https://github.com/nokiatech/heif_conformance "
             << "and place it in same directory with the executable." << endl;
    }
END:

    Reader::Destroy(reader);    

    

	return listPicture;
}

int CHeic::GetNbFrame(const string &filename)
{
	int nbId = 0;
    auto* reader = Reader::Create();

    if (reader->initialize(filename.c_str()) == ErrorCode::OK)
    {
		FileInformation info;
		reader->getFileInformation(info);

		// Print information for every track read
		for (const auto& trackProperties : info.trackInformation)
		{

			const auto sequenceId = trackProperties.trackId;
			//cout << "Track ID " << sequenceId << endl;  // Context ID corresponds to the track ID

			if (trackProperties.features & TrackFeatureEnum::IsMasterImageSequence)
			{
				//cout << "This is a master image sequence." << endl;
			}

			if (trackProperties.features & TrackFeatureEnum::IsThumbnailImageSequence)
			{
				// Assume there is only one type track reference, so check reference type and master track ID(s) from
				// the first one.
				const auto tref = trackProperties.referenceTrackIds[0];
				//cout << "Track reference type is '" << tref.type.value << "'" << endl;
				//cout << "This is a thumbnail track for track ID ";
				for (const auto masterTrackId : tref.trackIds)
				{
					//cout << masterTrackId << endl;
				}
			}

			Array<TimestampIDPair> timestamps;
			reader->getItemTimestamps(sequenceId, timestamps);
			//cout << "Sample timestamps:" << endl;
			for (const auto& timestamp : timestamps)
			{
				//cout << " Timestamp=" << timestamp.timeStamp << "ms, sample ID=" << timestamp.itemId << endl;
			}

			nbId = timestamps.size;
		}

		if (nbId == 0)
		{
			nbId = 1;
		}
    }    

	Reader::Destroy(reader);    
    return nbId;

}

void CHeic::DecodePictureMultiThread(void * parameter)
{
	x265Frame * decoding = (x265Frame *)parameter;

	decoding->picture = DecodeFrame(decoding->_memoryBuffer, decoding->memoryBufferSize);
	if (decoding->picture != nullptr)
	{
		decoding->picture->SetFilename(decoding->filename);
	}

	delete[] decoding->_memoryBuffer;
}

CRegardsBitmap * CHeic::GetPicture(const string &filename)
{
	struct PictureEncoder
	{
		x265Frame * frame = nullptr;
	};
    CRegardsBitmap * picture = nullptr;
    auto* reader = Reader::Create();

    // Input file available from https://github.com/nokiatech/heif_conformance
    if (reader->initialize(filename.c_str()) == ErrorCode::OK)
    {
        FileInformation info;
        if (reader->getFileInformation(info) != ErrorCode::OK)
        {
            goto END;
        }   
        
        // Find the item ID
        ImageId itemId;
        reader->getPrimaryItem(itemId);        
        
        Array<ItemPropertyInfo> propertyInfos;
        reader->getItemProperties(itemId, propertyInfos);

        unsigned int rotation = 0;
        for (const auto& property : propertyInfos)
        {
            // For example, handle 'irot' transformational property is anti-clockwise rotation
            if (property.type == ItemPropertyType::IROT)
            {
                // Get property struct by index to access rotation angle
                Rotate irot;
                reader->getProperty(property.index, irot);
                rotation = irot.angle;
                break;  // Assume only one property
            }
        }          

		uint32_t _width, _heigth;
		reader->getWidth(itemId, _width);
		reader->getHeight(itemId, _heigth);
		uint64_t memoryBufferSize = 1024 * 1024;
		uint8_t* memoryBuffer = new uint8_t[memoryBufferSize];
		ErrorCode err = reader->getItemDataWithDecoderParameters(itemId, memoryBuffer, memoryBufferSize);
		if (err == ErrorCode::OK)
		{
			picture = DecodeFrame(memoryBuffer, memoryBufferSize);
			if (picture != nullptr)
			{
				picture->SetFilename(filename);
				picture->RotateExif(rotation);
				// Feed 'data' to decoder and display the cover image...
			}
		}
		else
		{
			unsigned int rotation = 0;
			vector<PictureEncoder> listPicture;
			// Input file available from https://github.com/nokiatech/heif_conformance
			Array<ImageId> itemIds;
			// Find item IDs of master images
			reader->getMasterImages(itemIds);
			bool firstTime = true;
			// Find thumbnails for each master. There can be several thumbnails for one master image, get narrowest ones here.
			
			for (const auto masterId : itemIds)
			{
				Array<ItemPropertyInfo> propertyInfos;
				reader->getItemProperties(masterId, propertyInfos);

				for (const auto& property : propertyInfos)
				{
					// For example, handle 'irot' transformational property is anti-clockwise rotation
					if (property.type == ItemPropertyType::IROT)
					{
						// Get property struct by index to access rotation angle
						Rotate irot;
						reader->getProperty(property.index, irot);
						rotation = irot.angle;
						break;  // Assume only one property
					}
				}
				break;
			}

			for (const auto masterId : itemIds)
			{
				PictureEncoder picture;
				listPicture.push_back(picture);
			}

			int i = 0;
			int nbProcess = thread::hardware_concurrency();;
			
			vector<thread *> listThread;
			for (int j = 0; j < nbProcess; j++)
			{
				listThread.push_back(nullptr);
			}
			

			while (i < listPicture.size())
			{
				for (int j = 0; j < nbProcess; j++)
				{
					if (listThread[j] != nullptr)
					{
						listThread[j]->join();
						delete listThread[j];
						listThread[j] = nullptr;
					}
				}

				if ((i + 1) < listPicture.size())
				{
					for (int j = 0; j < nbProcess; j++)
					{
						if (listThread[j] == nullptr)
						{
							listPicture[i].frame = new x265Frame;
							listPicture[i].frame->memoryBufferSize = 1024 * 1024;
							listPicture[i].frame->_memoryBuffer = new uint8_t[memoryBufferSize];
							listPicture[i].frame->filename = filename;
							reader->getItemDataWithDecoderParameters(itemIds[i], listPicture[i].frame->_memoryBuffer, listPicture[i].frame->memoryBufferSize);
							listThread[j] = new thread(DecodePictureMultiThread, listPicture[i].frame);
							i++;
							if (!(i < listPicture.size()))
								break;
						}
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			} 
			

			for (int j = 0; j < nbProcess; j++)
			{
				if (listThread[j] != nullptr)
				{
					listThread[j]->join();
					delete listThread[j];
					listThread[j] = nullptr;
				}
			}
			
			if (listPicture.size() > 0)
			{
				ImageId itemId;
				reader->getPrimaryItem(itemId);

				Array<ItemPropertyInfo> propertyInfos;
				reader->getItemProperties(itemId, propertyInfos);

				uint32_t _width, _heigth;
				reader->getWidth(itemId, _width);
				reader->getHeight(itemId, _heigth);

				CRegardsBitmap * bitmapSrc = listPicture[0].frame->picture;
				int boxWidth = bitmapSrc->GetBitmapWidth();
				int boxHeight = bitmapSrc->GetBitmapHeight();

				int nbItemWidth = _width / boxWidth;
				if (nbItemWidth * boxWidth < _width)
					nbItemWidth++;

				int nbItemHeight = _heigth / boxHeight;
				if (nbItemHeight * boxHeight < _heigth)
					nbItemHeight++;

				CRegardsBitmap * out = new CRegardsBitmap(boxWidth * nbItemWidth, boxHeight * nbItemHeight);
				int x = 0;
				int y = (nbItemHeight * boxHeight) - boxHeight;

				for (int i = 0; i < listPicture.size(); i++)
				{
					out->InsertBitmap(listPicture[i].frame->picture, x, y, false);
					x += boxWidth;

					if (x > _width)
					{
						x = 0;
						y -= boxHeight;
					}
				}

				picture = out->CropBitmap(0, boxHeight * nbItemHeight - _heigth, _width, _heigth);

				for (PictureEncoder picture : listPicture)
				{
					if(picture.frame->picture != nullptr)
						delete picture.frame->picture;

					delete picture.frame;
				}

				delete out;
				listPicture.clear();
				picture->SetFilename(filename);

			}
		}
		delete[] memoryBuffer;
    }
    else
    {
        cout << "Can't find input file: " << filename << ". "
             << "Please download it from https://github.com/nokiatech/heif_conformance "
             << "and place it in same directory with the executable." << endl;
    }


END:

	
    Reader::Destroy(reader);    



	return picture;
}

void CHeic::GetPictureDimension(const string &filename, int &width, int &height)
{
    Array<ImageId> itemIds;
    auto* reader = Reader::Create();
     if (reader->initialize(filename.c_str()) == ErrorCode::OK)
     {
        FileInformation info;
        if (reader->getFileInformation(info) != ErrorCode::OK)
        {
            return;
        }   

        // Verify that the file has one or several images in the MetaBox
        if (!(info.features & FileFeatureEnum::HasSingleImage || info.features & FileFeatureEnum::HasImageCollection))
        {
            return;
        }     

        // Find the item ID
        // Find the item ID of the first master image
		ImageId itemId;
		reader->getPrimaryItem(itemId);

        uint32_t _width, _heigth;
        reader->getWidth(itemId, _width);
        reader->getHeight(itemId, _heigth);
        width = _width;
        height = _heigth;

     }
     else
     {
         width = 0;
         height = 0;
     }

}

CRegardsBitmap * CHeic::GetThumbnailPicture(const string &filename)
{
    CRegardsBitmap * picture = nullptr;
    auto* reader = Reader::Create();
    uint64_t itemSize = 1024 * 1024;
    uint8_t* itemData = new uint8_t[itemSize];
	Array<ImageId> itemIds;

	if (reader->initialize(filename.c_str()) == ErrorCode::OK)
	{
		FileInformation info;
		reader->getFileInformation(info);

		// Find the item ID
		ImageId itemId;
		reader->getPrimaryItem(itemId);

		// Thumbnail references ('thmb') are from the thumbnail image to the master image
		Array<ImageId> thumbIds;
		reader->getReferencedToItemListByType(itemId, "thmb", thumbIds);
		if (thumbIds.size > 0)
		{
			const ImageId thumbId = *std::min_element(thumbIds.begin(), thumbIds.end(), [&](ImageId a, ImageId b) {
				uint32_t widthA, widthB;
				reader->getWidth(a, widthA);
				reader->getWidth(b, widthB);
				return (widthA < widthB);
			});
			//imageMap[masterId] = thumbId;

			if (reader->getItemDataWithDecoderParameters(thumbId.get(), itemData, itemSize) == ErrorCode::OK)
			{
				picture = DecodeFrame(itemData, itemSize);
				if (picture != nullptr)
				{
					picture->SetFilename(filename);
				}
			}
		}

	}
	else
	{
		cout << "Can't find input file: " << filename << ". "
			<< "Please download it from https://github.com/nokiatech/heif_conformance "
			<< "and place it in same directory with the executable." << endl;
	}
    
    delete[] itemData;  
    Reader::Destroy(reader);
    return picture;   

}

/* raw JPEG image data */
static const unsigned char image_jpg[] = {
	0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 0x4a, 0x46, 0x49, 0x46, 0x00, 0x01,
	0x01, 0x01, 0x00, 0x48, 0x00, 0x48, 0x00, 0x00, 0xff, 0xdb, 0x00, 0x43,
	0x00, 0x14, 0x0e, 0x0f, 0x12, 0x0f, 0x0d, 0x14, 0x12, 0x10, 0x12, 0x17,
	0x15, 0x14, 0x18, 0x1e, 0x32, 0x21, 0x1e, 0x1c, 0x1c, 0x1e, 0x3d, 0x2c,
	0x2e, 0x24, 0x32, 0x49, 0x40, 0x4c, 0x4b, 0x47, 0x40, 0x46, 0x45, 0x50,
	0x5a, 0x73, 0x62, 0x50, 0x55, 0x6d, 0x56, 0x45, 0x46, 0x64, 0x88, 0x65,
	0x6d, 0x77, 0x7b, 0x81, 0x82, 0x81, 0x4e, 0x60, 0x8d, 0x97, 0x8c, 0x7d,
	0x96, 0x73, 0x7e, 0x81, 0x7c, 0xff, 0xc0, 0x00, 0x0b, 0x08, 0x00, 0x40,
	0x00, 0x40, 0x01, 0x01, 0x11, 0x00, 0xff, 0xc4, 0x00, 0x1b, 0x00, 0x00,
	0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x05, 0x06, 0x04, 0x03, 0x07, 0x02, 0x01, 0xff,
	0xc4, 0x00, 0x2f, 0x10, 0x00, 0x01, 0x03, 0x03, 0x02, 0x05, 0x03, 0x03,
	0x03, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x11,
	0x00, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x81, 0x61, 0x71,
	0x91, 0x13, 0x32, 0xa1, 0x14, 0x22, 0xc1, 0x15, 0x23, 0x52, 0xd1, 0xf0,
	0xff, 0xda, 0x00, 0x08, 0x01, 0x01, 0x00, 0x00, 0x3f, 0x00, 0xb3, 0xa2,
	0x8a, 0x28, 0xa2, 0x8a, 0x28, 0xa2, 0x97, 0x64, 0x72, 0xd6, 0x58, 0xd4,
	0x8f, 0xd5, 0x3d, 0xca, 0xa5, 0x7d, 0xa8, 0x4e, 0xaa, 0x3e, 0xb0, 0x3a,
	0x7a, 0x9d, 0x2b, 0x2d, 0x87, 0x13, 0xe3, 0xaf, 0x9f, 0x0c, 0xb6, 0xb5,
	0xb6, 0xe2, 0xb4, 0x48, 0x71, 0x30, 0x14, 0x7b, 0x02, 0x09, 0x14, 0xee,
	0x94, 0x64, 0x38, 0x87, 0x1f, 0x8d, 0x5f, 0xd3, 0x7d, 0xe2, 0xa7, 0x46,
	0xe8, 0x6c, 0x49, 0x1e, 0xfd, 0x07, 0xb1, 0x33, 0x5f, 0xb8, 0xdc, 0xf5,
	0x96, 0x51, 0x7c, 0x96, 0xee, 0x14, 0xba, 0x04, 0xf2, 0x2c, 0x42, 0xa3,
	0xd3, 0x70, 0x7c, 0x1a, 0x6d, 0x45, 0x2c, 0xcd, 0xe5, 0x11, 0x89, 0xb1,
	0x5b, 0xc4, 0x02, 0xe1, 0xd1, 0xb4, 0xcf, 0xdc, 0xa3, 0xfc, 0x0d, 0xcd,
	0x41, 0xde, 0xe3, 0xb2, 0x2e, 0xda, 0x1c, 0xbd, 0xe2, 0x4a, 0x90, 0xe9,
	0x04, 0x95, 0x2b, 0xf7, 0x41, 0xd0, 0x18, 0xe8, 0x36, 0x03, 0xc6, 0x91,
	0x4a, 0x81, 0x20, 0x82, 0x24, 0x10, 0x66, 0x45, 0x5a, 0xdd, 0xf1, 0x32,
	0xff, 0x00, 0xa2, 0x5a, 0x8b, 0x62, 0x57, 0x7d, 0x70, 0x80, 0x93, 0x1a,
	0x94, 0x10, 0x79, 0x4a,
};

/* length of data in image_jpg */
static const unsigned int image_jpg_len = sizeof(image_jpg);

/* dimensions of image */
static const unsigned int image_jpg_x = 64;
static const unsigned int image_jpg_y = 64;

/* start of JPEG image data section */
static const unsigned int image_data_offset = 20;
#define image_data_len (image_jpg_len - image_data_offset)

void CHeic::GetMetadata(const string &filename, uint8_t * & data, long & size)
{
	 auto* reader = Reader::Create();

	 if (reader->initialize(filename.c_str()) != ErrorCode::OK)
	 {
		 cout << "Can't find input file: " << filename << ". "
			 << "Please download it from https://github.com/nokiatech/heif_conformance "
			 << "and place it in same directory with the executable." << endl;
		 return;
	 }

	 FileInformation fileInfo{};
	 reader->getFileInformation(fileInfo);

	 // Find the primary item ID.
	 ImageId primaryItemId;
	 reader->getPrimaryItem(primaryItemId);

	 // Find item(s) referencing to the primary item with "cdsc" (content describes) item reference.
	 Array<ImageId> metadataIds;
	 reader->getReferencedToItemListByType(primaryItemId, "cdsc", metadataIds);
	 if (metadataIds.size > 0)
	 {
		 ImageId exifItemId = metadataIds[0];

		 // Optional: verify the item ID we got is really of "Exif" type.
		 FourCC itemType;
		 reader->getItemType(exifItemId, itemType);
		 if (itemType != "Exif")
		 {
			 return;
		 }

		 // Get item size from parsed information. For simplicity, assume it is the first and only non-image item in the
		 // file.
		 uint64_t itemSize = 1024 * 1024;
		 for (ItemInformation itemInfo : fileInfo.rootMetaBoxInformation.itemInformations)
		 {
			 if (itemInfo.itemId != exifItemId)
			 {
				 continue;
			 }
			 itemSize = itemInfo.size;
		 }
		 // Request item data.
		 if (size > 0)
		 {



			 /* raw EXIF header data */
			 static const unsigned char exif_header[] = {
				 0xff, 0xd8, 0xff, 0xe1
			 };
			 /* length of data in exif_header */
			 static const unsigned int exif_header_len = sizeof(exif_header);

			 uint8_t* memoryBuffer = new uint8_t[itemSize];
			 reader->getItemData(metadataIds[0], memoryBuffer, itemSize);

			 char value = 0;
			 int pos = 0;
			 memcpy(data, exif_header, exif_header_len);
			 pos += exif_header_len;
			 value = ((itemSize + 2) >> 8);
			 memcpy(data + pos, &value, 1);
			 pos++;
			 value = (itemSize + 2) & 0xff;
			 memcpy(data + pos, &value, 1);
			 pos++;
			 memcpy(data + pos, memoryBuffer + 4, itemSize - 4);
			 pos += itemSize - 4;
			 memcpy(data + pos, image_jpg + image_data_offset, image_data_len);
			 delete[] memoryBuffer;
			 itemSize = itemSize;
		 }
		 else
			 size = itemSize + 512;
	 }

	 Reader::Destroy(reader);
}

#endif