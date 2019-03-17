#pragma once


#include "../../PointTypes.h"
#include "../../WinTypes.h"


namespace OP2Internal
{

	class IWnd;


	class UIElement
	{
	public:
		// Virtual member functions
		virtual ~UIElement();							// 0x40A770 (Scalar Deleting: 0, 1)
		virtual void Draw(GFXClippedSurface* surface);	// 0x40B580
		virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 0x40B590
		virtual void OnAdd(IWnd* ownerWnd);				// 0x40A7E0
		virtual void OnRemove(IWnd* ownerWnd);			// 0x40A7F0
		virtual void SetEnabledState(bool bEnabled);	// 0x40B5A0
		virtual void InvalidateRect(IWnd* wnd);			// 0x40A830

		// Constructor/Destructor
		UIElement();									// 0x40A760
		// ~UIElement();								// 0x40A790 (non-virtual destructor)

		// Member functions
		void SetCapture(IWnd* wnd);						// 0x40A7A0
		void ReleaseCapture(IWnd* wnd);					// 0x40A7C0
		void SetFlagsState(int flags, bool bSetOrClear);// 0x40A880

	public:
		// Member Variables
		// -------------
		// vtbl						// 0x0 [0x4CF898]
		int flags;					// 0x4
		Rect position;				// 0x8
		// -------------
	};


	enum UIElementFlags
	{
		uieDisabled		= 0x2,
		uieAddedToWnd	= 0x4,
		uieHasFocus		= 0x20,
		uieHasHotKey	= 0x200,
	};

}	// End namespace
