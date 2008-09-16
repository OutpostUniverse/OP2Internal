

#ifndef UnitTypeInfo_H
#define UnitTypeInfo_H


namespace OP2ForcedExport
{

	class Unit;
	class StreamIO;
	enum map_id;


	enum BuildingAnimationTypeIndex
	{
		AnimationTypeConstruction	= 0,
		AnimationTypeDamagedLight	= 1,
		AnimationTypeDamagedHeavy	= 2,
		AnimationTypeDestruction	= 3,
		AnimationTypeIcon			= 4,
		AnimationTypeNormal			= 5, // ** Ambient?
		AnimationTypeAmbient1		= 6, // **
		AnimationTypeAmbient2		= 7, // **
		// = 8,
		// = 9,
		// ----
	};


	class UnitTypeInfo
	{
	public:
		// Virtual member functions
		virtual Unit* CreateUnit(int pixelX, int pixelY, int unitIndex);	// 0x0
		virtual char* GetUnitPropTag();				// 0x4 
		virtual int Save(StreamIO* savedGameFile);	// 0x8 BSuccess
		virtual int Load(StreamIO* savedGameFile);	// 0xC BSuccess
		virtual int Initialize();					// 0x10 BSuccess **
		virtual void F1(Unit* chasisUnit);			// 0x14 **
		virtual int F2(int a1, int a2);				// 0x18 **

	public:
		// Member variables
		// ----
		// vtbl								// 0x0
		map_id unitType;					// 0x4
	};


	class VehicleUnitTypeInfo : public UnitTypeInfo
	{
	public:
		int b1[145];						// **
		int edenAnimationIndex[16];			// [directionIndex]
		int b2[48];							// **
		int plymouthAnimationIndex[16];		// [directionIndex]
	};


	class BuildingUnitTypeInfo : public UnitTypeInfo
	{
	public:
		// Member variables
		int b1[119];						// **
		int requiredTechIndex;				// 0x1E4
		int b2[24];							// **
		short tileWidth;					// 0x248
		short tileHeight;					// 0x24A
		int initialFlags;					// 0x24C
		int edenAnimationIndex[10];			// 0x250 [BuildingAnimationTypeIndex]
		int plymouthAnimationIndex[10];		// 0x278 [BuildingAnimationTypeIndex]
		// ...?
	};


	// Globals
	extern UnitTypeInfo* unitTypeInfo[0x73];		// 0x4E1348  [0x73 = mapUnitLast = mapGeneralUnit]

}	// End namespace


#endif
