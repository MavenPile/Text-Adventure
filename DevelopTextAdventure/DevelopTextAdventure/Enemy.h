#pragma once

class Player;

class Enemy
{
protected:

	int m_health;

	Player* m_player;

public:

	virtual void TakeDamage(int dmg) = 0;

	virtual void DealDamage() = 0;
};

