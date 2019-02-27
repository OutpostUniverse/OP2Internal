

#pragma once


#include "../StreamIO.h"


namespace OP2Internal
{

	// Min Size: 0x28
	// Max Size: 0x28
	class LZWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~LZWStream();							// 0x4349E0 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4352B0
		virtual int  SetPosition(int position);				// 0x4352C0
		virtual int  F1();									// 0x434BB0 **
		virtual int  FlushFileBuffers();					// 0x435240
		virtual int  Write(int bufferSize, char* buffer);	// 0x434BF0
		virtual int  Read(int bufferSize, char* buffer);	// 0x4352E0
		virtual void Close();								// 0x434B90

		// Constructor/Destructor
		LZWStream();										// 0x434990
		LZWStream(StreamIO* wrappedStream);					// 0x434A40
		~LZWStream();										// 0x434AB0

		// Member functions
		void AllocateResources();							// 0x434B00
		void AttachToStream(StreamIO* wrappedStream);		// 0x434B40
		void DetachStream();								// 0x434B70
		void F1(int a1);									// 0x434E70 **
		void WriteBits(int bitBuffer, int numBitsToWrite);	// 0x434EB0
		void F2(int a1, int a2);							// 0x434F80 **
		void F3(int a1, int a2);							// 0x434FD0 **
		void F4(int a1);									// 0x435050 **
		void F5(int a1);									// 0x435090 **
		int  F6(int a1);									// 0x435160 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D0460]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC
		int streamPosition;					// 0x10
		int* b2;							// 0x14 ** char[4096]* buffer
		int* b3;							// 0x18 ** char[4096*12 + 12]* buffer
		int b7;								// 0x1C **
		int b6;								// 0x20 **
		char b4;							// 0x24 **
		char padding;						// 0x25 ** padding?
		short b5;							// 0x26 **
		// ----
	};

}	// End namespace
