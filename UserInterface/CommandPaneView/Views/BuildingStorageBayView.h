#pragma once


#include "../CommandPaneView.h"


namespace OP2Internal
{

	class BuildingStorageBayView : public CommandPaneView
	{
	public:
		virtual void UpdateView();											// 0x462CB0
		virtual void OnAddView();											// 0x463100
		virtual void OnRemoveView();										// 0x463170
		// virtual bool IsNewView();
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface);		// 0x4638F0
		// virtual void SetReportPageIndex();
		virtual bool DoesUnitSelectionChangeCauseUpdate();					// 0x462C00
		// virtual void OnAction();
		virtual int  GetSelectedReportButtonIndex();						// 0x462BF0

	public:
		// Member variables
		// ----------------
		// vtbl				// 0x4D54C0
		// ----------------
		// ...?
	};


	// Globals
	extern BuildingStorageBayView buildingStorageBayView;	// 0x565D30

}	// End namespace
