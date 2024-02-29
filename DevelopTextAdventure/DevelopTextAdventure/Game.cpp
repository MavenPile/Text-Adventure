#include "Game.h"

Game::Game()
{
	player = new Player(this);
}

Game::~Game()
{
	delete[] player;
}

void Game::Run()
{
	bool gaming = true;

	while (gaming)
	{

	}
}

void Game::PrintMap()
{	
	int mapIndex = 1;

	int playerRoom = 1;
	
	for (int row = 0; row < 5; row++)
	{
		std::cout << "|";

		for (int col = 0; col < 5; col++)
		{
			gameMap[row][col] = mapIndex;

			if (mapIndex == playerRoom)
			{
				std::cout << "##";
			}
			else if (mapIndex < 10)
			{
				std::cout << "0" << gameMap[row][col];
			}
			else
			{
				std::cout << gameMap[row][col];
			}

			std::cout << "|";

			mapIndex++;

			if (col == 4)
			{
				std::cout << std::endl;
			}
		}
	}
}

int* Game::GetPlayerRoom()
{
	return nullptr;
}

//void Game::CreateMap()
//{
//	int* rows = new int[5];
//
//	for (int i = 0; i < 5; i++)
//	{
//
//	}
//}