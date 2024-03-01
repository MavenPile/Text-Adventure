#include "Key.h"

Key::Key()
{
	desc = new String("It's a key.");
}

Key::~Key()
{
	delete desc;
}

String* Key::Description() const
{
	return desc;
}

void Key::Use()
{
	//if (game.GetPlayerRoom() == nullptr)
	//{

	//}
	//else
	//{
	//	std::cout << "Key cannot be used here." << std::endl;
	//}
}