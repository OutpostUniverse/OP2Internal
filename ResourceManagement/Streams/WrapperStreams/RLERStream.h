

#ifndef RLERStream_H
#define RLERStream_H


#include "..\StreamIO.h"


namespace OP2Internal
{

	// Min Size: 0x96
	// Max Size: 0x98
	class RLERStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~RLERStream();							// 0x4AFAC0 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4AFBD0
		virtual int  SetPosition(int position);				// 0x4AFBF0
		virtual int  F1();									// 0x4AFB90 **
		virtual int  FlushFileBuffers();					// 0x4AFC90
		virtual int  Write(int bufferSize, char* buffer);	// 0x4AFCA0
		virtual int  Read(int bufferSize, char* buffer);	// 0x4AFCB0
		virtual void Close();								// 0x4AFB80

		// Cosntructor/Destructor
		RLERStream();										// 0x4AFAA0
		RLERStream(StreamIO* wrappedStream);				// 0x4AFAE0

		// Member functions
		void Initialize();									// 0x4AFB10
		void AttachToStream(StreamIO* wrappedStream);		// 0x4AFB30
		void DetachStream();								// 0x4AFB60

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D761C]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* wrappedStream;			// 0xC
		char charToRepeat;					// 0x10 
		char numTimesToRepeat;				// 0x11 
		char chunkSize;						// 0x12 Raw data copy size
		// ... **
		int streamPosition;					// 0x92
		short padding;						// 0x96 ** padding?
	};

}	// End namespace


#endif
