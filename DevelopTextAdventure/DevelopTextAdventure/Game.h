#pragma once
#include "Player.h"
#include "Room.h"
#include <iostream>

class Game
{
private:

	Player* player;
	
	Room** gameMap;	//	a room object class pointer pointer

	Room*** gameMap3D;

	//Room* currentRoom /* = &room1 */;

public:

	Game();

	~Game();

	void Run();

	void PrintMap();

	int* GetPlayerRoom();

	//void CreateMap();

};

