

#ifndef VolFileRStream_H
#define VolFileRStream_H


#include "..\StreamIOBaseVolFileStream.h"
#include "..\BasicStreams\FileRStream.h"


namespace OP2ForcedExport
{

	// Min Size: 0x980  [Field access and contained object size]
	// Max Size: 0x980  [New size]
	class VolFileRStream : public BaseVolFileStream
	{
	public:
		// [StreamIO] Virtual member functions
		// virtual int  GetStatus();
		// virtual ~VolFileRStream();						// 0x4A0990 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4A1320
		virtual int  SetPosition(int position);				// 0x4A1330
		virtual int  F1();									// 0x4A1300 **
		// virtual int  FlushFileBuffers();
		virtual int  Write(int bufferSize, char* buffer);	// 0x4A1350
		virtual int  Read(int bufferSize, char* buffer);	// 0x4A1360
		virtual void Close();								// 0x4A12E0

		// [BaseVolFileStream] Virtual member functions
		virtual void OpenStream(DWORD identifier);			// 0x4A18D0 **
		virtual void OpenStream(char* fileName);			// 0x4A1830 **
		virtual void GetDataLength(DWORD identifier);		// 0x4A16D0 **
		virtual void GetDataLength(char* fileName);			// 0x4A1590 **

		// Constructor/Destructor
		VolFileRStream();									// 0x4A0960
		~VolFileRStream();									// 0x4A0A40

		// Member functions
		int OpenVolFile(char* volFile);						// 0x4A0AE0 BSuccess
		int F2();											// 0x4A0E90 **
		int F7OpenStream(VolIndexEntry* file);				// 0x4A0F20 BSuccess
		int F6OpenStream(char* fileName);					// 0x4A0FD0 BSuccess
		int F3(int a1);										// 0x4A10C0 ** BSuccess
		int F4(int a1);										// 0x4A1120 ** BSuccess
		int F5(int a1);										// 0x4A11E0 ** BSuccess

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D6B20]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		// int numIndexEntries;				// 0xC
		// VolIndexEntry* indexTable;		// 0x10 VolIndexEntry[]*
		// void* fileNameBuffer;			// 0x14 ["vols" section]
		// void* mappedAddress;				// 0x18 [memory mapped file]
		// HANDLE hFileMapping;				// 0x1C 
		// HANDLE hFile;					// 0x20 
		// DWORD fileSize;					// 0x24 [VOL file size of -1]
		// StreamIO* openedInternalStream;	// 0x28
		// MemRWStream memRWStream;			// 0x2C
		// VBlkRWStream vBlkRWStream;		// 0x44
		// RLERStream rleRStream;			// 0x64
		// LZHRStream lzhRStream;			// 0xFC
		// LZRStream lzRStream;				// 0x128
		// int bSetFileSize;				// 0x158 ** [Inits fileSize on open]
		// ----
		char* b1;							// 0x15C **
		FileRStream fileStream;				// 0x160 **
		// ----
	};

}	// End namespace


#endif
