#pragma once

class Item	//	this is an abstract class, it can only be derived, not instantiated
			//	the pure virtual functions below are what make this class abstract
{
private:

	char* name;

public:

	Item();

	~Item();

	virtual const char& GetName() = 0;	//	a pure virtual function, meaning it does nothing and makes the class abstract
	
	virtual void Description() = 0;	//	a pure virtual function

	virtual void Use() = 0;	//	a pure virtual function

protected:



};

