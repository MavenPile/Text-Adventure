#include "Player.h"
#include "String.h"
#include "Game.h"
#include "Spell.h"
#include <iostream>
#include <vector>
#include <algorithm>

Player::Player()
{
    CreateSpellList();
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
    String fireName("Fire");

    String onFire("You attempted to cast Fire... You engulf the room with an all consuming flame, disintegrating the skeleton... and yourself...");

    Spell fire(this, fireName, onFire);

    m_spells.push_back(fire);

    m_spellNames.push_back(fireName);


    String iceName("Ice");

    String onIce("You attempted to cast Ice... The walls grow white and frosty as the temperature drops far below zero, the skeleton can no longer move... And neither can you, you both shatter into pieces...");

    Spell ice(this, iceName, onIce);

    m_spells.push_back(ice);

    m_spellNames.push_back(iceName);


    String thunderName("Thunder");

    String onThunder("You attempted to cast Thunder... Large stormclouds start to collect in the room, and begin bellowing lightning all over... Bones have a natural resistance to thunder, but flesh doesn't... You die from electrocution...");

    Spell thunder(this, thunderName, onThunder);
    
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

void Player::CastSpell(const char c)
{
    switch (c)
    {
    case 'f':
        m_spells[0].Cast();
        break;
    case 'i':
        m_spells[1].Cast();
        break;
    case 't':
        m_spells[2].Cast();
        break;
    default:
        break;
    }
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

void Player::LoseGame()
{
    m_myGame->LoseGame();
}
