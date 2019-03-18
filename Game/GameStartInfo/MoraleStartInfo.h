#pragma once


namespace OP2Internal
{

	enum MoraleLevelIndex
	{
		MoraleLevelExcellent	= 0,	// Great
		MoraleLevelGood			= 1,	// Good
		MoraleLevelFair			= 2,	// OK
		MoraleLevelPoor			= 3,	// Poor
		MoraleLevelTerrible		= 4,	// Rotten/Terrible
	};

	// Size: 0x48
	struct MoraleState
	{
		int moraleLevel;				// 0x0
		int eventMoraleModifier;		// 0x4
		int b1;							// 0x8 **
		int morale;						// 0xC [0..99]
		int b2;							// 0x10 **
		int residenceDamand;			// 0x14
		int foodSupply;					// 0x18 [0 = Surplus, 1 = DefifictBigSupply, 2 = Deficit, 3 = Starving]
		int disabledBldgRatio;			// 0x1C [0%..100%]
		int recForumDemandPercent;		// 0x20 [0%..100%, 10000]
		int b3;							// 0x24 ** Unimplemented?
		int medCenterDemandPercent;		// 0x28 [0%..100%, 10000]
		int bNurseryOperational;		// 0x2C
		int bUniversityOperational;		// 0x30
		int numDisasterWarningSystems;	// 0x34
		int dirtAvgDamagePrevention;	// 0x38 [0..10000 = % * 100]
		int unoccupiedColonistPercent;	// 0x3C
		int scientistsAsWorkersPercent;	// 0x40
		int bGorfOperational;			// 0x44
	};

}	// End namespace
