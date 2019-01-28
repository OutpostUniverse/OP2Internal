#ifndef ScStubGroupMineGroup_H
#define ScStubGroupMineGroup_H


#include "ScStubGroup.h"


namespace OP2Internal
{

	// Size: Base + 0x30 (minimum)
	class MineGroup : public Group
	{
	public:
	public:
		// ----
		int mineUnitIndex;				// 0x308
		int smelterUnitIndex;			// 0x30C
		int minePixelX;					// 0x310
		int minePixelY;					// 0x314
		int smelterPixelX;				// 0x318
		int smelterPixelY;				// 0x31C
		map_id mineType;				// 0x320
		map_id smelterType;				// 0x324
		RECT mineGroupPixelRect;		// 0x328
		// ----
	};

}	// End namespace


#endif
