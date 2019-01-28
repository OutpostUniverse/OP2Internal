

#ifndef BitmapLightAdjustedBitmapMemoryMappedBitmap_H
#define BitmapLightAdjustedBitmapMemoryMappedBitmap_H


#include "BitmapLightAdjustedBitmap.h"
#include "..\WinTypes.h"


namespace OP2Internal
{

	// Min Size: 0xF8 [Member field access]
	// Max Size: 
	class MemoryMappedBitmap : public LightAdjustedBitmap
	{
	public:
		// Constructor/Destructor
		MemoryMappedBitmap();			// 0x403730
		~MemoryMappedBitmap();			// 0x403760

		// Member functions
		void Close();					// 0x4037C0
		int  Load(char* fileBaseName, int numLightLevels, int unused);	// 0x403820 BSuccess

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
		HANDLE hFile;					// 0xDC
		HANDLE hMapping;				// 0xE0
		void* mappedAddress;			// 0xE4
		int fileSize;					// 0xE8
		char* pixelData;				// 0xEC
		int b5;							// 0xF0 **
		int b6;							// 0xF4 **
		//int b7;							// 0xF8 ** ?
	};

}	// End namespace


#endif
