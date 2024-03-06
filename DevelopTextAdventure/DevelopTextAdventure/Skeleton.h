#pragma once
#include "Enemy.h"

class String;

class Skeleton : public Enemy
{
private:

	bool m_armLeft;

	bool m_armRight;

	bool m_legLeft;

	bool m_legRight;

	bool m_canAttack;

	String* m_desc;

public:

	Skeleton();

	Skeleton(Player* player);

	~Skeleton();

	void TakeDamage(int dmg) override;

	void DealDamage() override;

	void Description();
};

