


#define _CRT_SECURE_NO_WARNINGS
#include "check.h"
#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;


// Constructor of the Check class
// Pre: none
// Post: none
// Return: none
Check::Check()
{
	strcpy(input, "");
}


// Convert C-string to uppercase
// Pre: userinput - a pointer to a char
// Post: c-string is now uppercase
// Return: none
void Check::cstrUpper(char* userinput)
{
	while (*userinput != '\0')
	{
		*userinput = toupper(*userinput);
		userinput++;
	}
}

// Returns char input
// Pre: none
// Post: returns
// Return: char input
char* Check::getCheck()
{
	return input;
}

// Returns converted string to interger
// Pre: none
// Post: Converts string
// Return: integer input
int Check::getIntCheck()
{
	return atoi(input);
}


/*
bool Check::checkNegative(Dollar check)
{
	// if ((check.whole * 100) + part < 0);
}
*/


// Checks user's input is between set integer paramaeters.
// Only stores the user's input if it was valid.
// Pre: userinput - a pointer to a char, startRange - integer, endRange - integer
// Post: checks if input is between range
// Return: true or false
bool Check::isValid(char* userinput, int startRange, int endRange)
{
	int intinput;    // Convert the c-string to an integer
	intinput = atoi(userinput);
	if (intinput < startRange || intinput > endRange) // Check input
	{                                                       // Invad input
		cout << "\n\t\tPlease enter a number in the range "    // Display valid input
			<< startRange << " - " << endRange << "." << endl << endl;
		return false;
	}
	strcpy(input, userinput); // Reset input
	return true;
}

