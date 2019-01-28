

#ifndef VolFileWStream_H
#define VolFileWStream_H


#include "..\StreamIOBaseVolFileStream.h"


namespace OP2Internal
{

	class VolFileWStream : public BaseVolFileStream
	{
	public:
		// [StreamIO] Virtual member functions
		// virtual int  GetStatus();
		// virtual ~VolFileWStream();						// 0x49F550 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x4A08C0
		virtual int  SetPosition(int position);				// 0x4A08D0
		virtual int  F1();									// 0x4A08A0 **
		virtual int  FlushFileBuffers();					// 0x4A08F0
		virtual int  Write(int bufferSize, char* buffer);	// 0x4A0900
		virtual int  Read(int bufferSize, char* buffer);	// 0x4A0930
		virtual void Close();								// 0x4A07C0

		// [BaseVolFileStream] Virtual member functions
		virtual void OpenStream(DWORD identifier);			// 0x4A1520 **
		virtual void OpenStream(char* fileName);			// 0x4A14A0 **
		// virtual void GetDataLength(DWORD identifier);
		// virtual void GetDataLength(char* fileName);

		// Constructor/Destructor
		VolFileWStream();									// 0x49F4F0
		~VolFileWStream();									// 0x49F5B0

		// Member functions
		int F2(int a1, int a2, int a3);						// 0x49F600 **
		int F3(int a1, int a2, int a3);						// 0x49F930 **
		int F4(int a1);										// 0x49FAF0 **
		int F5();											// 0x49FDF0 **
		void F6(int a1);									// 0x4A0030 **
		void F7(int a1);									// 0x4A00D0 **
		int F8();											// 0x4A0160 **
		void F9();											// 0x4A01B0 **
		int F10(int a1, int a2, int a3);					// 0x4A01D0 **
		int F11(int a1, int a2, int a3);					// 0x4A03A0 **
		int F12(int a1, int a2, int a3);					// 0x4A0620 **
		int F13(VolIndexEntry* indexEntry);					// 0x4A06F0 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D6AE8]
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
		// int bSetFileSize;				// 0x158 ** [Sets file size]
		// ----
		int unused;							// 0x15C ** unused? [base classe member?]
		int b3;								// 0x160 **
		int b4;								// 0x164 **
		int b2;								// 0x168 **
		FileRWStream fileRWStream;			// 0x16C
		RLEWStream rleWStream;				// 0x180
		LZHWStream lzhWStream;				// 0x218
		LZWStream lzWStream;				// 0x260
		// ...?
	};

}	// End namespace


#endif
