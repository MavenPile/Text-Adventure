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

	Spell(Player* player, const char* name, const char* onCast);

	~Spell();	//	destructor
	
	void Cast();

	const char* CStr() const;

	//	Move Semantics

	Spell(const Spell& input);	//	copy constructor

	Spell(Spell&& other);	//	move constructor

	Spell& operator = (Spell&& other);	//	copy assignment operator

	bool operator < (const Spell& compare);	//	move assignment operator
};

