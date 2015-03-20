

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
		int lastAttackedTick;			// 0x28 (Valid when (gameTick - lastAttackedTick) < 30)
		short unitTypeInstanceNum;		// 0x2C
		short reloadTimer;				// 0x2E
		char groupScStubIndex;			// 0x30 (Set when added to a group)
		char groupUnitNodeIndex;		// 0x31 (Set when added to a group)
		char b1;						// 0x32 **
		char b2;						// 0x33 **
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

}	// End namespace


#endif
