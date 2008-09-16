// ** Note: This file needs a lot of work


#ifndef PrtGraphics_H
#define PrtGraphics_H


#include "..\PointTypes.h"


namespace OP2ForcedExport
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
		char offsetX;
		char offsetY;
		char b1;				// **
		char b2;				// **
	};

	// Size: 112
	struct AnimationInfo
	{
		int b1;					// **
		Rect selectionBox;
		int displacementX;
		int displacementY;
		int b2;					// **
		int numFrames;
		FrameInfo* frameData;	// Pointer to array of FrameData  [ordered in master list]
		short frameOptionalInfoStartIndex;
	};


	// Address: 0x004EFD68
	// Size: 
	class PrtGraphics
	{
	public:
		// Member functions

	public:
		// Member variables
		char* palData;			// ** Maybe?
		int palSize;			// ** Maybe?
		ImageInfo imageInfo[5608];
		int numImages;
		AnimationInfo animationInfo[2176];
		int numAnimations;
		Bitmap* bitmap;
		FrameInfo* frameInfo;
		FrameComponentInfo* frameComponentInfo;
		FrameOptionalInfo* frameOptionalInfo;
	};

}	// End namespace


#endif
