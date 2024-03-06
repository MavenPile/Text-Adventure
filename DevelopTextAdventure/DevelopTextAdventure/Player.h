#pragma once
#include <algorithm>

class String;
class Game;
class Spell;

class Player
{
private:

	Game* m_myGame;

	String* m_spells;

	Spell* m_playerSpells;

	int m_health;

public:

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	bool FindSpell(const String& spell);

	void LoseHealth(int dmg);
};

