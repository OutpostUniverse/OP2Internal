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
	static_assert(14 == sizeof(CommandPacketHeader), "Unexpected struct size");
	#pragma pack(pop)


	#pragma pack(push, 1)
	struct CommandPacket
	{
		CommandPacketHeader cpHeader;
		char data[99];					// 0x0E ** [Need adjustment after pragma pack?]
	};
	static_assert(113 == sizeof(CommandPacket), "Unexpected struct size");


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
		static_assert(3 == sizeof(UnitList), "Unexpected struct size");  // Note: Variable dynamic size

		struct WaypointList
		{
			short numWaypoints;
			Waypoint waypoint[1];
		};
		static_assert(6 == sizeof(WaypointList), "Unexpected struct size");  // Note: Variable dynamic size

		struct ShortPoint
		{
			short x;
			short y;
		};
		static_assert(4 == sizeof(ShortPoint), "Unexpected struct size");

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
		static_assert(8 == sizeof(ShortRect), "Unexpected struct size");


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
		static_assert(8 == sizeof(CargoRoute), "Unexpected struct size");

		struct Patrol
		{
			//UnitList
			//WaypointList
			short unknown1;		// ** Probably waypoint indexes of end patrol endpoints
			short unknown2;		// **
		};
		static_assert(4 == sizeof(Patrol), "Unexpected struct size");

		struct Build
		{
			//UnitList
			//WaypointList
			ShortRect buildArea;
			short unknown;		// ** Might be scStubIndex (related to BuildGroup), set to -1 if not used
		};
		static_assert(10 == sizeof(Build), "Unexpected struct size");

		struct BuildWall
		{
			//UnitList
			//WaypointList
			ShortRect buildArea;
			short tubeWallType;	// enum map_id
			short unknown;		// ** Might be scStubIndex (related to BuildGroup), set to 0 if not used
		};
		static_assert(12 == sizeof(BuildWall), "Unexpected struct size");

		struct RemoveWall
		{
			//UnitList
			//WaypointList
			ShortRect removeArea;
		};
		static_assert(8 == sizeof(RemoveWall), "Unexpected struct size");

		struct Produce
		{
			short factoryUnitIndex;		// 0x0E
			short itemType;				// 0x10 enum map_id
			short weaponType;			// 0x12 enum map_id
			short scStubIndex;			// 0x14 -1 if not used
		};
		static_assert(8 == sizeof(Produce), "Unexpected struct size");

		struct TransferCargo
		{
			short buildingUnitIndex;	// 0x0E
			short bayIndex;				// 0x10
			short unknown;				// 0x12 ** Might be scStubIndex, set to 0 if not used
		};
		static_assert(6 == sizeof(TransferCargo), "Unexpected struct size");

		struct LoadUnloadCargo
		{
			short buildingUnitIndex;
		};
		static_assert(2 == sizeof(LoadUnloadCargo), "Unexpected struct size");

		struct Recycle
		{
			short unitIndex;
			short unknown;		// **
		};
		static_assert(4 == sizeof(Recycle), "Unexpected struct size");

		struct DumpCargo
		{
			short unitIndex;
		};
		static_assert(2 == sizeof(DumpCargo), "Unexpected struct size");

		struct Idle
		{
			short buildingUnitIndex;
		};
		static_assert(2 == sizeof(Idle), "Unexpected struct size");

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
		static_assert(6 == sizeof(Research), "Unexpected struct size");

		struct Train
		{
			short universityUnitIndex;
			short numTrain;
		};
		static_assert(4 == sizeof(Train), "Unexpected struct size");

		struct Transfer
		{
			//UnitList
			short destPlayerNum;	// Note: *Write short, read char*
		};
		static_assert(2 == sizeof(Transfer), "Unexpected struct size");

		struct Launch
		{
			short spaceportUnitIndex;
			short destPixelX;
			short destPixelY;
		};
		static_assert(6 == sizeof(Launch), "Unexpected struct size");

		struct Salvage
		{
			short cargoTruckUnitIndex;
			ShortRect salvageArea;
			short unknown;		// **
		};
		static_assert(12 == sizeof(Salvage), "Unexpected struct size");

		struct CreateUnitInfo
		{
			int unitType;		// enum map_id
			short tileX;
			short tileY;
			int weaponOrCargo;	// enum map_id
		};
		static_assert(12 == sizeof(CreateUnitInfo), "Unexpected struct size");
		struct Create
		{
			short numUnits;
			CreateUnitInfo createUnitInfo[1];	// **
		};
		static_assert(14 == sizeof(Create), "Unexpected struct size");   // Note: Variable dynamic size

		struct SetLights
		{
			//UnitList
			short newState;		// 0 = off, 1 = on
		};
		static_assert(2 == sizeof(SetLights), "Unexpected struct size");

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
		static_assert(6 == sizeof(Attack), "Unexpected struct size");

		struct Poof
		{
			short unitIndex;
		};
		static_assert(2 == sizeof(Poof), "Unexpected struct size");

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
		static_assert(8 == sizeof(GameOpt), "Unexpected struct size");

		struct Chat
		{
			char sourcePlayerIndex;
			char destPlayerBitMask;
			char message[1];
		};
		static_assert(3 == sizeof(Chat), "Unexpected struct size");  // Note: Variable dynamic size

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
		static_assert(2 == sizeof(Quit), "Unexpected struct size");

		struct Ally
		{
			short fromPlayerIndex;	// Note: *Never read*
			short toPlayerIndex;	// Note: *Write short, read char*
		};
		static_assert(4 == sizeof(Ally), "Unexpected struct size");

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
		static_assert(8 == sizeof(MachineSettings), "Unexpected struct size");
	}

	#pragma pack(pop)
}	// End namespace
