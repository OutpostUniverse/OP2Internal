#pragma once



namespace OP2Internal
{
	struct Waypoint
	{
		unsigned int pixelX:15;
		unsigned int pixelY:14;
	};
	static_assert(4 == sizeof(Waypoint), "Unexpected struct size");
}	// End namespace
