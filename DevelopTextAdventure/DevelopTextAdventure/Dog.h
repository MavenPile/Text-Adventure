#pragma once
#include "Item.h"

class Dog : public Item
{
public:
	Dog();

	Dog(Game* myGame, Room* myRoom);

	~Dog();

	void Description() const override;

	void Use() override;

private:
	bool isDog;

	bool hasKey;

	String* m_desc;
};

