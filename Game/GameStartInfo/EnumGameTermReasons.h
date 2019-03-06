#pragma once


namespace OP2Internal
{

	enum class GameTermReasons
	{
		GameTermRunning				= 0,	// Still running
		
		GameTermMissionAccomplished = 3,	// Mission Accomplished
		GameTermMissionFailed		= 4,	// Mission Failed

		GameTermMissionAborted		= 6,	// Mission aborted  (single player abort?)
		GameTermVictory				= 7,	// Victory is sweet
		GameTermDefeat				= 8,	// You have been defeated
		GameTermControlTerminated	= 9,	// Control terminated  (multiplayer abort?)
		GameTermDemo1				= 10,	// Outpost 2 Demo
		GameTermDemo2				= 11,	// Outpost 2 Demo

		// ...								// other: Game Over
	};

}	// End namespace
