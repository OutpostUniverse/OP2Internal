#pragma once


namespace OP2Internal
{
	enum ActionType
	{
		moDone				= 0x01,
		moMove				= 0x02,
		moBuild				= 0x03,
		moBuildMine			= 0x04,
		moRepair			= 0x05,
		moDevelop			= 0x06,
		moObjWait			= 0x07,
		moOperationalWait	= 0x08,
		moEMPWait			= 0x09,
		moLanding			= 0x0A,
		moObjFroze			= 0x0B,
		moDelSelf			= 0x0C,
		moDoResearch		= 0x0D,
		moObjDocking		= 0x0E,
		moScavenge			= 0x0F,
		weaponMove			= 0x10,
		weatherMove			= 0x11,
		empRecover			= 0x12,
		weaponAimCoarse		= 0x13,
		weaponAimFine		= 0x14,
		SantaWalking		= 0x15,
		moInvalid			= 0x16,
	};
}	// End namespace
