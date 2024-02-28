#pragma once

class Enemy
{
private:

	int health;

	int damage;

	int posRow;

	int posCol;

public:

	virtual void TakeDamage(int dmg) = 0;

	virtual void DealDamage() = 0;
};

