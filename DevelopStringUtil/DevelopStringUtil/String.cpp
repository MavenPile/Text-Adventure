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

char String::CharacterAt(int index)
{
	//	uses C-String functionality of String Access to index the string
		
	if (index < 0 || index > strlen(m_string))	//	checks if input is invalid
	{
		return '\0';	//	outputs null terminator
	}
	else
	{
//		char hold = m_string[index];

		return m_string[index];	//	returns a char at index
	}

}	//	functionality confirmed

bool String::EqualTo(const String& input) const
{
	//	uses C-String functionality to compare the input to the string, returning a boolean
	//	pairs with an if statement to measure the output boolean of strcmp()

	if (strcmp(m_string,input.CStr()) == 0)		//	compares the input's string is equal to m_string
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

	int length = strlen(m_string) + strlen(input.CStr()) + 1;

	newArray = new char[length];
		//	sets newArray to an array with appropriate length
		//	manually allocates memory

	strcpy_s(newArray, length, m_string);
		//	newArray copies the string of m_string to its allocated memory

	strcat_s(newArray, length, input.CStr());
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

	for (int i = 0; i < input.Length(); i++)	//	loops for the length of the input
	{
		if (m_string[index + i] != input.m_string[i])	//	checks if the indexes do not match
		{
			return false;	//	returns false bool if indexes don't match/string not found
		}
	}

	return true;	//	returns true bool if if statement completes with only matches

}	//	functionality confirmed

//int String::Find(const String& findString)
//{
//	//	finds a string in a char array
//	//	this likely uses String Access from C-String functionality
//	//	a for loop can potentially be used to loop through the array to search
//	//	I can only think of a way to find specific characters, not strings
//
//	bool isMatch;
//
//	if (findString.Length() <= strlen(m_string))
//			//	determines if the input string is length is greater than m_string's length
//			//	can't find the input if there isn't enough space in m_string for it to exist
//	{
//		for (int i = 0; i <= strlen(m_string) - findString.Length(); i++)
//				//	for loop limit set to the latest point that the input could be found in m_string
//				//	if there isn't enough remaining space for the input, the rest is ignored
//		{			
//			isMatch = CompareAt(i, findString);
//				//	calls CompareAt to determine if findString is in m_string starting from index i
//			
//			if (isMatch == true)
//					//	checks if CompareAt helper function has found the input string
//			{
//				return i;	//	returns the index value if the string was found
//			}
//			else if (/*isMatch == false &&*/ (i != (strlen(m_string) - findString.Length())))
//					//	checks for last iteration
//			{
//				continue;	//	continues if string was not found but not at last iteration
//			}
//			else
//			{
//				return -1;	//	returns -1 if string was not found by last iteration
//			}
//		}
//	}
//	else
//			//	if the input length is greater than the length of m_string
//	{
//		return -1;	//	returns -1, because input cannot exist in m_string
//	}
//
//}	//	functionality confirmed, only outputs location of first found string

int String::Find(const String& findString)	
{
	//	Find() rewrite to make more readable and streamlined code

	//	finds the index of an input string in m_string

	if (findString.Length() > strlen(m_string))	//	checks if the input string is longer than m_string
	{
		return -1;	//	findString can't be found in m_string
	}
	else
	{
		bool isMatch;	//	declares a variable to hold CompareAt output

		int length = strlen(m_string) - findString.Length();	//	variable for length

		for (int i = 0; i <= length; i++)	//	repeats for searchable length of m_string
		{
			isMatch = CompareAt(i, findString);	//	compares with helper function

			if (isMatch == true)	//	if helper function outputs true
			{
				return i;	//	return index as location of findString
			}
			else if (i != length)	//	if helper function outputs false, and not on last iteration
			{
				continue;	//	continue for loop
			}
			else	//	if helper function false, and searched m_string fully
			{
				return -1;	//	findString not found in m_string
			}
		}
	}

}	//	functionality confirmed! Only finds first occurance of findString

//int String::FindFrom(int startIndex, const String& findString)
//{
//	//	a function to find a string within a string array, starting from an indicated index
//	//	basically a copy of Find(), but with an index input
//
//	bool isMatch;	//	declare a variable to hold a boolean
//
//	int length = strlen(m_string) - findString.Length();
//			//	The length of m_string that could contain the beginning of findString
//
//	if (findString.Length() <= strlen(m_string))
//			//	if the length of the input is less than or equal to m_string
//	{
//		for (int i = 0; i <= length; i++)
//				//	
//		{
//			isMatch = CompareAt(i + startIndex, findString);
//				//	checks for findString in m_string starting from the given index + i
//
//			if (isMatch == true)
//					//	if CompareAt finds findString in parameters
//			{
//				return i + startIndex;	//	output the index number
//			}
//			else if (i != length)
//					//	checks if function is not on last iteration
//			{
//				continue;
//			}
//			else
//					//	if on last iteration and string not found
//			{
//				return -1;
//			}
//		}
//	}
//	else
//			//	if the length of the input is greater than m_string
//	{
//		return -1;	//	input cannot exist in m_string
//	}
//
//}	//	functionality confirmed, only outputs location of first found string, only one location

