#pragma once
#include "String.h"
#include "Room.h"

class Player
{
private:

	Room* currentRoom;

public:

	Player();

	~Player();

	bool FindSpell(const String& spell);

	int* GetCurrentRoom();
};

