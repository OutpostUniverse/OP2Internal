

#ifndef UIElementListBox_H
#define UIElementListBox_H


#include "UIElement.h"


namespace OP2Internal
{

	class Font;

	// Max Size: 256  [Array indexing]
	struct ListItem
	{
		int listItemIndex;			// 0x0  [dataListIndex?]
		char text[120];				// 0x4  [char[120?]]
		//RenderData<?> renderData;	// 0x7C
	};

	class ListData
	{
	public:
		virtual int GetSize();
		virtual int GetFirstIndex();				// [-1 = List Empty]
		virtual int GetNextIndex(int dataIndex);	// [-1 = Past Last]
		virtual int GetPrevIndex(int index);		// [-1 = Before First]
		virtual int GetCurrentIndex(int index);		// ** Maybe? Return different index type?
		virtual int GetDisplayString(int index, char* string, int stringLength);
		virtual int GetStatusString(int index, char* string, int stringLength);
	public:
		// ...?
	};

	struct ListStyle
	{
		ListData* listData;			// 0x0
		Font* font;					// 0x4
		int selectedBorderWidth;	// 0x8
		short a1Color16;			// 0xC **
		short backColor16;			// 0xE
		int a2;						// 0x10 **
	};


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
		virtual void OnUpdateSelection();
		virtual void OnClick();
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
		// -------------		[** Some fields are list indexes, and others are data indexes **]
		// int numLinesVisible;		// 0x18 Total display area (**rounded up for partial lines?, or borders are padded and always integral height?)
		// int lineHeight;			// 0x1C Size of a single line
		// int numLinesDisplayed;	// 0x20 Sum of lines of all items at least partially visible
		// int numItems?;			// 0x24 *
		// void* listItem;			// 0x28 [ListItem[]*]
		// int scrollTopIndex;		// 0x2C [-1 = None, don't display list] [listIndex]
		// int maxIndex;			// 0x30 ** Totally wrong? numItemsDisplayed?+1 [listIndex] bottomIndex?
		// short a1;				// 0x34 *
		// short a2;				// 0x36 *
		// int currentIndex;		// 0x38
		// int lastClickTime;		// 0x3C [milliseconds]
		// int lastClickedOnIndex;	// 0x40 [Used to check if second of a double click is on same item]
		// ListStyle listStyle;		// 0x44 *
		//  ListData* listData;		// 0x44 [Object pointer, object has vtbl]
		//  Font* font;				// 0x48
		//  int selectedBorderWidth;// 0x4C [2]
		//  short a3;				// 0x50 *
		//  short backColor16;		// 0x52
		//  int a4;					// 0x54 *
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
