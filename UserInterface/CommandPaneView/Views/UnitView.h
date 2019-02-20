

#ifndef UnitView_H
#define UnitView_H


#include "../CommandPaneView.h"


namespace OP2Internal
{

	class UnitView : public CommandPaneView
	{
	public:
		virtual void UpdateView();										// 0x4593D0
		virtual void OnAddView();										// 0x459470
		// virtual void OnRemoveView();
		// virtual bool IsNewView();
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface);	// 0x4595C0
		// virtual void SetReportPageIndex();
		virtual bool DoesUnitSelectionChangeCauseUpdate();				// 0x459F80 Return 1
		// virtual void OnAction();
		// virtual int  GetSelectedReportButtonIndex();

	public:
		// Member variables
		// ----------------
		// vtbl				// 0x4D5278
		// ----------------
	};

}	// End namespace


#endif
