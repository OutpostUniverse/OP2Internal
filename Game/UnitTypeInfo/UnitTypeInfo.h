

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

	#pragma pack(push, 1)
	struct PlayerUnitInfo
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
		int moveSpeed;						// 0x24		// Vehicle: moveSpeed			// Building: powerRequired
		int turnRate;						// 0x28		// Vehicle: turnRate			// Building: workersRequired	// Weapon: concussionDamage
		int producationRate;				// 0x2C		// Vehicle: productionRate		// Building: scientistsRequired // Weapon: penetrationDamage
		int reloadTime;						// 0x30		// Building: storageCapacity	// Weapon: reloadTime
		int productionCapacity;				// 0x34		// Building: productionCapacity  (powerProduction)
		int storageBays;					// 0x38
		int completedUpgradeTechNumList[2];	// 0x3C
	};
	/*
	struct	// Vehicle
	{
		int moveSpeed;			// 0x24
		int turnRate;			// 0x28
		int productionRate;		// 0x2C
		int reloadTime;			// 0x30 **
	};
	*/
	/*
	struct	// Building
	{
		int powerRequired;		// 0x24
		int workersRequired;	// 0x28
		int scientistsRequired;	// 0x2C
		int storageCapacity;	// 0x30
		int productionCapacity;	// 0x34
		int storageBays;		// 0x38
	};
	*/
	/*
	struct	// Weapon
	{
		int moveSpeed			// 0x24 **
		int concussionDamage;	// 0x28
		int penetrationDamage;	// 0x2C
		int reloadTime;			// 0x30
	};
	*/
	#pragma pack(pop)


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
		map_id unitType;					// 0x4
		// ...?
		// 0x1F0
		// 0x1F4
	};


	// Globals
	extern UnitTypeInfo* unitTypeInfo[0x73];		// 0x4E1348  [0x73 = mapUnitLast = mapGeneralUnit]

}	// End namespace


#endif
