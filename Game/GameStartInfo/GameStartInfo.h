

#ifndef GameStartInfo_H
#define GameStartInfo_H


#include "EnumGameType.h"
#include "EnumGameTermReasons.h"
#include "StartFlags.h"
#include "MoraleStartInfo.h"
#include "PlayerStartInfo.h"
#include "ResearchStartInfo.h"


namespace OP2ForcedExport
{

	// Size: 0xBA
	#pragma pack(push, 1)
	struct GameStartInfo
	{
		int startupFlags;				// 0x0
		int version;					// 0x4
		int b1;							// 0x8 **
		int gameFlags;					// 0xC
		char scriptName[32];			// 0x10
		int playerFlags[6];				// 0x30
		int playerNetID[6];				// 0x48
		char playerName[13*6];			// 0x60
		int gameSpeed4X;				// 0xAE
		int randomNumberSeed;			// 0xB2
		int b2;							// 0xB6 **
	};
	#pragma pack(pop)


	// Size: 0x3DD
	#pragma pack(push, 1)
	struct MissionResults: public GameStartInfo
	{
		int gameTermReason;				// 0xBA
		int b3;							// 0xBE **
		PlayerEndInfo playerEndInfo[6];	// 0xC2
		int missionTypeOrLevelNum;		// 0x16A
		PlayerStartInfo playerStartInfo;// 0x16E [Local Player]
		char localPlayerNum;			// 0x18A
		int tick;						// 0x18B
		MoraleState moraleState;		// 0x18F
		ResearchState researchState;	// 0x1D7
	};
	#pragma pack(pop)

}	// End namespace


#endif
