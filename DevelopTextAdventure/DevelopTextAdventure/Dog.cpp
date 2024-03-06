#include "Dog.h"
#include "String.h"
#include "Game.h"

Dog::Dog()
{
	isDog = true;

	hasKey = true;

	m_desc = new String("It's a dog...");
}

Dog::Dog(Game* myGame)
{
	isDog = true;

	hasKey = true;

	m_desc = new String("It's a dog...");

	m_myGame = myGame;
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
		std::cout << "It's a dog that is no longer a dog... Using it gave you a key..." << std::endl;
		
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
	}
}
