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
    for (int i = 0; i < m_spells.size(); i++)
    {
        delete m_spells[i];
    }
}

void Player::CreateSpellList()
{
    Spell* fire = new Spell(this, "fire", "You attempted to cast Fire... You engulf the room with an all consuming flame, disintegrating the skeleton... and yourself...");

    m_spells.push_back(fire);


    Spell* ice = new Spell(this, "ice", "You attempted to cast Ice... The walls grow white and frosty as the temperature drops far below zero, the skeleton can no longer move... And neither can you, you both shatter into pieces...");

    m_spells.push_back(ice);


    Spell* thunder = new Spell(this, "thunder", "You attempted to cast Thunder... Large stormclouds start to collect in the room, and begin bellowing lightning all over... Bones have a natural resistance to thunder, but flesh doesn't... You die from electrocution...");
    
    m_spells.push_back(thunder);
}

int Player::FindSpell(const String& findSpell)
{
    std::sort(m_spells.begin(), m_spells.end());    //  sorts the vector

    int index = m_BinarySearch(findSpell, 0, m_spells.size());

    return index;

    //if (m_BinarySearch(find, 0, m_spells.size()) != -1)  //  calls binary search, hardcoded length
    //{
    //    return true;
    //}
    //
    //return false;
}

void Player::CastSpell(const String& spell)
{
    //switch (c)
    //{
    //case 'f':
    //    m_spells[0].Cast();
    //    break;
    //case 'i':
    //    m_spells[1].Cast();
    //    break;
    //case 't':
    //    m_spells[2].Cast();
    //    break;
    //default:
    //    break;
    //}

    int index = FindSpell(spell);

    if (-1 == index)
    {
        std::cout << "You felt no feedback from your spirit..." << std::endl;

        return;
    }

    m_spells[index]->Cast();
}

int Player::m_BinarySearch(const String& spell, int startIndex, int endIndex)
{
    int pivot;  //  pivot for binary search

    while (startIndex <= endIndex)  //  possible search length
    {
        pivot = (startIndex + endIndex) / 2;  //  start at centre of search area

        if (m_spells[pivot]->CStr() == spell.CStr())   //  if pivot is search target
        {
            return pivot;
        }
        else if (m_spells[pivot]->CStr() > spell.CStr())   //  if pivot is greater than search target
        {
            endIndex = pivot - 1;
        }
        else   //   if pivot is less than search target
        {
            startIndex = pivot + 1;
        }
    }

    return -1;
}

void Player::LoseGame()
{
    m_myGame->LoseGame();
}
