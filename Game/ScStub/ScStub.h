#pragma once


namespace OP2Internal
{
	class ScStubCreator;


	class ScStub
	{
	public:
		virtual ScStub* Release(int bDelSelf);		// 0x00
		virtual ScStubCreator* GetScStubCreator();	// 0x04
		virtual void Initialize();					// 0x08 (Set enableStatus = 2) ** [Initialize?]
		virtual void Enable();						// 0x0C (Set enableStatus = 1)
		virtual void Disable();						// 0x10 (Set enableStatus = 0)
		virtual int Save(StreamIO* savedGameFile);	// 0x14 (Saves enableStatus field)
		virtual int Load(StreamIO* savedGameFile);	// 0x18 (Loads enableStatus field)
		virtual ~ScStub();							// 0x1C (Destructor)
		virtual int Checksum();						// 0x20 (Returns scStubIndex * 16 + enableStatus + 1)
		// ----

	public:
		// vtbl				// 0x0 
		int scStubIndex;	// 0x4 
		int enableStatus;	// 0x8 (Values 0, 1, 2?)
		int unknown1;		// 0xC  **
		int unknown2;		// 0x10 **
		// ----
	};

}	// End namespace
