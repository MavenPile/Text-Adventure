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

	
	std::cout << "DEFAULT CONSTRUCTOR";
	
	String defaultCon;

	String defaultConTester("Hello, World!");

	file << "Test 00 ";

	if (strcmp(defaultCon.CStr(), defaultConTester.CStr()) == 0)
	{
		std::cout << "Default Constructor is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "FUNCTIONAL: Default Constructor." << std::endl;
		}
	}
	else
	{
		std::cout << "Default Constructor is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Default Constructor." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CUSTOM CONSTRUCTOR";

	String customCon("Hello, World!");

	file << "Test 01 ";


	if (strcmp(customCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "Custom Constructor is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "FUNCTIONAL: Custom Constructor." << std::endl;
		}
	}
	else
	{
		std::cout << "Custom Constructor is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Custom Constructor." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR" << std::endl;

	String copyCon(defaultCon);

	file << "Test 02 ";

	if (strcmp(copyCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "Copy Constructor is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Copy Constructor." << std::endl;
		}
	}
	else
	{
		std::cout << "is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Copy Constructor." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "DESTRUCTOR" << std::endl;

	std::cout << "Destructor is untested." << std::endl;

	file << "Test 03 ";

	if (file.is_open())
	{
		file << "UNTESTED: Destructor." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "Length()";

	String lengthTest;

	file << "Test 04 ";

	if (lengthTest.Length() == 13)
	{
		std::cout << "Length() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Length()." << std::endl;
		}
	}
	else
	{
		std::cout << "Length() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Length()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CharacterAt()";

	String characterAtTest;

	char charAt = characterAtTest.CharacterAt(0);

	file << "Test 05 ";

	if (charAt == 'H')
	{
		std::cout << "CharacterAt() is functional" << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: CharacterAt()." << std::endl;
		}
	}
	else
	{
		std::cout << "CharacterAt() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: CharacterAt()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "EqualTo()";

	String equalToTest;

	String equalToTrue(equalToTest);

	String equalToFalse("false");

	file << "Test 06 ";

	if (equalToTest.EqualTo(equalToTrue) == true && equalToTest.EqualTo(equalToFalse) == false)
	{
		std::cout << "EqualTo() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: EqualTo()." << std::endl;
		}
	}
	else
	{
		std::cout << "EqualTo() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: EqualTo()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Append()";

	String appendTest;

	String appender(" I am a string.");

	String appendTester("Hello, World! I am a string.");

	appendTest.Append(appender);

	file << "Test 07 ";

	if (strcmp(appendTest.CStr(), appendTester.CStr()) == 0)
	{
		std::cout << "Append() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Append()." << std::endl;
		}
	}
	else
	{
		std::cout << "Append() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Append()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Prepend()";

	String prependTest;

	String prependTester("Is anyone there? Hello, World!");

	String prepender("Is anyone there? ");

	prependTest.Prepend(prepender);

	file << "Test 08 ";

	if (strcmp(prependTest.CStr(), prependTester.CStr()) == 0)
	{
		std::cout << "Prepend() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Prepend()." << std::endl;
		}
	}
	else
	{
		std::cout << "Prepend() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Prepend()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CStr() is untested." << std::endl;

	file << "Test 09 ";

	if (file.is_open())
	{
		file << "UNTESTED: CStr()." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "ToLower()";

	String toLowerTest;

	String toLowerTester("hello, world!");

	toLowerTest.ToLower();

	file << "Test 10 ";

	if (strcmp(toLowerTest.CStr(), toLowerTester.CStr()) == 0)
	{
		std::cout << "ToLower() is functional." << std::endl;
		
		if (file.is_open())
		{
			file << "FUNCTIONAL: ToLower()." << std::endl;
		}
	}
	else
	{
		std::cout << "ToLower() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: ToLower()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ToUpper()";

	String toUpperTest;

	String toUpperTester("HELLO, WORLD!");

	toUpperTest.ToUpper();

	file << "Test 11 ";

	if (strcmp(toUpperTest.CStr(), toUpperTester.CStr()) == 0)
	{
		std::cout << "ToUpper() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: ToUpper()." << std::endl;
		}
	}
	else
	{
		std::cout << "ToUpper() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: ToUpper()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Find()";

	String findTest;

	String findHello("Hello");

	file << "Test 12 ";

	if (findTest.Find(findHello) == 0)
	{
		std::cout << "Find() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Find()." << std::endl;
		}
	}
	else
	{
		std::cout << "Find() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Find()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "FindFrom()";

	String findFromTest("Hello, World! Hello, Sky!");

	file << "Test 13 ";

	if (findFromTest.FindFrom(1, findHello) == 14)
	{
		std::cout << "FindFrom() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: FindFrom()." << std::endl;
		}
	}
	else
	{
		std::cout << "FindFrom() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: FindFrom()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Replace()";

	String replaceTest(findFromTest);

	String replaceTester("Hi, World! Hi, Sky!");

	String replaceHello("Hello");

	String withHi("Hi");

	replaceTest.Replace(replaceHello, withHi);

	file << "Test 14 ";

	if (strcmp(replaceTest.CStr(), replaceTester.CStr()) == 0)
	{
		std::cout << "Replace() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: Replace()." << std::endl;
		}
	}
	else
	{
		std::cout << "Replace() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: Replace()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ReadFromConsole() TEST" << std::endl;

	String readFromTest;

	String readFromTester;

	readFromTest.ReadFromConsole();

	file << "Test 15 ";

	if (strcmp(readFromTest.CStr(), readFromTester.CStr()) != 0)
	{
		std::cout << "ReadFromConsole() is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: ReadFromConsole()." << std::endl;
		}
	}
	else
	{
		std::cout << "ReadFromConsole() is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: ReadFromConsole()." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "WriteToConsole() TEST" << std::endl;

	std::cout << "WriteToConsole() is untested." << std::endl;

	file << "Test 16 ";

	if (file.is_open())
	{
		file << "UNTESTED: WriteToConsole()." << std::endl;
	}


	std::cout << std::endl;

	std::cout << "== operator";

	String isEqualsTest;

	String isEqualsTester(isEqualsTest);

	file << "Test 17 ";

	if (isEqualsTest == isEqualsTester)
	{
		std::cout << "== operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: == operator." << std::endl;
		}
	}
	else
	{
		std::cout << "== operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: == operator." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "< OPERATOR";

	String lessThanTest;

	String lessThanTester("Jello, World!");

	file << "Test 18 ";

	if (lessThanTest < lessThanTester)
	{
		std::cout << "< operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: < operator." << std::endl;
		}
	}
	else
	{
		std::cout << "< operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: < operator." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "[] operator";

	String indexTest;

	char atIndex = indexTest[0];

	file << "Test 19 ";

	if (atIndex == 'H')
	{
		std::cout << "[] operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: [] operator." << std::endl;
		}
	}
	else
	{
		std::cout << "[] operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL [] operator." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "= operator";

	String equalsOpTest;

	String equalsOpReplacer("Goodbye, World");

	String equalsOpTester(equalsOpTest);

	equalsOpTest = equalsOpReplacer;

	file << "Test 20 ";

	if (equalsOpTest.EqualTo(equalsOpTester) == false)
	{
		std::cout << "= operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: = operator." << std::endl;
		}
	}
	else
	{
		std::cout << "= operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: = operator." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+ operator";

	String addToOpTest("");	//	is empty

	String addToOpTester;

	String addOp1("Hello, ");

	String addOp2("World!");

	addToOpTest = addOp1 + addOp2;

	file << "Test 21 ";

	if (addToOpTest.EqualTo(addToOpTester) == true)
	{
		std::cout << "+ operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: + operator." << std::endl;
		}
	}
	else
	{
		std::cout << "+ operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: + operator." << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+= operator";

	String addEqualsOpTest("Hello, ");

	String addEqualsOpTester;

	String addEqualsTo("World!");

	addEqualsOpTest += addEqualsTo;

	file << "Test 22 ";

	if (addEqualsOpTest.EqualTo(addEqualsOpTester) == true)
	{
		std::cout << "+= operator is functional." << std::endl;

		if (file.is_open())
		{
			file << "FUNCTIONAL: += operator." << std::endl;
		}
	}
	else
	{
		std::cout << "+= operator is not functional." << std::endl;

		if (file.is_open())
		{
			file << "NOT FUNCTIONAL: += operator." << std::endl;
		}
	}

	file.close();

}