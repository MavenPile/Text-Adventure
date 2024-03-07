#include "Book.h"
#include "String.h"
#include "Player.h"
#include "Room.h"

Book::Book()
{
	m_myGame = nullptr;
	m_myRoom = nullptr;
	m_isOpen = false;
	m_desc = nullptr;
}

Book::Book(Room* myRoom)
{
	m_myGame = nullptr;
	m_myRoom = myRoom;
	m_isOpen = false;
	m_desc = new String("The book lays closed...");
}

Book::~Book()
{
	delete m_myGame;
	delete m_myRoom;
	delete m_desc;
}

void Book::Description() const
{
	m_desc->WriteToConsole();
}

void Book::Use()
{
	m_isOpen = !m_isOpen;

	std::cout << "You use the book..." << std::endl;

	if (m_isOpen)
	{
		delete m_desc;

		String* newDesc = new String("The book contains writings of spells of Fire, Ice, and Thunder... You resonate with this...");

		m_desc = newDesc;

		String newRoomDesc("There's a lectern with an opened book in this room...");

		m_myRoom->ChangeDesc(newRoomDesc);
	}
	else
	{
		delete m_desc;

		String* newDesc = new String("The book lays closed...");

		m_desc = newDesc;

		String newRoomDesc("There's a lectern with a book in this room...");

		m_myRoom->ChangeDesc(newRoomDesc);
	}
}
