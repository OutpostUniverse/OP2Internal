

#pragma once


#include "../WinTypes.h"


namespace OP2Internal
{

	class RandomNumberGenerator
	{
	public:
		// Member functions
		int Rand();								// 0x46F000
		int Rand(int range);					// 0x46F060
		void SetSeed(int seed);					// 0x46EFB0
		void SetSeed(DWORD dw1, DWORD dw2);		// 0x46EFF0
		void GetSeed(DWORD* dw1, DWORD* dw2);	// 0x46EF90

	public:
		// Member variables
		unsigned int dword1;	// 0x0
		unsigned int dword2;	// 0x4
	};


	// Globals
	extern RandomNumberGenerator randNumGen;	// 0x56BE20 [Main game RNG]
	extern RandomNumberGenerator thorsNumGen;	// 0x574428

}	// End namespace
