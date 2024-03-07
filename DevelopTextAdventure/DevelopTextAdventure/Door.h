#pragma once
#include "Item.h"

class Door : public Item
{
private:

	String* m_desc;

public:

	Door();

	Door(Game* myGame);

	~Door();

	void Description() const override;

	void Use() override;
};

