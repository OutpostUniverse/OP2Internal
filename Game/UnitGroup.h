#pragma once



namespace OP2Internal
{

	class UnitGroup
	{
	public:
		// Member functions
		int GetNumSelectedUnits() const;			// 0x41A9A0
		const int* GetSelectedUnitArray() const;	// 0x41A9B0

	public:
		// Member variables
		int numUnits;
		int unitIndex[32];
	};
	static_assert(132 == sizeof(UnitGroup), "Unexpected struct size");


	#pragma pack(push, 1)
	struct PackedUnitGroup
	{
		char numUnits;
		short unitIndex[32];
	};
	static_assert(65 == sizeof(PackedUnitGroup), "Unexpected struct size");
	#pragma pack(pop)


	// Globals
	extern UnitGroup selectedUnits;		// 0x547210

}	// End namespace
