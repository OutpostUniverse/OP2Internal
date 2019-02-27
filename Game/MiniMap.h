#pragma once


#include "../PointTypes.h"


namespace OP2Internal
{

	class GFXClippedSurface;
	class Bitmap;


	class MiniMap
	{
	public:
		// Member functions

	public:
		// Member variables
		int b1[11];						// 0x0    **
		short* updatedPixel[1023];		// 0x2C   Address of pixel overwritten with a unit dot
		int numUpdatedPixels;			// 0x1028 Number of unit dots drawn on minimap
		Rect viewRectNew;				// 0x102C
		Rect viewRectOld;				// 0x103C
		int bInvertMapColors;			// 0x104C
		int maxZoomOut;					// 0x1050 Min value for zoom
		int zoom;						// 0x1054 [maxZoomOut .. 5]
		int b4[2];						// 0x1058 **
		short playerMiniMapColor[8];	// 0x1060
		int b5[4];						// 0x1070 **
		GFXClippedSurface* surface;		// 0x1080 *  Duplicated below?
		int miniMapFlags;				// 0x1084 **
		int bGlobeView;					// 0x1088 *  Maybe?
		Point miniMapClickPos;			// 0x108C
		Point miniMapScrollPos;			// 0x1094
		int b7;							// 0x109C [Day/Night related?]
		Bitmap* miniMapBackgroud;		// 0x10A0 Cached terrain map
		Bitmap* surfaceBackBuffer;		// 0x10A4 Terrain with unit overlay (dots)
		GFXClippedSurface* surface2;	// 0x10A8 *  Difference from above?
		short** brightness;				// 0x10AC *  Maybe?  [short[tileWidth*2]*]
		int b8;							// 0x10B0 **
		// ...?
	};

}	// End namespace
