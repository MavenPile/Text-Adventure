#pragma once
#include "Item.h"
class Door : public Item
{
private:



public:

	Door();

	~Door();

	void Description() const override;

	void Use() override;
};

