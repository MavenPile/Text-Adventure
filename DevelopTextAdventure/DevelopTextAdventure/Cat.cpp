#include "Cat.h"
#include "String.h"

Cat::Cat()
{
	m_purring = false;
	
	m_desc = new String("It's a cat, wandering around the room...");
}

Cat::~Cat()
{
	delete m_desc;
}

void Cat::Description() const
{
	m_desc->WriteToConsole();
}

void Cat::Use()
{
	std::cout << "You use the cat, it might be happy about this...";

	m_purring = !m_purring;

	if (m_purring == true)
	{
		String* newDesc = new String("It's a cat, it's purring...");

		delete m_desc;

		m_desc = newDesc;
	}
	else
	{
		String* newDesc = new String("It's a cat, wandering around the room...");

		delete m_desc;

		m_desc = newDesc;
	}
}
