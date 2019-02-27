

#pragma once


#include "StreamIO.h"
#include "BasicStreams/MemRWStream.h"
#include "VBlkStreams/VBlkRWStream.h"
#include "WrapperStreams/RLERStream.h"
#include "WrapperStreams/LZHRStream.h"
#include "WrapperStreams/LZRStream.h"
#include "../../WinTypes.h"


namespace OP2Internal
{

	struct VolIndexEntry
	{
		DWORD fileNameOffset;	// 0x0 Offset in string table
		DWORD dataOffset;		// 0x4 Offset to the data in the VOL file
		DWORD dataLength;		// 0x8 Length of the internal file data
		BYTE compressionCode;	// 0xC Compression used on file data
		BYTE bUsed;				// 0xD Indicates index entry is valid  (not quite bool: tested against 1)  [Unused entries must only occur at the end of the table (binary searched)]
	};

	enum CompressionCode
	{
		CompressionCodeUncompressed = 0,
		CompressionCodeRLE			= 1,
		CompressionCodeLZ			= 2,
		CompressionCodeLZH			= 3,
	};


	// Min Size: 0x15C  [Based on fields accessed by member functions]
	// Max Size: 0x160  [Based on size and fields of derived classes]
	class BaseVolFileStream : public StreamIO
	{
	public:
		// [StreamIO] Virtual member functions
		virtual int  GetStatus();							// 0x4A1390 [Return opened internal stream status]
		// virtual ~BaseVolFileStream();					// 0x49EDC0 (Scalar Deleting: 0, 1)
		// virtual int  GetPosition();
		// virtual int  SetPosition(int position);
		// virtual int  F1();								// **
		// virtual int  FlushFileBuffers();
		// virtual int  Write(int bufferSize, char* buffer);
		// virtual int  Read(int bufferSize, char* buffer);
		virtual void Close() = 0;							// [Pure Call]

		// [New] Virtual member functions
		virtual void OpenStream(DWORD identifier) = 0;		// [Pure Call] ** maybe?
		virtual void OpenStream(char* fileName) = 0;		// [Pure Call] ** maybe?
		virtual void GetDataLength(DWORD identifier);		// 0x4A1440 **
		virtual void GetDataLength(char* fileName);			// 0x4A13B0 **

		// Constructor/Destructor
		BaseVolFileStream();								// 0x49ED60
		~BaseVolFileStream();								// 0x49EDE0

		// Member functions
		int  F2(char* fileName);							// 0x49EEE0 **
		void F3();											// 0x49F030 **
		int  F4(DWORD fileSize);							// 0x49F0B0 **
		void F5();											// 0x49F1C0 **
		int  F6(DWORD identifer);							// 0x49F200 **
		int  F7(char* fileName);							// 0x49F250 **
		int  F8(char* fileName);							// 0x49F2D0 **
		int  F9(DWORD identifier);							// 0x49F370 **
		int  F10(char* fileName);							// 0x49F400 **
		int  F11(DWORD identifier);							// 0x49F490 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4D6AB0]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		int numIndexEntries;				// 0xC
		VolIndexEntry* indexTable;			// 0x10 VolIndexEntry[]*
		void* fileNameBuffer;				// 0x14 ["vols" section]
		void* mappedAddress;				// 0x18 [memory mapped file]
		HANDLE hFileMapping;				// 0x1C 
		HANDLE hFile;						// 0x20 
		DWORD fileSize;						// 0x24 [VOL file size or -1]
		StreamIO* openedInternalStream;		// 0x28
		MemRWStream memRWStream;			// 0x2C [Input Stream]
		VBlkRWStream vBlkRWStream;			// 0x44  [Case 0: Uncompressed]
		RLERStream rleRStream;				// 0x64  [Case 1: RLE]
		LZHRStream lzhRStream;				// 0xFC  [Case 3: LZH]
		LZRStream lzRStream;				// 0x128 [Case 2: LZ]
		int bSetFileSize;					// 0x158 ** [Inits fileSize on open]
		// ----
	};

}	// End namespace
