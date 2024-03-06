#pragma once
#include "Item.h"

class String;
class Room;

class Cake : public Item
{
private:

	String* m_desc;

	int m_cakeRemaining;

public:

	Cake();

	Cake(Room* myRoom);

	~Cake();

	void Description() const override;

	void Use() override;

};

