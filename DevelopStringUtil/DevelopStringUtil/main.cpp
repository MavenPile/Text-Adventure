#include <iostream>
#include "String.h"

int main()
{
	String string1("one");
	String string2(" plus two");
	String string3(" equals three!");

	string3 = (string1 + string2);

	string3.WriteToConsole();
	
	
	//String string1("one");
	//String string3;

	//string3 = string1;

	//std::cout << string3.CStr() << std::endl;
	
	//String string1("a stringstring with string in it twice");

	//String string2("string");

	//String string3("sentence");

	//int index;

	//string1.Replace(string2, string3);

	//std::cout << string1.CStr() << std::endl;

	/*string1.ToUpper();

	string1.WriteToConsole();*/

	//if (string1 < string2)
	//{
	//	std::cout << "string1 is less than string2!" << std::endl;
	//}
	//else
	//{
	//	std::cout << "string1 is not less than string2!" << std::endl;
	//}

	//std::cout << "The 2nd char of string1 is: " << string1[1] << std::endl;
}