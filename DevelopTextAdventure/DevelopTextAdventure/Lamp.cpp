#include "Lamp.h"
#include "String.h"
#include "Room.h"

Lamp::Lamp()
{
	m_isOn = false;

	m_desc = new String("It's a lamp, it's not on...");
}

Lamp::Lamp(Room* myRoom)
{
	m_isOn = false;

	m_desc = new String("It's a lamp, it's not on...");

	m_myRoom = myRoom;
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
	std::cout << "You flick the switch on the lamp..." << std::endl;
	m_isOn = !m_isOn;

	if (m_isOn == true)
	{
		String* newDesc = new String("It's a lamp, it is on...");

		delete m_desc;

		m_desc = newDesc;

		String* newRoomDesc = new String("The lamp illuminates an etching of a key within what looks like a dog...");

		m_myRoom->ChangeDesc(*newRoomDesc);
	}
	else
	{
		String* newDesc = new String("It's a lamp, it's not on...");

		delete m_desc;

		m_desc = newDesc;

		String* newRoomDesc = new String("The room is dark. But, there is a lamp...");

		m_myRoom->ChangeDesc(*newRoomDesc);
	}
}