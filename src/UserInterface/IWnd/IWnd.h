#pragma once

#include "../Filter/EnumFilterPosition.h"
#include "../Filter/EnumFilterOption.h"
#include "../../WinTypes.h"


namespace OP2Internal
{

	class FilterNode;


	// Size: 0x14
	class IWnd
	{
	private:
		virtual char const * RegisterClassA(void);
	public:
		// Virtual member functions
		virtual ~IWnd();
		virtual void Destroy();
		virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,HWND,HMENU,void*,HINSTANCE);
		virtual long WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual int CallFilters(UINT uMsg, WPARAM wParam, LPARAM lParam);

		// Member functions
		IWnd(class IWnd const &);
		IWnd();
		class IWnd & operator=(class IWnd const &);
		class FilterNode * FindNode(class Filter *,int);
		void InstallFilter(class Filter*, int userData, FilterPosition filterPosition, FilterOption filterOptions);
		void RemoveFilter(class Filter*, int userData);

		// Static functions
		static class IWnd * __fastcall FromHWND(HWND hWnd);
		static long __stdcall IWndCbtFilterHook(int,unsigned int,long);
		static long __stdcall _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:	// Why not? =)
		// Member variables
		// ----------------
		// vtbl						// 0x0
		bool bNotWindowOwner;		// 0x4
		HWND hWnd;					// 0x8
		FilterNode* linkedListHead;	// 0xC
		FilterNode* linkedListTail;	// 0x10
		// ----------------
	};

}	// End namespace
