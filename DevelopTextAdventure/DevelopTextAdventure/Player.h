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

	int m_BinarySearch(const String& spell, int start, int end);

public:	//	public methods

	Player();

	Player(Game* myGame);

	~Player();

	void CreateSpellList();

	int FindSpell(const String findSpell);

	void CastSpell(const char c);

	void LoseGame();
};

