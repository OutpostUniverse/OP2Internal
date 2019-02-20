

#ifndef Map_H
#define Map_H


#include "../PointTypes.h"


namespace OP2Internal
{

	class Unit;

	struct TileData
	{
		unsigned int cellType:5;		// 0x0000001F
		unsigned int tileIndex:11;		// 0x0000FFE0
		unsigned int unitIndex:11;		// 0x07FF0000
		unsigned int bLava:1;			// 0x08000000
		unsigned int bLavaPossible:1;	// 0x10000000
		unsigned int bExpansion:1;		// 0x20000000 [Used by Blight and Lava]
		unsigned int bMicrobe:1;		// 0x40000000
		unsigned int bBuilding:1;		// 0x80000000 [Impassable? Wall, Building]
	};


	struct CellTypeInfo
	{
		char* name;
		// Track types are: Legged, Wheeled, Miner, Tracked, Hover, Lava?, Blight?, Unknown?
		// See HFL: enum TrackType
		int trackSpeed[8];
	};


	enum CellType
	{
		CellTypeNormalWall = 0x17,
		CellTypeMicrobeWall = 0x18,
		CellTypeLavaWall = 0x19,
	};


	class Map
	{
	public:
		// Member functions

	public:
		// Member variables
		int unknown;				// 0x0 **
		int pixelWidthMask;			// 0x4  [Wrap coordinates around map]
		int pixelWidth;				// 0x8
		int tileWidthMask;			// 0xC  [Wrap coordinates around map]
		int tileWidth;				// 0x10
		int lgTileWidth;			// 0x14 [logTileWidth+1 if < 9]
		int tileHeight;				// 0x18 [2^logTileHeight]
		Rect clipRect;				// 0x1C [Bound on unit movement]  Small: [32, 1, tileWidth + 31, tileHeight], Around the world: [-1. 1. 2^31-1, tileHeight]
		int numTiles;				// 0x2C [tileWidth * tileHeight]
		int numTileSets;			// 0x30 [512] [Reserved space]
		int lgTileHeight;			// 0x34 [Rounded up]
		int tileXOffset;			// 0x38 [Padding around map edges]
		int numUnits;				// 0x3C
		int lastUsedUnitIndex;		// 0x40
		int nextFreeUnitSlotIndex;	// 0x44
		int firstFreeUnitSlotIndex;	// 0x48
		Unit** freeUnitList;		// 0x4C Unit*[]*
		Unit* unit;					// 0x50 Unit[1025]*
		Unit* unknown2;				// 0x54 **
		int unknown3;				// 0x58 **
		char lightLevelBrightnessAdjustment[4];	// 0x5C ** Find actual size
		char unknown4[0x400];		// 0x60 **

		char** wellString;			// 0x460 WellString[]*
		TileData* tileData;			// 0x464 int[]* tileData
		// 0x468 tileMappings[]* (numTileSets elements)
		// 0x46C terrainTypeManager* (holds terrainType objects - 0x108 byte objects)
	};


	// Global functions
	int __fastcall IsBuildable(int tileX, int tileY);		// 0x438C80  Note: First call Unit:Vehicle.SetCurrentUnitAndTrackTypeAndAttackType()
	int __fastcall IsTilePassable(int tileX, int tileY);	// 0x4383C0  Note: First call Unit:Vehicle.SetCurrentUnitAndTrackTypeAndAttackType()
	int __fastcall IsDockLocation(int tileX, int tileY);	// 0x438B70  Note: Checks (tileX - 1, tileY) and (tileX, tileY - 1) for a building with a dock at the given location


	// Globals
	extern Map map;		// 0x54F7F8
	extern CellTypeInfo cellTypeInfo[32];	// 0x4DEBA8

}	// End namespace


#endif
