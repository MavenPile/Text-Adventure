#include "Room.h"
#include "Game.h"
#include "String.h"
#include "Dog.h"
#include "Lamp.h"
#include "Cat.h"

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
    //if (row == 2 && col == 2)
    //{
    //    //  creates ending room
    //}

    srand(time(NULL));

    int randVar = rand() % 8;

    switch (randVar)
    {
    case 0:
        break;
    case 1:
        break;
    case 2: //  dog or cat
        if (myGame->HasKey() == false)
        {
            this->item = new Dog();
            myGame->KeyGen();
            m_desc = new String("A dog smiles at you from the centre of the room...");
        }
        else
        {
            item = new Cat();
            m_desc = new String("A cat is sleeping in this room...");
        }        break;
    case 3: //  lamp
        item = new Lamp();
        m_desc = new String("There is a lamp in this room...");
        break;
    case 4: //  dog or empty
        if (myGame->HasKey() == false)
        {
            this->item = new Dog();
            myGame->KeyGen();
            m_desc = new String("A dog smiles at you from the centre of the room...");
        }
        else
        {
            this->item = nullptr;
            m_desc = new String("The room is empty...");
        }
        break;
    default:
        this->item = nullptr;
        m_desc = new String("The room is empty...");
        break;
    }
    
    
    //if (keyGen == ) //  if true, room generates with key
    //{

    //}
}

void Room::Description()
{
    m_desc->WriteToConsole();
}
