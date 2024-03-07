#include "Player.h"
#include "String.h"
#include "Game.h"
#include "Spell.h"
#include <iostream>
#include <vector>
#include <algorithm>

Player::Player()
{
    //m_posX, m_posY = 0;

    //hasKey = false;
}

Player::Player(Game* myGame)
{
    m_myGame = myGame;

    CreateSpellList();

    m_health = 100;
}

Player::~Player()
{    
    delete[] m_playerSpells;
}

void Player::CreateSpellList()
{
    m_playerSpells = new Spell[3];

    String* eruption = new String("Eruption");

    Spell eruptionSpell(10, this, eruption);

    m_playerSpells[0] = eruptionSpell;


    String* frostbolt = new String("Frostbolt");

    Spell frostboltSpell(10, this, frostbolt);

    m_playerSpells[1] = frostboltSpell;


    String* polymorph = new String("Polymorph");

    Spell polymorphSpell(10, this, frostbolt);

    m_playerSpells[2] = polymorphSpell;
}

bool Player::FindSpell(const String& spell)
{
    std::vector<Spell> v(m_playerSpells, m_playerSpells + 3);

    std::sort(v.begin(), v.end());

    if (std::binary_search(v.begin(), v.end(), spell))
    {
        return true;
    }
    
    return false;
}

void Player::LoseHealth(int dmg)
{
    m_health -= dmg;
}