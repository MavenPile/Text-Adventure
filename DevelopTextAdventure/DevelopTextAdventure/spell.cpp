#include "Spell.h"
#include "String.h"
#include "Player.h"

Spell::Spell()
{
	m_player = nullptr;
	m_name = nullptr;
	m_onCast = nullptr;
}

Spell::Spell(Player* player, String name, String onCast)
{
	m_player = player;
	m_name = new String(name);
	m_onCast = new String(onCast);
}

Spell::~Spell()
{
	//delete m_name;
	//delete m_onCast;
}

void Spell::Cast()
{
	m_onCast->WriteToConsole();
	m_player->LoseGame();
}

const char* Spell::SpellName()
{
	return m_name->CStr();
}
