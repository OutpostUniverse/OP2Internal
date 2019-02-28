#pragma once


#include "IWnd.h"


namespace OP2Internal
{

	// Size: 0x20
	class IDlgWnd : public IWnd
	{
	private:
		void InsertHWNDChain();
		void RemoveHWNDChain();

		static int __stdcall _DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		static int nModelessCount;
		static IDlgWnd* pFirst;
	public:
		// Virtual member functions
		virtual ~IDlgWnd();
		virtual int DoModal(const char*, HINSTANCE);
		virtual int DoModeless(const char*, HINSTANCE, HWND);
		virtual int DlgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

		// Non virtual member functions
		IDlgWnd(const IDlgWnd&);
		IDlgWnd();
		IDlgWnd& operator=(const IDlgWnd&);
		int IsModalParentSet() const;
		void SetAsModalParent(int);

		static IDlgWnd* __fastcall DlgFromHWND(HWND);
		static HWND __fastcall GetModalParent();
		static int __fastcall PretranslateModeless(struct tagMSG*);

	public:
		// Member variables
		// ----------------
		// vtbl
		// bool bNotWindowOwner;
		// HWND hWnd;
		// FilterNode* linkedListHead;
		// FilterNode* linkedListTail;
		// ----------------
		IDlgWnd* prev;
		IDlgWnd* next;
		int flags;
		// ----------------
	};


	// Global functions
	int __fastcall MsgBox(HWND hOwnerWnd, const char* message, const char* title, int flags);	// 0x0041E0E0

}	// End namespace
