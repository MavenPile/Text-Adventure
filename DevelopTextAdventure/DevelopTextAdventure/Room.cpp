#include "Room.h"
#include "Game.h"
#include "String.h"
#include "Dog.h"
#include "Lamp.h"
#include "Cat.h"
#include "Door.h"
#include "Cake.h"
#include "Skeleton.h"
#include <iostream>
#include <stdlib.h>

Room::Room()
{
    m_desc = new String("The room is empty...");
    item = nullptr;
    enemy = nullptr;
}

Room::~Room()
{
    delete m_desc;
    delete item;
    delete enemy;
}

void Room::Generate(Game* myGame, int row, int col)
{
    if (row == 0 && col == 4)   //  generates door
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
        srand(row + col);

        int randVar = rand() % 8;

        //int randVar = ((row * 7) * (col * 2)) % 4;

        switch (randVar)
        {
        case 0:
            m_desc = new String("There is a skeleton in the room, it seems to want to attack you...");
            enemy = new Skeleton(myGame->GetPlayer());
            break;
        case 1: //  cake
            m_desc = new String("There is a cake on a table in this room...");
            item = new Cake();
            break;
        case 2: //  cat
            m_desc = new String("A cat is sleeping in this room...");
            item = new Cat();
            break;
        case 3: //  lamp
            m_desc = new String("There is a lamp in this room...");
            item = new Lamp();
            break;
        case 4: //  empty
            break;
        default:    //  empty
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

void Room::ChangeDesc(String& inputDesc)
{
    String* newDesc = new String(inputDesc);
    
    delete m_desc;

    m_desc = newDesc;
}

void Room::RemoveItem()
{
    delete item;
}