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

	
	std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
	
	String defaultCon;

	String defaultConTester("Hello, World!");

	if (strcmp(defaultCon.CStr(), defaultConTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;
		
		if (file.is_open())
		{
			file << "Test 00 FUNCTIONAL:	 Default Constructor" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 00 NOT FUNCTIONAL: Default Constructor" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CUSTOM CONSTRUCTOR" << std::endl;

	String customCon("Hello, World!");

	if (strcmp(customCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;
		
		if (file.is_open())
		{
			file << "Test 01 FUNCTIONAL:	 Custom Constructor" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 01 NOT FUNCTIONAL: Custom Constructor" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR" << std::endl;

	String copyCon(defaultCon);

	if (strcmp(copyCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 02 FUNCTIONAL:	 Copy Constructor" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 02 NOT FUNCTIONAL: Copy Constructor" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "DESTRUCTOR" << std::endl;

	std::cout << "UNTESTED" << std::endl;

	if (file.is_open())
	{
		file << "Test 03 UNTESTED:	 Destructor" << std::endl;
	}


	std::cout << std::endl;

	std::cout << "Length() FUNCTION" << std::endl;

	String lengthTest;

	if (lengthTest.Length() == 13)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 04 FUNCTIONAL:	 Length()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 04 NOT FUNCTIONAL: Length()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CharacterAt() FUNCTION" << std::endl;

	String characterAtTest;

	char charAt = characterAtTest.CharacterAt(0);

	if (charAt == 'H')
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 05 FUNCTIONAL:	 CharacterAt()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 05 NOT FUNCTIONAL: CharacterAt()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "EqualTo() FUNCTION" << std::endl;

	String equalToTest;

	String equalToTrue(equalToTest);

	String equalToFalse("false");

	if (equalToTest.EqualTo(equalToTrue) == true && equalToTest.EqualTo(equalToFalse) == false)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 06 FUNCTIONAL:	 EqualTo()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 06 NOT FUNCTIONAL: EqualTo()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Append() FUNCTION" << std::endl;

	String appendTest;

	String appender(" I am a string.");

	String appendTester("Hello, World! I am a string.");

	appendTest.Append(appender);

	if (strcmp(appendTest.CStr(), appendTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 07 FUNCTIONAL:	 Append()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 07 NOT FUNCTIONAL: Append()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Prepend() FUNCTION" << std::endl;

	String prependTest;

	String prependTester("Is anyone there? Hello, World!");

	String prepender("Is anyone there? ");

	prependTest.Prepend(prepender);

	if (strcmp(prependTest.CStr(), prependTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 08 FUNCTIONAL:	 Prepend()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 08 NOT FUNCTIONAL: Prepend()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "CStr() FUNCTION" << std::endl;

	std::cout << "UNTESTED" << std::endl;

	if (file.is_open())
	{
		file << "Test 09 UNTESTED:	 CStr()" << std::endl;
	}


	std::cout << std::endl;

	std::cout << "ToLower() FUNCTION" << std::endl;

	String toLowerTest;

	String toLowerTester("hello, world!");

	toLowerTest.ToLower();

	if (strcmp(toLowerTest.CStr(), toLowerTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;
		
		if (file.is_open())
		{
			file << "Test 10 FUNCTIONAL:	 ToLower()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 10 NOT FUNCTIONAL: ToLower()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ToUpper() FUNCTION" << std::endl;

	String toUpperTest;

	String toUpperTester("HELLO, WORLD!");

	toUpperTest.ToUpper();

	if (strcmp(toUpperTest.CStr(), toUpperTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 11 FUNCTIONAL:	 ToUpper()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 11 NOT FUNCTIONAL: ToUpper()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Find() FUNCTION" << std::endl;

	String findTest;

	String findHello("Hello");

	if (findTest.Find(findHello) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 12 FUNCTIONAL:	 Find()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 12 NOT FUNCTIONAL: Find()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "FindFrom() FUNCTION" << std::endl;

	String findFromTest("Hello, World! Hello, Sky!");

	if (findFromTest.FindFrom(1, findHello) == 14)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 13 FUNCTIONAL:	 FindFrom()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 13 NOT FUNCTIONAL: FindFrom()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "Replace() FUNCTION" << std::endl;

	String replaceTest(findFromTest);

	String replaceTester("Hi, World! Hi, Sky!");

	String replaceHello("Hello");

	String withHi("Hi");

	replaceTest.Replace(replaceHello, withHi);

	if (strcmp(replaceTest.CStr(), replaceTester.CStr()) == 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 14 FUNCTIONAL:	 Replace()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 14 NOT FUNCTIONAL: Replace()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "ReadFromConsole() FUNCTION" << std::endl;

	String readFromTest;

	String readFromTester;

	readFromTest.ReadFromConsole();

	if (strcmp(readFromTest.CStr(), readFromTester.CStr()) != 0)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 15 FUNCTIONAL:	 ReadFromConsole()" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 15 NOT FUNCTIONAL: ReadFromConsole()" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "WriteToConsole() FUNCTION" << std::endl;

	std::cout << "UNTESTED" << std::endl;

	if (file.is_open())
	{
		file << "Test 16 UNTESTED:	 WriteToConsole()" << std::endl;
	}


	std::cout << std::endl;

	std::cout << "== OPERATOR FUNCTION" << std::endl;

	String isEqualsTest;

	String isEqualsTester(isEqualsTest);

	if (isEqualsTest == isEqualsTester)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 17 FUNCTIONAL:	 == operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 17 NOT FUNCTIONAL: == operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "!= OPERATOR FUNCTION" << std::endl;

	String notEqualsTest;

	String notEqualsTester("notEquals");

	if (notEqualsTest != notEqualsTester)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 18 FUNCTIONAL:	 != operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 18 NOT FUNCTIONAL: != operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "< OPERATOR FUNCTION" << std::endl;

	String lessThanTest;

	String lessThanTester("Jello, World!");

	if (lessThanTest < lessThanTester)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 18 FUNCTIONAL:	 < operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 18 NOT FUNCTIONAL: < operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "[] OPERATOR FUNCTION" << std::endl;

	String indexTest;

	char atIndex = indexTest[0];

	if (atIndex == 'H')
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 19 FUNCTIONAL:	 [] operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 19 NOT FUNCTIONAL [] operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "= OPERATOR FUNCTION" << std::endl;

	String equalsOpTest;

	String equalsOpReplacer("Goodbye, World");

	String equalsOpTester(equalsOpTest);

	equalsOpTest = equalsOpReplacer;

	if (equalsOpTest.EqualTo(equalsOpTester) == false)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 20 FUNCTIONAL:	 = operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 20 NOT FUNCTIONAL: = operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+ OPERATOR FUNCTION" << std::endl;

	String addToOpTest("");	//	is empty

	String addToOpTester;

	String addOp1("Hello, ");

	String addOp2("World!");

	addToOpTest = addOp1 + addOp2;

	if (addToOpTest.EqualTo(addToOpTester) == true)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 21 FUNCTIONAL:	 + operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 21 NOT FUNCTIONAL: + operator" << std::endl;
		}
	}


	std::cout << std::endl;

	std::cout << "+= OPERATOR FUNCTION" << std::endl;

	String addEqualsOpTest("Hello, ");

	String addEqualsOpTester;

	String addEqualsTo("World!");

	addEqualsOpTest += addEqualsTo;

	if (addEqualsOpTest.EqualTo(addEqualsOpTester) == true)
	{
		std::cout << "FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 22 FUNCTIONAL:	 += operator" << std::endl;
		}
	}
	else
	{
		std::cout << "NOT FUNCTIONAL" << std::endl;

		if (file.is_open())
		{
			file << "Test 22 NOT FUNCTIONAL: += operator" << std::endl;
		}
	}

	file.close();

}