

#ifndef FileRWStream_H
#define FileRWStream_H


#include "..\StreamIO.h"
#include "..\..\..\WinTypes.h"


namespace OP2ForcedExport
{

	// Min Size: 0x14
	// Max Size: 0x14
	class FileRWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~FileRWStream();							// 0x4B0D10 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4B0EE0
		virtual int  SetPosition(int position);				// 0x4B0F00
		virtual int  F1();									// 0x4B0DC0 **
		virtual int  FlushFileBuffers();					// 0x4B0F80
		virtual int  Write(int bufferSize, char* buffer);	// 0x4B1010
		virtual int  Read(int bufferSize, char* buffer);	// 0x4B1070
		virtual void Close();								// 0x4B0E40

		// Constructor/Destructor
		FileRWStream();										// 0x4B0CE0
		FileRWStream(HANDLE hFile);							// 0x4B0D30
		FileRWStream(char* fileName);						// 0x4B0D70
		~FileRWStream();									// 0x4B0DA0

		// Member functions
		void SetOpenFileHandle(HANDLE hFile);				// 0x4B0E00
		int  OpenFile(char* fileName);						// 0x4B0E80 BSuccess
		int  GetFileSize();									// 0x4B0F50
		int  TranslateLastError();							// 0x4B0F90 Return 0

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D76BC]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		HANDLE hFile;				// 0xC	OS file handle
		int bOwnsFile;				// 0x10 Will close the OS file handle on Close (set to True in FileOpen, and the corresponding Constructor)
		// ----
	};

}	// End namespace


#endif
