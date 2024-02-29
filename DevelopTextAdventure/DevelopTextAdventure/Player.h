#pragma once
#include "String.h"
#include "Game.h"
#include <algorithm>

class Player
{
private:

	Room* currentRoom;

	Game* game;

public:

	Player();

	Player(Game* currentGame);

	~Player();
	
	void SetCurrentRoom(Room* newRoom);

	Room* GetCurrentRoom();
	
	void Move(char direction);

	bool FindSpell(const String& spell);


};

