#pragma once
class CRegardsBitmap;


class IStatusBarInterface
{
public:
	virtual void SetText(const int &numPos, const wxString &libelle) = 0;
	virtual void SetRangeProgressBar(const int &range) = 0;
	virtual void SetPosProgressBar(const int &position) = 0;
	virtual void SetWindowTitle(const wxString &libelle) = 0;
    virtual void SetFullscreen(){};
	virtual void SetScreen(){};
	virtual void PrintPreview(CRegardsBitmap * imageToPrint){};
	virtual void Exit() = 0;
	virtual void ShowViewer(){};
};