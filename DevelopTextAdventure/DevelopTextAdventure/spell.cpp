#include "Spell.h"
#include "String.h"
#include "Player.h"

Spell::Spell()
{
	m_player = nullptr;
	m_name = nullptr;
	m_onCast = nullptr;
}

Spell::Spell(Player* player, const char* name, const char* onCast)
{
	m_player = player;
	m_name = new String(name);
	m_onCast = new String(onCast);
}

Spell::~Spell()
{
	delete m_name;
	delete m_onCast;
}

void Spell::Cast()
{
	m_onCast->WriteToConsole();
	m_player->LoseGame();
}

const char* Spell::CStr() const
{
	return m_name->CStr();
}

Spell::Spell(const Spell& input)
{
	m_name = new String(input.CStr());
}

Spell::Spell(Spell&& other)
{
	m_name = other.m_name;

	other.m_name = nullptr;
}

Spell& Spell::operator = (Spell&& other)
{
	m_name = other.m_name;

	return *this;
}

bool Spell::operator < (const Spell& compare)
{
	if (m_name < compare.m_name)
	{
		return true;
	}

	return false;
}