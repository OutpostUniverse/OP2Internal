

#ifndef GFXSurfaceGFXCDSSurfaceGFXClippedSurface_H
#define GFXSurfaceGFXCDSSurfaceGFXClippedSurface_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "GFXSurfaceGFXCDSSurface.h"
#include "Viewport.h"
#include "..\..\PointTypes.h"


namespace OP2ForcedExport
{

	class GFXClippedSurface : public GFXCDSSurface
	{
	public:
		// Base class virtual member functions

		// Non virtual member functions

	public:
		// Member variables
		Rect drawRect;					// 0xB0
		bool bScreenRequiresUpdate;		// 0xC0
		bool bMarkBackgroundOnDraw;		// 0xC4 **
		BITMAPINFO bitmapInfo;			// 0xC8
		BITMAPINFO* pBitmapInfo;		// 0xF4
		Rect redrawRect;				// 0xF8
		int* b2;						// 0x108 **
		int zoom;						// 0x10C
		Viewport viewport;				// 0x110
	};

}	// End namespace


#endif
