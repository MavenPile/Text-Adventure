#include "Door.h"
#include "Game.h"
#include <iostream>
#include "String.h"

Door::Door()
{
	m_desc = new String("It's a door with a lock...");
}

Door::Door(Game* myGame)
{
	m_desc = new String("It's a door with a lock...");

	m_myGame = myGame;
}

Door::~Door()
{
	delete m_desc;
}

void Door::Description() const
{
	m_desc->WriteToConsole();
}

void Door::Use()
{
	if (m_myGame->HasKey() == true)
	{
		std::cout << "You insert the key into the door..." << std::endl;

		m_myGame->WinGame();
	}
	else
	{
		std::cout << "The door appears to be locked..." << std::endl;
	}
}
