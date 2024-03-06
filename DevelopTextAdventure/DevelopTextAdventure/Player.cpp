#include "Player.h"
#include "String.h"
#include "Game.h"
#include <iostream>
#include "Spell.h"

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
}

void Player::CreateSpellList()
{
    m_playerSpells = new Spell[3];



    
    m_spells = new String[3];

    String* fireball = new String("Fireball");

    m_spells[0] = *fireball;
}

bool Player::FindSpell(const String& spell)
{
    return false;
}

void Player::LoseHealth(int dmg)
{
    m_health -= dmg;
}