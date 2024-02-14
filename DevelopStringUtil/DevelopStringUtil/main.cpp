#include <iostream>
#include "String.h"

int main()
{
	String string1("string a super");

	String string2("string");

	String string3("sentance");

	int index;

	string1.Replace(string2, string3);

	std::cout << string1.CStr() << std::endl;

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