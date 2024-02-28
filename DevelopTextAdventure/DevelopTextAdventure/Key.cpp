#include "Key.h"
#include <iostream>

Key::Key()
{
	name = new char[4] {"Key"};

	desc = new char[7] {"A key."};
}

Key::~Key()
{
	delete[] name;

	delete[] desc;
}

const char* Key::GetCharName()
{
	return name;
}

const char* Key::Description()
{
	return desc;
}

void Key::Use()
{
	if (player.GetCurrentRoom())
	{

	}
	else
	{
		std::cout << "Key cannot be used here." << std::endl;
	}
}