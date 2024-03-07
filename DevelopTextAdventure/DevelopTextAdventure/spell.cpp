#include "Spell.h"

Spell::Spell()
{
	m_damage = 0;
	m_player = nullptr;
	m_name = nullptr;
}

Spell::Spell(int dmg, Player* player, String* name)
{
	m_damage = dmg;
	m_player = player;
	m_name = name;
}

Spell::~Spell()
{
}

void Spell::Cast()
{

}

bool Spell::Compare(Spell a, Spell b)
{
	if (a.m_damage > b.m_damage)
	{
		return true;
	}
	return false;
}
