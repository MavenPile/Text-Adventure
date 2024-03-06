#pragma once

class Enemy
{
private:

	int health;

	int damage;

public:

	virtual void TakeDamage(int dmg) = 0;

	virtual void DealDamage() = 0;
};

