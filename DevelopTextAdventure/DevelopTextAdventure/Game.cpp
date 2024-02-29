#include "Game.h"

Game::Game()
{
	player = new Player(this);

	gameMap = new Room * [5];	//	allocating memory for an array of class pointers

	for (int i = 0; i < 5; i++)
	{
		gameMap[i] = new Room[5];	//	allocating (sub-)arrays

	}	//	can be accessed by gameMap[row][col]
}

Game::~Game()
{
	delete[] player;

	for (int i = 0; i < 5; i++)
	{
		delete[] gameMap[i];	//	deallocates memory of each (sub-)array
	}

	delete[] gameMap;	//	deallocates memory of main array
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
			player->Move('n');	//	same as (*player).MoveNorth();
				//	dereferences player pointer, and accesses class function
		}
		if (command.EqualTo("move east") == true)
		{
			player->Move('e');
		}
		if (command.EqualTo("move south") == true)
		{
			player->Move('s');
		}
		if (command.EqualTo("move west") == true)
		{
			player->Move('w');
		}


		system("cls");

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