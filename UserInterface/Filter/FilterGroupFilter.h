

#pragma once


#include "Filter.h"


namespace OP2Internal
{

	class GroupFilter : public Filter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);

		// Constructors
		GroupFilter(GroupFilter const &);
		GroupFilter();
		GroupFilter& operator=(GroupFilter const &);

		// Member functions
		SubFilter * GetSubFilter() const;
		void SetSubFilter(SubFilter* subFilter);

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
		SubFilter* subFilter;
		// ----------
	};

}	// End namespace
