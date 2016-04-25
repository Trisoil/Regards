#include "infoAbout.h"
#include "TreeElementTexte.h"
#include "TreeElementTexteClick.h"
#include "TreeDataLink.h"

using namespace Regards::Introduction;

CInfoAbout::CInfoAbout(CThemeTree * theme)
{
	themeTree = *theme;
	themeTree.themeTexte.SetHeight(themeTree.GetRowHeight());
	themeTree.SetMargeX(5);
	rowWidth.push_back(0);
	rowWidth.push_back(0);
};



CInfoAbout::~CInfoAbout()
{
	
}

void CInfoAbout::Init()
{
	top = tr.begin();
	tree<CTreeData *>::iterator top;
//	int item = 0;
//	int index = 0;

	top = tr.begin();

	tree<CTreeData *>::iterator child = top;

	CTreeData * treeDataPicture = new CTreeData();
	treeDataPicture->SetKey("Informations");
	child = tr.insert(top, treeDataPicture);

	CTreeData * treeDataFileName = new CTreeData();
	treeDataFileName->SetIsParent(false);
	treeDataFileName->SetKey("Developper");
	treeDataFileName->SetValue("Figuinha Jacques");
	tr.append_child(child, treeDataFileName);

	CTreeData * treeDataWidth = new CTreeData();
	treeDataWidth->SetIsParent(false);
	treeDataWidth->SetKey("Version");
	treeDataWidth->SetValue("2.4.0");
	tr.append_child(child, treeDataWidth);

	CTreeData * treeDataAnnee = new CTreeData();
	treeDataAnnee->SetIsParent(false);
	treeDataAnnee->SetKey("Copyright");
	treeDataAnnee->SetValue("2015 - 2016");
	tr.append_child(child, treeDataAnnee);

	CTreeData * treeDataLib = new CTreeData();
	treeDataLib->SetKey("External Library");
	child = tr.insert(top, treeDataLib);

	CTreeDataLink * treeFFMPEG = new CTreeDataLink();
	treeFFMPEG->SetIsParent(false);
	treeFFMPEG->SetKey("LibCairo");
    treeFFMPEG->SetLinkType(1);
    treeFFMPEG->SetLinkPath("mpl11.pdf");
	treeFFMPEG->SetValue("1.14.2 - Mozilla Public License (MPL) - Click to see licence");
	tr.append_child(child, treeFFMPEG);

	CTreeData * treeSQLite = new CTreeData();
	treeSQLite->SetIsParent(false);
	treeSQLite->SetKey("SQLite");
	treeSQLite->SetValue("3.8.5");
	tr.append_child(child, treeSQLite);

	CTreeData * treeRapipXML = new CTreeData();
	treeRapipXML->SetIsParent(false);
	treeRapipXML->SetKey("Rapid XML");
	treeRapipXML->SetValue("1.13");
	tr.append_child(child, treeRapipXML);

	CTreeData * treeHH = new CTreeData();
	treeHH->SetIsParent(false);
	treeHH->SetKey("tree.hh");
	treeHH->SetValue("2.81");
	tr.append_child(child, treeHH);

	CTreeData * treeCxImage = new CTreeData();
	treeCxImage->SetIsParent(false);
	treeCxImage->SetKey("CxImage ");
	treeCxImage->SetValue("7.0");
	tr.append_child(child, treeCxImage);
#if defined(__APPLE__) || defined(__WIN32__)
	CTreeDataLink * treelibRaw = new CTreeDataLink();
	treelibRaw->SetIsParent(false);
	treelibRaw->SetKey("MediaInfoLib");
    treelibRaw->SetLinkType(1);
    treelibRaw->SetLinkPath("MediaInfoLicense.pdf");
	treelibRaw->SetValue("0.7.76 - BSD Licence Like - Click to see licence");
	tr.append_child(child, treelibRaw);
#else
	CTreeData * treelibRaw = new CTreeData();
	treelibRaw->SetIsParent(false);
	treelibRaw->SetKey("Libraw");
	treelibRaw->SetValue("0.17.0");
	tr.append_child(child, treelibRaw);

	CTreeData * treelibFFmpeg = new CTreeData();
	treelibFFmpeg->SetIsParent(false);
	treelibFFmpeg->SetKey("FFMpeg");
	treelibFFmpeg->SetValue("2.6.2");
	tr.append_child(child, treelibFFmpeg);

	CTreeData * treelibExiv = new CTreeData();
	treelibExiv->SetIsParent(false);
	treelibExiv->SetKey("Exiv 2");
	treelibExiv->SetValue("0.24");
	tr.append_child(child, treelibExiv);
#endif
	CTreeData * treelibBPG = new CTreeData();
	treelibBPG->SetIsParent(false);
	treelibBPG->SetKey("wxWidget");
	treelibBPG->SetValue("3.0.2");
	tr.append_child(child, treelibBPG);

	CreateElement();
}


