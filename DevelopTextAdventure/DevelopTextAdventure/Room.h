#pragma once
#include "Item.h"
#include "String.h"
#include "Enemy.h"

class Room
{
private:
	
	//Item* item;

	//String description;



public:

	Room();

	Room(String desc);

	Room(String desc, Item* item);

	Room(String desc, Item* item, Enemy* enemy);	//	constructor for a room with an item and description
		//	most likely, this room constructor is used to initialise the rooms in the array

	~Room();

	const void Description();
};

