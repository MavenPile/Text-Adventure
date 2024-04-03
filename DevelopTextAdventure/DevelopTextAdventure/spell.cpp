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

const char* Spell::GetCast() const
{
	return m_onCast->CStr();
}

bool Spell::operator == (const Spell& compare)
{
	if (m_name != compare.m_name)
	{
		return false;
	}

	return true;
}

Spell::Spell(const Spell& input)
{
	m_name = new String(input.CStr());

	m_player = input.m_player;

	m_onCast = new String(input.GetCast());
}

Spell::Spell(Spell&& other)
{
	m_name = other.m_name;

	m_player = other.m_player;

	m_onCast = other.m_onCast;

	other.m_name = nullptr;

	other.m_player = nullptr;

	other.m_onCast = nullptr;
}

Spell& Spell::operator = (Spell&& other)
{
	delete[] m_name;

	delete m_player;

	delete[] m_onCast;
	
	m_name = other.m_name;

	m_player = other.m_player;

	m_onCast = other.m_onCast;

	other.m_name = nullptr;

	other.m_player = nullptr;

	other.m_onCast = nullptr;

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