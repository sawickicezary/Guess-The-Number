///////////////////////////////////////////////////////////////////
// NAME:               main.cpp
//
// PURPOSE:            Main drive to run program.
//
// FUNCTIONS/OBJECTS:  main			   
//					   
//
// AUTHOR:             Cezary Sawicki
///////////////////////////////////////////////////////////////////

#include <iostream>
#include "functions.h"


int main()
{
	
	while (1 < 2)
	{
		int iUserInput;
		system("cls");
		welcome_screen();
		iUserInput = get_user_input();
		choice(iUserInput);
		std::cin.ignore();
		std::cin.get();
	}
}