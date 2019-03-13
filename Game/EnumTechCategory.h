#pragma once


namespace OP2Internal
{
	// "CATEGORY" values (for both items and upgrades to these items)
	enum TechCategory
	{
		tcFree,                 // 0 = Free technologies (and unavailable technologies)
		tcBasic,                // 1 = Basic labratory sciences
		tcDefenses,             // 2 = Defenses (GP upgrade, walls, and efficiency engineering)
		tcPower,                // 3 = Power
		tcVehicles,             // 4 = Vehicles (which ones can be built, speed upgrades, armor upgrades)
		tcFood,                 // 5 = Food
		tcMetals,               // 6 = Metals gathering
		tcWeapons,              // 7 = Weapons
		tcSpace,                // 8 = Space (spaceport, observatory, launch vehicle, skydock)
		tcPopulationHappiness,  // 9 = Population (happiness)
		tcDisaster,             // 10 = Disaster warning (and defense)
		tcPopulationGrowth,     // 11 = Population (health, growth)
		tcSpaceshipModule,      // 12 = Spaceship module
	};
}	// End namespace
