#include "Room.h"
#include "Game.h"
#include "String.h"
#include "Dog.h"
#include "Lamp.h"
#include "Cat.h"
#include "Door.h"
#include "Cake.h"

Room::Room()
{
    m_desc = nullptr;
    item = nullptr;
}

Room::~Room()
{
    delete m_desc;
    delete item;
}

void Room::Generate(Game* myGame, int row, int col)
{
    if (row == 0 && col == 4)   //  generates end door
    {
        item = new Door(myGame);
        m_desc = new String("You see a door in the room, not connected to any walls...");
    }
    else if (row == 3 && col == 1)   //  generates dog
    {
        item = new Dog(myGame);
        m_desc = new String("A dog smiles at you from the centre of the room...");
    }
    else
    {
        //srand(time(NULL));

        //int randVar = rand() % 4;

        int randVar = ((row * 7) * (col * 2)) % 4;

        switch (randVar)
        {
        case 0:
            item = nullptr;

            break;
        case 1: //  cake
            item = new Cake();
            m_desc = new String("There is a cake on a table in this room...");
            break;
        case 2: //  cat
            item = new Cat();
            m_desc = new String("A cat is sleeping in this room...");
            break;
        case 3: //  lamp
            item = new Lamp();
            m_desc = new String("There is a lamp in this room...");
            break;
        case 4: //  empty
            this->item = nullptr;
            m_desc = new String("The room is empty...");
            break;
        default:
            this->item = nullptr;
            m_desc = new String("The room is empty...");
            break;
        }
    }
    
    
    //if (keyGen == ) //  if true, room generates with key
    //{

    //}
}

void Room::Description()
{
    m_desc->WriteToConsole();
}
