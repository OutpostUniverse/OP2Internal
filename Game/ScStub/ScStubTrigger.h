

#ifndef ScStubTrigger_H
#define ScStubTrigger_H


namespace OP2ForcedExport
{

	// Size: 0x30
	class FunctionReference : public ScStub
	{
	public:
	public:
		int a1;	// 0x14 **
		int a2;	// 0x18 **
		int a3;	// 0x1C **
		char* triggerName;	// 0x20
		void* callback;		// 0x24
		int a4; // 0x28 **
		int a5;	// 0x2C **
	};


	class Trigger : public ScStub
	{
	public:
	public:
		Trigger* prev;					// 0x14
		Trigger* next;					// 0x18
		int bOneShot;					// 0x1C
		int bVectorHasFired;			// 0x20 PlayerBitMask
		FunctionReference* callback;	// 0x24
	};

}	// End namespace


#endif
