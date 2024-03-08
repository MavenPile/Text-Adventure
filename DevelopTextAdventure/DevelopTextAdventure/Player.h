#pragma once
#include <vector>

class String;
class Game;
class Spell;

class Player
{
private:	//	private vars

	Game* m_myGame;

	std::vector<Spell> m_spells;

	std::vector<String> m_spellNames;

private:	//	private methods

	bool m_BinarySearchName(const String& spell, int start, int end);

public:	//	public methods

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	bool FindSpell(const char* findSpell);

	void CastSpell(const char c);

	void LoseGame();
};

