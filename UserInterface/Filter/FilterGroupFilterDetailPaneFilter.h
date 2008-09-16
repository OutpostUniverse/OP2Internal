

#ifndef FilterGroupFilterDetailPaneFilter_H
#define FilterGroupFilterDetailPaneFilter_H


#include "FilterGroupFilter.h"


namespace OP2ForcedExport
{

	class DetailPaneFilter : public GroupFilter
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
		// SubFilter* subFilter;
		// ----------
		// ...
	};

}	// End namespace


#endif
