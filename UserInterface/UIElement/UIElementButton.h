
#ifndef UIElementButton_H
#define UIElementButton_H


#include "UIElement.h"


namespace OP2Internal
{

	class Button : public UIElement
	{
	public:
		// Virtual member functions (inherited)
		virtual ~Button();												// 0x40A8F0 (Scalar Deleting: 0, 1)
		virtual void Draw(GFXClippedSurface* surface) = 0;				// [Pure Call]
		virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void OnAdd(IWnd* ownerWnd);
		virtual void OnRemove(IWnd* ownerWnd);
		virtual void SetEnabledState(bool bEnabled);
		// virtual void InvalidateRect(IWnd* wnd);

		// Virtual member functions
		virtual void GetHelpText(char* destBuffer, int bufferSize) = 0;	// [Pure Call]
		virtual void OnClick() = 0;										// [Pure Call]

		// Constructors and Destructor
		Button();
		// ~Button();													// 0x40A910 (non-virtual destructor)

		// Other member functions
		void SetHotKey(int nVirtKey);

	public:
		// Member variables
		// -------------
		// vtbl									// 0x0 [0x4CF8B8]
		// int flags;							// 0x4
		// Rect position;						// 0x8
		// -------------
		int hotKey;								// 0x18
		// -------------
	};

}	// End namespace


#endif