int String::FindFrom(int index, const String& findString)
{
	//	FindFrom() rewrite so code is more readable and streamlined

	//	a copy of Find() that takes an input for index to start search from

	if (findString.Length() > strlen(m_string))	//	determines if input is too large
	{
		return -1;	//	findString cannot be found in m_string
	}
	else
	{
		bool isMatch;	//	declares a variable to hold CompareAt output

		int length = strlen(m_string) + findString.Length();	//	holds searchable length of m_string

		for (int i = index; i <= length; i++)	//	loops through entire searchable length
		{
			isMatch = CompareAt(i, findString);	//	uses helper function

			if (isMatch == true)	//	if helper function output is true
			{
				return i;	//	return i as indexed location of findString
			}
			else if (i != length)	//	if helper outputs false, and before final for loop iteration
			{
				continue;	//	continue for loop
			}
			else	//	if helper outputs false, and on final iteration
			{
				return -1;	//	findString not found
			}
		}
	}
	
}	//	functionality confirmed! Only finds first occurance of of findString from index


void String::ReplaceAt(int index, const String& originString, const String& replaceString)
{
	//	a private helper function that replaces a portion of a string with another string

	int diff = replaceString.Length() - originString.Length();
		//	the size difference to determine how much more or less memory must be allocated

	int length = strlen(m_string) + diff + 1;
		//	the length of the new string that would contain replaceString instead of findString

	char* newString = new char[length];
		//	a new char array with allocated memory to store the new string with replacements

	char newChar;
		//	declares a helper variable

	for (int i = 0; i < index; i++)
			//	for loop until index
	{
		newChar = m_string[i];	//	define newChar with m_string at index
		newString[i] = newChar;	//	define newString at index with newChar
	}

	newString[index] = '\0';
		//	inputs a null terminator so strcat_s can work
		//	I don't know why visual studio is underlining this
		//	What is "buffer overrun"?

	strcat_s(newString, length, replaceString.CStr());
		//	concatenates replaceString to newString, at appropriate index

	for (int i = index; i <= strlen(newString); i++)
			//	a loop that repeats until the end of newString's allocated length
	{
		newChar = m_string[originString.Length() + i];	//	defines helper variable
		newString[replaceString.Length() + i] = newChar;	//	copies new information into newString
	}

	delete[] m_string;
		//	deallocates memory from m_string

	m_string = newString;
		//	sets m_string pointer location to newString

}	//	functionality confirmed

void String::Replace(const String& findString, const String& replaceString)
{
	//	another copy of Find(), but with additional functionality
	//	I'll rewrite and not copy paste here for practice and refining sake

	//	must find location of findString within m_string, and replace with replaceString
	//	This means reallocating memory
	//	because findString may not exist within m_string, a bool return type outputs if successful

	if (findString.Length() <= strlen(m_string))
		//	if the length of input is less than m_string, function continues
	{
		bool isMatch;
			//	a holder variable declaration

		int searchLength = strlen(m_string) - findString.Length();
			//	the length of m_string that might contain findString

		for (int i = 0; i <= searchLength; i++)
			//	loop from 0 to findString[0]'s final possible location in m_string
		{
			isMatch = CompareAt(i, findString);
			//	compare findString to m_string starting from i

			if (isMatch == true)
				//	if CompareAt outputs true, continue on to replace
			{
				ReplaceAt(i, findString, replaceString);
					//	uses ReplaceAt helper function to replace findString with replaceString at i

				if (i != searchLength)
						//	checks if m_string has been entirely searched for findString
				{
					searchLength = strlen(m_string) - findString.Length();	//	updates length with new length of m_string
					i += replaceString.Length() - 1;	//	skips replaced section
					continue;	//	if m_string has not been fully searched, continues for loop
				}
				else
				{
					break;	//	all occurances of findString replaced
				}
			}
			else/* if (i != searchLength)*/
				//	if i isn't at the final char
			{
				continue;	//	continue searching for findString
			}
			//else
			//{
			//	break;	//	findString not found
			//}
		}
	}
		
		
		//		//	if the input length is larger than m_string
	//{
	//	return false;
	//		//	impossible to find input, function outputs false
	//}
	//else
	//		//	if the length of input is less than m_string, function continues
	//{
	//	for (int i = 0; i <= length; i++)
	//			//	loop from 0 to findString[0]'s final possible location in m_string
	//	{
	//		isMatch = CompareAt(i, findString);
	//			//	compare findString to m_string starting from i

	//		if (isMatch == true)
	//				//	if CompareAt outputs true, continue on to replace
	//		{
	//			ReplaceAt(i, findString, replaceString);
	//			
	//			if (i != length)
	//			{
	//				continue;
	//			}
	//			else
	//			{
	//				return true;
	//			}
	//			
	//			
	//			
	//			//float diff = findString.Length() - replaceString.Length();
	//			//	//	the length difference between findString and replaceString
	//			//
	//			//char* newArray;
	//			//	//	declare new pointer

	//			//newArray = new char[strlen(m_string) + diff + 1];
	//			//	//	allocate memory from new pointer location

	//			//char thisChar;
	//			//	//	holder variable

	//			//int endIndex;
	//			//	//	holder variable for where first string copy ends

	//			//for (int index = 0; index < i; index++)
	//			//	//	for loop to copy into newArray from m_string until findString location
	//			//{
	//			//	thisChar = m_string[index];
	//			//		//	defines holder variable

	//			//	newArray[index] = thisChar;
	//			//		//	inputs holder variable into newArray

	//			//	endIndex = index;
	//			//}

	//			//strcat_s(newArray, strlen(m_string) + diff + 1, replaceString.CStr());
	//			//	//	concatenate replaceString into newArray at appropriate location

	//			//for (int index = endIndex + replaceString.Length(); index < strlen(m_string); index++)
	//			//		//	loop to copy in remainder of m_string to newArray
	//			//		//	index starts from where the last for loop ended plus length of input
	//			//{
	//			//	thisChar = m_string[index];
	//			//		//

	//			//	newArray[index] = thisChar;
	//			//		//
	//			//}


	//			////strcpy_s(newArray, replaceString.Length() + 1, replaceString.CStr());
	//			////	//	copy replaceString into new array

	//			//delete[] m_string;
	//			//	//	deallocate previous m_string memory

	//			//m_string = newArray;
	//			//	//	set m_string pointer location to newArray

	//			//return true;
	//		}
	//		else if (i != length)
	//				//	if i isn't at the final char
	//		{
	//			continue;
	//		}
	//		else
	//				//	otherwise, findString was not found in m_string
	//		{
	//			return false;
	//		}
	//	}
	//}

}	//	functionality confirmed, replaces all findString with replaceString

