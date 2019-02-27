#pragma once


// ** Note: This file needs a lot of work


#include "Waypoint.h"


namespace OP2Internal
{

	#pragma pack(push, 1)
	struct CommandPacketHeader
	{
		int messageType;				// 0x00
		short dataLength;				// 0x04
		int timeStamp;					// 0x06
		int unknown;					// 0x0A **
	};
	#pragma pack(pop)


	#pragma pack(push, 1)
	struct CommandPacket
	{
		CommandPacketHeader cpHeader;
		char data[99];					// 0x0E ** [Need adjustment after pragma pack?]
	};


	namespace CP
	{
		// Fixed size CommandPacket data structs
		// =====================================


		// Common header structs
		// ---------------------

		struct UnitList
		{
			char numUnits;		// If negative, then hot key group?
			short unitIndex[1];	// List of unit indexes
		};

		struct WaypointList
		{
			short numWaypoints;
			Waypoint waypoint[1];
		};
		struct ShortPoint
		{
			short x;
			short y;
		};
		union ShortRect
		{
			struct
			{
				// Top left
				short x1;
				short y1;
				// Bottom right
				short x2;
				short y2;
			};
			struct
			{
				ShortPoint topLeft;
				ShortPoint bottomRight;
			};
		};


		// Data structs
		// ------------

		struct CargoRoute
		{
			//UnitList
			//WaypointList
			short smelterWaypointIndex;
			short mineWaypointIndex;
			short mineUnitIndex;
			short smelterUnitIndex;
		};

		struct Patrol
		{
			//UnitList
			//WaypointList
			short unknown1;		// ** Probably waypoint indexes of end patrol endpoints
			short unknown2;		// **
		};

		struct Build
		{
			//UnitList
			//WaypointList
			ShortRect buildArea;
			short unknown;		// ** Might be scStubIndex (related to BuildGroup), set to -1 if not used
		};

		struct BuildWall
		{
			//UnitList
			//WaypointList
			ShortRect buildArea;
			short tubeWallType;	// enum map_id
			short unknown;		// ** Might be scStubIndex (related to BuildGroup), set to 0 if not used
		};

		struct RemoveWall
		{
			//UnitList
			//WaypointList
			ShortRect removeArea;
		};

		struct Produce
		{
			short factoryUnitIndex;		// 0x0E
			short itemType;				// 0x10 enum map_id
			short weaponType;			// 0x12 enum map_id
			short scStubIndex;			// 0x14 -1 if not used
		};

		struct TransferCargo
		{
			short buildingUnitIndex;	// 0x0E
			short bayIndex;				// 0x10
			short unknown;				// 0x12 ** Might be scStubIndex, set to 0 if not used
		};

		struct LoadUnloadCargo
		{
			short buildingUnitIndex;
		};

		struct Recycle
		{
			short unitIndex;
			short unknown;		// **
		};

		struct DumpCargo
		{
			short unitIndex;
		};

		struct Idle
		{
			short buildingUnitIndex;
		};

		struct SelfDestruct
		{
			//UnitList
		};

		struct Scatter
		{
			//UnitList
		};

		struct Research
		{
			short labUnitIndex;
			short techIndex;
			short numScientists;
		};

		struct Train
		{
			short universityUnitIndex;
			short numTrain;
		};

		struct Transfer
		{
			//UnitList
			short destPlayerNum;	// Note: *Write short, read char*
		};

		struct Launch
		{
			short spaceportUnitIndex;
			short destPixelX;
			short destPixelY;
		};

		struct Salvage
		{
			short cargoTruckUnitIndex;
			ShortRect salvageArea;
			short unknown;		// **
		};

		struct CreateUnitInfo
		{
			int unitType;		// enum map_id
			short tileX;
			short tileY;
			int weaponOrCargo;	// enum map_id
		};
		struct Create
		{
			short numUnits;
			CreateUnitInfo createUnitInfo[1];	// **
		};

		struct SetLights
		{
			//UnitList
			short newState;		// 0 = off, 1 = on
		};

		struct Attack
		{
			//UnitList
			short unknown1;		// **
			union {
				ShortPoint point;
				struct
				{
					short targetUnitIndex;
					short unknown2;		// **
				};
			};
		};

		struct Poof
		{
			short unitIndex;
		};

		// Variables not defined here are assumed to be dword indexes into TethysGame object
		enum GameOptVariable
		{
			optSetPlayerCommonOre = 8,
			optSetPlayerRareOre,
			optSetPlayerScientists,
			optSetPlayerWorkers,
			optSetPlayerFoodStored,
			optSetPlayerKids,
			// ---- Following affects everyone
			optForceDisableRccEffect,
			optForceEnableRccEffect,
			// ----
			optDaylightEverywhere,
			optGameSpeed,
			// ----
			optForceMoraleGreat,
			optForceMoraleGood,
			optForceMoraleOk,
			optForceMoralePoor,
			optForceMoraleRotten,
			// ----
			// Workers, scientists, kids, common ore, rare ore, food stored
			optIncreasePlayerResources,
			optIncreaseAllPlayersResources,
			// ----
			optCreateVortex,
			optCreateLightning,
			optCreateEarthquake,
			optCreateMeteor,
			// ----
			optFreeMoraleLevel,
		};
		struct GameOpt
		{
			short unknown;		// **
			short variableIndex;
			short newValue;
			// ---- Only used by specific variables
			short playerIndex;
		};

		struct Chat
		{
			char sourcePlayerIndex;
			char destPlayerBitMask;
			char message[1];
		};

		enum QuitMethod
		{
			SelfDestruct = 0,
			TransferToAllies,
			// Other = GoAI
		};
		struct Quit
		{
			char quitMethod;
			char lParam;
		};

		struct Ally
		{
			short fromPlayerIndex;	// Note: *Never read*
			short toPlayerIndex;	// Note: *Write short, read char*
		};

		struct GoAI
		{
			// Empty
		};

		struct MachineSettings
		{
			short cpuSpeed;					// MHz
			short totalPhysMem;				// MB rounded up to a multiple of 4
			short windowWidth;				// Dans_RULE_UIFrame
			short windowHeight;				// Dans_RULE_UIFrame
		};
	}

	#pragma pack(pop)
}	// End namespace
