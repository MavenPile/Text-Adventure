#include "Game.h"
#include "Player.h"
#include "String.h"
#include "Room.h"
#include "Lamp.h"

Game::Game()
{
	m_command = new String();

	m_player = new Player(this);

	m_row = 5;

	m_col = 5;

	CreateMap();

	m_hasKey = false;

	m_keyGen = false;

	gameWin = false;
}

Game::~Game()
{
	delete m_command;
	
	delete m_player;

	for (int i = 0; i < 5; i++)
	{
		delete[] m_gameMap[i];	//	deallocates memory of each (sub-)array
	}

	delete[] m_gameMap;	//	deallocates memory of main array
}

void Game::CreateMap()
{
	//	generates a 2D array, or an array of arrays
	
	m_gameMap = new Room* [m_row];	//	allocating memory for an array of class pointers

	for (int row = 0; row < m_row; row++)
	{
		m_gameMap[row] = new Room[m_col];	//	allocating (sub-)arrays

		for (int col = 0; col < m_col; col++)
		{
			m_gameMap[row][col].Generate(this, row, col);	//	generates the room
		}
	}	//	can be accessed by gameMap[row][col]
}

void Game::PrintMap()
{	
	system("cls");

	std::cout << "---------------" << std::endl;

	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			std::cout << "|";

			if (row == m_posY && col == m_posX)
			{
				std::cout << "P";	//	prints player location
			}
			//else if (row == (m_row / 2) && col == (m_col / 2))
			//{
			//	std::cout << "E";	//	prints end location at centre-ish
			//}
			else
			{
				std::cout << "_";
			}

			std::cout << "|";
		}
		std::cout << std::endl;
	}

	std::cout << "---------------" << std::endl;
}

void Game::Run()
{
	while (gameWin == false)
	{
		PrintMap();	//	prints the map
		
		m_gameMap[m_posX][m_posY].Description();	//	outputs description of room

		std::cout << "What action would you like to take? (move/use/inspect/cast)" << std::endl;

		m_command->ReadFromConsole();	//	recieves input

		m_command->ToLower();	//	makes input consistent

		switch (m_command->CharacterAt(0))
		{
		case 'm':	//	move
			if (m_command->Find("move") != -1)
			{
				if (m_command->Find("north") != -1)
				{
					m_TryMove('n');
				}
				else if (m_command->Find("south") != -1)
				{
					m_TryMove('s');
				}
				else if (m_command->Find("east") != -1)
				{
					m_TryMove('e');
				}
				else if (m_command->Find("west") != -1)
				{
					m_TryMove('w');
				}
				else
				{
					std::cout << "That isn't a direction to move..." << std::endl;
				}
			}
			break;
		case 'u':	//	use
			if (m_command->Find("use") != -1)
			{

			}
			break;
		case 'i':	//	inspect
			if (m_command->Find("inspect") != -1)
			{

			}
			break;
		case 'c':	//	cast
			if (m_command->Find("cast") != -1)
			{

			}
			break;
		default:
			std::cout << "Couldn't determine what you wanted to do..." << std::endl;
			break;
		}

		system("pause");
	}


}

void Game::Move()
{

}

void Game::KeyGen()
{
	m_keyGen = true;
}

bool Game::HasKey()
{
	if (m_hasKey == true)
	{
		return true;
	}
	return false;
}

void Game::GetKey()
{
	m_hasKey = true;
}

void Game::GameWin()
{
	gameWin = true;
}

void Game::m_TryMove(char c)
{
	switch (c)
	{
	case 'n':	//	North
		if (m_posY == 0)
		{
			std::cout << "You found no Northern paths..." << std::endl;
			break;
		}

		m_posY--;

		std::cout << "You moved North..." << std::endl;

		break;
	case 's':	//	South
		if (m_posY == (m_col - 1))
		{
			std::cout << "You found no Southern paths..." << std::endl;
			break;
		}

		m_posY++;

		std::cout << "You moved South..." << std::endl;

		break;
	case 'e':	//	East
		if (m_posX == (m_row - 1))
		{
			std::cout << "You found no Eastern paths..." << std::endl;
			break;
		}

		m_posX++;

		std::cout << "You moved East..." << std::endl;

		break;
	case 'w':	//	West
		if (m_posX == 0)
		{
			std::cout << "You found no Western paths..." << std::endl;
			break;
		}

		m_posX--;

		std::cout << "You moved West..." << std::endl;

		break;
	default:
		break;
	}
}

void Game::m_TryUse(char c)
{
	switch (c)
	{
	case 'l':
	{
		Lamp* lamp = dynamic_cast<Lamp*>(m_gameMap[m_posX][m_posY].item);
		if (lamp != nullptr)
		{
			lamp->Use();
		}
		else
		{
			std::cout << "That didn't seem to be in the room to use..." << std::endl;
		}
		break;
	}

	}
}

void Game::m_TryInspect()
{

}

void Game::m_TryCast()
{

}