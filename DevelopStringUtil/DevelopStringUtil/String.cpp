#include "String.h"
#include <iostream>
#include <cctype>
#include <ctype.h>

String::String()
{
	//function dynamically allocates space for new char
	//default constructor, so no inputs

	m_string = new char[14] {"Hello, World!"};
		//	because there is no input, a hard value is used for array length
		//	"Hello, World!" is 13 characters long. 14 is the length for null terminator
		//	then "Hello, World!" is used as the string input for the array

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

	//if (index > strlen(m_string))
	//{
	//	return '/0';
	//}
	//else if (index < 0)
	//{

	//}
	//else
	//{
		return m_string[index];
			//	returns the char at the input index
			//	just a single char, not an array
	/*}*/

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
	//	Step through every value in m_string
	//	call tolower function on every char

	char thisChar;	//	declares a variable to hold a char

	for (int i = 0; i < strlen(m_string); i++)	//	for loop to loop through full array
	{
		thisChar = tolower(m_string[i]);
			//	defines thisChar to equal to the lower case of the current index of m_string

		m_string[i] = thisChar;
			//	sets m_string at indexed point to thisChar, making it lower case if possible
	}

}	//	functionality confirmed

void String::ToUpper()
{
	//	step through each char in m_string and call toupper

	char thisChar;	//	declaring a variable which will hold a char

	for (int i = 0; i < strlen(m_string); i++)	//	to loop through m_string
	{
		thisChar = toupper(m_string[i]);
			//	thisChar becomes upper case of m_string at current index

		m_string[i] = thisChar;
			//	m_string at current index becomes thisChar, making it upper case if possible
	}

}	//	functionality confirmed

bool String::CompareAt(int index, const String& input)
{
	//	a helper function that compares for the presence of a string in this string
	//	starts from an index, checking for matches in m_string for the input

	//int length = strlen(m_string) - input.Length();
	//	//	finds the length of the array that could contain the input
	
	//int inputIndex = 0;
	//	//	to save the index of the input

	//for (int i = index; i < strlen(m_string); i++)
	//		//	isolates the area which will be searched for matching chars
	//{
	//	if (m_string[i] != input.m_string[inputIndex])
	//			//	checks if the char of the input at the index matches the indexed char of m_string
	//	{
	//		return false;	//	returns a false boolean if doesn't match
	//	}
	//	else if (i == input.Length())
	//			//	checks if the loop is at it's final iteration
	//	{
	//		return true;	//	returns a true boolean because it found the string
	//	}
	//	else
	//	{
	//		inputIndex++;	//	increments the index for the input
	//		continue;	//	continues the loop
	//	}
	//}		//TOO COMPLICATED, needed a proper step back

	for (int i = 0; i < input.Length(); i++)
			//	loops a number of times equal to the length of the string
	{
		if (m_string[index + i] != input.m_string[i])
				//	checks if the indexes do not match
		{
			return false;	//	returns false bool if indexes don't match/string not found
		}
	}

	return true;	//	returns true bool if if statement completes with only matches

}	//	functionality confirmed

int String::Find(const String& findString)
{
	//	finds a string in a char array
	//	this likely uses String Access from C-String functionality
	//	a for loop can potentially be used to loop through the array to search
	//	I can only think of a way to find specific characters, not strings

	bool isMatch;

	if (findString.Length() <= strlen(m_string))
			//	determines if the input string is length is greater than m_string's length
			//	can't find the input if there isn't enough space in m_string for it to exist
	{
		for (int i = 0; i <= strlen(m_string) - findString.Length(); i++)
				//	for loop limit set to the latest point that the input could be found in m_string
				//	if there isn't enough remaining space for the input, the rest is ignored
		{			
			isMatch = CompareAt(i, findString);
				//	calls CompareAt to determine if findString is in m_string starting from index i
			
			if (isMatch == true)
					//	checks if CompareAt helper function has found the input string
			{
				return i;	//	returns the index value if the string was found
			}
			else if (/*isMatch == false &&*/ (i != (strlen(m_string) - findString.Length())))
					//	checks for last iteration
			{
				continue;	//	continues if string was not found but not at last iteration
			}
			else
			{
				return -1;	//	returns -1 if string was not found by last iteration
			}
		}
	}
	else
			//	if the input length is greater than the length of m_string
	{
		return -1;	//	returns -1, because input cannot exist in m_string
	}

}	//	functionality confirmed

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

bool String::operator == (const String& input)
{
	//	a member function that allows the use of the '==' operator with string classes
	
	if (strcmp(m_string,input.CStr()) != 0)	//	checks if the inputs are different
	{
		return false;	//	returns false boolean
	}
	
		//	if conditional was not met

	return true;	//	returns true boolean

}	//	functionality confirmed!

bool String::operator < (const String& input)
{
	//	a member function to allow '<' (less than) functionality
	
	if (strcmp(m_string, input.CStr()) == -1)	//	checks if input comes before m_string alphabetically
	{
		return true;	//	if the if statement is true, returns true boolean
	}
	
	return false;	//	otherwise, returns false boolean

}	//	functionality confirmed!

char String::operator [] (const int index)
{
	//	a member function to allow '[]' (indexing/subscript) functionality
	//	has the same functionality as CharacterAt()
	
	if (index > strlen(m_string) || index < 0)	//	checks if input is outside array
	{
		return m_string[strlen(m_string)];	//	returns final char of m_string
	}
	else if (index < 0)	//	checks if input is outside array
	{
		return m_string[0];	//	returns first char of m_string
	}

	return m_string[index];	//	returns the value of m_string at the index

}	//	functionality confirmed!

void String::operator = (const String& input)
{
	//	a member function to allow '=' (assignment/replacement) functionality
	//	replaces m_string with the input

	char* newArray;
		//	define a new pointer to store information

	newArray = new char[strlen(input.CStr()) + 1];
		//	the pointer now points to a set of allocated memory for an array

	delete[] m_string;
		//	deallocates memory for m_string

	strcpy_s(newArray, strlen(input.CStr()) + 1, input.CStr());
		//	copies the input into the new array at the new pointer

	m_string = newArray;
		//	points m_string to the new pointer, which points to the new array

}	//	

//String& String::operator + (const String& input)
//{
//
//}
//
//String& String::operator += (const String& input)
//{
//
//}