#pragma once
#include "String.h"
#include "Game.h"

class Player
{
private:

	Room* roomPointer;

public:

	Player();

	~Player();

	bool FindSpell(const String& spell);

	//Room* GetCurrentRoom();
};

