#pragma once
#include "Item.h"

class String;

class Dog : public Item
{
public:
	Dog();

	Dog(Game* myGame);

	~Dog();

	void Description() const override;

	void Use() override;

private:
	bool isDog;

	bool hasKey;

	String* m_desc;

};

