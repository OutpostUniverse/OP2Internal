

#ifndef IWndTFrame_H
#define IWndTFrame_H


#include "IWnd.h"


namespace OP2ForcedExport
{

	class UIState;


	// Note: The later part of this class should be
	// part of Dans_RULE_UIFrame. The exact point
	// where the two meet is unknown
	class TFrame : public IWnd
	{
		// Base class virtual member functions
		// ----
		// virtual char const * RegisterClassA(void);	// [protected]
		// virtual ~IWnd();
		// virtual void Destroy();
		// virtual int CreateEx(unsigned long,char const *,unsigned long,int,int,int,int,HWND,HMENU,void*,HINSTANCE);
		// virtual long WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
		// virtual int CallFilters(UINT uMsg, WPARAM wParam, LPARAM lParam);

	protected:
		virtual long WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);	// [Overridden]
		virtual void ShutDown();

		void HandleMenuInit(HMENU, unsigned int,int);
	public:
		virtual ~TFrame();		// [Overridden]
		// Note: Insert 5 virtual members here
		virtual void TFrame_F1(UIState*) = 0;
		virtual void TFrame_F2(unsigned int controlId) = 0;
		virtual void TranslateAccelerators(MSG* msg) = 0;
		virtual void Init() = 0;
		virtual void Initialize() = 0;
		// Note: End extra 5 virtual members
		virtual void Activate();
		virtual void Deactivate();
		virtual void OnIdle();
		virtual void PreCreateDlg();
		virtual void PostCreateDlg();

		// Non virtual member functions
		TFrame(const TFrame&);
		TFrame();
		TFrame& operator=(const TFrame&);
		void PostDelayedLoadMessage(const char*);
	};

}	// End namespace


#endif
