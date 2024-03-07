#include "Game.h"
#include "Player.h"
#include "String.h"
#include "Room.h"
#include "Lamp.h"
#include "Skeleton.h"
#include "Cake.h"
#include "Door.h"
#include "Cat.h"
#include "Dog.h"

Game::Game()
{
	m_command = new String();

	m_player = new Player(this);

	m_row = 5;

	m_col = 5;

	CreateMap();

	m_hasKey = false;

	m_keyGen = false;

	gameWin = false;
}

Game::~Game()
{
	delete m_command;
	
	delete m_player;

	for (int i = 0; i < 5; i++)
	{
		delete[] m_gameMap[i];	//	deallocates memory of each (sub-)array
	}

	delete[] m_gameMap;	//	deallocates memory of main array
}

void Game::CreateMap()
{
	//	generates a 2D array, or an array of arrays
	
	m_gameMap = new Room* [m_row];	//	allocating memory for an array of class pointers

	for (int row = 0; row < m_row; row++)
	{
		m_gameMap[row] = new Room[m_col];	//	allocating (sub-)arrays

		for (int col = 0; col < m_col; col++)
		{
			m_gameMap[row][col].Generate(this, row, col);	//	generates the room
		}
	}	//	can be accessed by gameMap[row][col]
}

void Game::PrintMap()
{	
	system("cls");

	std::cout << "---------------" << std::endl;

	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			std::cout << "|";

			if (row == m_posY && col == m_posX)
			{
				std::cout << "P";	//	prints player location
			}
			else
			{
				std::cout << "_";
			}

			std::cout << "|";
		}
		std::cout << std::endl;
	}

	std::cout << "---------------" << std::endl;
}

void Game::Run()
{
	while (gameWin == false)
	{
		PrintMap();	//	prints the map
		
		m_gameMap[m_posX][m_posY].Description();	//	outputs description of room

		std::cout << "What action would you like to take? (type \"help\" for commands)" << std::endl;

		m_command->ReadFromConsole();	//	recieves input

		m_command->ToLower();	//	makes input consistent

		switch (m_command->CharacterAt(0))
		{
		case 'h':
			if (m_command->Find("help") != -1)
			{
				std::cout << std::endl;
				std::cout << "move <north, south, east, west: move to an adjacent room..." << std::endl;
				std::cout << "use <item>: use an item in the current room..." << std::endl;
				std::cout << "inspect <item/enemy>: see the description of an item or enemy..." << std::endl;
				std::cout << "cast <spell>: cast a spell on something in a room..." << std::endl;
				std::cout << "attack <enemy>: to attack an enemy in the room..." << std::endl;
				std::cout << std::endl;
			}
			break;
		case 'a':
			if (m_command->Find("attack") != -1)
			{
				m_TryAttack();
			}
			break;
		case 'm':	//	move
			if (m_command->Find("move") != -1)
			{
				if (m_command->Find("north") != -1)
				{
					m_TryMove('n');
				}
				else if (m_command->Find("south") != -1)
				{
					m_TryMove('s');
				}
				else if (m_command->Find("east") != -1)
				{
					m_TryMove('e');
				}
				else if (m_command->Find("west") != -1)
				{
					m_TryMove('w');
				}
				else
				{
					std::cout << "That isn't a direction to move..." << std::endl;
				}
			}
			break;
		case 'u':	//	use
			if (m_command->Find("use") != -1)
			{
				if (m_command->Find("cake") != -1)
				{
					m_TryUse('c');
				}
				else if (m_command->Find("cat") != -1)
				{
					m_TryUse('a');
				}
				else if (m_command->Find("dog") != -1)
				{
					m_TryUse('d');
				}
				else if (m_command->Find("door") != -1)
				{
					m_TryUse('o');
				}
				else if (m_command->Find("lamp") != -1)
				{
					m_TryUse('l');
				}
				else
				{
					std::cout << "There was nothing like that to use..." << std::endl;
				}
			}
			break;
		case 'i':	//	inspect
			if (m_command->Find("inspect") != -1)
			{
				if (m_command->Find("cake") != -1)
				{
					m_TryInspect('c');
				}
				else if (m_command->Find("cat") != -1)
				{
					m_TryInspect('a');
				}
				else if (m_command->Find("dog") != -1)
				{
					m_TryInspect('d');
				}
				else if (m_command->Find("door") != -1)
				{
					m_TryInspect('o');
				}
				else if (m_command->Find("lamp") != -1)
				{
					m_TryInspect('l');
				}
				else if (m_command->Find("skeleton") != -1)
				{
					m_TryInspect('s');
				}
				else
				{
					std::cout << "There was nothing like that to inspect..." << std::endl;
				}
			}
			break;
		case 'c':	//	cast
			if (m_command->Find("cast") != -1)
			{
				if (m_command->Find("eruption") != -1)
				{
					m_TryCast('e');
				}
				else if (m_command->Find("frostbolt") != -1)
				{
					m_TryCast('f');
				}
				else if (m_command->Find("polymorph") != -1)
				{
					m_TryCast('p');
				}
				else
				{
					std::cout << "You didn't have such a spell to cast..." << std::endl;
				}
			}
			break;
		case 'd':	//	debug
			if (m_command->Find("debug") != -1)
			{
				if (m_command->Find("getkey") != -1)
				{
					GetKey();
					std::cout << "Where'd you get that?" << std::endl;
				}
				else if (m_command->Find("endgame") != -1)
				{
					GameWin();
					std::cout << "How'd you do that?" << std::endl;
				}
				else if (m_command->Find("findspell") != -1)
				{
					if (m_command->Find("eruption") != -1)
					{
						m_player->FindSpell("eruption");
					}
				}
				break;
			}
		default:
			std::cout << "Couldn't determine what you wanted to do..." << std::endl;
			break;
		}

		system("pause");
	}

	std::cout << "Congratuations, you have exited the... Labyrinth? You Win!" << std::endl;

	system("pause");
}

