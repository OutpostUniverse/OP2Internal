#pragma once


#include "Filter.h"


namespace OP2Internal
{

	class UIElement;


	class HotKeyFilter : public Filter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);

		// Member functions
		bool SetHotKeyButton(UIElement* button, int hotKey);
		void RemoveHotKey(int hotKey);
		int  SetPauseCount(bool bPaused);

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
		UIElement* hotKeyTable[256];
		int pauseCount;
		// ----------
	};


	// Globals
	extern HotKeyFilter hotKeyFilter;

}	// End namespace
