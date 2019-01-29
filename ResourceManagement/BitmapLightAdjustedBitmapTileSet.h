

#ifndef BitmapLightAdjustedBitmapTileSet_H
#define BitmapLightAdjustedBitmapTileSet_H


#include "BitmapLightAdjustedBitmap.h"


typedef struct tagPALETTEENTRY PALETTEENTRY;
typedef struct tagRGBQUAD RGBQUAD;


namespace OP2Internal
{

	// Min Size: 
	// Max Size: 
	class TileSet : public LightAdjustedBitmap
	{
	public:
		// Constructor/Destructor
		TileSet();						// 0x4A8330
		~TileSet();						// 0x4A8340

		// Member functions
		int Load(int numTiles, char* fileBaseName, int bSpecialScale);	// 0x4A8360 BSuccess
		int LoadAndFlatten(char* fileBaseName, int bSpecialScale);		// 0x4A83E0 BSuccess  [Might only work for 8 bit bitmaps]
		void Flatten();													// 0x4A8560 Converts an (x,y) tile bitmap into an (1, x*y) tile bitmap  [Might only work for 8 bit bitmaps]
		void F2(int a1);												// 0x4A8620 **
		TileSet* Copy(TileSet** sourceTileSet, int a2);					// 0x4A86C0 **

		// Static functions
		static void __fastcall F3(PALETTEENTRY entryTable[256], RGBQUAD rgbTable[256]);	// 0x4A8680 **

	public:
		// Member variables
		// ----
		// int width;					// 0x0
		// int height;					// 0x4
		// int pitch;					// 0x8
		// int bitDepth;				// 0xC
		// int imageBufferSize;			// 0x10 [((pitch * bitDepth) / 8) * height]
		// char* imageBuffer;			// 0x14 char[imageBufferSize]*
		// Palette* palette;			// 0x18
		// int flags;					// 0x1C
		// ----
		// int numLightLevels;			// 0x20 [+1]
		// int b1;						// 0x24 **
		// int drawMethod;				// 0x28 ** bit flags? int enum?
		// short* lightLevelPal16;		// 0x2C short[256][numLightLevel+1?]*
		// char mappedPlayerColors[32];	// 0x30 [lighLevel indexed]
		// int b2;						// 0x50 **
		// short* pal16[32];			// 0x54 ** short[256]*[32]
		// int b3;						// 0xD4 **
		// int b4;						// 0xD8 **
		// ----
		int numTiles;					// 0xDC ** [tileWidth * tileHeight]
		int numTilesRequested;			// 0xE0 ** [0]
		int numTilesX;					// 0xE4 
		int numTilesY;					// 0xE8 
		int tileHeight;					// 0xEC [Height of a tile in pixels]
		int tileSetHeight;				// 0xF0 [Height of the entire tileset bitmap in pixels]
		int bytesPerTile;				// 0xF4 [Pitch * TileHeight]
		char* pixelData;				// 0xF8
		// ----
	};

}	// End namespace


#endif
