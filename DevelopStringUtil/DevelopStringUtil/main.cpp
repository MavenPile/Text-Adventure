#include <iostream>
#include "String.h"

int main()
{
	String string1;

	String string2("Is anyone there? ");

	string1.Prepend(string2);

	string1.WriteToConsole();
}