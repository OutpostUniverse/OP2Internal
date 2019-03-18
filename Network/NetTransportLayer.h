#pragma once

#include <rpc.h>

namespace OP2Internal
{

	struct Packet;


	struct TrafficCounters
	{
		int timeOfLastReset;
		int numPacketsSent;
		int numBytesSent;
		int numPacketsReceived;
		int numBytesReceived;
	};


	class NetTransportLayer
	{
	public:
		// Member variables
		int playerNetID;

	public:
		// Virtual member functions
		virtual ~NetTransportLayer() {};
		virtual int GetHostPlayerNetID() = 0;
		virtual void ShutDownInvite() = 0;
		virtual int ReplicatePlayersList() = 0;
		virtual int GetOpponentNetIDList(int netIDList[], int maxNumID) = 0;
		virtual void RemovePlayer(int playerNetID) = 0;
		virtual int Send(Packet& packet) = 0;
		virtual int Receive(Packet& packet) = 0;
		virtual int IsHost() = 0;
		virtual int IsValidPlayer() = 0;
		virtual int F1() = 0;						// ** Return 1
		virtual int GetAddressString(int playerNetID, char* addressString, int bufferSize) = 0;
		virtual int ResetTrafficCounters() = 0;
		virtual int GetTrafficCounts(TrafficCounters& trafficCounters) = 0;
	};


	// Globals
	extern GUID gameIdentifier;

}	// End namespace
