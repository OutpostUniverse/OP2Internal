// ** Note: This file is far from finished


#pragma once


struct DirectSoundBuffer;


namespace OP2Internal
{

	// Min Size: 0x24  [Member field access]
	// Max Size: 0x24  [Array stride]
	struct SoundBufferInfo
	{
		int soundIndex;							// 0x0
		int b1;									// 0x4 **
		int pixelY;								// 0x8
		int pixelX;								// 0xC
		int endTime;							// 0x10 [milliseconds]  [timeGetTime]
		DirectSoundBuffer* directSoundBuffer;	// 0x14
		long lVolume;							// 0x18
		long lPan;								// 0x1C
		int b5;									// 0x20 **
	};


	class SoundEffectsManager
	{
	public:
		// Member functions
		int  Init();												// 0x47DFD0 BSuccess  [Load .ini settings]
		// 0x47E070 **
		// 0x47E0B0 **
		// 0x47E170 **
		// 0x47E1B0 **
		// 0x47E1F0 **
		void SetPause(int bPause);									// 0x47E370
		// 0x47E4C0 **
		void Initialize();											// 0x47E5A0
		void Pause();												// 0x47E6A0
		void Unpause();												// 0x47E700
		// 0x47E710 **
		// 0x47E7A0 **
		// 0x47E830 **
		// 0x47E9F0 **
		// 0x47EC90 **
		void AddMapSound(int pixelX, int pixelY, int soundIndex);	// 0x47EDB0
		void AddGameSound(int soundIndex, int toPlayers);			// 0x47EFD0
		// 0x47F010 **
		// 0x47F050 **
		// 0x47F200 **

	public:
		// Member variables **
		// ----
		// 0x0
		// 0x4
		int numBuffersInUse;				// 0x8 ** maybe?
		SoundBufferInfo soundBufferInfo[1];	// 0xC **

		// 0x8FC
		// 
		int b1;					// 0x90C **
		int b2;					// 0x910 **
		int soundVolume;		// 0x914 [Game: SoundVol]
		int bPlaySounds;		// 0x918 [Game: Sound]
		// 0x91C
		int bDirectSoundInit;	// 0x920
		// 0x924 ???[]?  [0x80 bytes]
		int time;				// 0x9A4 [timeGetTime()]
		// 0x9A8
		// 0x9AC
	};


	// Globals
	extern SoundEffectsManager soundEffectsManager;		// 0x56D250
	extern char* soundEffectsFileNameTable[252];		// 0x4E0170

}	// End namespace
