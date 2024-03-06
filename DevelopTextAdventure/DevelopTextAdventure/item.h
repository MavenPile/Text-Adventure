#pragma once

class Game;

class Item	//	this is an abstract class, it can only be derived, not instantiated
			//	the pure virtual functions below are what make this class abstract
			//	being abstract means it doesn't need constructors/destructors
{
protected:

	Game* m_myGame;

public:
	virtual void Description() const = 0;	//	a pure virtual function

	virtual void Use() = 0;	//	a pure virtual function
};

