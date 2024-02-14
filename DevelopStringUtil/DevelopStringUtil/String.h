#pragma once

class String
{
private:

	//member variables

	char* m_string;

	bool CompareAt(int index, const String& input);

	void ReplaceAt(int index, const String& findString, const String& replaceString);

public:

	//constructors and destructors

	String();		//default constructor

	String(const char* input);		//custom constructor

	String(const String& input);		//copy constructor

	~String();		//the destructor


	//member function declarations

	int Length() const;		//function which returns the length of the string up to, not including, the null terminator

	char& CharacterAt(int index);		//returns a char that represents the character's location, and if impossible, returns '/0'

	bool EqualTo(const String& input) const;		//returns a boolean on if the strings are the same

	void Append(const String& input);		//Appends the input to the string, using the address of the string

	void Prepend(const String& input);		//Prepends the input to the string, using the address

	const char* CStr() const;		//outputs m_string for other objects to use

	void ToLower();		//converts the characters of the string to lower case

	void ToUpper();		//converts the characters of the string to upper case

	int Find(const String& findString);		//finds the address of findString, return -1 if not found

	int FindFrom(int index, const String& findString);		//returns the address of findString, starting from startIndex			

	void Replace(const String& findString, const String& replaceString);		//replaces instances of a string with another

	void ReadFromConsole();		//reads a string from the console

	void WriteToConsole();		//writes a string to the console

		//	Operator overload functions

	bool operator == (const String& input);

	bool operator < (const String& input);

	char operator [] (const int index);

	void operator = (const String& input);

		//	Optional functionality

	String& operator + (const String& input);

	String& operator += (const String& input);
};

