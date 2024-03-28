#include <iostream>
#include "Game.h"
#include "String.h"

int main()
{
	String exampleCommand("cast fire");

	exampleCommand.ToLower();

	String temp(exampleCommand, "cast ");

	temp.WriteToConsole();

	
/*	Game* myGame = new Game;
	
	myGame->Run();*/	
	
	return 0;
}