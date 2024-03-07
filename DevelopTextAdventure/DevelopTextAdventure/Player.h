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

	//String* m_spells;

	//Spell* m_playerSpells;

	int m_health;

	bool m_BinarySearch(const String& spell, int start, int end);

public:

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	bool FindSpell(const char c);

	void LoseHealth(int dmg);
};

