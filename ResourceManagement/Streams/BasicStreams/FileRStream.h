#pragma once


#include "../StreamIO.h"
#include "../../../WinTypes.h"


namespace OP2Internal
{

	// Min Size: 0x820
	// Max Size: 0x820
	class FileRStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~FileRStream();							// 0x4AB440 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4AB640
		virtual int  SetPosition(int position);				// 0x4AB670
		virtual int  F1();									// 0x4AB510 **
		virtual int  FlushFileBuffers();					// 0x4AB730
		virtual int  Write(int bufferSize, char* buffer);	// 0x4AB7C0
		virtual int  Read(int bufferSize, char* buffer);	// 0x4AB7D0
		virtual void Close();								// 0x4AB590

		// Constructor/Destructor
		FileRStream();										// 0x4AB400
		FileRStream(HANDLE hFile);							// 0x4AB460
		FileRStream(char* fileName);						// 0x4AB4B0
		~FileRStream();										// 0x4AB4F0

		// Member functions
		void SetOpenFileHandle(HANDLE hFile);				// 0x4AB550
		int OpenFile(char* fileName);						// 0x4AB5E0 BSuccess
		int GetFileSize();									// 0x4AB700
		int TranslateLastError();							// 0x4AB740 Return 0  [Translates GetLastError to a StreamIO status code and stores it]
		int ReadNextChunk(int position);					// 0x4AB8E0 BSuccess  [Reads a 2048 byte chunk from the file into a buffer]

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D7524]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		char buffer[2048];					// 0xC
		int positionOfLastReadChunkStart;	// 0x80C
		int positionOfLastReadChunkEnd;		// 0x810
		int streamPosition;					// 0x814
		HANDLE hFile;						// 0x818 OS file handle
		int bOwnsFile;						// 0x81C Will close the OS file handle on Close (set to True in FileOpen, and the corresponding Constructor)
		// ----
	};

}	// End namespace
