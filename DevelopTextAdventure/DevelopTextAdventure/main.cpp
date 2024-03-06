#include <iostream>
#include "Game.h"

int main()
{
	Game* myGame = new Game;
	
	while (true)
	{
		myGame->Run();
	}
	
	
	//bool gaming = false;

	//int playerPos = 1;

	//int mapIndex = 1;

	//const int mapSize = 3;

	//int map[mapSize][mapSize];
	//
	//String command;
	//
	//while (gaming)
	//{		
	//	std::cout << "Where would you like to go? " << std::endl;

	//	command.ReadFromConsole();

	//	system("cls");

	//	for (int row = 0; row < mapSize; row++)
	//	{
	//		if (mapIndex > mapSize * mapSize)
	//		{
	//			mapIndex = 1;
	//		}

	//		std::cout << "|";

	//		for (int col = 0; col < mapSize; col++)
	//		{
	//			map[row][col] = mapIndex;

	//			if (mapIndex == playerPos)
	//			{
	//				std::cout << "##";
	//			}
	//			else if (mapIndex < 10)
	//			{
	//				std::cout << "0" << map[row][col];
	//			}
	//			else
	//			{
	//				std::cout << map[row][col];
	//			}

	//			std::cout << "|";

	//			mapIndex++;

	//			if (col == (mapSize - 1))
	//			{
	//				std::cout << std::endl;
	//			}
	//		}
	//	}

	//	std::cout << std::endl;

	//	command.ToLower();

	//	if (command.EqualTo("move north") == true)
	//	{
	//		std::cout << "You have decided to move North." << std::endl;

	//		//player1.MoveNorth();
	//	}
	//	else if (command.EqualTo("move east") == true)
	//	{
	//		std::cout << "You have decided to move East." << std::endl;
	//	}
	//	else if (command.EqualTo("move south") == true)
	//	{
	//		std::cout << "You have decided to move South." << std::endl;
	//	}
	//	else if (command.EqualTo("move west") == true)
	//	{
	//		std::cout << "You have decided to move West." << std::endl;
	//	}
	//	else if (command.EqualTo("stop playing") == true)
	//	{
	//		std::cout << "You have decided to stop playing." << std::endl;

	//		gaming = false;
	//	}
	//	else
	//	{
	//		std::cout << "You didn't move." << std::endl;
	//	}
	//	
	//	std::cout << std::endl;

	//}

	return 0;
}