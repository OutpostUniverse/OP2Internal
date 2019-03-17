#pragma once


// ** Note: This file needs a lot of work


#include "../PointTypes.h"


namespace OP2Internal
{

	class Bitmap;

	// Size: 20
	struct ImageInfo
	{
		int pitch;
		int dataOffset;
		int height;
		int width;
		int typeAndPaletteIndex;
		//short typeFlags;		// 
		//short paletteIndex;
	};

	// Size: 6
	struct FrameComponentInfo
	{
		short offsetX;
		short offsetY;
		short imageInfoIndex;
	};

	// Size: 14
	struct FrameInfo
	{
		Rect frameRect;			// [.left = 0x7FFE = Auto compute bounding rect, 0x7FFF = Never compute bounding rect]
		short numFrameComponents;
		FrameComponentInfo* frameComponentInfo;		// Pointer to array of FrameComponentInfo
	};

	// Size: 4
	struct FrameOptionalInfo
	{
		int offsetX:8;
		int offsetY:8;
		int offsetX2:8;			// **
		int offsetY2:8;			// **
	};

	// Size: 112
	struct AnimationInfo
	{
		int b1;								// 0x00 **
		Rect selectionBox;					// 0x04
		int displacementX;					// 0x14
		int displacementY;					// 0x18
		int b2;								// 0x1C **
		int numFrames;						// 0x20
		FrameInfo* frameData;				// 0x24 Pointer to array of FrameData  [ordered in master list]
		short frameOptionalInfoStartIndex;	// 0x28
		// ...
	};


	// Address: 0x004EFD68
	// Size: 
	class PrtGraphics
	{
	public:
		// Member functions

	public:
		// Member variables
		char* palData;							// 0x04 ** Maybe?
		int palSize;							// 0x08 ** Maybe?
		ImageInfo imageInfo[5608];				// 0x0C
		int numImages;
		AnimationInfo animationInfo[2176];
		int numAnimations;
		Bitmap* bitmap;
		FrameInfo* frameInfo;
		FrameComponentInfo* frameComponentInfo;
		FrameOptionalInfo* frameOptionalInfo;
	};

}	// End namespace
