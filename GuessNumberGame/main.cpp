#include <iostream>

#include "functions.h"


using namespace std;


int main()
{
	
	while (1 < 2)
	{
		int iUserInput;
		system("cls");
		welcome_screen();
		iUserInput = get_user_input();
		choice(iUserInput);
		cin.ignore();
		cin.get();
	}
}