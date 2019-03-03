#pragma once
#include "PictureData.h"

class CLibResource
{
public:
	CLibResource(){};
	~CLibResource(){};
    static void InitializeSQLServerDatabase(const wxString & folder);
    static void KillSqlEngine();
    CPictureData * LoadBitmapFromResource(const wxString &idName);
    static wxString LoadStringFromResource(const wxString &idName, const int &idLang);
	static wxString LoadExifNameFromResource(const wxString &id);
    static wxString GetShaderProgram(const wxString &idName);
    static wxString GetVector(const wxString &idName);
    static int GetExtensionId(const wxString &extension);
};