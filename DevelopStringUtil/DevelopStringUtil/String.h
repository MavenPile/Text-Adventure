#pragma once

class String
{
private:

		//	Member Variables

	char* m_string;	//	holds the array of String

		//	Helper Function Declarations

	bool CompareAt(int index, const String& input);
		//	finds a String-Type object at an index of another String-Type object

	void ReplaceAt(int index, const String& findString, const String& replaceString);	
		//	replaces a section of a String-Type object with another String-Type object

public:

		//	Constructors and Destructor

	String();		//default constructor

	String(const char* input);		//custom constructor

	String(const String& input);		//copy constructor

	~String();		//the destructor

		//	Member Function Declarations

	int Length() const;	//	returns length of m_string, without null terminator

	char& CharacterAt(int index);	//	returns the char at an index of m_string, returns '\0' if not found

	bool EqualTo(const String& input) const;	//	returns true if input matches m_string, false otherwise

	void Append(const String& input);	//	appends input to the end of m_string

	void Prepend(const String& input);	//	prepends input to the start of m_string

	const char* CStr() const;	//	returns m_string

	void ToLower();	//	sets m_string to lower case

	void ToUpper();	//	sets m_string to upper case

	int Find(const String& findString);	//	returns index of findString within m_string, '-1' if not found

	int FindFrom(int index, const String& findString);	//	same as Find(), but begins search from index			

	void Replace(const String& findString, const String& replaceString);
			//	same as find, but uses ReplaceAt() helper function, and doesn't return anything

	void ReadFromConsole();	//	prompts user for input, writes input into m_string

	void WriteToConsole();	//	writes m_string to console

		//	Operator overload functions

	bool operator == (const String& input);

	bool operator < (const String& input);

	char operator [] (const int index);

	void operator = (const String& input);

		//	Optional functionality

	String operator + (const String& input);

	void operator += (const String& input);
};

