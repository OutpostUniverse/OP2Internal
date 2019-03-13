#pragma once

#include "Unit.h"
#include "EnumTruckCargo.h"


namespace OP2Internal
{

	class Vehicle : public PlayerUnit
	{
	public:
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void DrawDock(Viewport* viewport);	// 0x78 **  [** See Note Above **]
		virtual void Pathfind(int a1, int a2, int a3, int a4);	// 0x7C **
		virtual int GetChasisAnimationIndex(int rotationIndex);	// 0x80
		virtual void F5(int a1, int a2, int a3);	// 0x84 **
		virtual void F6();							// 0x88 **  [DoDock?]
		virtual void F7();							// 0x8C **
		virtual int CanMove(int tileX, int tileY);	// 0x90 int bCanMove  [Check celltype against track type, and if units can be bumped out of the way]
		// ----

		// Member functions
		void SetCurrentUnitAndTrackTypeAndAttackType();	// 0x438360

	public:
		// Member variables
		// ----
		// vtbl
		// ...
	};

	class CargoTruck : public Vehicle
	{
	public:
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void SetCargo(TruckCargo truckCargo, int cargoAmountOrTechID, short a2);	// 0x94 **
		virtual void F9();							// 0x98 **
		// ----
	};

}	// End namespace
