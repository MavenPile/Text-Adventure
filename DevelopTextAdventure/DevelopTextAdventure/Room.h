#pragma once
#include "Item.h"
#include "String.h"
#include "Enemy.h"

class Room
{
private:
	
	bool keyGen;	//	prevents more than one key from appearing

	String desc;

public:

	Room();

	~Room();

	void Generate();	//	generates the properties of the room (items, enemies, etc.)

	String Description();
};

