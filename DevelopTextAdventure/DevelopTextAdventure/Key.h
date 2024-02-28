#pragma once
#include "Item.h"

class Key : public Item
{
private:

	char* name;

	char* desc;

public:

	Key();

	Key(const char* newName, const char* newDesc);

	~Key();
	
	const char* GetName() override;

	const char* Description() override;

	void Use() override;

};

