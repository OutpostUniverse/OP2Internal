

#ifndef UICommand_H
#define UICommand_H


#include "..\..\WinTypes.h"


namespace OP2ForcedExport
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


#endif
