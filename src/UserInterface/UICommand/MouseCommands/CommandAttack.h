#pragma once


#include "../UICommandMouseCommand.h"


namespace OP2Internal
{

	class CommandAttack : public MouseCommand
	{
	public:
		// [UICommand] virtual member functions
		virtual int IsEnabled(DWORD param);					// 0x4530B0
		virtual int Execute(DWORD param);					// 0x4531F0
		virtual void GetButtonDisplayInfo(ButtonDisplayInfo* buttonDisplayInfo, int a1);	// 0x453160
		// [MouseCommand] virtual member functions
		virtual void OnClick();								// 0x453250
		virtual int GetMouseCursor(int pixelX, int pixelY, HCURSOR* mouseCursor);	// 0x453480
		// virtual int GetBuildCursor(int startPixelX, int startPixelY, int endPixelX, int endPixelY, HCURSOR* mouseCursor, int highLight[], Vehicle* constructionVehicle);	// 0x455C70
		// virtual void OnCancel();							// 0x4512B0
		// virtual void OnChangeCommand();					// 0x4512D0
		virtual int F1(int pixelX, int pixelY);				// 0x453510 **
		virtual HCURSOR GetCursor(int pixelX, int pixelY);	// 0x4533B0

		// New virtual member functions
		virtual int F2(int pixelX, int pixelY, int* a1);	// 0x4533D0 **

		// Constructor/Destructor
		// CommandAttack() {};					// 0x4533C0 [Static: 0x56560C]

	public:
		// Member variables
		// ----
		// vtbl			// 0x4D4C98
		// ----
		// ----
		// ...?
	};


	// Globals
	extern CommandAttack commandAttack;		// 0x56560C

}	// End namespace
