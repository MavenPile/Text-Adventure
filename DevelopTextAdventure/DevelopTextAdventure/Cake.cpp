#include "Cake.h"
#include "String.h"
#include "Room.h"

Cake::Cake()
{
	m_desc = new String("It is a full cake...");

	m_cakeRemaining = 100;
}

Cake::Cake(Room* myRoom)
{
	m_desc = new String("It is a full cake...");

	m_cakeRemaining = 100;

	m_myRoom = myRoom;
}

Cake::~Cake()
{
	delete m_desc;
}

void Cake::Description() const
{
	m_desc->WriteToConsole();
}

void Cake::Use()
{
	if (m_cakeRemaining < 0)
	{
		std::cout << "There is nothing to use... " << std::endl;
	}
	else
	{
		std::cout << "You use the cake. You feel you've lost sight of what's important..." << std::endl;

		srand(time(NULL));

		int randomLoss = rand() % 100;

		m_cakeRemaining -= randomLoss;

		if (m_cakeRemaining < 0)
		{
			std::cout << "You've used all of the cake. There is no longer a cake..." << std::endl;
			
			String* newDesc = new String("There is no cake...");

			delete m_desc;

			m_desc = newDesc;

			String* myRoomDesc = new String("There is just a table...");

			m_myRoom->ChangeDesc(*myRoomDesc);
		}
		else
		{
			String* newDesc = new String("It is not a full cake...");

			delete m_desc;

			m_desc = newDesc;
		}
	}
}
