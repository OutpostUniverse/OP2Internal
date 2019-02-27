

#pragma once


namespace OP2Internal
{

	class StreamIO;


	// Min Size: 0x16
	// Max Size: 0x16  [New sizes of both 0x16 and 0x18]
	class AdaptiveHuffmanTree
	{
	public:
		// Constructor/Destructor
		AdaptiveHuffmanTree();		// 0x4ABD30
		~AdaptiveHuffmanTree();		// 0x4ABD70

		// Member functions
		void Initialize(StreamIO* internalStream);		// 0x4ABDA0
		void WriteCodeToOutput(int code);				// 0x4ABE80
		void WriteFixedHuffmanCodeToOutput(int code);	// 0x4ABED0
		int  GetNextCode();								// 0x4ABF10
		int  GetOffsetToMatchStart();					// 0x4ABF60
		void FlushWriteBuffer();						// 0x4ABFC0
		int  GetNextBit();								// 0x4AC000
		int  GetNext8Bits();							// 0x4AC070
		void Write(char numBits, short wordBitBuffer);	// 0x4AC0E0
		void F1();										// 0x4AC170 **
		void UpdateTree(int code);						// 0x4AC2C0

	public:
		// Member variables			// **TODO** Verify packing/alignment
		StreamIO* internalStream;	// 0x0	
		short* count;				// 0x4	short[]*
		short* b2;					// 0x8	short[]*
		short* tree;				// 0xC	short[]*
		short readWordBitBuffer;	// 0x10	Read
		char numBitsAvailable;		// 0x12	Read
		short writeWordBitBuffer;	// 0x13	Write
		char numBitsPending;		// 0x15	Write
	};

}	// End namespace
