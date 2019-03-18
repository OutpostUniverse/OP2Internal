#pragma once


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "EnumSongId.h"

struct DirectSoundBuffer;


namespace OP2Internal
{
	class MusicManager
	{
	public:
		// Constructor/Destructor
		MusicManager();						// 0x450180
		~MusicManager();					// 0x4501D0
		// MusicManager();					// 0x4500F0 [Static]
		// ~MusicManager();					// 0x450140 [Static]

		// Member functions
		int  LoadIniMusicSettings();		// 0x450210 BSuccess
		void ShutdownAndClose();			// 0x450250
		int  OpenClmFile();					// 0x450340 BSuccess
		int  InitSongIndexes();				// 0x450570 BSuccess  [song name table => Clm file index]
		void CloseClmFile();				// 0x450620 
		int  InitializeDirectSound();		// 0x450680 BSuccess
		void ReleaseSoundBuffer();			// 0x450760 
		void Deinitialize();				// 0x4507E0
		void Initialize();					// 0x4508D0
		void ShutdownAndClose2();			// 0x450AC0 **  [Duplicate of 0x450250?]
		void Pause();						// 0x450BB0
		void Unpause();						// 0x450C20
		void Stop();						// 0x450C60 
		void StartTimer();					// 0x450CC0 
		void PlayPauseMusic(int bPlayMusic);// 0x450FB0
		void SetVolume(int volumeIndex);	// 0x451170
		void SetMusicPlaylist(int numSongs, int repeatStartIndex, SongId songs[]);	// 0x4511B0

		// Static functions
		static void MusicTimerCallback();	// 0x450CF0

	public:
		// Member variables
		DirectSoundBuffer* lpDirectSoundBuffer;	// 0x0
		int timerID;							// 0x4
		int bPlaying;							// 0x8
		int b1;									// 0xC **
		int volumeIndex;						// 0x10
		int pauseLockCount;						// 0x14
		int bPlayMusic;							// 0x18
		void* headerData;						// 0x1C **
		HANDLE hClmFile;						// 0x20 
		int totalFileHeaderSize;				// 0x24
		int songIndex[26];						// 0x28 [Initialized to -1]
		CRITICAL_SECTION timerCriticalSection;	// 0x90
		int b2;									// 0xA8 **
		CRITICAL_SECTION criticalSection;		// 0xAC [Controls access to +0xA8]
		int numPlaylistEntries;					// 0xC4
		int repeatStartIndex;					// 0xC8
		SongId* playlist;						// 0xCC int[]*
		int currentPlayingSongIndex;			// 0xD0 [PlayList index]
		int bHasBegunPlayback;					// 0xD4 [Has Playback begun at the first song yet]
		int currentSongFileIndex;				// 0xD8 [Clm file index]
		int currentSongPosition;				// 0xDC [Byte offset into WAV data]
	};


	// Globals
	extern MusicManager musicManager;	// 0x565390
	extern char* songNameTable[26];		// 0x4E2700

}	// End namespace
