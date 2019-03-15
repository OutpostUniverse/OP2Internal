#pragma once


// ** Note: This file needs a lot of work


#include "ScStubGroup.h"
#include "../Waypoint.h"
#include "../EnumMapId.h"
#include "../../PointTypes.h"


namespace OP2Internal
{
	//enum CombatGroupObjective
	//{
	//	GuardRect,		// 0
	//	Patrol,			// 1
	//	GuardGroup,		// 2
	//	GuardUnit,		// 3
	//	AttackUnit,		// 4
	//	AttackEnemy,	// 5
	//	ExitMap			// 6
	//};

	// Size: Base + 0xE0 (minimum)
	class CombatBase : public Group
	{
	public:
	public:
		// ... // 0x300?
		// ----
		int bCombineFire;				// 0x308
		int a0UnitIndex;				// 0x30C ** (CombineFire related)
		int a1;							// 0x310 ** [Set to 0xFFF00000, related to game tick, possibly spider related]
		int numWaypoints;				// 0x314
		int a2;							// 0x318 ** (Set in SetWaypoints to unknown parameter, used in IssuePatrol)
		Waypoint waypointList[8];		// 0x31C
		int patrolMode;					// 0x33C (Initialized to 0)
		int followMode;					// 0x340 (Initialized to 0)
		Rect pixelRect;					// 0x344 (SetRect converted to pixels) (rect.p1.y initialized to -1)
		int targetGroupIndex;			// 0x354 (Initialized to -1)
		map_id attackType;				// 0x358 (Initialized to 0  [mapNone])
		int targetUnitIndex;			// 0x35C (Initialized to -1)
		int numGuardedRects;			// 0x360
		Rect guardedRect[8];			// 0x364
		int a3Index;					// 0x3E4 ** (Index into a list of objects with 5 function pointers each)
		// ----
	};
	static_assert(0x3E8 == sizeof(CombatBase), "Unexpected struct size");

}	// End namespace
