

#ifndef UnitTypeInfoBuilding_H
#define UnitTypeInfoBuilding_H


#include "UnitTypeInfo.h"


namespace OP2ForcedExport
{

	class BuildingUnitTypeInfo : public UnitTypeInfo
	{
	public:
		// Member variables
		int b1[119];						// **
		int requiredTechIndex;				// 0x1E4
		int b2[24];							// **
		short tileWidth;					// 0x248
		short tileHeight;					// 0x24A
		int initialFlags;					// 0x24C
		int edenAnimationIndex[10];			// 0x250 [BuildingAnimationTypeIndex]
		int plymouthAnimationIndex[10];		// 0x278 [BuildingAnimationTypeIndex]
		// ...
	};

}	// End namespace


#endif
