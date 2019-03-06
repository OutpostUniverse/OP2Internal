#pragma once


namespace OP2Internal
{

	class Unit;
	class StreamIO;
	enum class map_id : short;


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


	struct VehicleInfo
	{
		int moveSpeed;			// 0x24
		int turnRate;			// 0x28
		int productionRate;		// 0x2C
		int reloadTime;			// 0x30 **
		// 0x34 **
		// 0x38 **
	};
	struct BuildingInfo
	{
		int powerRequired;		// 0x24
		int workersRequired;	// 0x28
		int scientistsRequired;	// 0x2C
		int storageCapacity;	// 0x30
		int productionCapacity;	// 0x34
		int storageBays;		// 0x38
	};
	struct WeaponInfo
	{
		int moveSpeed;			// 0x24 **
		int concussionDamage;	// 0x28
		int penetrationDamage;	// 0x2C
		int reloadTime;			// 0x30
		// 0x34 **
		// 0x38 **
	};
	struct PlayerUnitInfo
	{
	#pragma pack(push, 1)
		struct
		{
			int hitPoints;						// 0x0
			int b1;								// 0x4 **
			int armor;							// 0x8 **
			int commonOreCost;					// 0xC
			int rareOreCost;					// 0x10
			int buildTime;						// 0x14		// buildPoints
			int sightRange;						// 0x18
			unsigned char numUnitsOfType;		// 0x1C **
			int bImproved;						// 0x1D
			char padding[3];					// 0x20 **
		};
	#pragma pack(pop)
		// ----
		union
		{
			VehicleInfo vehicleInfo;		// 0x24
			BuildingInfo buildingInfo;		// 0x24
			WeaponInfo weaponInfo;			// 0x24
		};
		int completedUpgradeTechNumList[2];	// 0x3C
	};


	class UnitTypeInfo
	{
	public:
		// Virtual member functions
		virtual Unit* CreateUnit(int pixelX, int pixelY, int unitIndex);	// 0x0
		virtual char* GetUnitPropTag();				// 0x4 char* internalUnitName
		virtual int  Save(StreamIO* savedGameFile);	// 0x8 BSuccess
		virtual int  Load(StreamIO* savedGameFile);	// 0xC BSuccess
		virtual int  Initialize();					// 0x10 BSuccess
		virtual void Process(Unit* chasisUnit);		// 0x14
		virtual Unit* FindTarget(Unit* chassisUnit, int desiredFlags);	// 0x18
		// ----

	public:
		// Member variables
		// ----
		// vtbl								// 0x0
		map_id unitType;					// 0x4  (Note: This field is padded to 4 bytes for alignment of next field)
		PlayerUnitInfo playerInfo[7];		// 0x8
		int requiredTechIndex;				// 0x1E4
		int trackType;						// 0x1E8
		// ...?
		// 0x1F0
		// 0x1F4
	};


	// Globals
	extern UnitTypeInfo* unitTypeInfo[0x73];		// 0x4E1348  [0x73 = mapUnitLast = mapGeneralUnit]

}	// End namespace
