#pragma once
///////////////////////////////////////////////////////////////////
// NAME:               functions.h
//
// PURPOSE:            Declarations of functions required to run program.
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


int * geometric_string(int iFirstNumber, int iFactor); 
int * arithmetic_string(int iFirstNumber, int iFactor);
bool verify_result(int iUserInput, int iExpectedResult);
void welcome_screen();
int get_user_input();
void choice(int iChoice);