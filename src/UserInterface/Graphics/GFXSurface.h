#pragma once


#include "../../WinTypes.h"


namespace OP2Internal
{

	// Referenced classes
	class Palette;
	struct Rect;


	// Min Size: 
	// Max Size: 
	class GFXSurface
	{
	public:
		// Virtual member functions
		virtual void UpdatePalette(Palette* palette, int startEntry, int numEntries) = 0;
		virtual void LockImageBuffer() = 0;
		virtual void UnlockImageBuffer() = 0;
		virtual void LockMemoryDC() = 0;
		virtual void UnlockMemoryDC() = 0;
		virtual void* Release(int flags);
		virtual int GetF1() = 0;
		virtual int GetF2(int* a1);
		virtual void Realloc(HWND hWnd);
		virtual void F3() = 0;
		virtual void Draw(Rect* drawRect);
		virtual void Draw();
		virtual void F4(int a1, int a2, int a3) = 0;

		// Non virtual member functions

	public:
		// Member variables
		// ----
		// vtbl						// 0x0
		int flags;					// 0x4
		int b1[2];					// 0x8 **
		int maxX;					// 0x10
		int maxY;					// 0x14
		int b2[6];					// 0x18 **
		Palette* palette;			// 0x30
		char* imageBuffer;			// 0x34
		int pitch;					// 0x38
		int width;					// 0x3C
		int height;					// 0x40
		int bitDepth;				// 0x44
		int b3[7];					// 0x48 **
		int imageBufferLockCount;	// 0x64
		int memoryDCLockCount;		// 0x68
		HDC hMemDC;					// 0x6C
		int b4[2];					// 0x70 **
		// ----
	};

}	// End namespace
