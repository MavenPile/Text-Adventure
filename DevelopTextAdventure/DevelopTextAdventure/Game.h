#pragma once
#include "Player.h"
#include "Room.h"

class Game
{
private:

	Player* player;
	
	
	
	int gameMap[5][5];



public:

	Game();

	~Game();

	void Run();

	//void CreateMap();

};

