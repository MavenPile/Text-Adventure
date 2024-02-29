#pragma once
#include "String.h"
#include "Game.h"

class Player
{
private:

	Room* roomPointer;

public:

	Player();

	Player(Game game);

	~Player();

	bool FindSpell(const String& spell);

	//Room* GetCurrentRoom();
};

