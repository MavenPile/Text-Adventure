#pragma once
#include "String.h"
#include "Game.h"
#include <algorithm>

class Player
{
private:

	Room* roomPointer;

	Game* game;

public:

	Player();

	Player(Game* currentGame);

	~Player();

	bool FindSpell(const String& spell);

	//Room* GetCurrentRoom();
};

