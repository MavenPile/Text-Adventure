#pragma once
#include "Item.h"

class Cat : public Item
{
private:

	bool m_purring;

	String* m_desc;

public:

	Cat();

	~Cat();

	void Description() const override;

	void Use() override;
};

