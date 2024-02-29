#include "Key.h"

Key::Key()
{
	name = "Key";

	desc = "A key. You don't know where to use it.";
}

Key::Key(Game* currentGame)
{
	name = "Key";

	desc = "A key. You don't know where to use it.";

	game = currentGame;
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
	if (game.GetPlayerRoom() == nullptr)
	{

	}
	else
	{
		std::cout << "Key cannot be used here." << std::endl;
	}
}