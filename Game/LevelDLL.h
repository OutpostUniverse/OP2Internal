

#ifndef LevelDLL_H
#define LevelDLL_H


namespace OP2ForcedExport
{

	class Unit;
	class StreamIO;


	struct BufferInfo
	{
		void* buffer;
		int bufferSize;
	};


	class LevelDLL
	{
	public:
		// Constructor/Destructor
		LevelDLL();

		// Member functions
		bool LoadScript(char* filename);			// Return bSuccess
		bool InitializeLevel();						// Return bSuccess
		void ProcessTriggers();
		void RaiseUnitCreatedEvent(Unit* createdUnit, short scStubIndex);
		void RaiseUnitTransferredEvent(Unit* transferredUnit, int sourcePlayerNum, int destPlayerNum);
		void GoAI(int playerNum);
		bool Save(StreamIO* savedGameFile);			// ** Return b???
		int Checksum();

	public:
		// Member variables
		int hModule;						// 0x0
		int  (__cdecl *InitProc)();			// 0x4
		void (__cdecl *AIProc)();			// 0x8
		int  (__cdecl *StatusProc)();		// 0xC
		BufferInfo saveRegions;				// 0x10
		int unknown;						// 0x18 **
		char unknown2[0x30];				// 0x1C **
	};

}	// End namespace


#endif
