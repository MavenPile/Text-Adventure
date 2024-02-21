#include <iostream>
#include "String.h"

int main()
{
	std::cout << "Default Constructor ";
	
	String defaultCon;

	String defaultConTester("Hello, World!");

	if (strcmp(defaultCon.CStr(), defaultConTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();


	std::cout << std::endl;

	std::cout << "Custom Constructor ";

	String customCon("Hello, World!");

	if (strcmp(customCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//String stringCustom(" I am alive!");

	//stringCustom.WriteToConsole();


	std::cout << std::endl;

	std::cout << "Copy Constructor ";

	String copyCon(defaultCon);

	if (strcmp(copyCon.CStr(), defaultCon.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//String stringCopy(stringCustom);

	//stringCopy.WriteToConsole();



	std::cout << std::endl;

	std::cout << "Length() ";

	String lengthTest;

	if (lengthTest.Length() == 13)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringCopy.WriteToConsole();

	//int stringCopyLength = stringCopy.Length();

	//std::cout << "Length() output: " << stringCopyLength << std::endl;


	std::cout << std::endl;

	std::cout << "CharacterAt() ";

	String characterAtTest;

	char charAt = characterAtTest.CharacterAt(0);

	if (charAt == 'H')
	{
		std::cout << "is functional" << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}


	//stringCopy.WriteToConsole();

	//char stringCopyCharAt1 = stringCopy.CharacterAt(3);
	//char stringCopyCharAt2 = stringCopy.CharacterAt(20);

	//std::cout << "CharacterAt(3) output: " << stringCopyCharAt1 << std::endl;
	//std::cout << "CharacterAt(20) output: " << stringCopyCharAt2 << std::endl;


	std::cout << std::endl;

	std::cout << "EqualTo() ";

	String equalToTest;

	String equalToTrue(equalToTest);

	String equalToFalse("false");

	if (equalToTest.EqualTo(equalToTrue) == true && equalToTest.EqualTo(equalToFalse) == false)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringCopy.WriteToConsole();

	//stringCustom.WriteToConsole();

	//bool copyMatchCustom = stringCopy.EqualTo(stringCustom);

	//std::cout << "stringCopy equals stringCustom = " << copyMatchCustom << std::endl;


	std::cout << std::endl;

	std::cout << "Append() ";

	String appendTest;

	String appender(" I am a string.");

	String appendTester("Hello, World! I am a string.");

	appendTest.Append(appender);

	if (strcmp(appendTest.CStr(), appendTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//stringCopy.WriteToConsole();

	//stringDefault.Append(stringCopy);

	//std::cout << "stringDefault.Append(stringCopy): " << stringDefault.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "Prepend() ";

	String prependTest;

	String prependTester("Is anyone there? Hello, World!");

	String prepender("Is anyone there? ");

	prependTest.Prepend(prepender);

	if (strcmp(prependTest.CStr(), prependTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//String stringPrepend("Is anyone there? ");

	//stringPrepend.WriteToConsole();

	//stringDefault.Prepend(stringPrepend);

	//std::cout << "stringDefault.Append(stringPrepend): " << stringDefault.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "CStr() is functional." << std::endl;

	//std::cout << "Returns member array, not directly to console: " << stringDefault.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "ToLower() ";

	String toLowerTest;

	String toLowerTester("hello, world!");

	toLowerTest.ToLower();

	if (strcmp(toLowerTest.CStr(), toLowerTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//stringDefault.ToLower();

	//stringDefault.WriteToConsole();


	std::cout << std::endl;

	std::cout << "ToUpper() ";

	String toUpperTest;

	String toUpperTester("HELLO, WORLD!");

	toUpperTest.ToUpper();

	if (strcmp(toUpperTest.CStr(), toUpperTester.CStr()) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();
	//
	//stringDefault.ToUpper();

	//stringDefault.WriteToConsole();


	std::cout << std::endl;

	std::cout << "Find() ";

	String findTest;

	String findHello("Hello");

	if (findTest.Find(findHello) == 0)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//String findString1("WORLD");
	//String findString2("world");

	//findString1.WriteToConsole();
	//findString2.WriteToConsole();

	//std::cout << "Index of 'WORLD': " << stringDefault.Find(findString1) << std::endl;
	//std::cout << "Index of 'world': " << stringDefault.Find(findString2) << std::endl;


	std::cout << std::endl;

	std::cout << "FindFrom() ";

	String findFromTest("Hello, World! Hello, Sky!");

	if (findFromTest.FindFrom(1, findHello) == 14)
	{
		std::cout << "is functional." << std::endl;
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//findString1.WriteToConsole();

	//std::cout << "Index of 'WORLD', from 10: " << stringDefault.FindFrom(10, findString1) << std::endl;
	//std::cout << "Index of 'WORLD', from 25: " << stringDefault.FindFrom(25, findString1) << std::endl;


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
	}
	else
	{
		std::cout << "is not functional." << std::endl;
	}

	//stringDefault.WriteToConsole();

	//String replaceString("[[living world]]");

	//replaceString.WriteToConsole();

	//findString1.WriteToConsole();

	//stringDefault.Replace(findString1, replaceString);

	//std::cout << "Replace 'WORLD' with '[[living world]]': " << stringDefault.CStr() << std::endl;

	//String anotherAppendString(" Why am I not in the [[living world]]");

	//stringDefault.Append(anotherAppendString);

	//stringDefault.WriteToConsole();

	//stringDefault.Replace(replaceString, findString1);

	//std::cout << "Replace '[[living world]]' with 'WORLD': " << stringDefault.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "ReadFromConsole() TEST" << std::endl;

	String readFromTest;

	String readFromTester;

	readFromTest.ReadFromConsole();

	if (strcmp(readFromTest.CStr(), readFromTester.CStr()) != 0)
	{
		std::cout << "ReadFromConsole() is functional." << std::endl;
	}
	else
	{
		std::cout << "ReadFromConsole() is not functional." << std::endl;
	}


	//std::cout << "Please input a string (max char 64): ";

	//String readString;

	//readString.ReadFromConsole();

	//readString.WriteToConsole();


	std::cout << std::endl;

	std::cout << "WriteToConsole() TEST" << std::endl;

	String writeToTest;

	writeToTest.WriteToConsole();

	std::cout << "WriteToConsole() is functional." << std::endl;

	//String stringNew1("Yes! Someone is here!");

	//stringNew1.WriteToConsole();


	std::cout << std::endl;

	std::cout << "== OPERATOR" << std::endl;



	//stringNew1.WriteToConsole();

	//String stringNew2("Can you save me?");

	//stringNew2.WriteToConsole();


	//stringNew1.EqualTo(stringNew2);
	//stringNew1 == stringNew2;


	//if (stringNew1 == stringNew2)
	//{
	//	std::cout << "The strings are the same" << std::endl;
	//}
	//else
	//{
	//	std::cout << "The strings are not the same" << std::endl;
	//}


	std::cout << std::endl;

	std::cout << "< OPERATOR" << std::endl;

	//stringNew1.WriteToConsole();

	//stringNew2.WriteToConsole();

	//if (stringNew1 < stringNew2)
	//{
	//	std::cout << "The second string comes first" << std::endl;
	//}
	//else
	//{
	//	std::cout << "The first string comes first" << std::endl;
	//}


	std::cout << std::endl;

	std::cout << "[] OPERATOR" << std::endl;

	//String stringNew3("Hello? Can you hear me?");

	//stringNew3.WriteToConsole();

	//std::cout << "The string at index 7 is: " << stringNew3[7] << std::endl;


	std::cout << std::endl;

	std::cout << "= OPERATOR" << std::endl;

	//String stringNew4("Why aren't you responding anymore?");

	//stringNew3.WriteToConsole();

	//stringNew4.WriteToConsole();

	//stringNew3 = stringNew4;

	//std::cout << "String 3 is now: " << stringNew3.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "+ OPERATOR" << std::endl;

	//stringNew4.WriteToConsole();

	//String stringNew5("It's so dark.");

	//stringNew5.WriteToConsole();

	//String stringNew6(" It's so cold.");

	//stringNew6.WriteToConsole();

	//stringNew4 = (stringNew5 + stringNew6);

	//std::cout << "The new string is: " << stringNew4.CStr() << std::endl;


	std::cout << std::endl;

	std::cout << "+= OPERATOR" << std::endl;

	//String stringNew7("Goodbye");

	//String stringNew8(", then.");

	//stringNew7.WriteToConsole();

	//stringNew8.WriteToConsole();

	//stringNew7 += stringNew8;

	//std::cout << "The new string is: " << stringNew7.CStr() << std::endl;

}