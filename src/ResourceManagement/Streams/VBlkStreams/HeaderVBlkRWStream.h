#pragma once


#include "../StreamIOBaseVBlkRWStream.h"


namespace OP2Internal
{

	// Used to read VOL header sections  ['VOL ', 'volh', 'vols', 'voli']
	// Min Size: 0x20
	// Max Size: 0x28  [Based on local variable offsets, where 2 DWORDs are probably local variables with nothing to do with this class]
	// Size: 0x20
	class HeaderVBlkRWStream : public BaseVBlkRWStream
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~HeaderVBlkRWStream();					// 0x4074A0 (Scalar Deleting: 0, 1)
		// virtual int  GetPosition();
		// virtual int  SetPosition(int position);
		// virtual int  F1();								// **
		// virtual int  FlushFileBuffers();
		// virtual int  Write(int bufferSize, char* buffer);
		// virtual int  Read(int bufferSize, char* buffer);
		virtual void Close();								// 0x407720

		// Constructor/Destructor
		HeaderVBlkRWStream();								// 0x407470
		~HeaderVBlkRWStream();								// 0x407570

		// Member functions
		int OpenRead(StreamIO* containerStream, DWORD tag);	// 0x407620 [Verifies source tag matches parameter]
		int OpenRead(StreamIO* containerStream);			// 0x4076B0

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4CF598]
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
