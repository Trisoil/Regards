#pragma once

class CConvertUtility
{
public:
	CConvertUtility(void);
	~CConvertUtility(void);

	static wxString GetTimeLibelle(const int &timePosition);
	static std::vector<wxString> split(const wxString & s, char seperator);
    static const char * ConvertToUTF8(const wxString & s);
    static const std::string ConvertToStdString(const wxString & s);
    static const std::wstring ConvertToStdWstring(const wxString & s);
};

