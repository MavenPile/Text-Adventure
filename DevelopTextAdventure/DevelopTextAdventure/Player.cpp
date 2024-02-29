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

void Player::SetCurrentRoom(Room* newRoom)
{
    currentRoom = newRoom;
}

Room* Player::GetCurrentRoom()
{
    return currentRoom;

}
void Player::Move(char direction)
{
    if (direction == 'n')   //  North
    {

    }
    else if (direction == 'e')  //  East
    {

    }
    else if (direction == 's')  //  South
    {

    }
    else if (direction == 'w')  //  West
    {

    }
    else if (direction == 'd')  //  Down
    {

    }
    else if (direction == 'u')  //  Up
    {

    }
}

bool Player::FindSpell(const String& spell)
{
    return false;
}

