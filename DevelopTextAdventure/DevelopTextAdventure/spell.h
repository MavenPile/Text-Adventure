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

	~Spell();
	
	void Cast();

	const char* CStr() const;

	//	Move Semantics

	Spell(Spell&& other);

	Spell(const Spell& input);

	Spell& operator = (Spell&& other);

	bool operator < (const Spell& compare);
};

