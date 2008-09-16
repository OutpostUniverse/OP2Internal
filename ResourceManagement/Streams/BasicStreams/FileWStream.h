

#ifndef FileWStream_H
#define FileWStream_H


#include "..\StreamIO.h"
#include "..\..\..\WinTypes.h"


namespace OP2ForcedExport
{

	// Min Size: 
	// Max Size: 0x15
	class FileWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~FileWStream();							// 0x4AB9C0 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4ABB90
		virtual int  SetPosition(int position);				// 0x4ABBB0
		virtual int  F1();									// 0x4ABA70 **
		virtual int  FlushFileBuffers();					// 0x4ABC30
		virtual int  Write(int bufferSize, char* buffer);	// 0x4ABCC0
		virtual int  Read(int bufferSize, char* buffer);	// 0x4ABD20
		virtual void Close();								// 0x4ABAF0

		// Constructor/Destructor
		FileWStream();										// 0x4AB990
		FileWStream(HANDLE hFile);							// 0x4AB9E0
		FileWStream(char* fileName);						// 0x4ABA20
		~FileWStream();										// 0x4ABA50

		// Member functions
		void SetOpenFileHandle(HANDLE hFile);				// 0x4ABAB0
		int OpenFile(char* fileName);						// 0x4ABB30 BSuccess
		int GetFileSize();									// 0x4ABC00
		int TranslateLastError();							// 0x4ABC40 Return 0

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D754C]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		HANDLE hFile;				// 0xC	OS file handle
		int bOwnsFile;				// 0x10 Will close the OS file handle on Close (set to True in FileOpen, and the corresponding Constructor)
		char b1;					// 0x14 [Unused]
		// ----
	};

}	// End namespace


#endif
