#include "Spell.h"
#include "String.h"

Spell::Spell()
{
	m_damage = 0;
	m_player = nullptr;
	m_name = nullptr;
}

Spell::Spell(int dmg, Player* player, String name)
{
	m_damage = dmg;
	m_player = player;
	//m_name = &name;
	m_name = new String(name);
}

Spell::~Spell()
{
	//delete m_name;
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
