#include "Skeleton.h"
#include <iostream>
#include "Player.h"

Skeleton::Skeleton()
{
	m_armLeft = true;

	m_armRight = true;

	m_legLeft = true;

	m_legRight = true;

	m_desc = new String("It's a skeleton, it's standing up but has no weapon");

}

Skeleton::Skeleton(Player* player)
{
	m_player = player;

	m_armLeft = true;

	m_armRight = true;

	m_legLeft = true;

	m_legRight = true;

	m_canAttack = true;

	m_desc = new String("It's a skeleton, it's standing up but has no weapon...");
}

Skeleton::~Skeleton()
{
	delete m_desc;
}

void Skeleton::TakeDamage(int dmg)
{
	if (m_armRight == true)
	{
		std::cout << "You attack the skeleton, taking off its right arm..." << std::endl;
		m_armRight = false;

		String* newDesc = new String("The skeleton is standing straight, missing it's right arm...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_armLeft == true)
	{
		std::cout << "The skeleton guards you attack with its left arm, losing it..." << std::endl;
		m_armLeft = false;

		String* newDesc = new String("The skeleton still stands, with no arms...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_legRight == true)
	{
		std::cout << "The skeleton leaps back to dodge, and loses it's right leg..." << std::endl;
		m_legRight = false;

		String* newDesc = new String("The skeleton has a mean lean, missing it's arms and right leg...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_legLeft == true)
	{
		std::cout << "With all your might, you attack the skeleton, scattering it across the floor..." << std::endl;
		m_legLeft = false;

		String* newDesc = new String("The skeleton is scattered across the floor...");
		delete m_desc;
		m_desc = newDesc;
	}
	else
	{
		std::cout << "The skeleton can't be attacked anymore..." << std::endl;
	}

	DealDamage();
}

void Skeleton::DealDamage()
{
	if (m_armRight == true)
	{
		std::cout << "The skeleton swings at you, it loses it's right arm..." << std::endl;
		m_armRight = false;

		String* newDesc = new String("The skeleton is standing straight, missing it's right arm...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_armLeft == true)
	{
		std::cout << "The skeleton staggers as it swings with its left arm, losing it..." << std::endl;
		m_armLeft = false;

		String* newDesc = new String("The skeleton still stands, with no arms...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_legRight == true)
	{
		std::cout << "The skeleton attempts to kick you, and loses it's right leg..." << std::endl;
		m_legRight = false;

		String* newDesc = new String("The skeleton has a mean lean, missing it's arms and right leg...");
		delete m_desc;
		m_desc = newDesc;
	}
	else if (m_legLeft == true)
	{
		std::cout << "With all it's might, the skeleton lunges at you... Scattering on impact..." << std::endl;
		std::cout << "The skeleton will no longer attack you..." << std::endl;
		m_legLeft = false;

		String* newDesc = new String("The skeleton is scattered across the floor...");
		delete m_desc;
		m_desc = newDesc;
	}
}

void Skeleton::Description()
{
	m_desc->WriteToConsole();

	DealDamage();
}
