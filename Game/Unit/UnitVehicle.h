

#ifndef UnitVehicle_H
#define UnitVehicle_H


#include "Unit.h"


namespace OP2ForcedExport
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
		virtual void SetCargo(enum Truck_Cargo truckCargo, int cargoAmountOrTechID, short a2);	// 0x94 **
		virtual void F9();							// 0x98 **
		// ----
	};

}	// End namespace


#endif