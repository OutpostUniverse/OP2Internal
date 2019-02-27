#pragma once


#include "../StreamIO.h"


namespace OP2Internal
{

	// Min Size: 0x30
	// Max Size: 0x30? [0x44]
	// Size: 0x30
	class LZRStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~LZRStream();							// 0x434430 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x434970
		virtual int  SetPosition(int position);				// 0x434630
		virtual int  F1();									// 0x4345F0 **
		virtual int  FlushFileBuffers();					// 0x434960
		virtual int  Write(int bufferSize, char* buffer);	// 0x434980
		virtual int  Read(int bufferSize, char* buffer);	// 0x434800
		virtual void Close();								// 0x4345D0

		// Constructor/Destructor
		LZRStream();										// 0x434400
		LZRStream(StreamIO* wrappedStream);					// 0x434480
		~LZRStream();										// 0x434520

		// Member functions
		void AllocateResources();							// 0x434500
		void AttachToStream(StreamIO* wrappedStream);		// 0x434560
		void DetachStream();								// 0x4345B0
		int  GetBits(int numBitsToRead);					// 0x434730

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D0438]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC
		int streamPosition;					// 0x10
		char* buffer;						// 0x14 ** char[4096]*
		int writeIndex;						// 0x18 **
		char currentByte;					// 0x1C **
		char padding;						// 0x1D ** maybe?
		short currentBitMask;				// 0x1E ** [Initially 0x80]
		int numCharsRepeated;				// 0x20 ** [Repeat progress]
		int bRepeating;						// 0x24 ** [Buffer filled during repeat]
		int repeatIndex;					// 0x28 **
		int repeatedRunLength;				// 0x2C **
		// ----
	};

}	// End namespace
