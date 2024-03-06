#pragma once
#include "String.h"

class Player;

class Spell
{
private:

	String* name;

	int damage;

	Player* m_player;

public:

	virtual void Cast() = 0;

	virtual bool Compare(Spell a, Spell b) = 0;

};

