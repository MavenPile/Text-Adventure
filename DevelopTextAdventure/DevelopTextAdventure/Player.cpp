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


    String fireboltName("Firebolt");

    Spell firebolt(10, this, fireboltName);

    m_playerSpells[0] = firebolt;


    String frostboltName("Frostbolt");

    Spell frostbolt(10, this, frostboltName);

    m_playerSpells[1] = frostbolt;


    String thunderboltName("ThunderBolt");

    Spell thunderbolt(10, this, thunderboltName);

    m_playerSpells[2] = thunderbolt;
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