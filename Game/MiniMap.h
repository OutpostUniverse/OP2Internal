

#ifndef MiniMap_H
#define MiniMap_H


namespace OP2ForcedExport
{

	class GFXClippedSurface;
	class Bitmap;


	class MiniMap
	{
	public:
		// Member functions

	public:
		// Member variables
		int b1[11];						// **
		short* updatedPixel[1023];		// Address of pixel overwritten with a unit dot
		int numUpdatedPixels;			// Number of unit dots drawn on minimap
		int b2[4];						// **
		int b3[4];						// **
		int bInvertMapColors;			// 
		int maxZoomOut;					// Min value for zoom
		int zoom;						// [maxZoomOut .. 5]
		int b4[2];						// **
		short playerMiniMapColor[8];	// 
		int b5[4];						// **
		GFXClippedSurface* surface;		// *  Duplicated below?
		int b6;							// **
		int bGlobeView;					// *  Maybe?
		int b7[5];						// **
		Bitmap* miniMapBackgroud;		// Cached terrain map
		Bitmap* surfaceBackBuffer;		// Terrain with unit overlay (dots)
		GFXClippedSurface* surface2;	// *  Difference from above?
		short** brightness;				// *  Maybe?  [short[tileWidth*2]*]
		int b8;							// **
		// ...?
	};

}	// End namespace


#endif
