#pragma once


#include "../../WinTypes.h"


namespace OP2Internal
{

	struct ButtonDisplayInfo;


	class UICommand
	{
	public:
		// Virtual member functions
		virtual int  IsEnabled(DWORD param)	= 0;
		virtual int  Execute(DWORD param)	= 0;
		virtual void GetButtonDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int a1);	// 0x455C40

	public:
		// Member variables
		// ----
		// vtbl
		// ----
	};

}	// End namespace