void Game::KeyGen()
{
	m_keyGen = true;
}

bool Game::HasKey()
{
	if (m_hasKey == true)
	{
		return true;
	}
	return false;
}

void Game::GetKey()
{
	m_hasKey = true;
}

void Game::GameWin()
{
	gameWin = true;
}

Player* Game::GetPlayer()
{
	return m_player;
}

void Game::m_TryMove(char c)
{
	switch (c)
	{
	case 'n':	//	North
		if (m_posY == 0)
		{
			std::cout << "You found no Northern paths..." << std::endl;
			break;
		}

		m_posY--;

		std::cout << "You moved North..." << std::endl;

		break;
	case 's':	//	South
		if (m_posY == (m_col - 1))
		{
			std::cout << "You found no Southern paths..." << std::endl;
			break;
		}

		m_posY++;

		std::cout << "You moved South..." << std::endl;

		break;
	case 'e':	//	East
		if (m_posX == (m_row - 1))
		{
			std::cout << "You found no Eastern paths..." << std::endl;
			break;
		}

		m_posX++;

		std::cout << "You moved East..." << std::endl;

		break;
	case 'w':	//	West
		if (m_posX == 0)
		{
			std::cout << "You found no Western paths..." << std::endl;
			break;
		}

		m_posX--;

		std::cout << "You moved West..." << std::endl;

		break;
	default:
		break;
	}
}

void Game::m_TryUse(char c)
{
	switch (c)
	{
		case 'c':	//	cake
		{
			Cake* cake = dynamic_cast<Cake*>(m_gameMap[m_posX][m_posY].item);
			if (cake != nullptr)
			{
				cake->Use();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to use..." << std::endl;
			}
			break;
		}
		case 'a':	//	cat
		{
			Cat* cat = dynamic_cast<Cat*>(m_gameMap[m_posX][m_posY].item);
			if (cat != nullptr)
			{
				cat->Use();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to use..." << std::endl;
			}
			break;
		}
		case 'd':	//	dog
		{
			Dog* dog = dynamic_cast<Dog*>(m_gameMap[m_posX][m_posY].item);
			if (dog != nullptr)
			{
				dog->Use();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to use..." << std::endl;
			}
			break;
		}
		case 'o':	//	door
		{
			Door* door = dynamic_cast<Door*>(m_gameMap[m_posX][m_posY].item);
			if (door != nullptr)
			{
				door->Use();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to use..." << std::endl;
			}
			break;
		}
		case 'l':	//	lamp
		{
			Lamp* lamp = dynamic_cast<Lamp*>(m_gameMap[m_posX][m_posY].item);
			if (lamp != nullptr)
			{
				lamp->Use();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to use..." << std::endl;
			}
			break;
		}
	}
}

void Game::m_TryInspect(char c)
{
	switch (c)
	{
		case 'c':	//	cake
		{
			Cake* cake = dynamic_cast<Cake*>(m_gameMap[m_posX][m_posY].item);
			if (cake != nullptr)
			{
				cake->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
		case 'a':	//	cat
		{
			Cat* cat = dynamic_cast<Cat*>(m_gameMap[m_posX][m_posY].item);
			if (cat != nullptr)
			{
				cat->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
		case 'd':	//	dog
		{
			Dog* dog = dynamic_cast<Dog*>(m_gameMap[m_posX][m_posY].item);
			if (dog != nullptr)
			{
				dog->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
		case 'o':	//	door
		{
			Door* door = dynamic_cast<Door*>(m_gameMap[m_posX][m_posY].item);
			if (door != nullptr)
			{
				door->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
		case 'l':	//	lamp
		{
			Lamp* lamp = dynamic_cast<Lamp*>(m_gameMap[m_posX][m_posY].item);
			if (lamp != nullptr)
			{
				lamp->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
		case 's':
		{
			Skeleton* skeleton = dynamic_cast<Skeleton*>(m_gameMap[m_posX][m_posY].enemy);
			if (skeleton != nullptr)
			{
				skeleton->Description();
			}
			else
			{
				std::cout << "That didn't seem to be in the room to inspect..." << std::endl;
			}
			break;
		}
	}

}

void Game::m_TryCast(char c)
{
	Skeleton* skeleton = dynamic_cast<Skeleton*>(m_gameMap[m_posX][m_posY].enemy);

	if (skeleton != nullptr)
	{
		switch ('c')
		{
		case 'e':
			if (m_player->FindSpell("eruption") == true)
			{

			}
			else
			{
				std::cout << "You didn't seem to have that spell." << std::endl;
			}
			break;
		case 'f':
			if (m_player->FindSpell("frostbolt") == true)
			{

			}
			else
			{
				std::cout << "You didn't seem to have that spell." << std::endl;
			}
			break;
		case 'p':
			if (m_player->FindSpell("polymorph") == true)
			{

			}
			else
			{
				std::cout << "You didn't seem to have that spell." << std::endl;
			}
			break;
		default:
			std::cout << "You didn't seem to have that spell." << std::endl;
			break;
		}
	}
	else
	{
		std::cout << "It didn't seem like there was anything to cast a spell on..." << std::endl;
	}
}

void Game::m_TryAttack()
{
	Skeleton* skeleton = dynamic_cast<Skeleton*>(m_gameMap[m_posX][m_posY].enemy);

	if (skeleton != nullptr)
	{
		skeleton->TakeDamage(0);
	}
	else
	{
		std::cout << "It didn't seem like there was anything to attack..." << std::endl;
	}
}