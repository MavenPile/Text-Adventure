#pragma once
#include "String.h"
#include "Game.h"
#include <algorithm>

class Player
{
private:

	Game* game;

	//int m_posX, m_posY;

	bool m_hasKey;

public:

	Player();

	Player(Game* currentGame);

	~Player();
	
	//int GetPosX();

	//int GetPosY();

	//void Move(char direction);

	bool FindSpell(const String& spell);

	void GetKey();

	bool HasKey();
};

