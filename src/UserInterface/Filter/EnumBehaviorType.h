#pragma once


namespace OP2Internal
{
	enum BehaviorType
	{
		BandboxUnitSelect = 0,  // Left-clicking starts drawing a bandbox
		SetRectRegion = 1,      // Bulldoze or Salvage region
		SetBuildLocation = 2,   // Highlight area under mouse (tile aligned, multicoloured region)
		SetDest = 3,            // Left-click to set destination (Attack, Move, etc.) (don't select units)
		SetLineRegion = 4,      // Build Tube, Wall, Lava Wall, or Microbe Wall
		MouseDisabled = 5,      // Arrow cursor, clicking is disabled (including Right-click)
	};
}	// End namespace
