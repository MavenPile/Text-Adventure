#pragma once

class Game;
class Item;
class String;

class Room
{
private:
	
	String* m_desc;

public:	//	public variables

	Item* item;

public:	//	Methods

	Room();

	~Room();

	void Generate(Game* myGame, int row, int col);	//	generates the properties of the room (items, enemies, etc.)

	void Description();
};

