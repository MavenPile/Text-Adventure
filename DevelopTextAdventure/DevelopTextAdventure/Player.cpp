#include "Player.h"

Player::Player()
{
    //m_posX, m_posY = 0;

    //hasKey = false;
}

Player::Player(Game* currentGame)
{
    game = currentGame;
}

Player::~Player()
{
}

//int Player::GetPosX()
//{
//    return m_posX;
//}
//
//int Player::GetPosY()
//{
//    return m_posY;
//}

//void Player::Move(char direction)
//{
//    if (direction == 'n')   //  North
//    {
//
//    }
//    else if (direction == 'e')  //  East
//    {
//
//    }
//    else if (direction == 's')  //  South
//    {
//
//    }
//    else if (direction == 'w')  //  West
//    {
//
//    }
//    else if (direction == 'd')  //  Down
//    {
//
//    }
//    else if (direction == 'u')  //  Up
//    {
//
//    }
//    else
//    {
//        std::cout << "Couldn't find that direction..." << std::endl;
//    }
//}

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