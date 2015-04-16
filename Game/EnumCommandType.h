
#ifndef EnumCommandType_H
#define EnumCommandType_H


namespace OP2ForcedExport
{
	enum CommandType
	{
		ctNop				= 0x00,
		ctMoDoze			= 0x01,
		ctMoMove			= 0x02,
		ctMoDock			= 0x03,
		ctMoDockEG			= 0x04,
		ctMoStop			= 0x05,
		ctMoBuild			= 0x06,
		ctMoBuildWall		= 0x07,
		ctMoRemoveWall		= 0x08,
		ctMoProduce			= 0x09,
		ctMoTransferCargo	= 0x0A,
		ctMoLoadCargo		= 0x0B,
		ctMoUnloadCargo		= 0x0C,
		ctMoRecycle			= 0x0D,
		ctMoDumpCargo		= 0x0E,
		ctMoScavenge		= 0x0F,
		ctMoSpecialWait		= 0x10,
		ctMoSurvey			= 0x11,
		ctMoIdle			= 0x12,
		ctMoUnIdle			= 0x13,
		ctMoSelfDestruct	= 0x14,
		stMoScatter			= 0x15,
		ctMoResearch		= 0x16,
		ctMoTrainScientists	= 0x17,
		ctMoTransfer		= 0x18,
		ctMoLaunch			= 0x19,
		ctMoFlyInSpace		= 0x1A,
		ctMoRepair			= 0x1B,
		ctMoRepairObj		= 0x1C,
		ctMoReprogram		= 0x1D,
		ctMoDismantle		= 0x1E,
		ctMoSalvage			= 0x1F,
		ctMoCreate			= 0x20,
		ctMoDevelop			= 0x21,
		ctMoUnDevelop		= 0x22,
		ctMoLightToggle		= 0x23,
		ctMoAttackObj		= 0x24,
		ctMoGuard			= 0x25,
		ctMoStandGround		= 0x26,
		ctMoCargoRoute		= 0x27,
		ctMoPatrol			= 0x28,
		ctMapChange			= 0x29,
		ctMoPoof			= 0x2A,
		ctGameOpt			= 0x2B,
		ctGodWeapon			= 0x2C,
		ctChatText			= 0x2D,
		ctChatSFX			= 0x2E,
		ctMoDeath			= 0x2F,
		ctChat				= 0x30,
		ctQuit				= 0x31,
		ctAlly				= 0x32,
		ctGoAI				= 0x33,
		ctMachineSettings	= 0x34,
		ctInvalidCommand	= 0x35,
		WeaponFiring		= 0x36,
	};
}	// End namespace


#endif
