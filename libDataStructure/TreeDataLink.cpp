#include "TreeDataLink.h"

CTreeDataLink::CTreeDataLink(void)
{
    type = 2;
}


CTreeDataLink::~CTreeDataLink(void)
{
}

void CTreeDataLink::SetLinkType(const int & type)
{
    linktype = type;
}

int CTreeDataLink::GetLinkType()
{
    return linktype;
}

void CTreeDataLink::SetLinkPath(const wxString & value)
{
    linkPath = value;
}

wxString CTreeDataLink::GetLinkPath()
{
    return linkPath;
}