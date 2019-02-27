

#pragma once


#include "CommandPaneView.h"


namespace OP2Internal
{

	class ReportView : public CommandPaneView
	{
	public:
		// virtual void UpdateView();
		// virtual void OnAddView();
		// virtual void OnRemoveView();
		// virtual bool IsNewView();
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface);		// 0x459C90 [Return]
		virtual void SetReportPageIndex();									// 0x464A10
		virtual bool DoesUnitSelectionChangeCauseUpdate();					// 0x464A20 [Return 1]
		// virtual void OnAction();
		// virtual int  GetSelectedReportButtonIndex();
		virtual void F1();													// [Pure Call] **
		virtual void F2(int a1);											// [Pure Call] **
		virtual void UpdateListSelection(int selectedItemIndex);			// 0x459D60
		virtual void SetScrollButtonsEnabledState();						// 0x459DB0

	public:
		// Member variables
		// ----------------
		// vtbl				// 0x4D5590
		// ----------------
		// ...?
	};

}	// End namespace
