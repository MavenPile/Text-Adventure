#pragma once
#include "Item.h"
#include "Game.h"
#include <iostream>

class Key : public Item
{
private:

	String name;

	String desc;

	Game* game;

public:

	Key();

	Key(Game* currentGame);

	//~Key();
	
	String GetName() override;

	String Description() override;

	void Use() override;

};

