

#ifndef PlayerStartInfo_H
#define PlayerStartInfo_H


namespace OP2ForcedExport
{

	// Size: 4
	struct PlayerFlags
	{
		unsigned int b1:1;					// 0x01 **
		unsigned int bIsHost:1;				// 0x02
		unsigned int bIsEden:1;				// 0x04
		unsigned int resources:2;			// 0x18
		unsigned int color:3;				// 0xE0
	};

	// Size: 4
	struct SatelliteCounts
	{
		unsigned int numRLV:4;
		unsigned int numSolarSat:4;
		unsigned int b1:1;
		unsigned int numEdwardSat:4;
	};

	// Size: 0x1C
	struct PlayerEndInfo
	{
		int structuresBuilt;			// 0x0
		int vehiclesBuilt;				// 0x4
		int structuresLost;				// 0x8
		int vehiclesLost;				// 0xC
		int enemyStructuresDestroyed;	// 0x10
		int enemyVehiclesDestroyed;		// 0x14
		int oreHarvested;				// 0x18 [Midas]
	};

	// Size: 0x1C
	struct PlayerStartInfo
	{
		int food;						// 0x0
		int commonOre;					// 0x4
		int rareOre;					// 0x8
		int workers;					// 0xC
		int scientists;					// 0x10
		int kids;						// 0x14
		SatelliteCounts satCounts;		// 0x18
	};


}	// End namespace


#endif
