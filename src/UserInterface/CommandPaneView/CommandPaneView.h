#pragma once


namespace OP2Internal
{

	struct Rect;
	class GFXClippedSurface;


	// Size: 4
	class CommandPaneView
	{
	public:
		virtual void UpdateView();											// 0x459F10
		virtual void OnAddView();											// 0x459F20 [Add buttons, clear mouse filter]
		virtual void OnRemoveView();										// 0x459F30 Return
		virtual bool IsNewView();											// 0x459F40 Return 1
		virtual void Draw(Rect* drawRect, GFXClippedSurface* surface) = 0;	// [Pure Call]
		virtual void SetReportPageIndex();									// 0x459F50
		virtual bool DoesUnitSelectionChangeCauseUpdate();					// 0x459F60 Return 0
		virtual void OnAction();											// 0x46D960
		virtual int  GetSelectedReportButtonIndex();						// 0x459F70 Return 0

	public:
		// Member variables
		// ----------------
		// vtbl				// 0x4D5200
		// ----------------
	};

}	// End namespace
