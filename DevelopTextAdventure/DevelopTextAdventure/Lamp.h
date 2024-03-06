#pragma once
#include "Item.h"
class String;
class Room;

class Lamp : public Item
{
private:

	bool m_isOn;

	String* m_desc;

public:

	Lamp();

	Lamp(Room* myRoom);

	~Lamp();

	void Description() const override;

	void Use() override;
};

