#include "Lamp.h"
#include "String.h"

Lamp::Lamp()
{
	m_isOn = false;

	m_desc = new String("It's a lamp, it's not on...");
}

Lamp::~Lamp()
{
	delete m_desc;
}

void Lamp::Description() const
{
	m_desc->WriteToConsole();
}

void Lamp::Use()
{
	std::cout << "You flick the switch on the lamp...";
	m_isOn = !m_isOn;

	if (m_isOn == true)
	{
		String* newDesc = new String("It's a lamp, it is on!");

		delete m_desc;

		m_desc = newDesc;
	}
	else
	{
		String* newDesc = new String("It's a lamp, it's not on...");

		delete m_desc;

		m_desc = newDesc;
	}
}