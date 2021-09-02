// Implement files						
#define _CRT_SECURE_NO_WARNINGS
#include "MainMenu.h"
#include "Check.h"	
#include "Cashier.h"
#include "File.h"
#include "Book.h"	
#include "InventoryMenu.h"
#include "ReportMenu.h"
#include "Menu.h"	


Menu bookMenu;							// Menu class
Check menuInput;					    // Check class

int main()
{
	while (true)
	{
		bookMenu.mainMenu();
		if (!menuInput.isValid(bookMenu.itemListPrompt(), 1, 4)) { // Get the input & validate.  Fill in 'menuInput.input' if successful.
			continue;
		}

		switch (menuInput.getIntCheck())                    // Choose selected option
		{
		case 1:
			cashier();										 // Cashier function
			break;

		case 2:
			inventory();
			break;	// Return main menu

		case 3:
			reports();
			break;

		case 4:	// Main menu selection 4: end program
			cout << endl << endl;
			cout << "Goodbye" << endl << endl;
			exit(0); // Instead of system("pause"), we exit(0) to completey close program 
			break;
		}
	}
	
	return 0;
}