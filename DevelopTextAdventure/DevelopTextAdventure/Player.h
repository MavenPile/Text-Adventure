#pragma once
#include <algorithm>

class String;
class Game;

class Player
{
private:

	Game* m_myGame;

	String* m_spells;

public:

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	bool FindSpell(const String& spell);

	void GetKey();

	bool HasKey();
};

