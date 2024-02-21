#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>

std::fstream file;

int main()
{
	struct tm newTime;
	time_t now = time(0);
	localtime_s(&newTime, &now);
	int sec = newTime.tm_sec;
	int min = newTime.tm_min;
	int hour = newTime.tm_hour;
	int day = newTime.tm_mday;
	int month = newTime.tm_mon + 1;
	int year = newTime.tm_year + 1900;

	file.open("testFile.txt", std::ios::app);

	file << std::endl;

	file << "Date: " << day << "/" << month << "/" << year;

	file << " Time: " << hour << ":" << min << ":" << sec << std::endl;

	
	std::cout << "Default Constructor ";
	
	String defaultCon;

	String defaultConTester("Hello, World!");

	if (strcmp(defaultCon.CStr(), defaultConTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "Default Constructor is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Default Constructor is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Custom Constructor ";

	String customCon("Hello, World!");

	if (strcmp(customCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "Custom Constructor is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Custom Constructor is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR" << std::endl;

	String copyCon(defaultCon);

	if (strcmp(copyCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "Copy Constructor is functional." << std::endl;

		if (file.is_open())
		{
			file << "Copy Constructor is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Copy Constructor is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "DESTRUCTOR" << std::endl;

	std::cout << "Destructor untested." << std::endl;

	if (file.is_open())
	{
		file << "Destructor untested." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "Length() ";

	String lengthTest;

	if (lengthTest.Length() == 13)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "Length() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Length() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CharacterAt() ";

	String characterAtTest;

	char charAt = characterAtTest.CharacterAt(0);

	if (charAt == 'H')
	{
		std::cout << "is functional" << std::endl;

		if (file.is_open())
		{
			file << "CharacterAt() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "CharacterAt() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "EqualTo() ";

	String equalToTest;

	String equalToTrue(equalToTest);

	String equalToFalse("false");

	if (equalToTest.EqualTo(equalToTrue) == true && equalToTest.EqualTo(equalToFalse) == false)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "EqualTo() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "EqualTo() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Append() ";

	String appendTest;

	String appender(" I am a string.");

	String appendTester("Hello, World! I am a string.");

	appendTest.Append(appender);

	if (strcmp(appendTest.CStr(), appendTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "Append() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Append() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Prepend() ";

	String prependTest;

	String prependTester("Is anyone there? Hello, World!");

	String prepender("Is anyone there? ");

	prependTest.Prepend(prepender);

	if (strcmp(prependTest.CStr(), prependTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "Prepend() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Prepend() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CStr() is functional." << std::endl;

	if (file.is_open())
	{
		file << "CStr() is functional." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "ToLower() ";

	String toLowerTest;

	String toLowerTester("hello, world!");

	toLowerTest.ToLower();

	if (strcmp(toLowerTest.CStr(), toLowerTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "ToLower() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "ToLower() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ToUpper() ";

	String toUpperTest;

	String toUpperTester("HELLO, WORLD!");

	toUpperTest.ToUpper();

	if (strcmp(toUpperTest.CStr(), toUpperTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "ToUpper() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "ToUpper() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Find() ";

	String findTest;

	String findHello("Hello");

	if (findTest.Find(findHello) == 0)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "Find() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Find() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "FindFrom() ";

	String findFromTest("Hello, World! Hello, Sky!");

	if (findFromTest.FindFrom(1, findHello) == 14)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "FindFrom() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "FindFrom() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Replace() ";

	String replaceTest(findFromTest);

	String replaceTester("Hi, World! Hi, Sky!");

	String replaceHello("Hello");

	String withHi("Hi");

	replaceTest.Replace(replaceHello, withHi);

	if (strcmp(replaceTest.CStr(), replaceTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "Replace() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "Replace() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ReadFromConsole() TEST" << std::endl;

	String readFromTest;

	String readFromTester;

	readFromTest.ReadFromConsole();

	if (strcmp(readFromTest.CStr(), readFromTester.CStr()) != 0)
	{
		std::cout << "ReadFromConsole() is functional." << std::endl;

		if (file.is_open())
		{
			file << "ReadFromConsole() is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "ReadFromConsole() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "ReadFromConsole() is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "WriteToConsole() TEST" << std::endl;

	std::cout << "WriteToConsole() is untested." << std::endl;

	if (file.is_open())
	{
		file << "WriteToConsole() is untested." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "== operator ";

	String isEqualsTest;

	String isEqualsTester(isEqualsTest);

	if (isEqualsTest == isEqualsTester)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "== operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "== operator is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "< OPERATOR ";

	String lessThanTest;

	String lessThanTester("Jello, World!");

	if (lessThanTest < lessThanTester)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "< operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "< operator is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "[] operator ";

	String indexTest;

	char atIndex = indexTest[0];

	if (atIndex == 'H')
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << " [] operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "[] operator is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "= operator ";

	String equalsOpTest;

	String equalsOpReplacer("Goodbye, World");

	String equalsOpTester(equalsOpTest);

	equalsOpTest = equalsOpReplacer;

	if (equalsOpTest.EqualTo(equalsOpTester) == false)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "= operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "= operator is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+ operator ";

	String addToOpTest("");	//	is empty

	String addToOpTester;

	String addOp1("Hello, ");

	String addOp2("World!");

	addToOpTest = addOp1 + addOp2;

	if (addToOpTest.EqualTo(addToOpTester) == true)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "+ operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "+ operator is not functional." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+= operator ";

	String addEqualsOpTest("Hello, ");

	String addEqualsOpTester;

	String addEqualsTo("World!");

	addEqualsOpTest += addEqualsTo;

	if (addEqualsOpTest.EqualTo(addEqualsOpTester) == true)
	{
		std::cout << "is functional." << std::endl;

		if (file.is_open())
		{
			file << "+= operator is functional." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "+= operator is not functional." << std::endl;
		}
	}

	file.close();

}