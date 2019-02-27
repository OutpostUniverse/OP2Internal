

#pragma once


namespace OP2Internal
{

	class UnitTypeInfo;
	class Viewport;

	struct UnitFlags {
		unsigned int lightsOn:1;					// 0x00 0x00000001
		unsigned int isVehicle:1;					// 0x01 0x00000002
		unsigned int isBuilding:1;					// 0x02 0x00000004
		unsigned int _3:1;							// 0x03 0x00000008 **
		unsigned int isOffensive:1;					// 0x04 0x00000010 (1 = show attack/patrol buttons, 0 = no buttons)
		unsigned int doubleFireRate:1;				// 0x05 0x00000020 (Dual turret)
		unsigned int _6:1;							// 0x06 0x00000040 (If 0 and !isVehicle, does "moDelSelf" on "ctMoDeath")
		unsigned int damageIncrease:1;				// 0x07 0x00000080 (150% damage for guard posts connected by tubes to a Command Center)
		unsigned int canExplode:1;					// 0x08 0x00000100 ** ?
		unsigned int _9:1;							// 0x09 0x00000200 **
		unsigned int _10:1;							// 0x0A 0x00000400 **
		unsigned int _11:1;							// 0x0B 0x00000800 **
		unsigned int isEden:1;						// 0x0C 0x00001000 (Used to display correct chasis for combat vehicles)
		unsigned int enabledPower:1;				// 0x0D 0x00002000 ** (DisasterDetected)
		unsigned int enabledWorkers:1;				// 0x0E 0x00004000 ** (DisasterNoFirstWarn)
		unsigned int enabledScientists:1;			// 0x0F 0x00008000 ** (DisasterNoSecondWarn)
		unsigned int _16:1;							// 0x10 0x00010000 ** (DoAftershock) [Earthquake]
		unsigned int isDead:1;						// 0x11 0x00020000 (Used by IsLive)
		unsigned int isStickyfoamed:1;				// 0x12 0x00040000 ** (Building: isInfected)
		unsigned int isEMPed:1;						// 0x13 0x00080000
		unsigned int isESGed:1;						// 0x14 0x00100000
		unsigned int _21:1;							// 0x15 0x00200000 **
		unsigned int preventExplosion:1;			// 0x16 0x00400000 (Prevents EMP blasts and harmful explosions upon building death)
		unsigned int oppFiredUpon:1;				// 0x17 0x00800000 (Allows opponent units to auto target this building)
		unsigned int isUndocking:1;					// 0x18 0x01000000 (Convec/CargoTruck? being moved up out of storage bay after pickup/dropoff)
		unsigned int hasSpecialTarget:1;			// 0x19 0x02000000 (CreateSpecialTarget, ClearSpecialTarget)
		unsigned int _26:1;							// 0x1A 0x04000000 **
		unsigned int forceFullLightVisibility:1;	// 0x1B 0x08000000 **
		unsigned int isInvisible:1;					// 0x1C 0x10000000 (for disasters (and buildings)) (before they appear they exist)
		unsigned int noAutoTarget:1;				// 0x1D 0x20000000 ** (HasSpecialTarget?)
		unsigned int _30:1;							// 0x1E 0x40000000 **
		unsigned int _31:1;							// 0x1F 0x80000000 **
	};

