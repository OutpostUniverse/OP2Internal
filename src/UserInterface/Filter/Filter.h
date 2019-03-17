#pragma once


#include "../../WinTypes.h"


namespace OP2Internal
{

	class IWnd;
	class FilterNode;


	class Filter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);

		// Constructors
		Filter(Filter const &);
		Filter();
		Filter& operator=(Filter const &);

		// Member functions
		void ReleaseCapture(IWnd* wnd);
		void SetCapture(IWnd* wnd, int userData);

		// Statis functions
		static Filter* __fastcall GetCapture();

	private:
		// Static variables
		static FilterNode*  pCaptureNode;

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
	};

}	// End namespace
