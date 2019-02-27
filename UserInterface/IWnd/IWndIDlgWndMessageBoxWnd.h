

#pragma once


#include "IWndIDlgWnd.h"


namespace OP2Internal
{

	class MsgBoxWnd : public IDlgWnd
	{
	public:
		// Virtual member functions
		virtual ~MsgBoxWnd();													// 0x00497DA0 (scalar deleting destructor)
		virtual int DoModal(const char*, HINSTANCE);
		virtual int DoModeless(const char*, HINSTANCE, HWND);
		virtual int DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);			// 0x00498230

		// Non virtual member functions
		// Constructors
		MsgBoxWnd();															// 0x00497DC0
		MsgBoxWnd(int titleIndex, const char* message, int buttonTextIndex);	// 0x00497E20
		MsgBoxWnd(int titleIndex, int messageIndex, int buttonTextIndex);		// 0x00497EC0
		// Destructor (non virtual member)										// 0x00497D10

	public:
		// Member variables
		// ----------------
		// vtbl
		// bool bNotWindowOwner;
		// HWND hWnd;
		// FilterNode* linkedListHead;
		// FilterNode* linkedListTail;
		// ----------------
		// ...
	};

}	// End namespace
