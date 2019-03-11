#pragma once


#include "IWnd.h"


namespace OP2Internal
{

	class GFXClippedSurface;
	class UIElement;
	struct Point;


	// Base class size: 0x14
	// Size: 0x6C
	class Pane : public IWnd
	{
	private:
		// virtual char const * RegisterClassA(void);
	public:
		// [IWnd] Virtual member functions
		virtual ~Pane();
		// virtual void Destroy(void);
		// virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,struct HWND__ *,struct HMENU__ *,void *,struct HINSTANCE__ *);
		virtual long WndProc(unsigned int uMsg, unsigned int wParam, long lParam);
		// virtual int CallFilters(unsigned int uMsg, unsigned int wParam, long lParam);

		// [New] Virtual member functions
		virtual void ReleaseSurface();
		virtual void ReallocSurface(int zoom);
		virtual void Draw();
		virtual void F1();							// **
		virtual bool GetAbsolutePos(int pixelX, int pixelY, Point& absolutePos);

		// Member functions
		void AddControl(UIElement& control);
		void RemoveControl(UIElement& control);
		void SetNumControls(int newNumControls);
		UIElement& GetControlFromPos(int pixelX, int pixelY);


	public:
		// Member variables
		// -----------
		// vtbl
		// bool bNotWindowOwner;
		// HWND hWnd;
		// FilterNode* linkedListHead;
		// FilterNode* linkedListTail;
		// -----------
		GFXClippedSurface* surface;
		UIElement* controlArray[20];
		int numControls;
		// -----------
	};

}	// End namespace
