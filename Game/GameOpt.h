

#pragma once


namespace OP2Internal
{

	const int numOptions = 26;

	enum GameOptIndex
	{
		// Main Debug flags
		GameOptBoolPowerBoost			= 0,	// 0x0 Adds 0x100000 = 1048576 power, buildings work without CC, and common and rare max storage is set to 100000
		GameOptBoolAllTechsAvailable	= 1,	// 0x1 Research.HasTech always returns true, and all beacons surveyed. Lab research list not updated: prevents research (fails to start as expected)
		GameOptBoolLogMoraleOutput		= 2,	// 0x2 Log Morale status to "MORALE.LOG"
		GameOptBoolDoDamage4X			= 3,	// 0x3 
		GameOptBoolFastUnits			= 4,	// 0x4 
		GameOptBoolInstantKitBuild		= 5,	// 0x5 Instant research
		GameOptBoolShowUnitPaths		= 6,	// 0x6 
		GameOptBoolShowMiniMapUnits		= 7,	// 0x7 Does not hide vehicles in the dark when headlights are off
		
		// Placeholder Cheats  [switched through to specified Player]
		GameOptSetCommonOre				= 8,	// 0x8
		GameOptSetRareOre				= 9,	// 0x9
		GameOptSetScientists			= 10,	// 0xA
		GameOptSetWorkers				= 11,	// 0xB
		GameOptSetFoodStored			= 12,	// 0xC
		GameOptSetKids					= 13,	// 0xD

		// RCC Effect Debug flags
		GameOptBoolDisableRccEffect		= 14,	// 0xE
		GameOptBoolEnableRccEffect		= 15,	// 0xF

		// Unknown, possibly removed  [Set by hidden or removed UI]
		// = 16,	// 0x10 **
		// = 17,	// 0x11 **

		// Daylight flags
		GameOptBoolDaylightMoves		= 18,	// 0x12
		GameOptBoolDaylightEverywhere	= 19,	// 0x13 (Not Cheat)

		// Game Speed
		GameOptGameSpeed4X				= 20,	// 0x14 (Not Cheat)

		// Fixed morale
		GameOptForceMoraleExcellentMask	= 21,	// 0x15 
		GameOptForceMoraleGoodMask		= 22,	// 0x16 
		GameOptForceMoraleFairMask		= 23,	// 0x17 
		GameOptForceMoralePoorMask		= 24,	// 0x18 
		GameOptForceMoraleTerribleMask	= 25,	// 0x19 

		// -- End Global options --

		// Player resource cheats
		GameOptPlayerAddResources		= 26,	// 0x1A  Workers + 50, Scientists + 25, Kids + 10, Common Ore + 1000, Rare Ore + 1000, Food Stored + 25000
		GameOptAllPlayerAddResources	= 27,	// 0x1B  Workers + 50, Scientists + 25, Kids + 10, Common Ore + 1000, Rare Ore + 1000, Food Stored + 25000

		// Disaster creation debug options
		GameOptCreateVortex				= 28,	// 0x1C  Vortex (0,   700):8,  RoboDozer (0, 21)
		GameOptCreateLightning			= 29,	// 0x1D  Storm  (0,   500):12, RoboDozer (0, 15)
		GameOptCreateEarthquake			= 30,	// 0x1E  Quake  (512, 2048):4
		GameOptCreateMeteor				= 31,	// 0x1F  Meteor (100, 700):4,  RoboDozer (3, 15)

		// Free morale level
		GameOptFreeMoraleLevel			= 32,	// 0x20 (Not Cheat)
	};

	union GameOpt
	{
		struct
		{
			// Main Debug flags
			int bPowerBoost;				// 0x0  Adds 0x100000 = 1048576 power, buildings work without CC, and 100000 common ore storage (rare storage?)
			int bAllTechsAvailable;			// 0x4  All bulding options available. Prevents research  (fails to start as expected)
			int bLogMoraleOutput;			// 0x8  
			int bDoDamage4X;				// 0xC  
			int bFastUnits;					// 0x10
			int bInstantKitBuild;			// 0x14 Instant research
			int bShowUnitPaths;				// 0x18
			int bAllMiniMapUnitsVisible;	// 0x1C

			// [No global references, special cased to map to specified player]
			int setCommonOrePlaceholder;	// 0x20
			int setRareOrePlaceholder;		// 0x24
			int setScientistsPlaceholder;	// 0x28
			int setWorkersPlaceholder;		// 0x2C
			int setFoodStoredPlaceholder;	// 0x30
			int setKidsPlaceholder;			// 0x34

			// RCC Effect Debug flags
			int bForceDisableRCCEffect;		// 0x38 For all Human Players
			int bForceEnableRCCEffect;		// 0x3C For all Human Players

			// Unknown, possibly removed
			int b1;							// 0x40 ** [Possibly set through hidden or removed UI]
			int b2;							// 0x44 ** [Possibly set through hidden or removed UI]

			// Daylight flags
			int bDaylightMoves;				// 0x48
			int bDaylightEverywhere;		// 0x4C (Not Cheat)

			// Game Speed
			int gameSpeed4X;				// 0x50 (Not Cheat)

			// Fixed morale
			union
			{
				struct
				{
					int forceMoraleExcellentPlayerBitMask;	// 0x54
					int forceMoraleGoodPlayerBitMask;		// 0x58
					int forceMoraleFairPlayerBitMask;		// 0x5C
					int forceMoralePoorPlayerBitMask;		// 0x60
					int forceMoraleTerriblePlayerBitMask;	// 0x64
				};
				int forceMoralePlayerBitMask[5];
			};
		};
		int option[numOptions];				// 26 Options
	};

}	// End namespace
