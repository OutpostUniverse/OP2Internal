

#ifndef UIElementListBox_H
#define UIElementListBox_H


#include "UIElement.h"


namespace OP2ForcedExport
{

	class ListBox : public UIElement
	{
	public:
		// Virtual member functions (inherited)
		virtual ~ListBox();
		virtual void Draw(GFXClippedSurface* surface);
		virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void OnAdd(IWnd* ownerWnd);
		virtual void OnRemove(IWnd* ownerWnd);
		// virtual void SetEnabledState(bool bEnabled);
		// virtual void InvalidateRect(IWnd* wnd);

		// Virtual member functions
		// virtual ...

		// Non virtual member functions
		// Constructors and Destructor
		// Other member functions


	public:
		// Member Variables
		// -------------
		// vtbl						// 0x0
		// int flags;				// 0x4
		// Rect position;			// 0x8
		// -------------
		// ...
	};

}	// End namespace


#endif
