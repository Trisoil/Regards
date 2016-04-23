//////////////////////////////////////////////////////////////////////////////
// Name:        SVGRenderingIntent.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_RENDERING_INTENT_H
#define WX_SVG_RENDERING_INTENT_H


enum wxRENDERING_INTENT
{
  wxRENDERING_INTENT_UNKNOWN = 0,
  wxRENDERING_INTENT_AUTO = 1,
  wxRENDERING_INTENT_PERCEPTUAL = 2,
  wxRENDERING_INTENT_RELATIVE_COLORIMETRIC = 3,
  wxRENDERING_INTENT_SATURATION = 4,
  wxRENDERING_INTENT_ABSOLUTE_COLORIMETRIC = 5
};

class wxSVGRenderingIntent
{
  public:
    virtual ~wxSVGRenderingIntent() {}
};

#endif // WX_SVG_RENDERING_INTENT_H
