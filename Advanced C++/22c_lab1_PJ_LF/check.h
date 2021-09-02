#pragma once

#ifndef CHECK_H
#define _CRT_SECURE_NO_WARNINGS
#define CHECK_H

const int CHECK_INPUT_SIZE = 81; // constant array size

class Check {
private:
	char input[CHECK_INPUT_SIZE];					// variable to hold user input 
	void cstrUpper(char*);							// Convert C-string to uppercase

public:
	Check();										// Constructor 
	char* getCheck();								// Returns char input
	int getIntCheck();								// Returns converted string to interger
	bool isValid(char*, int, int);					// Checks user's input is between set integer paramaeters. Only stores the user's input if it was valid.
};

#endif