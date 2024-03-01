#pragma once
#include "Item.h"
#include <iostream>

class Key : public Item
{
private:

	String* desc;

public:

	Key();

	~Key();

	String* Description() const override;

	void Use() override;

};

