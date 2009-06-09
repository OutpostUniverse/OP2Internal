

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
		// int // 0x18
		// int // 0x1C
		// int // 0x20
		// int // 0x24
		// void* listMem;			// 0x28
		// int // 0x2C
		// int // 0x30
		// short // 0x34
		// short // 0x36
		// int // 0x38
		// int ??? // 0x3C
		// int?[5]/struct // 0x44
		 // void* // 0x48
		 // int // 0x4C
		 // short // 0x52
		// ...? 0x58?
	};


	// Max Size: 0x68  [class member variable packing]
	class DoubleClickListBox : public ListBox
	{
	public:
		// Virtual member functions (inherited)
		// virtual ~ListBox();
		// virtual void Draw(GFXClippedSurface* surface);
		// virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		// virtual void OnAdd(IWnd* ownerWnd);
		// virtual void OnRemove(IWnd* ownerWnd);
		// virtual void SetEnabledState(bool bEnabled);
		// virtual void InvalidateRect(IWnd* wnd);


		// Virtual member functions
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
