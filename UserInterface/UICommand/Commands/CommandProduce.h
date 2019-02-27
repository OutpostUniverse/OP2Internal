#pragma once


#include "../UICommand.h"


namespace OP2Internal
{

	class CommandProduce : public UICommand
	{
	public:
		// Base class virtual member functions
		virtual int IsEnabled(DWORD param);			// 0x4568D0
		virtual int Execute(DWORD param);			// 0x456C70
		// virtual void GetButtonDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int a1);	// 0x455C40

		// Constructor/Destructor
		// UICommandProduce() {};					// 0x4568C0 [Static: 0x565680]

	public:
		// Member variables
		// ----
		// vtbl			// 0x4D5000
		// ----
		// ----
		// ...?
	};


	// Globals
	extern CommandProduce commandProduce;		// 0x565680

}	// End namespace
