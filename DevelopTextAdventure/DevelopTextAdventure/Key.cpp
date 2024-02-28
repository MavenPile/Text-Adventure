#include "Key.h"
#include <iostream>

Key::Key()
{
	name = new char[4] {"Key"};

	desc = new char[7] {"A key."};
}

Key::Key(const char* newName, const char* newDesc)
{
	name = new char[strlen(newName) + 1];

	strcpy_s(name, strlen(newName) + 1, newName);

	desc = new char[strlen(newDesc) + 1];

	strcpy_s(desc, strlen(newDesc) + 1, newDesc);
}

Key::~Key()
{
	delete[] name;

	delete[] desc;
}

const char* Key::GetName()
{
	return name;
}

const char* Key::Description()
{
	return desc;
}