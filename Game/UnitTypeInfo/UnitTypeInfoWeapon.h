

#pragma once


#include "UnitTypeInfo.h"


namespace OP2Internal
{
/*
	class WeaponUnitTypeInfo : public UnitTypeInfo
	{
	public:
		// Virtual member functions
		//virtual Unit* CreateUnit(int pixelX, int pixelY, int unitIndex);	// 0x0
		//virtual char* GetUnitPropTag();				// 0x4 char* internalUnitName
		// virtual int  Save(StreamIO* savedGameFile);	// 0x8 BSuccess
		// virtual int  Load(StreamIO* savedGameFile);	// 0xC BSuccess
		//virtual int  Initialize();					// 0x10 BSuccess
		virtual void Process(Unit* chasisUnit);		// 0x14
		virtual Unit* FindTarget(Unit* chassisUnit, int desiredFlags);	// 0x18
		// New Virtual member functions
		virtual void GetGuardPostAnimationInfo(Unit* chassisUnit, int rotation);	// 0x1C
		virtual void GetTigerAnimationInfo(Unit* chassisUnit, int rotation);		// 0x20
		virtual void GetPantherAnimationInfo(Unit* chassisUnit, int rotation);		// 0x24
		virtual void GetLynxAnimationInfo(Unit* chassisUnit, int rotation);			// 0x28
		virtual int GetMovementAimOffset(int pixelDistance);						// 0x2C int estimatedOffset
		// ----

	public:
		//char* weaponName;		// 0x1F8 ???
		// ...
		int weaponBlastPixelRadius;				// 0x248
		int b1;									// 0x24C **
		int bTargetOnlyOnce;					// 0x250 ** Maybe? Stickyfoam?
		int fireSoundIndex;						// 0x254
		int hitSoundIndex;						// 0x258
		// ...?
	};
*/
}	// End namespace
