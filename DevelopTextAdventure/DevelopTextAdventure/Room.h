#pragma once
#include "Item.h"
#include "String.h"
#include "Enemy.h"

class Room
{
private:
	
	//Item* item;

	//String description;

	int row;

	int col;

public:

	Room();

	Room(int iRow, int iCol);

	Room(int iRow, int iCol, String desc);

	Room(int iRow, int iCol, String desc, Item* item);

	Room(int iRow, int iCol, String desc, Item* item, Enemy* enemy);	//	constructor for a room with an item and description
		//	most likely, this room constructor is used to initialise the rooms in the array

	~Room();

	const void Description();
};

