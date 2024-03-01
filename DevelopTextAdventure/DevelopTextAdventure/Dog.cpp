#include "Dog.h"

Dog::Dog()
{
	isDog = true;

	desc = new String("It's a dog...");
}

Dog::~Dog()
{
	delete desc;
}

String* Dog::Description() const
{
	return desc;
}

void Dog::Use()
{
	if (isDog == false)
	{
		std::cout << "It's a dog that is no longer a dog... It gave you a key..." << std::endl;
		
		m_player.GetKey();
	}
	else
	{
		std::cout << "You use the dog... Something isn't right..." << std::endl;
		isDog = false;

		String* newDesc = new String("It looks like a dog...");

		delete desc;

		desc = newDesc;
	}
}
