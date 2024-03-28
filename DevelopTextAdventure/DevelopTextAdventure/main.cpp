#include <iostream>
#include "Game.h"
#include "String.h"

int main()
{
	String exampleCommand("cast fire");

	String temp(exampleCommand, "cast ");	//	temp = "fire" with null terminator

	temp.WriteToConsole();	//	outputs "fire"

	
/*	Game* myGame = new Game;
	
	myGame->Run();*/	
	
	return 0;
}