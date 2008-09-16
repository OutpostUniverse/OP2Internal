

#ifndef UIElementButtonGraphicalButton_H
#define UIElementButtonGraphicalButton_H


#include "UIElementButton.h"


namespace OP2ForcedExport
{

	class Font;
	class CommandPaneView;

	struct ButtonDisplayInfo
	{
		int animationIndex;
		short normalFrameIndex;
		short activeFrameIndex;
		short disabledFrameIndex;
		short unknownFrameIndex;	// **
		char* helpText;
		char* buttonText;
		Font* font;
		short b1;					// **
		short b2;					// **
		short b3;					// **
		// -----------
		short padding;
	};

	// Global functions
	void AddButtons(CommandPaneView* view, int numButtons, ...);	// (UIElement:Button* button, char* buttonText, char* helpText)


	class GraphicalButton : public Button
	{
	public:
		// Virtual member functions (inherited)
		//virtual ~GraphicalButton();			// 0x4666D0
		virtual void Draw(GFXClippedSurface* surface);
		// virtual int  OnUIEvent(IWnd *wnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		// virtual void OnAdd(IWnd* ownerWnd);
		// virtual void OnRemove(IWnd* ownerWnd);
		// virtual void SetEnabledState(bool bEnabled);
		// virtual void InvalidateRect(IWnd* wnd);
		virtual void GetHelpText(char* destBuffer, int bufferSize);
		virtual void OnClick() = 0;

		// Constructors and Destructor
		GraphicalButton();
		// ~GraphicalButton();

		// Other member functions
		void SetDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int pixelX, int pixelY, int flags);
		void SetDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, Rect* buttonRect, int flags);


	public:
		// Member variables
		// -------------
		// vtbl									// 0x0
		// int flags;							// 0x4
		// Rect position;						// 0x8
		// -------------
		// int hotKey;							// 0x18
		// -------------
		int buttonTextStringLength;				// 0x1C
		short b11;								// 0x20 **
		short b12;								// 0x22 **
		int b2;									// 0x24 **
		int b3;									// 0x28 **
		char b4[0x58];							// 0x28 **
		ButtonDisplayInfo buttonDisplayInfo;	// 0x84
		// -------------
	};

}	// End namespace


#endif
