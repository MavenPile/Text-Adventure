#include "Room.h"

Room::Room()
{
    description = "this is a room";
}

Room::Room(String desc)
{
    description = desc;
}

Room::Room(String desc, Item* item)
{

}

Room::Room(String desc, Item* item, Enemy* enemy)
{

}

Room::~Room()
{
    
}

const void Room::Description()
{
    return void();
}
