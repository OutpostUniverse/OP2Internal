#pragma once


#include "FilterSubFilter.h"
#include "EnumBehaviorType.h"
#include "../../PointTypes.h"


namespace OP2Internal
{
	class BoolState;
	class Pane;


	class MouseCommandFilter : public SubFilter
	{
	public:
		// Virtual member functions
		virtual int OnUIEvent(IWnd* wnd, UINT uMsg, WPARAM wParam, LPARAM lParam, int userData);
		virtual void F1();
		virtual void ClearMouseCommand();
		virtual int GetControlBoolState(int controlId);
		virtual int GetControlState(BoolState* controlState);
		virtual void DoMouseOverEvents();
		virtual void OnUnitSelectionChange(int userData, int reason);
		virtual HCURSOR GetMouseCursor();
		virtual int F4();
		virtual void DrawSelectionBoxesAndMouseOverText(Pane* pane);
		// ...?

		// Member functions
		void SetMouseCommand(BehaviorType behaviorType, MouseCommand* mouseCommand, int maxNumWaypoints, int a3, int a4);	// 0x41B670
		void SetOverlaySize(int pixelX, int pixelY);	// 0x41B6D0
		void GetHighlightRect(Rect* highlightRect);		// 0x41B6F0

	public:
		// Member variables
		// ----------
		// vtbl
		// ----------
		union						// **TODO** Make sure this does what I mean
		{
			struct
			{
				Point mapMousePos;			// 0x04 
				int overlayPixelWidth;		// 0x0C 
				int overlayPixelHeight;		// 0x10 
			};
			Rect pixelRegion;				// 0x04
		};
		int mouseOverUnitIndex;		// 0x14  Set when the mouse hovers over a unit, and none are selected
		int mouseOverTick;			// 0x18  Set when the mouse hovers over a unit, and none are selected
		int b1;						// 0x1C **
		int b2;						// 0x20 **
		BehaviorType behaviorType;	// 0x24     [param1]
		IWnd* captureWnd;			// 0x28 
		MouseCommand* command;		// 0x2C     [param2] 
		int b4;						// 0x30 **  [param4] 
		int maxNumWaypoints;		// 0x34     [param3]
		int b6;						// 0x38 **  [param5] 
		int b7;						// 0x3C **  
		// ...?
	};


	extern MouseCommandFilter mouseCommandFilter;		// 0x5471B0


	// SetMouseCommand
	// 3, 7, 0, 1	Move, StandGround, DestroyTubeOrWall, Guard, Repair, Reprogram, Dismantle
	// 2, 7, 0, 1	Build, BuildGeoPlantOrMine
	// 4, 0, 0, 1	BuildWalld
	// 3, ?, 0, 1	Attack, PatrolSetFinalPoint
	// 1, 0, 0, 1	Bulldoze, Salvage
	// 3, 1, 0, 1	SalvageSetRouteToGorf, Launch
	// 3, 5, 0, 1	SetOreRouteToMine
	// 3, ?, 0, ?	SetOreRouteToSmelter/BackToMine
	// 3, 6, 0, 1	PatrolSetInitialPoint
	// 3, ?, 1, 1	MoveButton
	// 0, 0, 1, 1	(LaunchDest), (CPV[Building]/[Vehicle].OnRemoveView), (???), (OnUnitSelectionChange), (CPV[StorageBay]/[TrainScientists].OnSetupDisplay), (CPVReport[Factory]/[Resources].???), (CPVReport[GameOptions]/[Communications]/[NetStats]/[BuildList]/[VehicleList]/[Lab]/[ResearchList]/[Satellite].OnAddView)

}	// End namespace
