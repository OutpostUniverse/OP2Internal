

#ifndef Unit_H
#define Unit_H


namespace OP2ForcedExport
{

	class UnitTypeInfo;
	class Viewport;


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
		int b1;							// 0x28 **
		short unitTypeInstanceNum;		// 0x2C
		short reloadTimer;				// 0x2E
		int b2;							// 0x30 **
		int* b3;						// 0x34 ** WaypointStruct?
		int b4;							// 0x38 **
		int actionTimer;				// 0x3C
		int animationAndFrameIndex;		// 0x40
		int flags;						// 0x44 
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

	class Vehicle : public PlayerUnit
	{
	public:
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void DrawDock(Viewport* viewport);	// 0x78 **  [** See Note Above **]
		virtual void Pathfind(int a1, int a2, int a3, int a4);	// 0x7C **
		virtual int GetChasisAnimationIndex(int rotationIndex);	// 0x80
		virtual void F5(int a1, int a2, int a3);	// 0x84 **
		virtual void F6();							// 0x88 **  [DoDock?]
		virtual void F7();							// 0x8C **
		virtual int CanMove(int tileX, int tileY);	// 0x90 int bCanMove  [Check celltype against track type, and if units can be bumped out of the way]
		// ----

	public:
		// Member variables
		// ----
		// vtbl
		// ...
	};

	class CargoTruck : public Vehicle
	{
	public:
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void SetCargo(Truck_Cargo truckCargo, int cargoAmountOrTechID, short a2);	// 0x94 **
		virtual void F9();							// 0x98 **
		// ----
	};

	class Building : public PlayerUnit
	{
	public:
		// Member functions
		// ----  [Overridden base class functions]
		virtual void ProcessTimers();
		virtual int CheckExplode();
		// ...
		virtual void Draw(Viewport* viewport);
		// ...
		virtual void MarkBackgroundRectToRedraw(Viewport* viewport);
		virtual int IsSightRangeVisible(Viewport* viewport);
		// ...
		virtual int GetAnimationIndex();
		virtual void GetSelectionBoxSize(int* width, int* height);
		virtual void GetSelectionBoxPos(int* xOffset, int* yOffset);
		virtual int MouseOver(int xOffset, int yOffset);				// Relative to bounding box
		// ...
		virtual ~Building();						// Destructor(int flags)
		virtual void DoEvent();						// Meteor impact, Dock damage, etc.
		// ...
		virtual void SetEMP(short empTime);
		// ...
		virtual void TransferUnit(int destPlayerNum);
		virtual void GetLocation(int a1, int a2, int* tileX, int* tileY);
		// ...
		// ----  [New virtual functions]
		virtual void DrawDock(Viewport* viewport);	// 0x78 **  [** See Note Above **]
		virtual void F5(Viewport* viewport);		// 0x7C **
		virtual void DoExplode(int bExplode);		// 0x80
		virtual void SetDisabled();					// 0x84
		virtual void SetEnabled();					// 0x88
		virtual void SetOwnerRecalculateValues();	// 0x8C
		virtual int GetSpecialAnimationIndex(int type);	// 0x90
		virtual void DoAmbientAnimation();			// 0x94
		virtual int GetAnimationFrame();			// 0x98
		virtual void F6(int a1, int a2);			// 0x9C **
		virtual int IsEnabled();					// 0xA0
		virtual int IsActivePowerGenerator();		// 0xA4
		virtual void SetDisabledWorkers();			// 0xA8
		virtual void SetEnabledWorkers();			// 0xAC
		virtual void SetDisabledScientists();		// 0xB0
		virtual void SetEnabledScientists();		// 0xB4
		virtual void SetEnabledPower();				// 0xB8
		virtual void SetDisabledPower();			// 0xBC
		virtual void F7();							// 0xC0 **  [:Lab.ClearResearch()]
		virtual void F8();							// 0xC4 **  [DoAmbientAnimation?]
		virtual int GetNumAnimationFrames();		// 0xC8
		virtual int GetF9();						// 0xCC **
		virtual int GetPowerProduction();			// 0xD0
		virtual int F10();							// 0xD4 **
		virtual int GetFoodProduction();			// 0xD8
		virtual int F11();							// 0xDC **
		virtual int GetNumScientistsRequired();		// 0xE0 [Includes scientists assigned to research at a lab]
		virtual int GetNumScientistsResearching();	// 0xE4 [Includes only scientists assigned to research at a lab]
		virtual int GetNumWorkersRequired();		// 0xE8
		virtual int GetNumScientistsRequired2();	// 0xEC **  [Return 0]?
		virtual int GetPowerRequiredAndEnable();	// 0xF0
		virtual int GetNumWorkersRequiredAndEnable();	// 0xF4
		virtual int GetNumScientistsRequiredAndEnable();	// 0xF8 Scientists required + Scientists researching
		// ----

	public:
		// Member variables
		// ----
		// vtbl
		// ...
	};

	class Weapon : public PlayerUnit
	{
		// ----  [Overridden base class functions]
		// ... **TODO**
		// ----  [New virtual functions]
		virtual void DrawDock(Viewport* viewport);	// 0x78 **  [** See Note Above **]
		virtual void F5(int a1, int a2);			// 0x7C **
		virtual void DoExplode(Unit* source);		// 0x80
		virtual void F6(int a1);					// 0x84 **
		virtual void DoDamage();					// 0x88
		virtual int GetAnimationIndex();			// 0x8C
		virtual int GetNumAnimationFrames();		// 0x90
		virtual void SetWeaponSource(int weaponSourceUnitIndex);	// 0x94
		// ----
	};

}	// End namespace


#endif
