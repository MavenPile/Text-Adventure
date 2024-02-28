#include "Room.h"

Room::Room()
{
}

Room::Room(int iRow, int iCol, String desc)
{
    row = iRow;
    col = iCol;
}

Room::Room(int iRow, int iCol, String desc, Item* item)
{

}

Room::Room(int iRow, int iCol, String desc, Item* item, Enemy* enemy)
{

}

Room::~Room()
{
    
}

const void Room::Description()
{
    return void();
}
