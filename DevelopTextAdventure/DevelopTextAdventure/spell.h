#pragma once
#include "String.h"


class Spell
{
private:

	String name;

	int damage;

public:

	//Spell();

	//Spell(String name, int damage);

	//~Spell();

	virtual void Cast() = 0;

	virtual bool Compare(Spell a, Spell b) = 0;

};

