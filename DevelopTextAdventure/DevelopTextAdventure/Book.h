#pragma once
#include "Item.h"

class Book : public Item
{
private:	//	private vars

	bool m_isOpen;

	String* m_desc;

public:	//	public methods

	Book();

	Book(Room* myRoom);

	~Book();
	
	void Description() const override;

	void Use() override;
};

