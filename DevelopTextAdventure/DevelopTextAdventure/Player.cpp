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
    String fireboltName("Firebolt");

    Spell firebolt(10, this, fireboltName);

    m_spells.push_back(firebolt);


    String iceboltName("Icebolt");

    Spell icebolt(10, this, iceboltName);

    m_spells.push_back(icebolt);

    
    String thunderboltName("Thunderbolt");

    Spell thunderbolt(10, this, thunderboltName);
    
    m_spells.push_back(thunderbolt);


    m_spellNames.push_back(String("Firebolt"));

    m_spellNames.push_back(String("Icebolt"));

    m_spellNames.push_back(String("Thunderbolt"));
}

bool Player::FindSpell(const char c)
{
    std::sort(m_spellNames.begin(), m_spellNames.end());    //  sorts the vector

    String findSpell;

    if (c == 'f')
    {
        findSpell = "Firebolt";
    }
    else if (c == 'i')
    {
        findSpell = "Icebolt";
    }
    else
    {
        findSpell = "Thunderbolt";
    }

    if (m_BinarySearch(findSpell, 0, 2) == true)  //  calls binary search, hardcoded length
    {
        return true;
    }
    
    return false;
}

bool Player::m_BinarySearch(const String& spell, int startIndex, int endIndex)
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