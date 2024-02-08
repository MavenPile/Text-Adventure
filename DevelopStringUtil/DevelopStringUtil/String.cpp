#include "String.h"
#include <iostream>
#include <CString>

String::String()
{
	//function dynamically allocates space for new char
	//default constructor, so no inputs

	m_string = new char[14];
		//	because there is no input, a hard value is used
		//	"Hello, World!" is 13 characters long. 14 is the length for null terminator

	strcpy_s(m_string, 14, "Hello, World!");
		//	copies "Hello, World!" into m_string

}	//function properly defines m_string

String::String(const char* input)
{
	//function manually allocates space for a new char

	m_string = new char[strlen(input) + 1];
		//	Sets the m_string pointer to an array with size of input, + 1 for null terminator
		//	null terminator is not counted by strlen() syntax

	strcpy_s(m_string, (strlen(input) + 1), input);
		//	copies the input into m_string array

}	//function is properly defining m_string

String::String(const String& input)
{
	//	a copy constructor
	
	m_string = new char[strlen(input.CStr()) + 1];
		//	'input.CStr()' accesses the member variable of 'input'
		//	this allows the copy constructor to copy m_string from another string class

	strcpy_s(m_string, (strlen(input.CStr()) + 1), input.CStr());
		//	same code as custom constructor, copies input into m_string

}	//	copy constructor functionality confirmed

String::~String()
{
	//manually deallocates space so no memory space is kept
	
	delete[] m_string;
		//	deallocates memory for m_string once destructor is triggered

}	//untested

int String::Length() const
{
	//Simply uses the C-String functionality

	return strlen(m_string);
		//	outputs the length of the string, including spaces, but not the null terminator

}	//after testing, function works properly!

char& String::CharacterAt(int index)
{
	//uses C-String functionality of String Access to index the string

	return m_string[index];
		//	returns the char at the input index
		//	just a single char, not an array

}	//	functionality confirmed

bool String::EqualTo(const String& input) const
{
	//	uses C-String functionality to compare the input to the string, returning a boolean
	//	pairs with an if statement to measure the output boolean of strcmp()

	if (strcmp(m_string,input.CStr()))		//	compares the input's string is equal to m_string
	{
		return true;	//	outputs a true boolean
	}
	else
	{
		return false;	//	outputs a false boolean
	}

}	//	functionality confirmed

void String::Append(const String& input)
{
	//	uses C-String functionality to append the input to the end of m_string

	char* newArray;		//	new pointer to save information

	newArray = new char[strlen(m_string) + strlen(input.CStr()) + 1];
		//	sets newArray to an array with appropriate length
		//	manually allocates memory

	strcpy_s(newArray, (strlen(m_string) + strlen(input.CStr()) + 1), m_string);
		//	newArray copies the string of m_string to its allocated memory

	strcat_s(newArray, strlen(m_string) + strlen(input.CStr()) + 1, input.CStr());
		//	newArray appends the string of the input to its allocated memory

	delete[] m_string;
		//	deallocate m_string's memory

	m_string = newArray;
		//	m_string pointer set to newArray address beginning

}	//	functionality confirmed

void String::Prepend(const String& input)
{
	//	uses the same functionality as the Append function

	char* newArray;		//	new char pointer

	newArray = new char[strlen(m_string) + strlen(input.CStr()) + 1];
		//	allocates memory for new array equal to the size of the prepended array

	strcpy_s(newArray, strlen(m_string) + strlen(input.CStr()) + 1, input.CStr());
		//	copies the string of the input to newArray

	strcat_s(newArray, strlen(m_string) + strlen(input.CStr()) + 1, m_string);
		//	appends the string of m_string to newArray

	delete[] m_string;
		//	deallocates m_string's memory

	m_string = newArray;
		//	points m_string to newArray address

}	//	functionality confirmed

const char* String::CStr() const
{
	
	//	a function that returns m_string as a string
	//	allowing string inputs for functions of another object

	return m_string;
	
		//	once called, this function outputs the string of m_string
		//	this allows you to access the m_string of multiple classes
		//	so, another object can access the string of this object

		//	This is a very important function

}	//	functionality confirmed

void String::ToLower()
{
	for (int i = 0; i < strlen(m_string); i++)
	{
		if (isupper(m_string[i]))
		{
			tolower(m_string[i]);
		}
		else
		{
			continue;
		}
	}
}

void String::ToUpper()
{
	// TODO: insert return statement here
}

//int String::Find(const String& findString)
//{
//	//	finds a string in a char array
//	//	this likely uses String Access from C-String functionality
//	//	a for loop can potentially be used to loop through the array to search
//	//	I can only think of a way to find specific characters, not strings
//
//	for
//
//}

//int String::Find(int startIndex, const String& findString)
//{
//	//	a function to find a string within a string array, starting from an indicated index
//}

//String& String::Replace(const String& findString, const String& replaceString)
//{
//	//TODO
//}

void String::ReadFromConsole()
{
	//	reads the console to replace m_string with the input

	std::cout << "Waiting for input." << std::endl;		
		//	prompts the user for input

	std::cin >> m_string;		
		//	recieves console input and writes it to m_string

}	//	functionality confirmed

void String::WriteToConsole()
{
	//	writes the value of the string to the console

	std::cout << m_string << std::endl;
		//	outputs m_string to the console

}	//	functionality confirmed