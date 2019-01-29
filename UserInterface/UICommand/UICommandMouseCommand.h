

#ifndef UICommandMouseCommand_H
#define UICommandMouseCommand_H


#include "UICommand.h"
#include "..\..\WinTypes.h"


namespace OP2Internal
{

	class Vehicle;


	class MouseCommand : public UICommand
	{
	public:
		// Virtual member functions (inherited)
		virtual int  IsEnabled(DWORD param)	= 0;
		virtual int  Execute(DWORD param)	= 0;
		virtual void GetButtonDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int a1) = 0;

		// Virtual member functions
		virtual void OnClick();									// 0x455C50 Left-Click Detail Pane event
		virtual int  GetMouseCursor(int pixelX, int pixelY, HCURSOR* mouseCursor);	// 0x455C60
		virtual int  GetBuildCursor(int startPixelX, int startPixelY, int endPixelX, int endPixelY, HCURSOR* mouseCursor, int highLight[], Vehicle* constructionVehicle);	// 0x455C70
		virtual void OnCancel();								// 0x4512B0 Right-click or ESC event
		virtual void OnChangeCommand();							// 0x4512D0
		virtual int  IsDefaultCommand(int pixelX, int pixelY);	// 0x455C80
		virtual HCURSOR GetCursor(int pixelX, int pixelY);		// 0x455C90

	public:
		// Member variables
		// ----
		// vtbl
		// ----
		// ----
	};


	// Globals
	extern HCURSOR mouseCursorTable[35];				// 0x56EA08
	extern char* mouseCursorResIDOrStringTable[35];		// 0x4E9878 union{ WORD resID, LPCTSTR fileName }[35]

	// ** Finish filling in
	enum CursorTypeIndex
	{
		// -- System cursors --
		CursorIndexWait = 0,			// Standard Windows Hourglass cursor
		CursorIndexCross = 1,			// Standard Windows Crosshair cursor
		CursorIndexNormal = 2,			// Standard Windows Arrow cursor

		// -- Out2Res.dll or ".ani" file cursors --
		CursorIndexDestruct = 3,		// File "destruct.ani"
		//CursorIndexNoDestruct? = 4,	// Out2Res.dll: 0xCC
		CursorIndexMove = 5,			// File "move.ani"
		CursorIndexNoMove = 6,			// File "no_move.ani"
		CursorIndexAttack = 7,			// File "attack.ani"
		CursorIndexNoAttack = 8,		// File "noattack.ani"
		CursorIndexBulldoze = 9,		// File "bulldoze.ani"
		CursorIndexNoBulldoze = 10,		// Out2Res.dll: 0xCC
		CursorIndexBuild = 11,			// File "build.ani"
		CursorIndexNoBuild = 12,		// File "nobuild.ani"
		CursorIndexDock = 13,			// File "dock.ani"
		CursorIndexNoDock = 14,			// File "nodock.ani"
		CursorIndexRepair = 15,			// File "repair.ani"
		CursorIndexNoRepair = 16,		// File "norepair.ani"
		CursorIndexReprog = 17,			// File "reprog.ani"
		CursorIndexNoReprog = 18,		// File "no_repro.ani"
		CursorIndexGuard = 19,			// File "guard.ani"
		//CursorIndexNoGuard? = 20,		// Out2Res.dll: 0xCC
		//CursorIndex = 21,				// Out2Res.dll: 0xB0
		//CursorIndex = 22,				// Out2Res.dll: 0xCC
		CursorIndexSalvage = 23,		// File "salvage.ani"
		//CursorIndexNoSalvage = 24,	// Out2Res.dll: 0xCC
		CursorIndexWaypoint = 25,		// File "waypoint.ani"
		CursorIndexNoWaypoint = 26,		// Out2Res.dll: 0xCC
		//CursorIndex = 27,				// Out2Res.dll: 0x71
		//CursorIndex = 28,				// Out2Res.dll: 0x6F
		//CursorIndex = 29,				// Out2Res.dll: 0x75
		//CursorIndex = 30,				// Out2Res.dll: 0x6D
		//CursorIndex = 31,				// Out2Res.dll: 0x73
		//CursorIndex = 32,				// Out2Res.dll: 0x6E
		//CursorIndex = 33,				// Out2Res.dll: 0x70
		//CursorIndex = 34,				// Out2Res.dll: 0x74
	};

}	// End namespace


#endif
