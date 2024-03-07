#pragma once

class Player;	//	forward declaration, helps prevent circular dependencies
class String;

class Spell	
{
private:	//	private vars

	Player* m_player;

	String* m_onCast;

public:	//	public vars

	String* m_name;

public:	//	public methods
	
	Spell();

	Spell(Player* player, String name, String onCast);

	~Spell();
	
	void Cast();
};

