// Implement files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Check.h"
#include "Menu.h"
#include "ReportMenu.h"
#include "FileContents.h"
#include "Book.h"
using namespace std;

// Print entire inventory
static void rListing(Books& allBooks)
{
	cout << "\t\tSerendipity Booksellers Inventory Listing" << endl << endl;  // Display title
	cout << fixed << showpoint << right << setprecision(2);
	for (int i = 0; i < allBooks.getNumBooks(); i++) {
		Book& book = allBooks.getBook(i);
		cout << endl;
		cout << "_____________________________________________________";
		cout << endl << endl;
		cout << "Title:\t\t\t" << book.getTitle();
		cout << endl;
		cout << "ISBN:\t\t\t" << book.getISBN();
		cout << endl;
		cout << "Author:\t\t\t" << book.getAuthor();
		cout << endl;
		cout << "Publisher:\t\t" << book.getPub();
		cout << endl;
		cout << "Date Added:\t\t" << book.getDateAdded();
		cout << fixed << showpoint << right << setw(2);
		cout << endl;
		cout << "Quantity On Hand:\t" << book.getQty();
		cout << endl;
		cout << "Wholesale Cost:\t\t" << book.getWholesale();
		cout << endl;
		cout << "Retail Price:\t\t" << book.getRetail();
	}
	cout << endl << endl;
	cout << "_____________________________________________________";
	cout << endl << endl;
	cout << "End of Inventory printout.";
	cout << endl << endl << endl;
	cout << "Press Enter to finish"; // For user to read
	cin.ignore();
	cin.get();
}

// Print Wholesale value of each book
static void rWholesale(Books& allBooks)
{
	cout << fixed << showpoint << right << setprecision(2);
	cout << "\t\tSerendipity Booksellers Inventory Listing" << endl << endl;
	cout << "\t\t\tWholesale Value Listing" << endl << endl;
	cout << "\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale";		// Display item heading
	cout << endl;
	cout << "\t_________________________________________________________________" << endl << endl;
	double	subTot = 0;

	for (int i = 0; i < allBooks.getNumBooks(); i++)
	{
		Book& book = allBooks.getBook(i);

		cout << endl;
		cout << "\t" << left << setw(26) << book.getTitle();
		cout << left << setw(14) << book.getISBN();
		cout << right << setw(6) << book.getQty() << "\t";
		cout << fixed << showpoint << right << setw(2);
		cout << setw(6) << "\t$ " << book.getWholesale();
		double itemSubTot = book.getQty() * book.getWholesale();
		subTot += itemSubTot;
	}

	cout << endl << endl << endl;
	cout << "\tTotal Wholesale Value:  $ " << subTot << endl;

	cout << "\t_________________________________________________________________" << endl;
	cout << endl;
	cout << "\tEnd of Wholesale printout.";
	cout << endl << endl << endl;
	
	cout << "Press Enter to finish"; // Pause
	cin.ignore();
	cin.get();
}


// Print the retail value of each book
static void rRetail(Books& allBooks)
{
	cout << fixed << showpoint << right << setprecision(2);
	cout << "\t\tSerendipity Booksellers Inventory Listing" << endl << endl;
	cout << "\t\t\t Retail Value Listing" << endl << endl;

	cout << "\tTitle\t\t\t  ISBN\t\tQuantity\tRetail";		// Display item heading
	cout << endl;
	cout << "\t_________________________________________________________________" << endl << endl;

	double subTot = 0;

	for (int i = 0; i < allBooks.getNumBooks(); i++)
	{
		Book& book = allBooks.getBook(i);

		cout << endl;
		cout << "\t" << left << setw(26) << book.getTitle();
		cout << left << setw(14) << book.getISBN();
		cout << fixed << showpoint << right << setw(2);
		cout << right << setw(6) << book.getQty() << "\t";
		cout << setw(6) << "\t$ " << book.getRetail();
		double itemSubTot = book.getQty() * book.getRetail();
		subTot += itemSubTot;
	}

	cout << endl << endl << endl;
	cout << "\tTotal Retail Value:  $ " << subTot << endl;

	cout << "\t_________________________________________________________________" << endl;
	cout << endl;
	cout << "\tEnd of Retail printout.";
	cout << endl << endl << endl;


	cout << "Press Enter to finish"; // Pause
	cin.ignore();
	cin.get();
}

// Sort by quantity
static void rQty(Books& allBooks)
{
	allBooks.sortByQuantity();
	rListing(allBooks);	
}

// Sort by Cost
static void rCost(Books& allBooks)
{
	allBooks.sortByCost();
	rListing(allBooks);
}


// Sort by age
static void rAge(Books& allBooks)
{
	allBooks.sortByAge();
	rListing(allBooks);
}

void reports() {
	Menu bookMenu;

	// Start off by reading the inventory file into memory.
	Books allBooks(inventoryFileName);

	// Display report menu until 7 is selected
	while (true)
	{
		Check menuInput;
		do
		{
			bookMenu.reports();
		} while (!menuInput.isValid(bookMenu.itemListPrompt(), 1, 7)); // Validate input

		switch (menuInput.getIntCheck()) // Choose selected options
		{
		case 1:
			rListing(allBooks);	    // rListing Function
			break;

		case 2:
			rWholesale(allBooks);	// rWholesale Function
			break;

		case 3:
			rRetail(allBooks);	    // rRetail Function
			break;

		case 4:
			rQty(allBooks);		    // call the rQty Function
			break;

		case 5:
			rCost(allBooks);	    // rCost Function
			break;

		case 6:
			rAge(allBooks);			// rAge Function
			break;

		case 7:
			return;
		}

	}
}