	// Size: 0x54
	class Unit
	{
	public:
		virtual UnitTypeInfo* GetUnitTypeInfo();	// 0x0
		virtual void ProcessForGameCycle();			// 0x4
		virtual void ProcessTimers();				// 0x8
		virtual int  CheckExplode();				// 0xC
		virtual int  FireWeapon();					// 0x10
		virtual void GetTurretAnimationIndex(Unit* chasisUnit, int rotationIndex);	// 0x14
		virtual void Draw(Viewport* viewport);		// 0x18
		virtual void LightUpVisibleRange(Viewport* viewport);			// 0x1C
		virtual void MarkBackgroundRectToRedraw(Viewport* viewport);	// 0x20
		virtual int  IsSightRangeVisible(Viewport* viewport);			// 0x24
		virtual int  IsSightRangeVisibleY(Viewport* viewport);			// 0x28
		virtual int  GetAnimationIndex();			// 0x2C
		virtual void GetSelectionBoxSize(int* width, int* height);		// 0x30
		virtual void GetSelectionBoxPos(int* xOffset, int* yOffset);	// 0x34
		virtual int  MouseOver(int xOffset, int yOffset);				// 0x38 Relative to bounding box
		virtual void GetRolloverText(char* destBuffer, int bufferSize);	// 0x3C
		virtual int  GetSelectedUnitDisplayString(char* destBuffer, int bufferSize);	// 0x40 Returns string length
		virtual int  IsMouseCursorOverSelectionBox(int pixelX, int pixelY);	// 0x44
		virtual int  F2();							// 0x48 ** [Return 2]
		virtual ~Unit();							// 0x4C Destructor(int flags)  [Scalar-deleting: 0]
		virtual void DoEvent();						// 0x50 Meteor impact, Dock damage, etc.
		virtual void OnLoad();						// 0x54 Translate unit saved game format into memory format (also called when saving to untranslate after writing the file)
		virtual void OnSave();						// 0x58 Translate unit memory format into saved game format
		virtual void SetEMP(short empTime);			// 0x5C
		virtual void SetSticky(int stickyTime);		// 0x60
		virtual void Move();						// 0x64
		virtual void TransferUnit(int destPlayerNum);	// 0x68
		virtual void GetLocation(int tileX1, int tileY1, int* tileX2, int* tileY2);	// 0x6C
		virtual int  F3(int a1, int a2);			// 0x70 ** BSuccess?  [Used by SCAT]
		virtual int  IsEnabled();					// 0x74 False if dead, EMPed, or moObjFroze
		// ----

	public:
		// Member variables
		// ----------------
		// vtbl							// 0x0  
		Unit* next;						// 0x4  -1 = IsDead
		Unit* prev;						// 0x8  
		Unit* playerNext;				// 0xC  
		int unitIndex;					// 0x10 
		int pixelX;						// 0x14 
		int pixelY;						// 0x18 
		char rotation;					// 0x1C 
		char creatorAndOwnerNum;		// 0x1D 
		short damage;					// 0x1E 
		char bBusy;						// 0x20 
		char command;					// 0x21 
		char action;					// 0x22 
		char executingAction;			// 0x23 
		short cargo;					// 0x24 [enum map_id]
		short attackingUnitIndex;		// 0x26 
		int lastAttackedTick;			// 0x28 (Valid when (gameTick - lastAttackedTick) < 30)
		short unitTypeInstanceNum;		// 0x2C
		short reloadTimer;				// 0x2E
		char groupScStubIndex;			// 0x30 (Set when added to a group)
		char groupUnitNodeIndex;		// 0x31 (Set when added to a group)
		char b1;						// 0x32 **
		char b2;						// 0x33 **
		int* b3;						// 0x34 ** WaypointStruct?
		int b4;							// 0x38 ** nextWaypoint?
		int actionTimer;				// 0x3C
		int animationAndFrameIndex;		// 0x40
		UnitFlags flags;				// 0x44 
		int b5[3];						// 0x48 **
		// ----
	};



	class PlayerUnit : public Unit
	{
	public:
		// Member functions
		// ----  [Overridden base class functions]
		virtual ~PlayerUnit();				// Destructor(int flags)
		// ----  [New virtual functions]  [None]
		// ----

	public:
		// Member variables
		// ----
		// vtbl
		// ...
		// ----
		// ...
	};


	// ** Note ** : There seems to be a missing class between PlayerUnit and Building or Vehicle,
	// which is a common base class to both. This observation is based on shared functions in the
	// virtual function tables of both buildings and vehicles, beyond what is accounted for by
	// the PlayerUnit virtual function table entries. There is exactly one virtual function added
	// in the missing class.

}	// End namespace
