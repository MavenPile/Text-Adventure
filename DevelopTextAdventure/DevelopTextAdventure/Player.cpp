#include "Player.h"
#include "String.h"
#include "Game.h"
#include <iostream>

Player::Player()
{
    //m_posX, m_posY = 0;

    //hasKey = false;
}

Player::Player(Game* myGame)
{
    m_myGame = myGame;

    CreateSpellList();
}

Player::~Player()
{
}

void Player::CreateSpellList()
{
    m_spells = new String[3];

    String* fireball = new String("Fireball");

    m_spells[0] = *fireball;
}

bool Player::FindSpell(const String& spell)
{
    return false;
}

void Player::GetKey()
{
    m_hasKey = true;
}

bool Player::HasKey()
{
    if (m_hasKey == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}