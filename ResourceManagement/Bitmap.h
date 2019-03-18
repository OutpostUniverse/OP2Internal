#pragma once


namespace OP2Internal
{

	class StreamIO;
	class Palette;
	struct Rect;

	enum BitmapFlags
	{
		BitmapFlagLoadPaletteData	= 1,
		BitmapFlagFreeImageBuffer	= 8,
		BitmapFlagSaveBmpFormat		= 0x80000000,
	};


	// Min Size: 0x20 [Member field access]
	// Max Size: 0x20 [New]
	class Bitmap
	{
	public:
		// Constructor/Destructor
		Bitmap();						// 0x419950
		~Bitmap();						// 0x419970  [0x4199C0 is an identical copy]

		// Static functions
		Bitmap* __fastcall CreateBitmap(int width, int height, int bitDepth);	// 0x419A10
		Bitmap* __fastcall LoadBitmap(char* fileName, int flags);				// 0x419C90
		Bitmap* __fastcall LoadBitmap(StreamIO* stream, int flags);				// 0x419D90

		// Member functions
		Bitmap* CreateSubBitmap(Rect* sourceRect);								// 0x419B00
		void SetSourceBitmap(Bitmap* sourceBitmap, Rect* sourceRect);			// 0x419BE0
		int Load(char* fileName, int flags);									// 0x419E30 BSuccess
		int Load(StreamIO* stream, int flags);									// 0x419EB0 BSuccess
		int LoadBmpFile(StreamIO* stream, int flags);							// 0x41A110 BSuccess
		int Save(char* fileName, int flags);									// 0x41A2B0 BSuccess
		int Save(StreamIO* stream, int flags);									// 0x41A320 BSuccess
		int SaveBmpFile(StreamIO* stream, int flags);							// 0x41A440 BSuccess
		int F1();																// 0x41A5D0 ** (int/void*/char*)

	public:
		// Member variables
		int width;				// 0x0
		int height;				// 0x4
		int pitch;				// 0x8
		int bitDepth;			// 0xC
		int imageBufferSize;	// 0x10 [((pitch * bitDepth) / 8) * height]
		char* imageBuffer;		// 0x14 char[imageBufferSize]*
		Palette* palette;		// 0x18
		int flags;				// 0x1C **
		// ----
	};

}	// End namespace
