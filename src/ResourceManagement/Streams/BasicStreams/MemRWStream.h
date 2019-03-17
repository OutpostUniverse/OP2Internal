#pragma once


#include "../StreamIO.h"


namespace OP2Internal
{

	// Min Size: 0x18
	// Max Size: 0x18
	class MemRWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~MemRWStream();							// 0x4AFE30 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4AFF40
		virtual int  SetPosition(int position);				// 0x4AFF50
		virtual int  F1();									// 0x4AFF00 **
		virtual int  FlushFileBuffers();					// 0x4AFFA0
		virtual int  Write(int bufferSize, char* buffer);	// 0x4AFFB0
		virtual int  Read(int bufferSize, char* buffer);	// 0x4B0020
		virtual void Close();								// 0x4AFEA0

		// Constructor/Destructor
		MemRWStream();										// 0x4AFE10
		MemRWStream(int size, char* address);				// 0x4AFE50

		// Member functions
		void SetBuffer(int size, char* address);			// 0x4AFE80
		int  F1(int a1);									// 0x4AFEC0 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D7644]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		char* bufferStart;					// 0xC
		char* bufferEnd;					// 0x10
		char* currentPos;					// 0x14
		// ----
	};

}	// End namespace
