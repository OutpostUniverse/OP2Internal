

#ifndef GFXSurfaceGFXMemSurface_H
#define GFXSurfaceGFXMemSurface_H


#include "GFXSurface.h"


namespace OP2Internal
{

	class GFXMemSurface : public GFXSurface
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
	};

}	// End namespace


#endif
