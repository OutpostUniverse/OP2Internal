

#ifndef Player_H
#define Player_H


#include "CommandPacket.h"
#include "UnitGroup.h"
#include "GameStartInfo\MoraleStartInfo.h"
#include "GameStartInfo\PlayerStartInfo.h"


namespace OP2Internal
{

	class Unit;


	struct BuildingStats
	{
		int numBuildings;
		int numActive;
		int numDisabled;
		int numIdle;
	};


	// Size: 0xC24 = 3108
	class Player
	{
	public:
		// Member functions
		CommandPacket* GetNextCommandPacketAddress();
		void ProcessCommandPacket(CommandPacket* commandPacket);

	public:
		// Member variables
		int playerNum;						// 0x0
		int allyMask;						// 0x4
		SatelliteCounts satCounts;			// 0x8
		int difficulty;						// 0xC
		int foodStored;						// 0x10
		int maxFood;						// 0x14 ** Maybe? Unimplemented? [500000]
		int maxCommonOre;					// 0x18
		int maxRareOre;						// 0x1C
		int currentCommonOre;				// 0x20
		int currentRareOre;					// 0x24
		int bIsHuman;						// 0x28
		int bIsEden;						// 0x2C
		int colorNumber;					// 0x30

		// Morale
		MoraleState moraleState;			// 0x34

		// Population growth
		int scientistGrowthRemainder;		// 0x7C Maybe? Unimplemented?
		int workerGrowthRemainder;			// 0x80
		int kidGrowthRemainder;				// 0x84

		// Population death
		int kidDeathRemainder;				// 0x88
		int scientistDeathRemainder;		// 0x8C
		int workerDeathRemainder;			// 0x90

		// Population
		int numWorkers;						// 0x94
		int numScientists;					// 0x98
		int numKids;						// 0x9C

		// Colony state
		int bRecalculateValues;				// 0xA0 [Set to true whenever values below need to be updated. They are cleared to 0, and recounted.]
		int numAvailableWorkers;			// 0xA4
		int numAvailableScientists;			// 0xA8
		int amountPowerGenerated;			// 0xAC
		int inactivePowerCapacity;			// 0xB0
		int amountPowerConsumed;			// 0xB4
		int amountPowerAvailable;			// 0xB8
		int numIdleBuildings;				// 0xBC
		int numActiveBuildings;				// 0xC0
		int numBuildings;					// 0xC4
		int numUnpoweredStructures;			// 0xC8
		int numWorkersRequired;				// 0xCC
		int numScientistsRequired;			// 0xD0
		int numScientistsAsWorkers;			// 0xD4
		int numScientistsResearching;		// 0xD8
		int totalFoodProduction;			// 0xDC
		int totalFoodConsumption;			// 0xE0
		int foodLacking;					// 0xE4
		int netFoodProduction;				// 0xE8
		int numSolarSatellites;				// 0xEC

		// Total Capacities
		int totalRecFacilityCapacity;		// 0xF0
		int totalForumCapacity;				// 0xF4
		int totalMedCenterCapacity;			// 0xF8
		int totalResidenceCapacity;			// 0xFC

		// Number of Active special buildings
		int numActiveCommandCenters;		// 0x100
		int numActiveNurseries;				// 0x104
		int numActiveUniversities;			// 0x108
		int numActiveObservatories;			// 0x10C
		int numActiveMeteorDefenses;		// 0x110
		int b4;								// 0x114 **

		// Building counts [Num, Active, Disabled, Idled]
		BuildingStats powerPlants;			// 0x118
		BuildingStats argridomes;			// 0x128
		BuildingStats commonOreSmelters;	// 0x138
		BuildingStats commonOreStorage;		// 0x148
		BuildingStats rareOreStorage;		// 0x158
		BuildingStats rareOreSmelters;		// 0x168
		BuildingStats gorfs;				// 0x178
		BuildingStats commonOreMines;		// 0x188
		BuildingStats rareOreMines;			// 0x198
		BuildingStats robotCommandCenters;	// 0x1A8

		// Robot Command Center Operational
		bool bRccOperational;				// 0x1B8

		// [GameStartInfo/MissionResults related]
		PlayerEndInfo endInfo;				// 0x1BC

		int b6[5];							// 0x1D8 **
		int starvationCase;					// 0x1EC [mod 5] [0, 4 = Kids, 1, 2 = Scientists, 3 = Workers]

		PackedUnitGroup unitGroup[11];		// 0x1F0
		char padding;						// 0x4BB **
		int playerNetID;					// 0x4BC
		CP::MachineSettings machineSettings;	// 0x4C0
		CommandPacket cp[16];				// 0x4C8
		int unitIndex[16];					// 0xBD8 ** [Set when processing single unit CPs]

		// Linked List heads
		Unit* buildingUnitList;				// 0xC18
		Unit* vehicleUnitList;				// 0xC1C
		Unit* unknownUnitList;				// 0xC20 **
		// ----
	};


	// Globals
	// extern Player player[7];		// 0x56EF1C [TethysGame.Player[7]]

}	// End namespace


#endif		// End redefinition error protection
