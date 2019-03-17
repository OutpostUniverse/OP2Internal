#pragma once

#include "EnumTechCategory.h"


namespace OP2Internal
{

	// Forward declares
	struct GameStartInfo;
	struct TechInfo;
	struct TechUpgradeInfo;
	struct UpgradeType;


	class Research
	{
	public:
		// Member functions
 		int GetTechNum(int techID);
 		bool HasTech(int playerNum, int techNum);
		bool CanResearchTech(int playerNum, int techNum);
 		void MarkResearchComplete(int playerNum, int techNum);
		void SetTechLevel(int playerNum, int techID);
		void GiveClosureOfTech(int playerNum, int techNum);
		void GiveTechUpgrades(int playerNum, int techNum);
		void LoadAndProcessTechFile(const char* fileName, int maxTechLevel);
		void LoadTechFile(const char* fileName, int maxTechID);
		bool SaveStartState(GameStartInfo* gameStartInfo);
		bool LoadStartState(GameStartInfo* gameStartInfo);
		bool Save(StreamIO* savedGameFile);
		bool Load(StreamIO* savedGameFile);
		void GiveInitialTechs();
		int Checksum();

	public:
		// Member variables
		int numTechs;
		TechInfo **techInfo;		// TechInfo*[]*
		int maxTechID;				// 12999  [maxTechLevel * 1000 + 999]
		// ...
		// 0x2C
	};


	// Globals
	extern Research research;		// 0x0056C230



	// Min Size: 0x48  [Member access]
	// Max Size: 0x50  [New?]  [MemAlloc padding?]
	struct TechInfo
	{
		int techID;					// 0x00  TechID found in the sheets files
		TechCategory category;		// 0x04  In sheets "CATEGORY" tells what kind this tech is
		int techLevel;				// 0x08  Tech level of this tech (the thousands digit)
		int plymouthCost;			// 0x0C  Amount of research required by Plymouth
		int edenCost;				// 0x10  Amount of research required by Eden
		int maxScientists;			// 0x14  Max number of scientists allowed to assign to research
		int lab;					// 0x18  Lab type research is done at  [1 = Basic, 2 = Standard, 3 = Advanced]
		int playerHasTechMask;		// 0x1C  Bit vector of which players have this technology
		int numUpgrades;			// 0x20  Number of unit upgrades it performs ("UNIT_PROP"s in tech file)
		int numRequiredTechs;		// 0x24  Number of other techs required to research this one ("REQUIRES"s in tech file)
		char* techName;				// 0x28  Name of the technology (in sheets files)
		char* description;			// 0x2C  Description of tech given after research
		char* teaser;				// 0x30  Description of tech given before research
		char* improveDesc;			// 0x34  Description of the upgrades given by this tech
		int* requiredTechNum;		// 0x38  Pointer to array of techNums that this tech requires
		TechUpgradeInfo* upgrade;	// 0x3C  Pointer to array of structs containing upgrade info
		int numDependentTechs;		// 0x40  Number of technologies dependent on this one
		int* dependentTechNum;		// 0x44  Pointer to array of techNums that depend on this tech
	};


	struct TechUpgradeInfo
	{
		UpgradeType* type;			// Pointer to struct describing the type of upgrade (Production_Capacity, Move_Speed, Sight_Range, etc.)
		enum map_id unitType;		// Type of unit this upgrade applies to
		int newValue;				// New value of property being upgraded
	};

	struct UpgradeType
	{
		int type;					// Type of upgrade  [0 = Unit_Prop, 1 = Player_Prop, 2 = Function_Result]
		char* upgradeType;			// Pointer to a string that follows the "UNIT_PROP" tag in the sheets
		int offsetToProp;			// Offset of property in the upgraded structure (byte offset added to base of where data starts for current player)
									// or function address for type = 2 (Function_Result)
	};

}	// End namespace
