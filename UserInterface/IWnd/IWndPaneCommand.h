#pragma once


#include "IWndPane.h"
#include "../UIElement/UIElementButtonGraphicalButtonViewButton.h"


namespace OP2Internal
{

	class UIElement;
	class CommandPaneView;


	// Address: 0x575D18
	// Base class size: 0x6C
	// Size: 0x498
	class CommandPane : public Pane
	{
	private:
		// virtual char const * RegisterClassA(void);
	public:
		// [IWnd] Virtual member functions (inherited)
		virtual ~CommandPane();
		// virtual void Destroy(void);
		// virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,struct HWND__ *,struct HMENU__ *,void *,struct HINSTANCE__ *);
		virtual long WndProc(unsigned int uMsg, unsigned int wParam, long lParam);
		// virtual int CallFilters(unsigned int uMsg, unsigned int wParam, long lParam);
		// virtual void ReleaseSurface();
		virtual void ReallocSurface(int zoom);
		virtual void Draw();
		// virtual void F1();
		// virtual bool GetAbsolutePos(int pixelX, int pixelY, Point* absolutePos);

		// [Pane] Virtual member functions
		virtual void MarkRectToRedraw(Rect* drawRect);
		virtual void DrawBackBuffer(Rect* drawRect);

		// Member functions
		void SetSelectedControl(UIElement* control);
		void SetNewView(CommandPaneView* newView);
		void DrawControlsAndUpdateScreen();
		int  GetReportButtonHeight();
		void UpdateUnitSelection();


	public:
		// Member variables
		// ---------------------------
		// vtbl
		// bool bNotWindowOwner;
		// HWND hWnd;
		// FilterNode* linkedListHead;
		// FilterNode* linkedListTail;
		// ---------------------------
		// GFXClippedSurface* surface;
		// UIElement* controlArray[20];
		// int numControls;
		// ---------------------------
		ViewButton reportButton[6];		// [Factory, Lab, Resources, Communications, Satellites, GameOptions]
		Rect redrawRect;
		int b1;							// **
		int controlNum;
		UIElement* selectedControl;
		CommandPaneView* currentView;
		int viewTop;					// Top pixel of pane
		// ---------------------------
	};

}	// End namespace
