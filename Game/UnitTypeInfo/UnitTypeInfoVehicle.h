

#ifndef UnitTypeInfoVehicle_H
#define UnitTypeInfoVehicle_H


#include "UnitTypeInfo.h"


namespace OP2ForcedExport
{

	class VehicleUnitTypeInfo : public UnitTypeInfo
	{
	public:
		int b1[145];						// **
		int edenAnimationIndex[16];			// [directionIndex]
		int b2[48];							// **
		int plymouthAnimationIndex[16];		// [directionIndex]

	public:
		// ...
		int trackType;						// 0x1E8
		// ...?
	};

}	// End namespace


#endif
