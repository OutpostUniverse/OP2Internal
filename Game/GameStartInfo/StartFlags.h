

#ifndef StartFlags_H
#define StartFlags_H


namespace OP2Internal
{

	struct StartupFlags
	{
		int bDisastersOn:1;					// 0x000001
		int bDayNightOn:1;					// 0x000002
		int bMoraleOn:1;					// 0x000004
		int bCampaign:1;					// 0x000008
		int bMultiplayer:1;					// 0x000010
		int bCheatsOn:1;					// 0x000020
		unsigned int maxPlayers:3;			// 0x0001C0
		int missionType:5;					// 0x003E00
		int b1:3;							// 0x01C000 **
		unsigned int numInitialVehicles:4;	// 0x1E0000
	};

	struct GameFlags
	{
		int numPlayers:3;					// 0x7
		int bReplay:1;						// 0x8
	};

}	// End namespace


#endif
