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
}

void Player::CreateSpellList()
{
    String fireName("Fire");

    Spell fire(10, this, fireName);

    m_spells.push_back(fire);

    m_spellNames.push_back(fireName);


    String iceName("Ice");

    Spell ice(10, this, iceName);

    m_spells.push_back(ice);

    m_spellNames.push_back(iceName);


    String thunderName("Thunder");

    Spell thunder(10, this, thunderName);
    
    m_spells.push_back(thunder);

    m_spellNames.push_back(thunderName);
}

bool Player::FindSpell(const char* findSpell)
{
    std::sort(m_spellNames.begin(), m_spellNames.end());    //  sorts the vector

    String find(findSpell);

    if (m_BinarySearchName(find, 0, 2) == true)  //  calls binary search, hardcoded length
    {
        return true;
    }
    
    return false;
}

bool Player::m_BinarySearchName(const String& spell, int startIndex, int endIndex)
{
    int pivot;  //  pivot for binary search

    while (startIndex <= endIndex)  //  possible search length
    {
        pivot = (startIndex + endIndex) / 2;  //  start at centre of search area

        if (m_spellNames[pivot] == spell)   //  if pivot is search target
        {
            return true;
        }
        else if (m_spellNames[pivot] > spell)   //  if pivot is greater than search target
        {
            endIndex = pivot - 1;
        }
        else   //   if pivot is less than search target
        {
            startIndex = pivot + 1;
        }
    }

    return false;
}

void Player::LoseHealth(int dmg)
{
    m_health -= dmg;
}

void Player::LoseGame()
{
    m_myGame->LoseGame();
}
