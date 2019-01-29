

#ifndef NetGameProtocol_H
#define NetGameProtocol_H


namespace OP2Internal
{

	class NetGameProtocol
	{
	public:
		// Virtual member functions
		virtual bool IsEnabled() = 0;
		virtual bool DoStart() = 0;
		virtual bool F1() = 0;						// ** Return 1
		virtual const char* GetProtocolName() = 0;
	};



	struct ProtocolEntry
	{
		int controlId;
		NetGameProtocol* netGameProtocol;
	};



	// Globals
	extern NetGameProtocol* protocolNameLookupTable[4];		// 0x004D6450
	extern ProtocolEntry protocolList[5];					// 0x004DF380

	// ProtocolNameLookupTable
	//  0:  TCP
	//  1:  SIGS
	//  2:  Modem
	//  3:  IPX

	// ProtocolList
	// Index:  controlId = Protocol
	//  0:  3 = TCP
	//  1:  5 = IPX
	//  2:  4 = Modem
	//  3:  7 = Serial
	//  4:  6 = SIGS

}	// End namespace


#endif
