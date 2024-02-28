#include "Key.h"
#include <iostream>

Key::Key()
{
	name = "Key";

	desc = "A key. You don't know where to use it.";
}

//Key::~Key()
//{
//
//}

String Key::GetName()
{
	return name;
}

String Key::Description()
{
	return desc;
}

void Key::Use()
{
	//if (player.GetCurrentRoom())
	//{

	//}
	//else
	//{
	//	std::cout << "Key cannot be used here." << std::endl;
	//}
}