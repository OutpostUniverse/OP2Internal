

#pragma once


namespace OP2Internal
{

	class Vehicle;


	// BaseAddress: 0x551340
	class PathFinder
	{
	public:
		bool __fastcall (a0*)(int tileX, int tileY);			// 0x00 (Function pointer)
		int __fastcall (a1*)(int startTileX, int startTileY);	// 0x04 (Function pointer)
		Vehicle* pathFindingUnit;	// 0x08
		int startTileX;		// 0x0C
		int startTileY;		// 0x10
		int destTileX;		// 0x14
		int destTileY;		// 0x18
		int distance;		// 0x1C (rangeTileX^2 + rangeTileY^2) (squared distance)
		int rangeTileX;		// 0x20
		int rangeTileY;		// 0x24
		// ...
	};

}	// End namespace
