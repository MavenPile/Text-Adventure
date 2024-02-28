#pragma once
#include "Item.h"

class Key : public Item
{
private:

	String name;

	String desc;

public:

	Key();

	//~Key();
	
	String GetName() override;

	String Description() override;

	void Use() override;

};

