// ** Note: This file needs a lot of work


#ifndef ScStubGroupBuildGroup_H
#define ScStubGroupBuildGroup_H


#include "ScStubGroup.h"
#include "../../PointTypes.h"


enum map_id;


namespace OP2ForcedExport
{

	// Size: 0x1C (28 bytes)
	struct RecordedBuilding
	{
		Rect buildingTileRect;			// 0x00
		map_id buildingType;			// 0x10
		map_id weaponType;				// 0x14
		int groupScStubIndex;			// 0x18 **
	};

	// Size: 0x1C (28 bytes)
	struct RecordedMine
	{
		Rect mineTileRect;				// 0x00
		map_id mineType;				// 0x10
		int groupScStubIndex;			// 0x14 **
		int a4;							// 0x18 **
	};

	// Size: 0x0C (12 bytes)
	struct RecordedTubeWall
	{
		short tileX;					// 0x00
		short tileY;					// 0x02
		int cellType;					// 0x04 (0x17 = Wall, 0x18 = MicrobeWall, 0x19 = LavaWall, 0x1A = Tube)
		int a3;							// 0x08 ** (Initialized to 0)
	};

	// Size: 0x0C (12 bytes)
	struct RecordedVehGroup
	{
		int targetGroupScStubIndex;		// 0x00
		int priority;					// 0x04
		int unitIndex;					// 0x08 ** (Initialized to 0)
	};

	class BuildGroup : public Group
	{
	public:
	public:
		// ----
		int numAllocatedRecordedBuildings;		// 0x308 (Allocated in blocks of 8 entries)
		RecordedBuilding* recordedBuildings;	// 0x30C (Allocated in blocks of 8 entries)
		int numAllocatedRecordedMines;			// 0x310 (Allocated in blocks of 4 entries)
		RecordedMine* recordedMines;			// 0x314 (Allocated in blocks of 4 entries)
		int numAllocatedRecordedTubesWalls;		// 0x318 (Allocated in blocks of 8 entries)
		RecordedTubeWall* recordedTubesWalls;	// 0x31C (Allocated in blocks of 8 entries)
		int numAllocatedRecordedVehGroups;		// 0x320 (Allocated in blocks of 4 entries)
		RecordedVehGroup* recordedVehGroups;	// 0x324 (Allocated in blocks of 4 entries)
		struct {								// 0x328 [MemClear]
			int numRecordedBuildings;			 // 0x328
			int numRecordedMines;				 // 0x32C
			int numRecordedTubesWalls;			 // 0x330
			int numRecordedVehGroup;			 // 0x334
			Rect defaultPixelRect;				 // 0x338
			int a18;							 // 0x348 ** (=0) (Index into function pointer table)
		};
		int convecUnitIndex;					// 0x34C (TransferCargo related)
		int factoryUnitIndex;					// 0x350 (TransferCargo related)
		int recordedBuildingIndex;				// 0x354 (TransferCargo related)
		int factoryBayIndex;					// 0x358 (TransferCargo related)
		// ----
	};

}	// End namespace


#endif
