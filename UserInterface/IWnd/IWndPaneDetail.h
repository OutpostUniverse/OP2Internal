

#ifndef IWnd_Pane_Detail_H
#define IWnd_Pane_Detail_H


#include "IWndPane.h"


namespace OP2Internal
{

	// Address: 0x5758B4
	// Base class Size: 0x6C
	// Size: 0x150
	class DetailPane : public Pane
	{
	private:
		// virtual char const * RegisterClassA(void);
	public:
		// [IWnd] Virtual member functions
		virtual ~DetailPane();
		// virtual void Destroy(void);
		// virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,struct HWND__ *,struct HMENU__ *,void *,struct HINSTANCE__ *);
		virtual long WndProc(unsigned int uMsg, unsigned int wParam, long lParam);
		virtual int CallFilters(unsigned int uMsg, unsigned int wParam, long lParam);
		// virtual void ReleaseSurface();
		virtual void ReallocSurface(int zoom);
		virtual void Draw();
		// virtual void F1();
		virtual bool GetAbsolutePos(int pixelX, int pixelY, Point* absolutePos);

		// [New] Virtual member functions
		virtual void GetViewportRelativePos(int pixelX, int pixelY, Point* relPos);
		virtual void GetViewportTilePositionAndSize(Point* topLeftTilePos, Point* tileSize);

		// Member functions
		void GetViewCenter(Point* viewCenter);


	public:
		// Member variables
		// -----------
		// vtbl							// 0x0
		// bool bNotWindowOwner;		// 0x4
		// HWND hWnd;					// 0x8
		// FilterNode* linkedListHead;	// 0xC
		// FilterNode* linkedListTail;	// 0x10
		// -----------
		// GFXClippedSurface* surface;	// 0x14
		// UIElement* controlArray[20];	// 0x18
		// int numControls;				// 0x68
		// -----------
		HDC hDestDC;					// 0x6C
		int b1[0xF];					// 0x70 **
		char largeMessage[0x84];		// 0xAC ** Determine real size
		HFONT hLargeMessageFont;		// 0x130
		int b2[3];						// 0x134 **
		Rect unknown;					// 0x140 **
		// -----------
	};

}	// End namespace


#endif