void CInfoAbout::CreateElement()
{
	bool isVisible = true;
	widthPosition = 0;

	tree<CTreeData *>::sibling_iterator it = tr.begin();
	tree<CTreeData *>::iterator itend = tr.end();
	yPos = 0;
	nbRow = 0;

	while (it != itend) {
		CTreeData * data = *it;
		int profondeur = tr.depth(it);
		if (profondeur == 0)
		{

			int xPos = themeTree.GetMargeX();
			int widthElement = 0;
			CTreeElementTexte * treeElementTexte = nullptr;
			CTreeElementTriangle * treeElementTriangle = nullptr;
			CPositionElement * posElement = nullptr;

			treeElementTriangle = CreateTriangleElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), true);
			treeElementTriangle->SetVisible(isVisible);
			posElement = CreatePositionElement(xPos, yPos, nbRow, 0, treeElementTriangle->GetWidth(), treeElementTriangle->GetHeight(), ELEMENT_TRIANGLE, treeElementTriangle, data);

			xPos += posElement->GetWidth() + themeTree.GetMargeX();
			widthPosition = posElement->GetWidth() + themeTree.GetMargeX();


            if(data->GetType() == 2)
            {
                CTreeDataLink * dataLink = (CTreeDataLink *)data;
                treeElementTexte = CreateTexteLinkElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey(), dataLink->GetLinkPath(), dataLink->GetLinkType());
            }
            else
                treeElementTexte = CreateTexteElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey());
            
			treeElementTexte->SetVisible(isVisible);
			posElement = CreatePositionElement(xPos, yPos, nbRow, 0, treeElementTexte->GetWidth(), treeElementTexte->GetHeight(), ELEMENT_TEXTE, treeElementTexte, data, false);

			widthElement += xPos + posElement->GetWidth() + themeTree.GetMargeX();
			yPos += themeTree.GetRowHeight();
			nbRow++;
			if (rowWidth[0] < widthElement)
				rowWidth[0] = widthElement;

			if (treeElementTriangle->GetOpen())
				CreateChildTree(it);

		}
		it++;

	}
}

void CInfoAbout::ClickOnElement(CPositionElement * element, wxWindow * window, const int &x, const int &y, const int& posLargeur, const int &posHauteur)
{
    CTreeElement * treeElement = element->GetTreeElement();
    if (element->GetType() == ELEMENT_TEXTEVALUE)
    {
        CTreeElementTexteClick * treeElementTexte= (CTreeElementTexteClick *)treeElement;
        treeElementTexte->ClickElement(window, x, y);
    }
    
}

