

#pragma once


namespace OP2Internal
{

	class Filter;

	enum FilterPositions
	{
		FilterPosLast = 0,
		FilterPosFirst = 1,
	};

	enum FilterOptions
	{
		FilterOptMouseMessage = 1,
		FilterOptKeyboardMessage = 2,
	};


	// Size: 0x14  [New, fields accessed]
	class FilterNode
	{
		FilterNode* prev;				// 0x0
		FilterNode* next;				// 0x4
		Filter* filter;					// 0x8
		int userData;					// 0xC
		FilterOptions filterOptions;	// 0x10
	};

}	// End namespace
