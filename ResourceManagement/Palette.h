#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#ifndef Palette_H
#define Palette_H


namespace OP2ForcedExport
{

	class StreamIO;

	enum PaletteFormatFlags
	{
		PaletteFormatRiff = 0x80000000,
	};


	// Max Size: 0x454  [New]
	class Palette
	{
	public:
		// Constructor/Destructor
		Palette();											// 0x4AA860
		~Palette();											// 0x4AA8C0

		// Member functions
		void SetPalette(PALETTEENTRY* newEntryTable);		// 0x4AA930
		void SetPalette(RGBQUAD* newEntryTable);			// 0x4AA960 [BGR => RGB]
		void GetPalette(PALETTEENTRY* entryTable);			// 0x4AA9B0
		void GetPalette(RGBQUAD* rgbTable);					// 0x4AA9E0 [RGB => BGR]

		int Load(char* fileName, int unused);				// 0x4AAB60 BSuccess
		int Load(StreamIO* stream, int unused);				// 0x4AABE0 BSuccess
		int LoadRiffPalette(StreamIO* stream, int unused);	// 0x4AAE50 BSuccess
		int Save(char* fileName, int formatFlags);			// 0x4AAF20 BSuccess
		int Save(StreamIO* stream, int formatFlags);		// 0x4AAF90 BSuccess
		int SaveRiffPalette(StreamIO* stream, int unused);	// 0x4AB1E0 BSuccess
		int F2();											// 0x4AB2C0 **

		// Static functions
		static Palette* __fastcall CreatePalette(PALETTEENTRY* newEntryTable);	// 0x4AAA20
		static Palette* __fastcall CreatePalette(RGBQUAD* newEntryTable);		// 0x4AAA60
		static Palette* __fastcall CreatePalette(char* fileName);				// 0x4AAAA0
		static Palette* __fastcall CreatePalette(StreamIO* stream);				// 0x4AAB00

	public:
		// Member variables
		short b1;						// 0x0 ** [0x300]
		short numEntries;				// 0x2
		PALETTEENTRY entryTable[256];	// 0x4
		int b10;						// 0x404 **
		int b13;						// 0x408 **
		int b11;						// 0x40C **
		// 0x410 **
		int b14;						// 0x414 **
		int b12;						// 0x418 **
		int b15;						// 0x41C **
		// 0x420 **
		int* b2;						// 0x424 **
		// 0x428 **
		int* b3;						// 0x42C **
		int* b4;						// 0x430 **
		int* b5;						// 0x434 **
		int* b6;						// 0x438 **
		int* b7;						// 0x43C **
		int b8;							// 0x440 **
		int b9;							// 0x444 **
		// 0x448 **
		// 0x44C **
		// 0x450 **
		// ----
	};

}	// End namespace


#endif
