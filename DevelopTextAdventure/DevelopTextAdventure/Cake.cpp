#include "Cake.h"
#include "String.h"

Cake::Cake()
{
	m_desc = new String("It is a full cake...");

	m_cakeRemaining = 100;
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
		std::cout << "You use a random amount of cake. It feels like you've lost sight of something..." << std::endl;

		srand(time(NULL));

		int randomLoss = rand() % 40;

		m_cakeRemaining -= randomLoss;

		if (m_cakeRemaining < 0)
		{
			String* newDesc = new String("There is no cake...");

			delete m_desc;

			m_desc = newDesc;
		}
		else
		{
			String* newDesc = new String("It is not a full cake...");

			delete m_desc;

			m_desc = newDesc;
		}
	}
}
