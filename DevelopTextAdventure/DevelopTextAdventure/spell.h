#pragma once

class Player;	//	forward declaration, helps prevent circular dependencies
class String;

class Spell	
{
private:	//	private vars

	int m_damage;

	Player* m_player;

public:	//	public vars

	String* m_name;

public:	//	public methods
	
	Spell();

	Spell(int dmg, Player* player, String name);

	~Spell();
	
	void Cast();

	bool Compare(Spell a, Spell b);
};

