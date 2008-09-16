

#ifndef FilterUIElementFilter_H
#define FilterUIElementFilter_H


#include "Filter.h"


namespace OP2ForcedExport
{

	class UIElement;


	class UIElementFilter : public Filter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);

		// Member functions

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
		UIElement* control;
		// ----------
	};


	// Globals
	extern UIElementFilter controlFilter;

}	// End namespace


#endif
