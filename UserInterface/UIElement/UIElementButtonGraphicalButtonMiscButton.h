

#ifndef UIElementButtonGraphicalButtonMiscButton_H
#define UIElementButtonGraphicalButtonMiscButton_H


#include "UIElementButtonGraphicalButton.h"


namespace OP2ForcedExport
{

	// UIElement:Button:GraphicalButton derived classes
	// which don't define new member variables.
	// They just implement Release and OnClick.
	// -----------------------------------------------


	class MessageLogJumpToButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~MessageLogJumpToButton();
		virtual void OnClick();
	};

	class VehicleListJumpToButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~VehicleListJumpToButton();
		virtual void OnClick();
	};

	class ListScrollButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~ListScrollButton();
		virtual void OnClick();
	};

	class LessMoreAssignResearchButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~LessMoreAssignResearchButton();
		virtual void OnClick();
	};

	class LessMoreTrainScientistsButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~LessMoreTrainScientistsButton();
		virtual void OnClick();
	};

	class LessMoreGameOptionButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~LessMoreGameOptionButton();
		virtual void OnClick();
	};

	class MiniMapButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~MiniMapButton();
		virtual void OnClick();
	};

	class ResetNetworkStatsButton : public GraphicalButton
	{
	public:
		// Virtual member functions (inherited)
		virtual ~ResetNetworkStatsButton();
		virtual void OnClick();
	};

}	// End namespace


#endif
