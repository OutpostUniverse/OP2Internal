

#ifndef LZHRStream_H
#define LZHRStream_H


#include "..\StreamIO.h"


namespace OP2Internal
{

	class AdaptiveHuffmanTree;


	// Min Size: 0x2C
	// Max Size: 0x2C
	class LZHRStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~LZHRStream();							// 0x433EC0 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4343E0
		virtual int  SetPosition(int position);				// 0x434170
		virtual int  F1();									// 0x434130 **
		virtual int  FlushFileBuffers();					// 0x4343D0
		virtual int  Write(int bufferSize, char* buffer);	// 0x4343F0
		virtual int  Read(int bufferSize, char* buffer);	// 0x434280
		virtual void Close();								// 0x434110

		// Constructor/Destructor
		LZHRStream();										// 0x433E60
		LZHRStream(StreamIO* wrappedStream);				// 0x433F30
		~LZHRStream();										// 0x434020

		// Member functions
		void AllocateResources();							// 0x433FE0
		void AttachToStream(StreamIO* wrappedStream);		// 0x434080
		void DetachStream();								// 0x4340F0

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D0410]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC
		AdaptiveHuffmanTree* adaptHuffTree;	// 0x10
		char* circularBuffer;				// 0x14 char[4096+59]*
		int matchIndex;						// 0x18
		int numCharsInRun;					// 0x1C
		int numCharsCopied;					// 0x20
		int writeIndex;						// 0x24
		int streamPosition;					// 0x28
		// ----
	};

}	// End namespace


#endif
