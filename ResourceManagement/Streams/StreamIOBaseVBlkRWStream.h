

#ifndef StreamIOBaseVBlkRWStream_H
#define StreamIOBaseVBlkRWStream_H


#include "StreamIO.h"


namespace OP2Internal
{

	struct VBlkHeader
	{
		unsigned int tag;			// 'VBLK'
		unsigned int size:31;		// Size, including header
		unsigned int alignment:1;	// 0 = 16 bit, 1 = 32 bit
	};


	// Min Size: 0x20
	// Max Size: 0x20
	class BaseVBlkRWStream : public StreamIO
	{
	public:
		// Virtual member functions
		// virtual int  GetStatus();
		// virtual ~BaseVBlkRWStream();						// 0x406E50 (Scalar Deleting: 0, 1)
		virtual int  GetPosition();							// 0x406EB0
		virtual int  SetPosition(int position);				// 0x406ED0
		virtual int  F1();									// 0x406E90 **
		virtual int  FlushFileBuffers();					// 0x406F60
		virtual int  Write(int bufferSize, char* buffer);	// 0x406FA0
		virtual int  Read(int bufferSize, char* buffer);	// 0x407080
		virtual void Close();								// 0x4AB3A0 [Return]

		// Constructor/Destructor
		BaseVBlkRWStream();									// 0x406E20
		~BaseVBlkRWStream();								// 0x406E80

	public:
		// Member variables
		// ----
		// vtbl								// 0x0 [0x4CF548]
		// int numBytesReadOrWritten;		// 0x4
		// int streamStatus;				// 0x8
		// ----
		StreamIO* containerStream;			// 0xC  Vol file image
		VBlkHeader header;					// 0x10
		int positionOffset;					// 0x18 Offset within vol file  [Current stream position]
		int startOffset;					// 0x1C Offset within vol file  [Offset of header, data is at +8]
		// ----
	};

}	// End namespace


#endif
