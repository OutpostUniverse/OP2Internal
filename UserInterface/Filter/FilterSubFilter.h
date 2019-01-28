

#ifndef FilterSubFilter_H
#define FilterSubFilter_H


#include "Filter.h"


namespace OP2Internal
{

	class GroupFilter;


	class SubFilter : public Filter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);

		// Constructors
		SubFilter(SubFilter const &);
		SubFilter();
		SubFilter& operator=(SubFilter const &);

		// Member functions
		void ReleaseCapture(GroupFilter* groupFilter, IWnd* wnd);
		void SetCapture(GroupFilter* groupFilter, IWnd* wnd, int userData);

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
		// ----------
	};

}	// End namespace


#endif
