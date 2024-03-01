#include "Game.h"
#include "Player.h"
#include "String.h"

Game::Game()
{
	m_command = new String();

	m_player = new Player();

	CreateMap();

	hasKey = false;
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

void Game::Run()
{
	bool gaming = true;

	String command;

	while (gaming)
	{
		PrintMap();
		
		std::cout << "Where would you like to go? " << std::endl;

		command.ReadFromConsole();

		command.ToLower();

		if (command.EqualTo("move north") == true)
		{
			//player->Move('n');	//	same as (*player).MoveNorth();
				//	dereferences player pointer, and accesses class function
		}
		if (command.EqualTo("move east") == true)
		{
			//player->Move('e');
		}
		if (command.EqualTo("move south") == true)
		{
			//player->Move('s');
		}
		if (command.EqualTo("move west") == true)
		{
			//player->Move('w');
		}


		system("cls");

	}
}

void Game::PrintMap()
{	
	system("cls");

	std::cout << "------------" << std::endl;

	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			std::cout << "| ";

			//if (row == m_player->GetPosY() && col == m_player->GetPosX())
			//{
			//	std::cout << "P";	//	prints player location
			//}
			//else if (row == (m_row / 2) && col == (m_col / 2))
			//{
			//	std::cout << "E";	//	prints end location at centre-ish
			//}
			//else
			//{
			//	std::cout << "_";
			//}

			std::cout << " |";
		}
	}

	std::cout << "------------" << std::endl;
}

int* Game::GetPlayerRoom()
{
	return nullptr;
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
			m_gameMap[row][col].Generate();	//	generates the room
		}
	}	//	can be accessed by gameMap[row][col]


	//	A challenge

	bool is3D = false;

	if (is3D == true)
	{
		m_gameMap3D = new Room** [m_row];

		for (int row = 0; row < m_row; row++)
		{
			m_gameMap3D[row] = new Room* [m_col];

			for (int col = 0; col < m_col; col++)
			{
				m_gameMap3D[row][col] = new Room[m_dep];

			}	//	accessed with gameMap3D[row][col][dep]
		}
	}


	//	Another challenge

	bool is4D = false;

	if (is4D == true)
	{
		m_gameMap4D = new Room*** [m_row];

		for (int row = 0; row < m_row; row++)
		{
			m_gameMap4D[row] = new Room** [m_col];

			for (int col = 0; col < m_col; col++)
			{
				m_gameMap4D[row][col] = new Room* [m_dep];

				for (int godKnows = 0; godKnows < m_dep; godKnows++)
				{
					m_gameMap4D[row][col][godKnows] = new Room[m_godKnows];

				}	//	accessed with gameMap4D[row][col][dep][godKnows]
			}
		}
	}
}

void Game::GetKey()
{
	hasKey = true;
}