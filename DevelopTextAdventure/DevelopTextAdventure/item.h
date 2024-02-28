#pragma once
#include "String.h"

class Item	//	this is an abstract class, it can only be derived, not instantiated
			//	the pure virtual functions below are what make this class abstract
			//	being abstract means it doesn't need constructors/destructors
{
private:



public:

	virtual String GetName() = 0;	//	a pure virtual function, meaning it does nothing and makes the class abstract
	
	virtual String Description() = 0;	//	a pure virtual function

	virtual void Use() = 0;	//	a pure virtual function

protected:



};

