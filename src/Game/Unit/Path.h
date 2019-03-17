#pragma once


#include "../Waypoint.h"


namespace OP2Internal
{

	struct Path
	{
		union {
			Path* nextFree;			// 0x00
			int numWaypoints;		// 0x00 ** See offset 0x74
		};
		int lastWaypointIndex;		// 0x04
		int _08;					// 0x08 **
		int _0C;					// 0x0C **
		int _10;					// 0x10 **
		Waypoint waypointList[8];	// 0x14
		int flags;					// 0x34 **
		Path* next;					// 0x38 **
		int a0Enum;					// 0x3C ** (0 = Move/Dock/DockEG/StandGround/CargoRoute/Patrol/Build, 3 = RemoveWall)
		int _40;					// 0x40 **
		int _44;					// 0x44 **
		int currentPixelX;			// 0x48 ** (or start)
		int currentPixelY;			// 0x4C ** (or start)
		int destTileX;				// 0x50
		int destTileY;				// 0x54
		int a1;						// 0x58 ** Copy of 0x5C
		int a2;						// 0x5C ** (0, sign extend of 0x60)
		char rotationSpeed;			// 0x60
		char a3;					// 0x61 ** (padding?)
		char a4;					// 0x62 ** (padding?)
		char a5;					// 0x63 ** (padding?)
		int a6;						// 0x64 ** (20, copy of 0x70)
		int a7;						// **
		int a8;						// **
		int a9;						// 0x70 ** (Used as range in call to Rand, set using results)
		int numWaypoints;			// 0x74
		int currentWaypoint;		// 0x78
		char direction[80];			// 0x7C ** (0..7: 0 = Right, increases clockwise, 45 degree increments)
		int a10;					// 0xBC **
		int a11;					// 0xC0 **
		//
		int a12Enum;				// 0xCC ** (0, 1, 2, 3)
		int distance;				// 0xD0
	};

}	// End namespace
