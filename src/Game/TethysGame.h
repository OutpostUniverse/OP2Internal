#pragma once


#include "GameOpt.h"
#include "GameStartInfo/GameStartInfo.h"
#include "Player.h"


namespace OP2Internal
{

	enum GameTermReasons;
	class StreamIO;
	class TFileDialog;
	class GameNetLayer;


	class TethysGame
	{
	public:
		// Static Constructor/Destructor
		// [Static]Constructor()	// 0x4890C0
		// [Static]Destructor()		// 0x489100

		// Constructor/Destructor
		TethysGame();				// 0x489130

		// Member functions
		bool LoadDebugMap();												// 0x489170
		bool StartGame(GameStartInfo* gameStartInfo);						// 0x4893B0 bSuccess
		void LoadPlayerGameStartInfo(GameStartInfo* gameStartInfo);			// 0x4899C0
		int  F1(MissionResults* missionResults);							// 0x489AB0 **
		MissionResults* GetMissionResults();								// 0x489B00
		void InitPlayers(int numPlayers);									// 0x489E50
		void ProcessGameCycle();											// 0x489EA0
		void Deinitialize();												// 0x48A080
		bool Save(StreamIO* savedGame);										// 0x48A150 ** [Dead code?]
		bool Load(StreamIO* savedGame);										// 0x48A170 ** [Dead code?]
		bool VerifySavedGameTileTag(StreamIO* savedGame);					// 0x48A190 bSuccess
		bool SaveGame(StreamIO* savedGame, TFileDialog* savedGameDialog);	// 0x48A1F0 bSuccess
		bool LoadGame(StreamIO* savedGame);									// 0x48A3E0 bSuccess
		void LocalPlayerQuit(char a1, char a2);								// 0x48A6A0 **
		void PostQuitMessage(int quitMessageIndex, int quitDelay);			// 0x48A720
		// ----

		// Static member functions
		static void __fastcall AddMessage(int pixelX, int pixelY, const char* message, int toPlayerNum, int soundIndex);	// 0x478710

	public:
		// Member variables
		GameOpt gameOpt;				// 0x0
		int numPlayers;					// 0x68 Initialized from level DescBlock
		int numHumanPlayers;			// 0x6C 
		int cpRate;						// 0x70 Number of ticks between processing CPs [Note: Must be a power of 2]
		int lgCpRate;					// 0x74 Cached base 2 log, so a bit shift can be used to multiply or divide
		int networkCpArraySpace;		// 0x78 Space available for Command Packet data in network packets
		int cpTick;						// 0x7C Current CP Processing cycle  [*cpRate = tick]  [tick/rate = cpTick]
		int cpDelay;					// 0x80 Number of cpTicks to delay each command cycle
		int tick;						// 0x84 Note: 100 ticks per mark, most input processing done every 4 ticks
		int tickOfLastSetGameOptCp;		// 0x88 Not set by FreeMoraleLevel, SetGameSpeed, SetDaylightEverywhere
		int b3;							// 0x8C **  [SantaWalking related, cleared to 0 on LoadLevel, and SantaWalking.DoDeath]
		// ----
		int localPlayerNum;				// 0x90 
		int chatDestPlayerBitMask;		// 0x94 Bitmask of Players that chat messages will be sent to
		int startFadeOutTick;			// 0x98 
		GameTermReasons termReason;		// 0x9C 
		int bSkipProgressSave;			// 0xA0 Don't display SaveLoadContinue dialog box on level end
		MissionResults gameStartInfo;	// 0xA4 GameStartInfo  [Game starting parameters, used to restart a level, and return MissionResults]
		char padding[3];				// 0x481 Padding, due to unaligned size of GameStartInfo
		Player player[7];				// 0x484
		GameNetLayer* gameNetLayer;		// 0x5980
	};


	// Globals
	extern TethysGame tethysGame;		// 0x56EA98

}	// End namespace


	// End Include Guard
