

#ifndef CConfig_H
#define CConfig_H


namespace OP2Internal
{

	class CConfig
	{
	public:
		// Constructor/Destructor
		CConfig();						// fileName = "<ModuleName>.ini"
		CConfig(const char* fileName);
		~CConfig();

		// Operators
		CConfig & operator=(const CConfig& config);

		// Member functions
		int CopyIniFile(const char* existingFileName);
		int FileExists();
		void Flush();
		int GetInt(const char* sectionName, const char* keyName, int defaultValue);
		int GetInt(const char*, int);
		int GetString(const char* sectionName, const char* keyName, char* destBuffer, unsigned int bufferSize, const char* defaultValue);
		int GetString(const char*, char*, unsigned int, const char*);
		int SetInt(const char* sectionName, const char* keyName, int newValue);
		int SetInt(const char*, int);
		int SetString(const char* sectionName, const char* keyName, const char* newValue);
		int SetString(const char*, const char*);
	};


	// Global functions
	void __fastcall GetPlayerName(char* destBuffer, bool bHost);		// 0x0047C380


	// Global variables
	extern CConfig config;		// 0x00547090

}	// End namespace


#endif
