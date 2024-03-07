#include "Room.h"
#include "Game.h"
#include "String.h"
#include "Dog.h"
#include "Lamp.h"
#include "Cat.h"
#include "Door.h"
#include "Cake.h"
#include "Book.h"
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
        item = new Dog(myGame, this);
        m_desc = new String("A dog smiles at you from the centre of the room...");
    }
    else
    {
        srand(row + col);

        int randVar = rand() % 9;

        //int randVar = ((row * 7) * (col * 2)) % 4;

        switch (randVar)
        {
        case 0: //  skeleton
            m_desc = new String("There is a skeleton in the room, it seems to want to attack you...");
            enemy = new Skeleton(myGame->GetPlayer());
            break;
        case 1: //  cake
            m_desc = new String("There is a cake on a table in this room...");
            item = new Cake(this);
            break;
        case 2: //  cat
            m_desc = new String("A cat is sleeping in this room...");
            item = new Cat();
            break;
        case 3: //  lamp
            m_desc = new String("The room is dark. But, there is a lamp...");
            item = new Lamp(this);
            break;
        case 4: //  book
            m_desc = new String("There's a lectern with a book in this room...");
            item = new Book(this);
            break;
        default:    //  empty
            break;
        }
    }
}

void Room::Description()
{
    m_desc->WriteToConsole();
}

void Room::ChangeDesc(String inputDesc)
{
    String* newDesc = new String(inputDesc);
    
    delete m_desc;

    m_desc = newDesc;
}

void Room::RemoveItem()
{
    delete item;
}

void Room::FullRemoveItem()
{
    delete item;

    delete m_desc;

    String* newDesc = new String("The room is empty...");

    m_desc = newDesc;
}