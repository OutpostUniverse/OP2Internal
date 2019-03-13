#pragma once

#include "EnumFilterOption.h"


namespace OP2Internal
{
	class Filter;


	// Size: 0x14  [New, fields accessed]
	class FilterNode
	{
		FilterNode* prev;				// 0x0
		FilterNode* next;				// 0x4
		Filter* filter;					// 0x8
		int userData;					// 0xC
		FilterOption filterOption;	// 0x10
	};

}	// End namespace
