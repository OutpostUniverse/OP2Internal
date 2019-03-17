#pragma once


#include <winuser.h>
#include "../WinTypes.h"


namespace OP2Internal
{

	class TFrame;
	class GurManager;
	class TLobby;
	class NetTransportLayer;
	class DirectDrawWnd;
	struct IDirectDraw;


	class TApp
	{
	public:
		// Member functions
		void NetShutdown(int bSendQuitMessage);		// 0x00487E30

	public:
		// Member variables
		HINSTANCE hInstance;			// 0x0
		HINSTANCE hOut2ResLib;			// 0x4
		int nCmdShow;					// 0x8
		int bShowShell;					// 0xC
		char* savedGameName;			// 0x10
		int b1;							// 0x14 ** [/cmdlog, /playback]
		int bPlayback;					// 0x18    [/cmdlog, /playback]
		int b2;							// 0x1C ** [/cmdlog, /playback]
		char* netProtocolName;			// 0x20 [TCP = "winsock", SIGS = "sigs", Modem = "dplay_modem", IPX = "dplay_ipx"]  [Note: Serial = "dplay_Serial" is exluded]
		MSG msg;						// 0x24
			// msg.hWnd					//  0x24
			// msg.uMsg					//  0x28
			// msg.wParam				//  0x2C
			// msg.lParam				//  0x30
			// msg.time					//  0x34
			// msg.pt.x					//  0x38
			// msg.pt.y					//  0x3C
		HHOOK hHelpHook;				// 0x40
		TFrame* mainWnd;				// 0x44
		HINSTANCE hShellLib;			// 0x48
		HWND hShellWnd;					// 0x4C
		GurManager* gurManager;			// 0x50
		TLobby* lobby;					// 0x54
		NetTransportLayer* netTLayer;	// 0x58
		char string[260];				// 0x5C ** [MAX_PATH length?]
		int cursorWaitCount;			// 0x160
		HCURSOR hOldCursor;				// 0x164 [BeginWaitCursor()/EndWaitCursor()]
		int b4;							// 0x168 **  [(DrawScanline8Pal16MMX*)(BitmapCopyInfo* bitmapCopyInfo)]
		int bGameInitialized;			// 0x16C
		int bIsDrawing;					// 0x170
		int fActive;					// 0x174 [BOOL]
		int bPaused;					// 0x178 [bRunning?]
		DWORD lpDirectDrawCreate;		// 0x17C
		IDirectDraw* lpDD;				// 0x180
		HINSTANCE hDDrawLib;			// 0x184
		DirectDrawWnd* directDrawWnd;	// 0x188

		// HCURSOR ???	// 0x56EA08
	};


	extern TApp app;			// 0x0056E868

}	// End namespace
