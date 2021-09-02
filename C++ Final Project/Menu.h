#pragma once
#ifndef MENU_H
#define MENU_H

// Implement files
#include "Book.h"

const int PROMPT_SIZE = 51;			// MAXIMUM STRING SIZE

class Menu
{
private:
	char input[PROMPT_SIZE];		// User's input
public:
	Menu();						    // Constructor
	void mainMenu();				// Main menu output
	void invMenu();					// Inventory menu output
	void reports();					// Report menu output
	char* itemListPrompt();			// Set input
	char* simplePrompt();			// Set input
};

#endif