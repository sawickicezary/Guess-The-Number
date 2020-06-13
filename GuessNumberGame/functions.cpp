///////////////////////////////////////////////////////////////////
// NAME:               functions.cpp
//
// PURPOSE:            Generating main string for program.
//
// FUNCTIONS/OBJECTS:  generated_string
//
// AUTHOR:             Cezary Sawicki
///////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int* geometric_string(int iFirstNumber, int iFactor)
{
	int static result[] = { iFirstNumber,
					iFirstNumber * iFactor,
					iFirstNumber * iFactor * iFactor,
					iFirstNumber * iFactor * iFactor * iFactor };
	return result;
}

int* arithmetic_string(int iFirstNumber, int iFactor)
{
	int static result[] = { iFirstNumber,
					iFirstNumber + iFactor,
					iFirstNumber + iFactor + iFactor,
					iFirstNumber + iFactor + iFactor + iFactor };
	return result;
}

bool verify_result(int iUserInput, int iExpectedResult)
{
	if (iUserInput == iExpectedResult)
		return true;
	else
		return false;
}

int* generated_string()
{	
	int iFactor = rand() % 100 + 1;
	int iFirstNumber = rand() % 100 + 1;
	int iStringType = rand() % 2;
	int* iNumbers;

	if (iStringType)
		iNumbers = geometric_string(iFirstNumber, iFactor);
	else
		iNumbers = arithmetic_string(iFirstNumber, iFactor);

	return iNumbers;
}

void welcome_screen()
{
	cout << "Welcome in game made by Cezary Sawicki!" << endl;
	cout << "[ + ] Write 1 to play a game" << endl;
	cout << "[ + ] Write 2 to read description of game" << endl;
	cout << "[ + ] Write 3 to quit" << endl;
}

int get_user_input()
{
	int iChoice = 0;
	bool bValid = true;
	cin >> iChoice;
	if (cin.fail())
		bValid = false;

	if (bValid)
		return iChoice;
	else
	{
		cout << endl << "Wrong input type! Type number again." << endl;
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
	int* iString;
	srand(time(NULL));
	iString = generated_string();

	cout << endl << "Wyrazy ciagu: " << iString[0] << " " << iString[1] << " " << iString[2] << endl;
	int iGuess = get_user_input();
	bool bGuessed;
	bGuessed = verify_result(iGuess, iString[3]);
	if (bGuessed)
	{
		cout << "You guessed correctly!";
	}
	else
	{
		cout << "You lost!";

}
void description()
{
	system("cls");
	cout <<			"Player has to guess next number." << endl;
	cout << endl << "[ + ]  Game steps:";
	cout << endl << "[ 1 ]  User sees 3 first numbers of a string (geometric or arythmetic only)";
	cout << endl << "[ 2 ]  User has to input the next number";
	cout << endl << "[ 3 ]  The results are going to be shown" << endl;;

}