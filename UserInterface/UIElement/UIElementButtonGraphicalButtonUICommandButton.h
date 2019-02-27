

#pragma once


#include "UIElementButtonGraphicalButton.h"


namespace OP2Internal
{

	class UICommand;


	class UICommandButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		//virtual ~UICommandButton();				// 0x459EF0
		// virtual void Draw(GFXClippedSurface* surface);
		// virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		// virtual void OnAdd(IWnd* ownerWnd);
		// virtual void OnRemove(IWnd* ownerWnd);
		// virtual void SetEnabledState(bool bEnabled);
		// virtual void InvalidateRect(IWnd* wnd);
		// virtual void GetHelpText(char* destBuffer, int bufferSize);
		virtual void OnClick();

		// Constructors and Destructor
		UICommandButton();						// 0x459EC0
		// ~UICommandButton();					// 

		// Other member functions


	public:
		// Member variables
		// -------------
		// vtbl									// 0x0
		// int flags;							// 0x4
		// Rect position;						// 0x8
		// -------------
		// int hotKey;							// 0x18
		// int buttonTextStringLength;			// 0x1C
		// int b1;								// 0x20 **
		// int b2;								// 0x24 **
		// char b3[0x5C];						// 0x28 **
		// ButtonDisplayInfo buttonDisplayInfo;	// 0x84
		// -------------
		int commandParam;						// 0xA4
		UICommand* command;						// 0xA8
		// -------------
	};

}	// End namespace
