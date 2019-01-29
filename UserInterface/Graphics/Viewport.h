

#ifndef Viewport_H
#define Viewport_H


namespace OP2Internal
{

	class GFXClippedSurface;


	class Viewport
	{
	public:
		// Member functions

	public:
		// Member variables
		int b1;						// 0x0 ** [numUnitsVisible?]
		int bitVectorLineWidth;		// 0x4
		int bitVectorSize;			// 0x8
		int scrollX;				// 0xC
		int scrollY;				// 0x10
		int height;					// 0x14 [GFXSurface.height]
		int width;					// 0x18 [GFXSurface.width]
		int b3;						// 0x1C **
		int lightUpdateTileX;		// 0x20
		// View Rect
		int tileLeft;				// 0x24
		int tileTop;				// 0x28
		int tileRight;				// 0x2C
		int rectTileHeight;			// 0x30
		// Static Buffers
		char redrawBitVector1[400];	// 0x34  **
		char redrawBitVector2[400];	// 0x1C4 **
		int b6[100];				// 0x354 **
		char lightBitVector1[400];	// 0x4E4 **
		char lightBitVector2[400];	// 0x674 **
		// 
		int b9;						// 0x804 **
		char* redrawBitVector;		// 0x808 Background tiles to redraw
		char* oldRedrawBitVector;	// 0x80C **
		char* lightBitVector;		// 0x810 **
		char* oldLightBitVector;	// 0x814 **
		bool bTotalBackgroundRedraw;// 0x818 **
		// 
		int tileWidth;				// 0x81C Account for fractional tile position (on either size)
		int tileHeight;				// 0x820 Account for fractional tile position (on either size)
		// 
		GFXClippedSurface* surface;	// 0x824
		int oldPixelX;				// 0x828
		int oldPixelY;				// 0x82C
		// 
		int pixelX;					// 0x830
		int pixelY;					// 0x834
		int tileStartPixelOffsetX;	// 0x838 [0 .. -31]
		int tileStartPixelOffsetY;	// 0x83C [0 .. -31]
		int tileX;					// 0x840
		int tileY;					// 0x844
		int b15;					// 0x848 **
	};

}	// End namespace


#endif
