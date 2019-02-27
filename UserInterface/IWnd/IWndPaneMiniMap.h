

#pragma once


#include "IWndPane.h"
#include "../UIElement/UIElementButtonGraphicalButtonMiscButton.h"


namespace OP2Internal
{

	class MiniMapButton;


	// Address: 0x575A04
	// Base class size: 0x6C
	// Size: 0x314
	class MiniMapPane : public Pane
	{
	private:
		// virtual char const * RegisterClassA(void);
	public:
		// [IWnd] Virtual member functions
		virtual	~MiniMapPane();
		virtual void Destroy();
		virtual int  CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,HWND,HMENU,void*,HINSTANCE);
		virtual long WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual int  CallFilters(UINT uMsg, WPARAM wParam, LPARAM lParam);

		// [Pane] Virtual member functions
		virtual void ReleaseSurface();
		virtual void ReallocSurface(int zoom);
		virtual void Draw();
		virtual void F1();											// **
		virtual bool GetAbsolutePos(int pixelX, int pixelY, Point* absolutePos);

		// [New] Virtual member functions
		virtual void ButtonClick(MiniMapButton* miniMapButton);
		virtual int  F2(int a1, int a2, int a3);					// **

		// Non virtual member functions
		// ...?
		
	public:
		// Member variables
		// Member variables
		// -----------
		// vtbl								// 0x0
		// bool bNotWindowOwner;			// 0x4
		// HWND hWnd;						// 0x8
		// FilterNode* linkedListHead;		// 0xC
		// FilterNode* linkedListTail;		// 0x10
		// -----------
		// GFXClippedSurface* surface;		// 0x14
		// UIElement* controlArray[20];		// 0x18
		// int numControls;					// 0x68
		// -----------
		int b1[5];							// 0x6C  **
		MiniMapButton miniMapButton[4];		// 0x80  zoomIn, zoomOut, invertMapColors, toggleGlobeView
		int buttonPosition;					// 0x310 [0 = Top, 1 = Bottom, 2 = Right, 3 = Left, 4 = Not Visible]
		// -----------
	};

}	// End namespace
