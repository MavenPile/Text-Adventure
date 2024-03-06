#pragma once
#include "Item.h"

class String;

class Cake : public Item
{
private:

	String* m_desc;

	int m_cakeRemaining;

public:

public:

	Cake();

	~Cake();

	void Description() const override;

	void Use() override;

};

