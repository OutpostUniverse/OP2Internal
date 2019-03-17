#pragma once


#include "../ReportView.h"


namespace OP2Internal
{

	class LabReportView : public ReportView
	{
	public:
		virtual void UpdateView();											// 0x46B9A0
		virtual void OnAddView();											// 0x46B9C0
		// virtual void OnRemoveView();
		// virtual bool IsNewView();
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface);		// 0x46BC30
		// virtual void SetReportPageIndex();
		// virtual bool DoesUnitSelectionChangeCauseUpdate();
		// virtual void OnAction();
		virtual int  GetSelectedReportButtonIndex();						// 0x46B840 [Return 2]
		//virtual		// 0x46BCB0
		//virtual		// 0x46BDF0
		virtual void UpdateListSelection(int selectedItemIndex);			// 0x46BE50
		// virtual void SetScrollButtonsEnabledState();
		// ...

	public:
		// Member variables
		// ----------------
		// vtbl				// 0x4D59B8
		// ----------------
		// ...?
	};


	// Globals
	extern LabReportView labReportView;		// 0x568E88

}	// End namespace
