#pragma once
#include "Player.h"
#include "Room.h"
#include <iostream>

class Game
{
private:

	Player* player;
	
	int gameMap[5][5];

	//Room* currentRoom /* = &room1 */;

public:

	Game();

	~Game();

	void Run();

	void PrintMap();

	int* GetPlayerRoom();

	//void CreateMap();

};

