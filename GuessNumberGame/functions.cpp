///////////////////////////////////////////////////////////////////
// NAME:               functions.cpp
//
// PURPOSE:            Definitions of functions required to run program.
//
// FUNCTIONS/OBJECTS:  geometric_string
//                     arithmetic_string
//                     verify_result
//					   welcome_screen
//					   get_user_input
//					   choice
//
// AUTHOR:             Cezary Sawicki
///////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <iostream>
#include <time.h>


int* geometric_string(int iFirstNumber, int iFactor, int * tab)
{
	tab[0] = iFirstNumber;
	tab[1] = iFirstNumber * iFactor;
	tab[2] = iFirstNumber* iFactor* iFactor;
	tab[3] = iFirstNumber * iFactor * iFactor * iFactor;
	return tab;
}

int* arithmetic_string(int iFirstNumber, int iFactor, int * tab)
{
	for (int i = 0; i < 4; i++)
	{
		tab[i] = iFirstNumber + (i * iFactor);
	}
	return tab;
}

bool verify_result(int iUserInput, int iExpectedResult)
{
	if (iUserInput == iExpectedResult)
		return true;
	else
		return false;
}

int* generated_string(int * tab)
{	
	int iFactor = rand() % 100 + 1;
	int iFirstNumber = rand() % 100 + 1;
	int iStringType = rand() % 2;
	int* iNumbers;

	if (iStringType)
		iNumbers = geometric_string(iFirstNumber, iFactor, tab);
	else
		iNumbers = arithmetic_string(iFirstNumber, iFactor, tab);

	return iNumbers;
}

void welcome_screen()
{
	std::cout << "Welcome in game made by Cezary Sawicki!" << std::endl;
	std::cout << "[ + ] Write 1 to play a game" << std::endl;
	std::cout << "[ + ] Write 2 to read description of game" << std::endl;
	std::cout << "[ + ] Write 3 to quit" << std::endl;
}

int get_user_input()
{
	int iChoice = 0;
	bool bValid = true;
	std::cin >> iChoice;
	if (std::cin.fail())
		bValid = false;

	if (bValid)
		return iChoice;
	else
	{
		std::cout << std::endl << "Wrong input type! Type number again." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		return get_user_input();
	}

}

void game();
void description();

void choice(int iChoice)
{
	switch (iChoice)
	{
	case 1:
		game();
		break;
	case 2:
		description();
		break;
	case 3:
		exit(0);
	default:
		break;
	}
}


void game()
{
	srand(time(NULL));
	int * iString = new int[4];
	generated_string(iString);

	std::cout << std::endl << "Wyrazy ciagu: " << iString[0] << " " << iString[1] << " " << iString[2] << std::endl;
	int iGuess = get_user_input();
	bool bGuessed;
	bGuessed = verify_result(iGuess, iString[3]);
	if (bGuessed)
	{
		std::cout << "You guessed correctly!";
		delete[] iString;
	}
	else
	{
		std::cout << "You lost!";
		delete[] iString;
	}
}
void description()
{
	system("cls");
	std::cout <<			"Player has to guess next number." << std::endl;
	std::cout << std::endl << "[ + ]  Game steps:";
	std::cout << std::endl << "[ 1 ]  User sees 3 first numbers of a string (geometric or arythmetic only)";
	std::cout << std::endl << "[ 2 ]  User has to input the next number";
	std::cout << std::endl << "[ 3 ]  The results are going to be shown" << std::endl;;

}