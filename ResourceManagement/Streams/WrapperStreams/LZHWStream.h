

#ifndef LZHWStream_H
#define LZHWStream_H


#include "../StreamIO.h"


namespace OP2Internal
{

	class AdaptiveHuffmanTree;


	// Min Size: 0x48
	// Max Size: 0x48
	class LZHWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~LZHWStream();							// 0x4B00B0 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4B07D0
		virtual int  SetPosition(int position);				// 0x4B07E0
		virtual int  F1();									// 0x4B0270 **
		virtual int  FlushFileBuffers();					// 0x4B06A0
		virtual int  Write(int bufferSize, char* buffer);	// 0x4B0540
		virtual int  Read(int bufferSize, char* buffer);	// 0x4B0800
		virtual void Close();								// 0x4B0260

		// Constructor/Destructor
		LZHWStream();										// 0x4B0090
		LZHWStream(StreamIO* wrappedStream);				// 0x4B00D0
		~LZHWStream();										// 0x4B0100

		// Member functions
		void AllocateResources();							// 0x4B0160
		void AttachToStream(StreamIO* wrappedStream);		// 0x4B01D0
		void DetachStream();								// 0x4B0240
		void FindLongestRun(int a1);						// 0x4B02B0 **
		void F1(int a1);									// 0x4B0450 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D766C]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC 
		AdaptiveHuffmanTree* adaptHuffTree;	// 0x10 
		int b5;								// 0x14 ** int ? index
		int writeIndex;						// 0x18 **
		int b7;								// 0x1C **
		int b8;								// 0x20 **
		int b9;								// 0x24 **
		int b10;							// 0x28 **
		int runOffset;						// 0x2C
		int runLength;						// 0x30
		int streamPosition;					// 0x34
		int* circularBuffer;				// 0x38 char[4096 + 59]*
		int* b2;							// 0x3C ** char[8192 + 2]*
		int* b3;							// 0x40 ** char[8192 + 512 + 2]*
		int* b4;							// 0x44 ** char[8192 + 2]*
		// ----
	};

}	// End namespace


#endif
