

#ifndef Viewport_H
#define Viewport_H


namespace OP2ForcedExport
{

	class GFXClippedSurface;


	class Viewport
	{
	public:
		// Member functions

	public:
		// Member variables
		int b1;					// **
		int redrawBackgroundBitVectorLineWidth;
		int redrawBackgroundBitVectorSize;
		int b2[2];				// **
		int height;				// [GFXSurface.height]
		int width;				// [GFXSurface.width]
		int b3[2];				// **
		// 
		int tileLeft;
		int tileTop;
		int tileRight;
		int rectTileHeight;
		// 
		int b4[100];			// **
		int b5[100];			// **
		int b6[100];			// **
		int b7[100];			// **
		int b8[100];			// **
		int b9;					// **
		char* redrawBackgroundBitVector;		// Main view? **
		char* b10;				// **
		char* b11;				// **
		char* b12;				// **
		bool b13;				// **
		// 
		int tileWidth;			// Account for fractional tile position (on either size)
		int tileHeight;			// Account for fractional tile position (on either size)
		// 
		GFXClippedSurface* surface;
		int b14[2];				// **
		// 
		int pixelX;
		int pixelY;
		int tileStartPixelOffsetX;		// [0 .. -31]
		int tileStartPixelOffsetY;		// [0 .. -31]
		int tileX;
		int tileY;
		int b15;				// **
	};

}	// End namespace


#endif
