#pragma once

// ** Note: This file needs a lot of work

#include "EnumMapId.h"


namespace OP2Internal
{
	class Unit;


	class Sheet
	{
	public:
		// Member functions
		Unit* CreateUnit(map_id unitType, int pixelX, int pixelY, int creatorIndex, map_id cargo, int unitIndex, int bCenterInTile);	// 0x004467C0  Returns 0 (NULL) when out of unit records

	public:
		// Member variables
		// ----------------
		int b1;					// **
		int b2;					// **
		// ----------------
	};
	static_assert(8 == sizeof(Sheet), "Unexpected struct size");


	// Globals
	extern Sheet &sheet;// = *(Sheet*)0x0055B780;		// 0x0055B780

}	// End namespace
