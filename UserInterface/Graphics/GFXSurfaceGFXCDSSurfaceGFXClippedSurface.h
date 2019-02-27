#pragma once


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "GFXSurfaceGFXCDSSurface.h"
#include "Viewport.h"
#include "../../PointTypes.h"


namespace OP2Internal
{

	class GFXClippedSurface : public GFXCDSSurface
	{
	public:
		// Base class virtual member functions

		// Non virtual member functions
		void DrawLine(Point& p1, Point& p2, int color16);	// 0x41EFF0

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

	

	// Global functions
	void __fastcall DrawBorder(GFXClippedSurface& surface, Rect& position, short topLeftColor16, short bottomRightColor16, int bReverse);	// 0x40B2F0
	void __fastcall DrawBox(GFXClippedSurface* surface, Rect* position, short color16);		// 0x40B4D0
	void __fastcall DrawHpBar(Rect* position, GFXClippedSurface* surface, int currentHp, int maxHp, short hpBarColor16, short hpBarBackgroundColor16, int a1, short a2Color16, int a3, short a4Color16);	// 0x45C3A0

}	// End namespace
