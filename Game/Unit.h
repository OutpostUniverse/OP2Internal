

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
		virtual UnitTypeInfo* GetUnitTypeInfo();
		virtual void ProcessForGameCycle();
		virtual void ProcessTimers();
		virtual int CheckExplode();
		virtual int FireWeapon();
		virtual void GetTurretAnimationIndex(Unit* chasisUnit, int rotationIndex);
		virtual void Draw(Viewport* viewport);
		virtual void LightUpVisibleRange(Viewport* viewport);
		virtual void MarkBackgroundRectToRedraw(Viewport* viewport);
		virtual int IsSightRangeVisible(Viewport* viewport);
		virtual int IsSightRangeVisibleY(Viewport* viewport);
		virtual int GetAnimationIndex();
		virtual void GetSelectionBoxSize(int* width, int* height);
		virtual void GetSelectionBoxPos(int* xOffset, int* yOffset);
		virtual int MouseOver(int xOffset, int yOffset);				// Relative to bounding box
		virtual void GetRolloverText(char* destBuffer, int bufferSize);
		virtual int GetSelectedUnitDisplayString(char* destBuffer, int bufferSize);		// Returns string length
		virtual int IsMouseCursorOverSelectionBox(int pixelX, int pixelY);
		virtual int F2();					// ** [Return 2]
		virtual ~Unit();					// Destructor(int flags)  [Scalar-deleting: 0]
		virtual void DoEvent();				// Meteor impact, Dock damage, etc.
		virtual void OnLoadTranslateData();	// Translate unit saved game format into memory format (also called when saving to untranslate after writing the file)
		virtual void OnSaveTranslateData();	// Translate unit memory format into saved game format
		virtual void SetEMP(short empTime);
		virtual void SetSticky(int stickyTime);
		virtual void Move();
		virtual void TransferUnit(int destPlayerNum);
		virtual void GetLocation(int tileX1, int tileY1, int* tileX2, int* tileY2);
		virtual int F3(int a1, int a2);		// ** BSuccess?  [Used by SCAT]
		virtual int IsLive();
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
		virtual ~Building();					// Destructor(int flags)
		virtual void DoEvent();					// Meteor impact, Dock damage, etc.
		// ...
		virtual void SetEMP(short empTime);
		// ...
		virtual void TransferUnit(int destPlayerNum);
		virtual void GetLocation(int a1, int a2, int* tileX, int* tileY);
		// ...
		// ----  [New virtual functions]
		virtual void F4(Viewport* viewport);	// **  [** See Note Above **]
		virtual void F5(Viewport* viewport);	// **
		virtual void DoExplode(int bExplode);
		virtual void SetDisabled();
		virtual void SetEnabled();
		virtual void SetOwnerRecalculateValues();
		virtual int GetSpecialAnimationIndex(int type);
		virtual void DoAmbientAnimation();
		virtual int GetAnimationFrame();
		virtual void F6(int a1, int a2);		// **
		virtual int IsEnabled();
		virtual int IsActivePowerGenerator();
		virtual void SetDisabledWorkers();
		virtual void SetEnabledWorkers();
		virtual void SetDisabledScientists();
		virtual void SetEnabledScientists();
		virtual void SetEnabledPower();
		virtual void SetDisabledPower();
		virtual void F7();						// **
		virtual void F8();						// **
		virtual int GetNumAnimationFrames();
		virtual int GetF9();					// **
		virtual int GetPowerProduction();
		virtual int F10();						// **
		virtual int GetFoodProduction();
		virtual int F11();						// **
		virtual int GetNumScientistsRequired1();// **
		virtual int F12();						// **
		virtual int GetNumWorkersRequired();
		virtual int GetNumScientistsRequired2();// **
		virtual int GetPowerRequired();
		virtual int GetNumWorkersRequiredAndEnable();
		virtual int GetNumScientistsRequiredAndEnable();
		// ----

	public:
		// Member variables
		// ----
		// vtbl
		// ...
	};

}	// End namespace


#endif
