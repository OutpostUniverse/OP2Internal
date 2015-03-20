// ** Note: This file needs a lot of work


#ifndef ScStubGroupBuildGroup_H
#define ScStubGroupBuildGroup_H


#include "ScStubGroup.h"


namespace OP2ForcedExport
{

	class BuildGroup : public Group
	{
	public:
	public:
		void* a1;			// 0x30C **
		int a12;			// 0x310 ** ?
		void* a2;			// 0x314 **
		int a22;			// 0x318 ** ?
		void* a3;			// 0x31C **
		int a32;			// 0x320 ** ?
		void* a5;			// 0x324 **
		int a6[13];			// 0x328 ** [MemClear]
		int a7;				// 0x348 ** (=0) (overlapped by MemClear)
	};

}	// End namespace


#endif
