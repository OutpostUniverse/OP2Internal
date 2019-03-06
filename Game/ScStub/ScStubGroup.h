#pragma once

#include "ScStub.h"


enum class UnitClassifactions;
enum class map_id;


namespace OP2Internal
{

	class Unit;


	// Size: 0x14
	struct UnitNode
	{
		union {
			int nextFreeIndex;				// 0x00
			UnitNode* prev;					// 0x00
		};
		UnitNode* next;						// 0x04
		Unit* unit;							// 0x08
		int issueCommandTick;				// 0x0C ** [Set to 0xFFF00000 when adding unit to group, related to gameTick and deleteWhenEmpty]
		UnitClassifactions classification;	// 0x10
		// ----
	};

	// Size: 0x14
	class TargetCount
	{
	public:
	public:
		int a1;					// 0x00 **
		void* a2;				// 0x04 **
		int groupScStubIndex;	// 0x08
		int a3;					// 0x0C **
		int a4;					// 0x10 **
		// ----
	};


	class Group : public ScStub
	{
	public:
		// ----  [New virtual functions]
		virtual void HasFired();					// 0x24 ** [Name?]
		virtual void AddUnit(Unit* unit);			// 0x28
		virtual void RemoveUnit(Unit* unit);		// 0x2C
		virtual void RemoveDeadAndCapturedUnits();	// 0x30
		virtual void A2();							// 0x34 **
		// ----

	public:
		int a1;							// 0x14  **
		int a2;							// 0x18  **
		int lastFreeUnitNodeIndex;		// 0x1C  ** (+= 1)
		int a4;							// 0x20  ** (+= 1)
		UnitNode unitNode[32];			// 0x24 (Linked list node storage for pointers to up to 32 units)
		UnitNode* unitByType[16];		// 0x2A4 (Indexed by UnitClassifactions)
		TargetCount* targetCount;		// 0x2E4 (Object to keep track of target counts)
		UnitNode* unitLinkedListHead;	// 0x2E8 (Ordered by UnitClassifactions)
		UnitNode* unitLinkedListTail;	// 0x2EC (Ordered by UnitClassifactions)
		int numUnits;					// 0x2F0 (Returned by TotalUnitCount())
		int ownerPlayerNum;				// 0x2F4 (All units in group should belong to this player)
		int deleteWhenEmptyTick;		// 0x2F8 (Initialized to MAX_INT, set to TethysGame.tick + 10000 by SetDeleteWhenEmpty(true))
		int bSetLights;					// 0x2FC (Initialized to 1 (on))
		// ...? 0x300? 0x304?
		int a5;							// 0x300 ** (Part of this class, or derived classes?)
		int a6;							// 0x304 ** (Part of this class, or derived classes?)
		// ----
	};

}	// End namespace
