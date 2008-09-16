

#ifndef StreamIO_H
#define StreamIO_H


namespace OP2ForcedExport
{

	// Min Size: 0xC
	// Max Size: 0xC
	class StreamIO
	{
	public:
		// Virtual member functions
		virtual int  GetStatus();							// 0x4077C0
		virtual ~StreamIO();								// 0x4AB340 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4AB3B0
		virtual int  SetPosition(int position);				// 0x4AB3C0
		virtual int  F1();									// 0x4AB370 **
		virtual int  FlushFileBuffers();					// 0x4AB3D0 Return 1
		virtual int  Write(int bufferSize, char* buffer);	// 0x4AB3E0 BSuccess
		virtual int  Read(int bufferSize, char* buffer);	// 0x4AB3F0 BSuccess
		virtual void Close();								// 0x4AB3A0

	public:
		// Member variables
		// ----
		// vtbl							// 0x0 [0x4D74FC]
		int numBytesReadOrWritten;		// 0x4 Most recent Read/Write
		int streamStatus;				// 0x8 [0 = OK, other = errorCode]
		// ----
	};

}	// End namespace


#endif
