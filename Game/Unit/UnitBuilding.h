#pragma once


#include "Unit.h"


namespace OP2Internal
{

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

}	// End namespace
