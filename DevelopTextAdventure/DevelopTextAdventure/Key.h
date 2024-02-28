#pragma once
#include "Item.h"

class Key : public Item
{
private:

	char* name;

	char* desc;

public:

	Key();

	~Key();
	
	const char* GetCharName() override;

	const char* Description() override;

	void Use() override;

};

