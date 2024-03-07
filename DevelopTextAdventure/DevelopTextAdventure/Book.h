#pragma once
#include "Item.h"

class Book : public Item
{
private:

	bool m_isOpen;

	String* m_desc;

public:

	Book();

	Book(Room* myRoom);

	~Book();
	
	void Description() const override;

	void Use() override;

};

