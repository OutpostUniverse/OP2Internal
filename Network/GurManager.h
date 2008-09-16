

#ifndef GurManager_H
#define GurManager_H


#include "Packet.h"


namespace OP2ForcedExport
{

	class NetTransportLayer;


	struct PlayerGurInfo
	{
		int playerNetID;
		int b1[7];				// **
		int timeOfLastReceivedPacket;
		int b2;					// **
		int b3;					// **
		int numResentPackets;
	};


	#pragma pack(push, 1)
	class NetBuffer
	{
	public:
		// Member variables
		NetBuffer* prev;
		NetBuffer* next;
		int b1[5];				// **
		Packet packet;
	};
	#pragma pack(pop)


	class GurManager
	{
	public:
		// Member functions
		GurManager();												// 0x0042D710
		int Initialize(NetTransportLayer* netTransportLayer);		// 0x0042D760
		// Operator New/Delete  (delete is called from the exe on it's own heap)
		void* operator new(size_t tSize);
		void operator delete(void*);

	public:
		// Member variables
		// ----------------
		int b1;					// **
		NetBuffer* b2;			// **
		int b3;					// **
		NetBuffer* head;
		NetBuffer* tail;
		NetBuffer netBuffer[37];
		NetTransportLayer* netTransportLayer;
		int b4;					// **
		int b5;					// **
		int numPlayers;
		PlayerGurInfo playerInfo[5];
		int numRetries;
		int timeOut;
		int timeOutD4;
		int b6[4];				// **
	};

}	// End namespace


#endif
