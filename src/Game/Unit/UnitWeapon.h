#pragma once


#include "Unit.h"


namespace OP2Internal
{

	class Weapon : public PlayerUnit
	{
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void DrawDock(Viewport* viewport);	// 0x78 **  [** See Note Above **]
		virtual void F5(int a1, int a2);			// 0x7C **
		virtual void DoExplode(Unit* source);		// 0x80
		virtual void F6(int a1);					// 0x84 **
		virtual void DoDamage();					// 0x88
		virtual int GetAnimationIndex();			// 0x8C
		virtual int GetNumAnimationFrames();		// 0x90
		virtual void SetWeaponSource(int weaponSourceUnitIndex);	// 0x94
		// ----
	};

}	// End namespace
