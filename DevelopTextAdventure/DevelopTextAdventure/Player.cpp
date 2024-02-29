#include "Player.h"

Player::Player()
{
    //currentRoom = room[0][0];
}

Player::Player(Game* currentGame)
{
    game = currentGame;
}

Player::~Player()
{
}

bool Player::FindSpell(const String& spell)
{
    return false;
}

//Room* Player::GetCurrentRoom()
//{
//    return currentRoom;
//}