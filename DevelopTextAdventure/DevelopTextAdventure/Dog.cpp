#include "Dog.h"
#include "String.h"
#include "Game.h"
#include "Room.h"

Dog::Dog()
{
	isDog = true;

	hasKey = true;

	m_desc = new String("It's a dog...");
}

Dog::Dog(Game* myGame, Room* myRoom)
{
	isDog = true;

	hasKey = true;

	m_desc = new String("It's a dog...");

	m_myGame = myGame;

	m_myRoom = myRoom;
}

Dog::~Dog()
{
	delete m_desc;
}

void Dog::Description() const
{
	m_desc->WriteToConsole();
}

void Dog::Use()
{
	if (hasKey == false)
	{
		std::cout << "You use it, nothing happens..." << std::endl;
	}
	else if (isDog == false)
	{
		std::cout << "It's no longer a dog... Using it gave you a key..." << std::endl;
		
		hasKey = false;

		m_myGame->GetKey();
	}
	else
	{
		std::cout << "You use the dog... Something isn't right..." << std::endl;
		isDog = false;

		String* newDesc = new String("It looks like a dog...");

		delete m_desc;

		m_desc = newDesc;

		String* newRoomDesc = new String("What looks like a dog smiles at you from the centre of the room...");

		m_myRoom->ChangeDesc(*newRoomDesc);
	}
}
