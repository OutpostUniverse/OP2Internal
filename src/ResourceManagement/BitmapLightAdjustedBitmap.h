#pragma once


#include "Bitmap.h"


namespace OP2Internal
{

	// Min Size: 
	// Max Size: 0xDC [New]
	class LightAdjustedBitmap : public Bitmap
	{
	public:
		// Constructor/Destructor
		LightAdjustedBitmap();				// 0x4A9B30
		~LightAdjustedBitmap();				// 0x4A9B70

		// Member functions
		void Convert8To16();				// 0x4A9B90
		int Load(char* fileName, int bSpecialColorScale, int numLightLevels);	// 0x4A9CC0	BSuccess  [special scale only applies to colors with min{red, green, blue} = blue, and (((max{r,g,b} - min{r,g,b}) * 256) / max{r,g,b}) >= 64]  [Lava => lightLevel * 2 + 8, out of 32 light levels]

		// Static fucntions
		static LightAdjustedBitmap* __fastcall CreateBitmap(int width, int height, int bitDepth);	// 0x4AA0D0

	public:
		// Member variables
		// int width;					// 0x0
		// int height;					// 0x4
		// int pitch;					// 0x8
		// int bitDepth;				// 0xC
		// int imageBufferSize;			// 0x10 [((pitch * bitDepth) / 8) * height]
		// char* imageBuffer;			// 0x14 char[imageBufferSize]*
		// Palette* palette;			// 0x18
		// int flags;					// 0x1C
		// ----
		int numLightLevels;				// 0x20 [+1]
		int b1;							// 0x24 **
		int drawMethod;					// 0x28 ** bit flags? int enum?
		short* lightLevelPal16;			// 0x2C short[256][numLightLevel+1?]*
		char mappedPlayerColors[32];	// 0x30 [lighLevel indexed]
		int b2;							// 0x50 **
		short* pal16[32];				// 0x54 ** short[256]*[32]
		int b3;							// 0xD4 **
		int b4;							// 0xD8 **
		// ----
	};

}	// End namespace
