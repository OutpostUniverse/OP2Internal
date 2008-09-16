// ** Note: This file needs a lot of work


#ifndef CommandPacket_H
#define CommandPacket_H


namespace OP2ForcedExport
{

	#pragma pack(push, 1)
	struct CommandPacketHeader
	{
		int messageType;
		short dataLength;
		int timeStamp;
		int unknown;					// **
	};
	#pragma pack(pop)


	#pragma pack(push, 1)
	struct CommandPacket
	{
		CommandPacketHeader cpHeader;
		char data[99];					// ** [Need adjustment after pragma pack?]
	};
	#pragma pack(pop)


	struct MachineSettings
	{
		short cpuSpeed;					// MHz
		short totalPhysMem;				// MB rounded up to a multiple of 4
		short windowWidth;				// Dans_RULE_UIFrame
		short windowHeight;				// Dans_RULE_UIFrame
	};

}	// End namespace


#endif
