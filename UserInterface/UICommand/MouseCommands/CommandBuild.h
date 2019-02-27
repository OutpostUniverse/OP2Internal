

#pragma once


#include "../UICommandMouseCommand.h"


namespace OP2Internal
{

	class CommandBuild : public MouseCommand
	{
	public:
		// Base class virtual member functions
		virtual int IsEnabled(DWORD param);						// 0x451B40
		virtual int Execute(DWORD param);						// 0x451BE0
		virtual void GetButtonDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int a1);	// 0x451BA0

		// Virtual member functions
		virtual void OnClick();									// 0x451C50
		virtual int GetMouseCursor(int pixelX, int pixelY, HCURSOR* mouseCursor);			// 0x451D50
		virtual int GetBuildCursor(int startPixelX, int startPixelY, int endPixelX, int endPixelY, HCURSOR* mouseCursor, int highLight[], Vehicle* constructionVehicle);	// 0x451DC0
		// virtual void OnCancel();								// 0x4512B0
		// virtual void OnChangeCommand();						// 0x4512D0
		// virtual int F1(int pixelX, int pixelY);				// 0x455C80 **
		// virtual HCURSOR GetCursor(int pixelX, int pixelY);	// 0x455C90

		// Constructor/Destructor
		// CommandBuild() {};					// 0x451B30 [Static: 0x5655B4]

	public:
		// Member variables
		// ----
		// vtbl			// 0x4D4B50
		// ----
		// ----
		// ...?
	};


	// Globals
	extern CommandBuild commandBuild;		// 0x5655B4

}	// End namespace