void String::ReadFromConsole()
{
	//	reads the console to replace m_string with the input
	//	this function crashes the program if the user input is larger than 64

	std::cout << "Waiting for input (max 64 char.)" << std::endl;		
	//	//	prompts the user for input

	char* input = new char[65];	//	allocates hard buffer cap

	std::cin.getline (input,65);	//	writes console input to input array

	//std::cin.get(input, 65, '\n');	//	alternate version, '\n' means enter or new line

	int length = strlen(input) + 1;	//	finds the length of console input

	char* newString = new char[length];	//	allocates memory for new array

	strcpy_s(newString, length, input);	//	copies console input to new array

	delete[] input;	//	deallocates memory from temp input array

	delete[] m_string;	//	deallocates memory from m_string

	m_string = newString;	//	points m_string to newString array

	//if (length > 64)
	//{
	//	std::cout << "Invalid input." << std::endl;

	//	delete[] input;
	//}
	//else
	//{
	//	char* newString = new char[length];

	//	strcpy_s(newString, length, input);

	//	delete[] input;
	//	
	//	delete[] m_string;

	//	m_string = newString;
	//}


	//String input;

	//std::cin >> input;		
	//	//	recieves console input and writes it to m_string
	//
	//char tempString[strlen(input)];

	//String tempString(input);

	//delete[] m_string;

	//m_string = tempString;

}	//	

void String::WriteToConsole()
{
	//	writes the value of the string to the console

	std::cout << m_string << std::endl;
		//	outputs m_string to the console

}	//	functionality confirmed

bool String::operator == (const String& compareString)
{
	//	a member function that allows the use of the '==' operator with string classes
	
	if (strcmp(m_string,compareString.CStr()) != 0)	//	checks if the inputs are different
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
	
	if (index > strlen(m_string))	//	checks if input is outside array
	{
		return m_string[strlen(m_string)];	//	returns final char of m_string
	}
	else if (index < 0)	//	checks if input is outside array
	{
		return m_string[0];	//	returns first char of m_string
	}
	else
	{
		return m_string[index];	//	returns the value of m_string at the index
	}

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

}	//	functionality confirmed!

String String::operator + (const String& input)
{
	//	a member function that provides '+' operator functionality

	int length = strlen(m_string) + input.Length() + 1;	//	variable for length of new string

	char* tempArray = new char[length];	//	allocates memory for new char array

	strcpy_s(tempArray, length, m_string);	//	copy m_string into new array

	strcat_s(tempArray, length, input.CStr());	//	concatenate input string into new array

	String newString(tempArray);	//	assign new array values to a new string-type variable

	delete[] tempArray;	//	deallocates tempArray memory after its values are copied into newString

	return newString;	//	return the new string

}	//	functionality confirmed

void String::operator += (const String& input)
{
	//	a member function to provide '+=' operator functionality to String objects

	int length = strlen(m_string) + input.Length() + 1;	//	length of new string

	char* newString = new char[length];	//	allocates memory for new string array

	strcpy_s(newString, length, m_string);	//	copies m_string into newString array

	strcat_s(newString, length, input.CStr());	//	concatenates the input

	delete[] m_string;	//	deallocates m_string memory

	m_string = newString;	//	points m_string to new array memory

}	//	functionality confirmed