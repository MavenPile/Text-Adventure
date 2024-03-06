#pragma once

class Player;
class Room;
class String;

class Game
{
private:	//	Private Variables

	String* m_command;	//	the user input for commands

	Player* m_player;	//	the player

	Room** m_gameMap;	//	a room object class pointer pointer

	int m_row, m_col;	//	size of the map

	bool m_hasKey;	//	if the player has collected the key or not

	bool m_keyGen;	//	if the key exists in the world

	int m_posX, m_posY;	//	position of the player

	bool gameWin;

private:	//	Private Methods

	void m_TryMove(char c);

	void m_TryUse(char c);

	void m_TryInspect();

	void m_TryCast();

public:	//	Public Methods

	Game();

	~Game();

	void CreateMap();

	void PrintMap();

	void Run();

	void Move();

	void KeyGen();	//	prevents more than one key from appearing

	bool HasKey();	//	check if the player has the key

	void GetKey();	//	gives the player the key

	void GameWin();
};

