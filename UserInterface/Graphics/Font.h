

#ifndef Font_H
#define Font_H


#include <windef.h>
#include <wingdi.h>


namespace OP2Internal
{
	
	class GFXSurface;
	struct RenderDataBase;
	struct Point;
	struct Size;
	struct Rect;


	// Min Size: 0x4
	class FontBase
	{
	public:
		// Virtual member functions
		virtual ~FontBase();				// 0x416BE0  (scalar-deleting: 0,1)

	public:
		// Member variables
		// ----
		// vtbl								// 0x4CFBD0
		// ----
	};


	// Min Size: 0x1C60
	class Font : public FontBase
	{
	public:
		// Virtual member functions
		virtual ~Font();					// 0x415CB0  (scalar-deleting: 0,1)
		virtual Size* GetTextSize(Size* size, char* string, int stringLength);	// 0x415F60

		// Constructor/Destructor
		Font();								// 0x415C80
		// ~Font();							// 0x415CF0  (non-virtual destructor)

		// Member functions
		void CreateFont(LOGFONT* logFont);	// 0x415D10
		void DrawString(char* string, int stringLength, GFXSurface* surface, Point* drawPos, Rect* drawRect, COLORREF color);							// 0x4162B0
		void DrawString(char* string, RenderDataBase* renderData, GFXSurface* surface, Point* drawPos, Rect* drawRect, COLORREF color, int vSpacing);	// 0x4161F0
		void DrawString(char* string, RenderDataBase* renderData, GFXSurface* surface, Rect* textRect, Rect* drawRect, int vSpacing);					// 0x416B20
		void ParseString(char* string, int stringLength, int boundingWidth, RenderDataBase* renderData, Size* size);									// 0x416770
		void ParseString(char* string, int stringLength, int boundingWidth, RenderDataBase* renderData, Size* size, int a1);							// 0x415FE0 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x4CFBC8
		// ----
		LOGFONT logFont;					// 0x4  
		int b1;								// 0x40 ** [Gets MemCopied with LOGFONT]
		int tmHeight;						// 0x44 
		int tmAscent;						// 0x48 
		int tmDescent;						// 0x4C 
		int tmInternalLeading;				// 0x50 
		int tmExternalLeading;				// 0x54 
		int tmMaxCharWidth;					// 0x58 MaxCharWidth+1
		GLYPHMETRICS glyphMetrics[256];		// 0x5C ** [See below] **
		char* characterImageBuffer;			// 0x1C5C
		// ----
	};



	struct RenderChunk
	{
		int xOffset;						// 0x0  Pixel offset of this chunk of text
		int stringStart;					// 0x4  Index of first string char in this chunk
		int stringLen;						// 0x8  Length of this chunk in characters
		int bIsEOL;							// 0xC  Is-End-Of-Line, used for text wrapping
		COLORREF color;						// 0x10 Color used to render this chunk of text
	};

	struct RenderDataBase
	{
		int numChunks;						// 0x0 Total allocated RenderChunk space
		int numLines;						// 0x4 
		int numChunksUsed;					// 0x8 Used RenderChunk space
		//RenderChunk renderChunk[1];		// 0xC Describes a section of unbroken text in a single color

		RenderDataBase() { numChunks = 0; };// Convenient initalizer for the struct array size
	};
	// For convenience to make a varible of a specific size
	template <int N>
	struct RenderData : public RenderDataBase
	{
		RenderChunk renderChunk[N];			// 0xC Describes a section of unbroken text in a single color

		RenderData<N>()	{ numChunks = N; };	// Convenient initalizer for the struct array size
	};

	// Globals
	extern Font buttonFont;					// 0x577EE8
	extern Font aFont;						// 0x579B48  ** Find out what this font is for


}	// End Namespace


// LOGFONT
// -------
// 0x0	4	LONG lfHeight; 
// 0x4	4	LONG lfWidth; 
// 0x8	4	LONG lfEscapement; 
// 0xC	4	LONG lfOrientation; 
// 0x10	4	LONG lfWeight; 
// 0x14	4	BYTE lfItalic; 
// 0x18	4	BYTE lfUnderline; 
// 0x1C	4	BYTE lfStrikeOut; 
// 0x20	4	BYTE lfCharSet; 
// 0x24	4	BYTE lfOutPrecision; 
// 0x28	4	BYTE lfClipPrecision; 
// 0x2C	4	BYTE lfQuality; 
// 0x30	4	BYTE lfPitchAndFamily; 
// 0x34	4	TCHAR lfFaceName[LF_FACESIZE]; 	// 32


// GlyphMetrics
// ------------
// Note: Based on GLYPHMETRICS
// Size: 0x1C
// ------------
// 0x0	8	gmptGlyphOrigin
//  0x0	 4	 int x
//  0x4	 4	 int y
// 0x8	4	int gmCellIncX
// 0xC	4	int gmCellIncY
// 0x10	4	int gmBlackBoxX
// 0x14	4	int gmBlackBoxY
// 0x18	4	int bufferIndex	[init: bufferSize return value]
// ------------


#endif
