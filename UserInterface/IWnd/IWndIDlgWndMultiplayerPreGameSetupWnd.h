

#ifndef IWndIDlgWndMultiplayerPreGameSetupWnd_H
#define IWndIDlgWndMultiplayerPreGameSetupWnd_H


#include "IWndIDlgWnd.h"
#include "..\..\Game\GameStartInfo\GameStartInfo.h"


namespace OP2ForcedExport
{

	struct HostGameParameters
	{
		StartupFlags startupFlags;
		int unused1;				// **
		int unused2;				// **
		char gameCreatorName[13];
	};


	struct PlayerControls
	{
		HWND hPlayerNameTextBoxWnd;
		HWND hColorComboBoxWnd;
		HWND hColonyCheckBoxWnd;		// [0 = Plymouth, 1 = Eden]
		HWND hResourceComboBoxWnd;
		HWND hReadyCheckBoxWnd;
		HWND hEjectButtonWnd;
	};


	class MultiplayerPreGameSetupWnd : public IDlgWnd
	{
	public:
		// Virtual member functions
		virtual ~MultiplayerPreGameSetupWnd() {};												// 0x0045F080
		virtual int DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);							// 0x00460BC0

		// Non virtual member functions
		MultiplayerPreGameSetupWnd();															// 0x0045F050
		bool ShowHostGame(HostGameParameters* hostGameParameters);								// 0x0045F0D0
		bool ShowJoinGame(char* playerName, int hostPlayerNetID, bool bPurgedDroppedPlayers);	// 0x0045F2F0

	public:
		// Member variables
		// ----------------
		// vtbl
		// bool bNotWindowOwner;
		// HWND hWnd;
		// FilterNode* linkedListHead;
		// FilterNode* linkedListTail;
		// ----------------
		// IDlgWnd* prev;
		// IDlgWnd* next;
		// int flags;
		// ----------------
		UINT timerId;
		HWND hEnterChatTextBoxWnd;
		WNDPROC lpPrevWndFunc;
		HWND hMessageTextBoxWnd;
		HWND hLevelComboBoxWnd;
		HWND hStartGameButtonWnd;
		PlayerControls playerControls[6];
		GameStartInfo gameStartInfo;
		short padding;						// **
		int b1[3];							// **
		int bPurgeDroppedPlayers;
		int bNeedRedraw;
		int bGameStarting;
		int time;							// **
		int hostPlayerNetID;
		int missionType1;					// **
		int missionType2;					// ** 
		// ----------------
	};

}	// End namespace


#endif
