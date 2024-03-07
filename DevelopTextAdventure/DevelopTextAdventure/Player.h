#pragma once
#include <vector>

class String;
class Game;
class Spell;

class Player
{
private:

	Game* m_myGame;

	std::vector<Spell> m_spells;

	std::vector<String> m_spellNames;

	int m_health;

	bool m_BinarySearchName(const String& spell, int start, int end);

public:

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	bool FindSpell(const char* findSpell);

	void LoseHealth(int dmg);
};

