// Implement files
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor, set to empty
Menu::Menu()
{
	strcpy(input, "\0");
}

// Display main menu
void Menu::mainMenu()
{
	cout << endl << endl;						 // Display header
	cout << "Serendipity Booksellers" << endl;
	cout << "\tMain Menu";
	cout << endl << endl;

	cout << "1.Cashier Module" << endl;		     // Display inputs
	cout << "2.Inventory Database Module" << endl;
	cout << "3.Report Module" << endl;
	cout << "4.Exit" << endl << endl;
}

// Display inventory menu
void Menu::invMenu()
{
	cout << endl << endl;						 // Display header
	cout << "\tSerendipity Booksellers" << endl;
	cout << "\tInventory Database" << endl << endl;

	cout << "\t\t1.Look Up a Book" << endl;      // Display inputs
	cout << "\t\t2.Add a Book" << endl;
	cout << "\t\t3.Edit a Book's Record" << endl;
	cout << "\t\t4.Delete a Book" << endl;
	cout << "\t\t5.Return to the Main Menu" << endl << endl;
}

// Display report menu
void Menu::reports()
{
	cout << endl << endl;						// Display header						
	cout << "\t\t\tSerendipity Booksellers" << endl;
	cout << "\t\t\t\tReports" << endl << endl;

	cout << "\t\t1.Inventory Listing" << endl;	// Display inputs
	cout << "\t\t2.Inventory Wholesale Value" << endl;
	cout << "\t\t3.Inventory Retail Value" << endl;
	cout << "\t\t4.Listing by Quantity" << endl;
	cout << "\t\t5.Listing by Cost" << endl;
	cout << "\t\t6.Listing by Age" << endl;
	cout << "\t\t7.Return to the Main Menu" << endl << endl;
}

// Set input
char* Menu::itemListPrompt()
{
	cout << "Enter your choice: ";
	cin >> input;
	return input;
}

// Set input 
char* Menu::simplePrompt()
{
	cin >> input;
	return input;
}