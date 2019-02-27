#pragma once


#include "../ReportView.h"
#include "../../UIElement/UIElementListBox.h"
#include "../../UIElement/UIElementButtonGraphicalButton.h"


namespace OP2Internal
{

	class FactoryReportView : public ReportView
	{
	public:
		virtual void UpdateView();											// 0x464BB0
		virtual void OnAddView();											// 0x464BD0
		// virtual void OnRemoveView();
		// virtual bool IsNewView();
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface);		// 0x464DC0
		// virtual void SetReportPageIndex();
		// virtual bool DoesUnitSelectionChangeCauseUpdate();
		// virtual void OnAction();
		virtual int  GetSelectedReportButtonIndex();						// 0x464AD0  [Return 1]
		//virtual		// 0x464D00
		//virtual		// 0x464D40
		virtual void UpdateListSelection(int selectedItemIndex);			// 0x464D60
		// virtual void SetScrollButtonsEnabledState();
		//virtual ???();	// 0x464C20
		//virtual ???();	// 0x464DA0

	public:
		// Member variables
		// ----------------
		// vtbl								// 0x0   [0x566408] 0x4D55C8
		// ----------------
		DoubleClickListBox buildListBox;	// 0x4   [0x56640C]
		//ListScrollButton downButton;		// 0x6C  [0x566474]  down? maybe
		//ListScrollButton upButton;			// 0x118 [0x566520] up? maybe
		// [0x5665CC]
		// [0x5665D0] BuildList? (object)
		//UICommandButton buildButton;		// [0x566658] build? maybe
		// ...?
	};


	// Globals
	extern FactoryReportView factoryReportView;		// 0x566408

}	// End namespace
