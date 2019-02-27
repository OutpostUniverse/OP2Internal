#pragma once


namespace OP2Internal
{

	class StreamIO;


	class TextStreamParser
	{
	public:
		// Constructor/Destructor
		TextStreamParser();								// 0x48EFF0
		~TextStreamParser();							// 0x48F000

		// Member functions
		int  OpenFile(char* fileName);					// 0x48F020 BSuccess
		void Close();									// 0x48F050
		void ResetToLastToken();						// 0x48F070
		int  SkipRestOfLine();							// 0x48F090 BSuccess
		int  ReadInt(int* intValue);					// 0x48F0E0 BSuccess
		int  ReadToken(char* token, int bufferSize);	// 0x48F210 BSuccess  [buffer non-null, size >= 1]
		int  ReadString(char* string, int bufferSize);	// 0x48F330 BSuccess  [buffer non-null, size >= 1] [Read quoted string, discard quotes]
		int  FindLineOfLastReadToken();					// 0x48F430 [-1 = Error]

	public:
		// Member variables
		StreamIO* textStream;	// 
		int position;			// 
	};

}	// End namespace
