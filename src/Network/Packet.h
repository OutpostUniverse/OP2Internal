#pragma once


// Bring in definitions of structs: GUID, sockaddr_in
#include <winsock2.h>

#include "../Game/GameStartInfo/GameStartInfo.h"


namespace OP2Internal
{

	// Everything in this file should be byte aligned
	#pragma pack(push, 1)


	// ****************************************

	// ------
	// Header
	// ------

	struct PacketHeader
	{
		int sourcePlayerNetID;
		int destPlayerNetID;
		unsigned char sizeOfPayload;
		unsigned char type;
		int checksum;
	};



	// ************************
	// Transport Layer messages
	// ************************

	enum TransportLayerCommandType
	{
		tlcJoinRequest = 0,
		tlcJoinGranted = 1,
		tlcJoinRefused = 2,
		tlcStartGame = 3,
		tlcSetPlayersList = 4,
		tlcSetPlayersListFailed = 5,
		tlcUpdateStatus = 6,
		// Custom message types
		tlcHostedGameSearchQuery = 7,
		tlcHostedGameSearchReply = 8,
		tlcGameServerPoke = 9,
		tlcJoinHelpRequest = 10,
		tlcRequestExternalAddress = 11,
		tlcEchoExternalAddress = 12,
	};

	enum class PeerStatus : short
	{
		EmptySlot,
		Joining, // Joining Player Cleaned from list
		Normal,
		ReplicateSuccess, // Successfully replicated players list
		ReplicateFailure  // Failed to replicate players list
	};


	// ****************************************

	// ---------------
	// Payload formats
	// ---------------

	// [Nested structure]
	struct NetPeerInfo
	{
		int ip;
		short port;
		PeerStatus status;
		int playerNetID;
	};

	struct TransportLayerHeader
	{
		TransportLayerCommandType commandType;
	};

	struct JoinRequest : public TransportLayerHeader
	{
		GUID sessionIdentifier;
		int returnPortNum;			// [47800-47807]
		char password[12];
	};

	struct JoinReply : public TransportLayerHeader
	{
		GUID sessionIdentifier;
		int newPlayerNetID;
	};

	struct JoinReturned : public TransportLayerHeader
	{
		int newPlayerNetID;
		int unused1;
		int unused2;
		int unused3;
	};

	struct PlayersList : public TransportLayerHeader
	{
		int numPlayers;
		NetPeerInfo netPeerInfo[6];
	};

	struct StatusUpdate : public TransportLayerHeader
	{
		PeerStatus newStatus;
	};



	// ****************************************

	// ---------------------
	// Custom Packet formats
	// ---------------------

	// [Nested structure]
	struct CreateGameInfo
	{
		StartupFlags startupFlags;
		char gameCreatorName[15];
	};

	struct HostedGameSearchQuery : public TransportLayerHeader
	{
		GUID gameIdentifier;
		unsigned int timeStamp;
		char password[12];
	};

	struct HostedGameSearchReply : public TransportLayerHeader
	{
		GUID gameIdentifier;
		unsigned int timeStamp;
		GUID sessionIdentifier;
		CreateGameInfo createGameInfo;
		sockaddr_in hostAddress;
	};


	enum PokeStatusCode
	{
		pscGameHosted = 0,
		pscGameStarted = 1,
		pscGameCancelled = 2,
		pscGameDropped = 3,
	};

	struct GameServerPoke : public TransportLayerHeader
	{
		int statusCode;
		int randValue;
	};

	struct JoinHelpRequest : public TransportLayerHeader
	{
		GUID sessionIdentifier;
		int returnPortNum;			// [47800-47807]
		char password[12];
		sockaddr_in clientAddr;
	};

	struct RequestExternalAddress : public TransportLayerHeader
	{
		unsigned short internalPort;
	};

	struct EchoExternalAddress : public TransportLayerHeader
	{
		unsigned short replyPort;
		sockaddr_in addr;
	};

	// ****************************************

	union TransportLayerMessage
	{
		// Header only
		TransportLayerHeader tlHeader;

		// Standard messages
		JoinRequest joinRequest;
		JoinReply joinReply;
		JoinReturned joinReturned;
		PlayersList playersList;
		StatusUpdate statusUpdate;

		// Custom messages
		HostedGameSearchQuery searchQuery;
		HostedGameSearchReply searchReply;
		GameServerPoke gameServerPoke;
		JoinHelpRequest joinHelpRequest;
		RequestExternalAddress requestExternalAddress;
		EchoExternalAddress echoExternalAddress;
	};


	// ****************************************

	// *************
	// Game Messages
	// *************

	struct GameMessageHeader
	{
	};


	union GameMessage
	{
		// Header only
		GameMessageHeader gmHeader;

		// Standard messages
	};


	// ****************************************

	// ------
	// Packet
	// ------

	struct Packet
	{
		PacketHeader header;
		union
		{
			char payloadData[0x212];
			TransportLayerMessage tlMessage;
			GameMessage gameMessage;
		};

		// Member functions
		int Checksum() const;
	};



	// Restore old alignment setting
	#pragma pack(pop)

}	// End namespace
