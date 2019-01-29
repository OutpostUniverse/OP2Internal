

#ifndef GFXSurfaceGFXCDSSurface_H
#define GFXSurfaceGFXCDSSurface_H


#include "GFXSurface.h"


namespace OP2Internal
{

	// Min Size: 
	// Max Size: 0xB0 [New]
	class GFXCDSSurface : public GFXSurface
	{
	public:
		// Base class virtual members
		virtual void UpdatePalette(Palette* palette, int startEntry, int numEntries);
		virtual void LockImageBuffer();
		virtual void UnlockImageBuffer();
		virtual void LockMemoryDC();
		virtual void UnlockMemoryDC();
		virtual void* Release(int flags);
		virtual int GetF1();
		virtual int GetF2(int* a1);
		virtual void Realloc(HWND hWnd);
		virtual void F3();
		virtual void Draw(Rect* drawRect);
		virtual void Draw();
		virtual void F4(int a1, int a2, int a3);

		// Non virtual member functions


	public:
		// Member variables
		// ----
		// vtbl						// 0x0
		// ...
		// ----
		HBITMAP hDibSection;		// 0x78
		void* pBits;				// 0x7C
		HDC hDestDC;				// 0x80
		HDC hSrcDC;					// 0x84
		HPALETTE hNewPalette;		// 0x88
		HPALETTE hOldPalette;		// 0x8C
		HBITMAP hOldDibSection;		// 0x90
		HWND hDestWnd;				// 0x94
		int b1[6];					// 0x98 **
		// ----
	};

}	// End namespace


#endif
