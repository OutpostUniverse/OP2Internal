#pragma once


#include "../StreamIO.h"


namespace OP2Internal
{

	// Min Size: 
	// Max Size: 0x98
	class RLEWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~RLEWStream();							// 0x4B0830 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4B0960
		virtual int  SetPosition(int position);				// 0x4B0980
		virtual int  F1();									// 0x4B0920 **
		virtual int  FlushFileBuffers();					// 0x4B09B0
		virtual int  Write(int bufferSize, char* buffer);	// 0x4B0B00
		virtual int  Read(int bufferSize, char* buffer);	// 0x4B0CD0
		virtual void Close();								// 0x4B0910

		// Cosntructor/Destructor
		RLEWStream();										// 0x4B0810
		RLEWStream(StreamIO* wrappedStream);				// 0x4B0850
		~RLEWStream();										// 0x4B0880

		// Member functions
		void Initialize();									// 0x4B08A0
		void AttachToStream(StreamIO* wrappedStream);		// 0x4B08C0
		void DetachStream();								// 0x4B08F0

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D7694]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC
		char chatToRepeat;					// 0x10 ** ?
		char numTimesToRepeat;				// 0x11 ** ?
		char chunkSize;						// 0x12 ** ?
		char b1[1];							// 0x13 **
		// ... **
		int streamPosition;					// 0x92
		short padding;						// 0x96 ** padding?
	};

}	// End namespace
