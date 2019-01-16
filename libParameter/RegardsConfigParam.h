#pragma once


#include "ConfigParam.h"
#include <iostream>
#include <fstream>
using namespace rapidxml;


class CRegardsConfigParam : public CConfigParam
{
public:
	CRegardsConfigParam();
	~CRegardsConfigParam();

	int GetPreviewLibrary();
	void SetPreviewLibrary(const int &numLib);

	bool GetDatabaseInMemory();
	void SetDatabaseInMemory(const int &value);
    
    float GetIconSizeRatio();
    void SetIconSizeRatio(const float &ratio);
    
	int GetVideoLibrary();
	void SetVideoLibrary(const int &numLib);

	int GetEffectLibrary();
	void SetEffectLibrary(const int &numLib);

	int GetOpenCLPlatformIndex();
	void SetOpenCLPlatformIndex(const int &numIndex);

	int GetFaceDetectionPictureSize();
	void SetFaceDetectionPictureSize(const int &numIndex);

	wxString GetOpenCLPlatformName();
	void SetOpenCLPlatformName(const wxString &platformName);

	int GetEffect();
	void SetEffect(const int &numEffect);

	wxString GetUrlServer();
    int GetNbGpsIterationByMinute();

	int GetDiaporamaTime();
	void SetDiaporamaTime(const int &diaporamaTime);

	int GetDiaporamaTransitionEffect();
	void SetDiaporamaTransitionEffect(const int &diaporamaEffect);

	int GetDiaporamaFullscreen();
	void SetDiaporamaFullscreen(const int &diaporamaFullscreen);

	int GetThumbnailQuality();
	void SetThumbnailQuality(const int &quality);

	int GetThumbnailIconeCache();
	void SetThumbnailIconeCache(const int &iconeCache);
    
	int GetThumbnailProcess();
	void SetThumbnailProcess(const int &nbProcess);
    
	int GetFaceProcess();
	void SetFaceProcess(const int &nbProcess);

	int GetExifProcess();
	void SetExifProcess(const int &nbProcess);

	int GetNumLanguage();
	void SetNumLanguage(const int &numLanguage);

protected:

	void InitVideoToolbar();
	void InitBitmapToolbar();
	void InitClickToolbar();
	void InitToolbar();

	void LoadParameter();
	void SaveParameter();
    
    void SetIconParameter(xml_node<>* sectionPosition);
    void GetIconParameter(xml_node<>* position_node);

	void SetImageLibrary(xml_node<>* sectionPosition);
	void GetImageLibrary(xml_node<> * position_node);

	void SetDatabaseParameter(xml_node<>* sectionPosition);
	void GetDatabaseParameter(xml_node<> * position_node);

	void SetEffectLibrary(xml_node<>* sectionPosition);
	void GetEffectLibrary(xml_node<> * position_node);

	void SetVideoLibrary(xml_node<>* sectionPosition);
	void GetVideoLibrary(xml_node<> * position_node);

	void SetDiaporamaParameter(xml_node<>* sectionPosition);
	void GetDiaporamaParameter(xml_node<> * position_node);

	void SetGeolocalisationServer(xml_node<>* sectionPosition);
	void GetGeolocalisationServer(xml_node<> * position_node);

	void SetThumbnail(xml_node<>* sectionPosition);
	void GetThumbnail(xml_node<> * position_node);
	
	int pictureSize;
	int numLibPreview;
	int numLibEffect;
	int numLibVideo;
	int numEffect;
	int openCLNumIndex;
    int numLanguage;

	//Diaporama
	int diaporamaTime;
	int diaporamaEffect;
	int diaporamaFullscreen;

	int thumbnailQuality;
	int thumbnailIconeCache;

    float iconSizeRatio;
	wxString openCLPlatformName;
	wxString geolocUrl;

	int dataInMemory;
    
    int nbProcessThumbnail;
    int nbProcessExif;
    int nbProcessFace;
    int nbGpsFileByMinute;

};

