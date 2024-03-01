#pragma once
#include "Item.h"

class Dog : public Item
{
public:
	Dog();

	~Dog();

	String* Description() const override;

	void Use() override;

private:
	bool isDog;

	String* desc;

};

