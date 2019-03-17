#pragma once


namespace OP2Internal
{

	// Size: 0x206
	struct ResearchState
	{
		int numTechs;					// 0x0
		short techLevel;				// 0x4 [Give techs up to techID = (techLevel * 1000 + 999)]
		char techNum[256];				// 0x6
		char playerBitVector[256];		// 0x106
	};

}	// End namespace
