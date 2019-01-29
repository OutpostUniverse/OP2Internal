

#ifndef IWndTFrameDans_RULE_UIFrame_H
#define IWndTFrameDans_RULE_UIFrame_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "IWndTFrame.h"
#include "IWndPaneDetail.h"
#include "IWndPaneMiniMap.h"
#include "IWndPaneCommand.h"


namespace OP2Internal
{

	struct IniSettings
	{
		int scrollRate;
		int zoom;
		int bShowAmbientAnimations;
		int bShowComputerOverlay;
		int bShowShadows;
		int bShowStationaryShadows;
		int bShowMobileShadows;
		int bShowCompletedObjectives;
		int b1;					// **
		int frameSkip;
		// -----------
		// Font
	};


	// Address: 0x5756C0
	// Base class min size: 0x14
	// Size: 
	class Dans_RULE_UIFrame : public TFrame
	{
	public:
		// Virtual member functions (IWnd)
		// -------------------------------
		virtual char const * RegisterClassA(void);
		virtual ~Dans_RULE_UIFrame();
		// virtual void Destroy();
		// virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,HWND,HMENU,void*,HINSTANCE);
		virtual long WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual int CallFilters(UINT uMsg, WPARAM wParam, LPARAM lParam);
		// Virtual member functions (TFrame)
		// ---------------------------------
		virtual void ShutDown();
		// Note: Insert 5 virtual members here
		virtual void TFrame_F1(UIState*);
		virtual void TFrame_F2(unsigned int controlId);
		virtual void TranslateAccelerators(MSG* msg);
		virtual void Init();
		virtual void Initialize();
		// Note: End extra 5 virtual members
		virtual void Activate();
		virtual void Deactivate();
		virtual void OnIdle();
		virtual void PreCreateDlg();
		virtual void PostCreateDlg();

	public:
		// Member variables
		// ---------------------------
		// vtbl								// 0x0
		// bool bNotWindowOwner;			// 0x4
		// HWND hWnd;						// 0x8
		// FilterNode* linkedListHead;		// 0xC
		// FilterNode* linkedListTail;		// 0x10
		// ---------------------------
		HFONT hLargeFont;					// 0x14
		char largeMessage[80];				// 0x18
		int largeMessageLength;				// 0x68
		COLORREF textColor;					// 0x6C
		Rect textRect;						// 0x70
		int b1[5];							// 0x80 **
		int textY;							// 0x94
		int b2[2];							// 0x98 **
		int displayedCommonOre;				// 0xA0
		int displayedRareOre;				// 0xA4
		int b3[2];							// 0xA8 **
		LARGE_INTEGER performanceFrequency;	// 0xB0 [/1000]
		int milliSecOfLastProcessingLoop;	// 0xB8 [Set just after time guarded entry in Dans_RULE_UIFrame.OnIdle()]
		int desiredMilliSecPerGameTick;		// 0xBC [-1] [(1000 / gameSpeed4X) - 1]
		int milliSecPerGameTick;			// 0xC0 [-1] [(1000 / gameSpeed4X) - 1, adjusted due to lag]
		int estimatedPacketLag;				// 0xC4 [currentDiff + history * 0.6]
		int milliSecOfLastNetExchange;		// 0xC8 
		int numNetExchanges;				// 0xCC [Since last SetGameSpeed]
		LARGE_INTEGER performanceCount[16];	// 0xD0 ** [Set at end of Dans_RULE_UIFrame.OnIdle()]
		int performanceCountIndex;			// 0x150 **
		int b5;								// 0x154 **
		LARGE_INTEGER performanceCount2[16];// 0x158 ** [Set after TethysGame.ProcessGameCycle()]
		int performanceCountIndex2;			// 0x1D8 **
		int b8;								// 0x1DC **
		int gamePausedCount;				// 0x1E0
		HDC hBackgroundDC;					// 0x1E4
		HACCEL hViewAccel;					// 0x1E8
		HACCEL hUnitAccel;					// 0x1EC
		HACCEL hPauseAccel;					// 0x1F0
		// -----
		DetailPane detailPane;				// 0x1F4
		MiniMapPane miniMapPane;			// 0x344
		CommandPane commandPane;			// 0x658
		// -----
		int b9[0x2C];						// 0xAF0 ** StatusBar
		// -----
		IniSettings settings;				// 0xBA0
		// Font
		// ...
	};


	// Globals
	extern Dans_RULE_UIFrame dansFrame;	// 0x5756C0

}	// End namespace


#endif
