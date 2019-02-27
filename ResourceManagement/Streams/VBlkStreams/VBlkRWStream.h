#pragma once


#include "../StreamIOBaseVBlkRWStream.h"


namespace OP2Internal
{

	// Used to read VOL data sections  ['VBLK']
	// Min Size: 0x20
	// Max Size: 0x20
	class VBlkRWStream : public BaseVBlkRWStream
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~VBlkRWStream();							// 0x407180
		// virtual int  GetPosition();
		// virtual int  SetPosition(int position);
		// virtual int  F1();								// **
		// virtual int  FlushFileBuffers();
		// virtual int  Write(int bufferSize, char* buffer);
		// virtual int  Read(int bufferSize, char* buffer);
		virtual void Close();								// 0x407370

		// Constructor/Destructor
		VBlkRWStream();										// 0x407150
		~VBlkRWStream();									// 0x4071C0

		// Member functions
		int OpenWrite(StreamIO* containerStream, DWORD tag, int size, int bAlign32);	// 0x4071E0 BSuccess
		int OpenRead(StreamIO* containerStream, DWORD tag);	// 0x407270 BSuccess  [Verifies source tag matches parameter]
		int OpenRead(StreamIO* containerStream);			// 0x407300 BSuccess

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4CF570]
		// int numBytesReadOrWritten;		// 0x4 Most recent Read/Write
		// int streamStatus;				// 0x8 [0 = OK, other = errorCode]
		// ----
		// StreamIO* containerStream;		// 0xC  
		// VBlkHeader header;				// 0x10
		// int positionOffset;				// 0x18 Offset within vol file  [Current stream position]
		// int startOffset;					// 0x1C Offset within vol file  [Offset of header, data is a +8]
		// ----
		// ----
	};

}	// End namespace