void CInfoAbout::CreateChildTree(tree<CTreeData *>::sibling_iterator &parent)
{
	CPositionElement * posElement = nullptr;
	tree<CTreeData *>::sibling_iterator it = tr.begin(parent);
	//tree<CTreeData *>::iterator itend = tr.end(parent);
	bool isVisible = true;
	//int i = 

	for (int i = 0; i < parent.number_of_children(); i++)
	{
		int profondeur = tr.depth(it);
		CTreeData * data = *it;

		if (data->GetValue().size() > 0 || it.number_of_children() == 0)
		{
			int xPos = widthPosition * (profondeur + 1);
			int widthElementColumn1 = 0;
			int widthElementColumn2 = 0;
			CTreeElementTexte * treeElementTexte = nullptr;

            if(data->GetType() == 2)
            {
                CTreeDataLink * dataLink = (CTreeDataLink *)data;
                treeElementTexte = CreateTexteLinkElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey(), dataLink->GetLinkPath(), dataLink->GetLinkType());
            }
            else
                treeElementTexte = CreateTexteElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey());
			
            treeElementTexte->SetVisible(isVisible);
			posElement = CreatePositionElement(xPos, yPos, nbRow, 0, treeElementTexte->GetWidth(), treeElementTexte->GetHeight(), ELEMENT_TEXTE, treeElementTexte, data, false);

			widthElementColumn1 = xPos + posElement->GetWidth() + themeTree.GetMargeX();

			if (data->GetValue() != "")
			{
				xPos = themeTree.GetMargeX();
                
                if(data->GetType() == 2)
                {
                    CTreeDataLink * dataLink = (CTreeDataLink *)data;
                    treeElementTexte = CreateTexteLinkElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetValue(), dataLink->GetLinkPath(), dataLink->GetLinkType());
                }
                else
                    treeElementTexte = CreateTexteElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetValue());
				
                treeElementTexte->SetVisible(isVisible);
				posElement = CreatePositionElement(xPos, yPos, nbRow, 1, treeElementTexte->GetWidth(), treeElementTexte->GetHeight(), ELEMENT_TEXTEVALUE, treeElementTexte, data, (data->GetType() == 2));
				widthElementColumn2 = xPos + posElement->GetWidth() + themeTree.GetMargeX();
			}

			yPos += themeTree.GetRowHeight();

			nbRow++;
			if (rowWidth[0] < widthElementColumn1)
				rowWidth[0] = widthElementColumn1;

			if (rowWidth[1] < widthElementColumn2)
				rowWidth[1] = widthElementColumn2;
		}
		else
		{
			int xPos = widthPosition * profondeur;
			int widthElement = 0;
			CTreeElementTexte * treeElementTexte = nullptr;
			CTreeElementTriangle * treeElementTriangle = nullptr;
			treeElementTriangle = CreateTriangleElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), true);
			treeElementTriangle->SetVisible(isVisible);
			posElement = CreatePositionElement(xPos, yPos, nbRow, 0, treeElementTriangle->GetWidth(), treeElementTriangle->GetHeight(), ELEMENT_TRIANGLE, treeElementTriangle, data);

			xPos += posElement->GetWidth() + themeTree.GetMargeX();

            if(data->GetType() == 2)
            {
                CTreeDataLink * dataLink = (CTreeDataLink *)data;
                treeElementTexte = CreateTexteLinkElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey(), dataLink->GetLinkPath(), dataLink->GetLinkType());
            }
            else
                treeElementTexte = CreateTexteElement(themeTree.GetRowWidth(), themeTree.GetRowHeight(), data->GetKey());
            
			treeElementTexte->SetVisible(isVisible);
			posElement = CreatePositionElement(xPos, yPos, nbRow, 0, treeElementTexte->GetWidth(), treeElementTexte->GetHeight(), ELEMENT_TEXTE, treeElementTexte, data, false);

			widthElement = xPos + posElement->GetWidth() + themeTree.GetMargeX();
			yPos += themeTree.GetRowHeight();

			nbRow++;
			if (rowWidth[0] < widthElement)
				rowWidth[0] = widthElement;

			CreateChildTree(it);
		}
		it++;

	}
}