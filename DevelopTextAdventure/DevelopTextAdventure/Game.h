#pragma once

class Player;
class Room;
class String;

class Game
{
private:
	String* m_command;	//	the user input for commands

	Player* m_player;	//	the player

	Room** m_gameMap;	//	a room object class pointer pointer

	Room*** m_gameMap3D;	//	a pointer pointer pointer, for a 3D array of rooms

	Room**** m_gameMap4D;	//	I guess this is possible

	int m_row = 5;	//	no. of rows in the map

	int m_col = 5;	//	no. of columns in the map

	int m_dep = 5;	//	optional: depth of the map, can't be printed

	int m_godKnows = 5;	//	optional: a fourth dimension, can't be printed

	bool hasKey;

public:

	Game();

	~Game();

	void Run();

	void PrintMap();

	int* GetPlayerRoom();

	void CreateMap();

	void GetKey();

};

