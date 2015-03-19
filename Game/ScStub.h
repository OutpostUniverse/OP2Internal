// ** Note: This file needs a lot of work


#ifndef ScStub_H
#define ScStub_H


namespace OP2ForcedExport
{
	class ScStubCreator;

	class ScStub
	{
	public:
		virtual ScStub* Release(int bDelSelf);		// 0x00
		virtual ScStubCreator* GetScStubCreator();	// 0x04
		virtual void SetA1();						// 0x08 (Set enableStatus = 2) **
		virtual void Enable();						// 0x0C (Set enableStatus = 1)
		virtual void Disable();						// 0x10 (Set enableStatus = 0)
		virtual int Save(StreamIO* savedGameFile);	// 0x14 (saves enableStatus field)
		virtual int Load(StreamIO* savedGameFile);	// 0x18 (loads enableStatus field)
		virtual ~ScStub();							// 0x1C (Destructor)
		virtual int GetOffsetA2();					// 0x20 (returns scStubIndex * 16 + enableStatus + 1) **

	public:
		// vtbl				// 0x0 
		int scStubIndex;	// 0x4 
		int enableStatus;	// 0x8 (Values 0, 1, 2?)
		int unknown1;		// 0xC  **
		int unknown2;		// 0x10 **
	};


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
		Trigger* prev;			// 0x14
		Trigger* next;			// 0x18
		int bOneShot;			// 0x1C
		int bVectorHasFired;	// 0x20 PlayerBitMask
		FunctionReference* callback;	// 0x24
	};

}	// End namespace


#endif
