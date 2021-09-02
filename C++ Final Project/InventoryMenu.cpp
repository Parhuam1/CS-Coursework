// Implement Files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "InventoryMenu.h"
#include "Book.h"
#include "BookInformation.h"
#include "Check.h"	
#include "strupper.h"
#include "File.h"
#include "FileContents.h"
#include "Menu.h"

using namespace std;

const int STR_SIZE = 51;			 // MAXIMUM STRING SIZE

// Ask the user to enter all or part of the title.
// If found, ask if it was the correct match.
// If it was, return the book's index.
// If not found, return -1
int findBook(Books& allBooks) {
	char title[STR_SIZE];

	Check menuInput;				 // Check Class
	Menu bookMenu;				     // Menu class

	cin.ignore();
	cout << endl;
	cout << "Please enter all or part of the title: ";
	cin.getline(title, STR_SIZE);
	strUpper(title);				// Convert title to uppercase							

	for (int i = 0; i < allBooks.getNumBooks(); i++) {
		if (allBooks.getBook(i).match(title)) // If book found was match
		{
			cout << endl;
			cout << "Possible Match Found:  " << allBooks.getBook(i).getTitle() << endl << endl; // Display match
			do
			{
				cout << "Is this what you were searching for?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl << endl;
			} while (!menuInput.isValid(bookMenu.itemListPrompt(), 1, 2)); // Check user input

			if (menuInput.getIntCheck() == 1)
			{
				return i;
			}
		}
	}

	cout << endl;
	cout << "No match \'" << title << "\' was found." << endl << endl;
	return -1;
}

// Looks for book in inventory
void lookUpBook(Books& allBooks)
{
	int bookIndex = findBook(allBooks);
	if (bookIndex == -1) {
		return;
	}
	
	bookInfo(allBooks.getBook(bookIndex));
}	

// Adds book to inventory by updating allBooks.  Changes are only
// written to the file when we leave the inventory menu.
// Updating all at once keeps things simpler.
void addBook(Books& allBooks)
{								// Stores what user inputs
	char title[STR_SIZE];		// Book title
	char isbn[STR_SIZE];		// Book ISBN
	char author[STR_SIZE];	    // Book author
	char publisher[STR_SIZE];	// Book publisher
	char date[STR_SIZE];		// Book data
	int  quantity;			    // Book Quantity
	double wholesale;			// Book Wholesale
	double retail;				// Book retail

	Book newBook;

	cin.ignore();
	
	cout << endl;
	cout << "Enter Title: ";
	cin.getline(title, STR_SIZE);
	newBook.setTitle(title);
	
	cout << endl;
	cout << "Enter ISBN(###-###-###): ";
    cin.getline(isbn, STR_SIZE);
	newBook.setISBN(isbn);
	
	cout << endl;
	cout << "Enter Author: ";
	cin.getline(author, STR_SIZE);
	newBook.setAuthor(author);
	
	cout << endl;
	cout << "Enter Publisher: ";
	cin.getline(publisher, STR_SIZE);
	newBook.setPub(publisher);

	cout << endl;
	cout << "Enter Date Added to Inventory(MM/DD/YYYY): ";
	cin.getline(date, STR_SIZE);
	newBook.setDateAdded(date);

	cout << endl;
	cout << "Enter Quantity Being Added: ";
	cin >> quantity;
	newBook.setQty(quantity);
	
	cout << endl;
	cout << "Enter Wholesale Cost: ";
	cin >> wholesale;
	newBook.setWholesale(wholesale);
	
	cout << endl;
	cout << "Enter Retail Price: ";
	cin >> retail;
	newBook.setRetail(retail);
	
	cout << endl << endl;
	cout << "Record was successfully entered." << endl;

	allBooks.appendToInventory(newBook);
}	

// Edits book in inventory.
void editBook(Books& allBooks)
{									// Stores what user inputs
	char   title[STR_SIZE];			// Book title
	char   isbn[STR_SIZE];			// Book ISBN
	char   author[STR_SIZE];		// Book author
	char   publisher[STR_SIZE];		// Book publisher
	char   date[STR_SIZE];			// Book data
	int    quantity;				// Book Quantity
	double wholesale;				// Book Wholesale
	double retail;					// Book retail

	Check menuInput;				// Check class
	Menu bookMenu;					// Menu class
	
	int bookIndex = findBook(allBooks);
	if (bookIndex == -1) {
		return;
	}

	// We found the book that the user wants to edit
	// First print the whole book out, for convenience, to help remind them
	// what they may want to change.
	Book& book = allBooks.getBook(bookIndex);
	bookInfo(book);
	
	do {
		cout << endl;
		cout << "You may edit any of the following fields:" << endl;
		cout << "\t1.  ISBN" << endl;
		cout << "\t2.  Title" << endl;
		cout << "\t3.  Author's Name" << endl;
		cout << "\t4.  Publisher's Name" << endl;
		cout << "\t5.  Date Book Was Added To Inventory" << endl;;
		cout << "\t6.  Quantity On Hand" << endl;
		cout << "\t7.  Wholesale Cost" << endl;
		cout << "\t8.  Retail Price" << endl;
		cout << "\t9.  Exit" << endl << endl;

		cout << "Please choose 1 - 8 to EDIT an item, or 9 to EXIT\n";
	} while (!menuInput.isValid(bookMenu.itemListPrompt(), 1, 9)); // Check input

	switch (menuInput.getIntCheck()) // Display inputs
	{
	case 1:
		cout << endl;
		cout << "Current ISBN:  "<< book.getISBN() << endl;
		cin.ignore();
		cout << "Enter new ISBN(###-###-###): ";
		cin >> isbn;
		book.setISBN(isbn);
		break;

	case 2:
		cout << endl;
		cout << "Current Title:  " << book.getTitle() << endl;
		cin.ignore();
		cout << "Enter new Title:  ";
		cin.getline(title, STR_SIZE);
		book.setTitle(title);
		break;

	case 3:
		cout << endl;
		cout << "Current Author:  " << book.getAuthor() << endl;
		cin.ignore();
		cout << "Enter new Author:  ";
		cin.getline(author, STR_SIZE);
		book.setAuthor(author);
		break;

	case 4:
		cout << endl;
		cout << "Current Publisher:  " << book.getPub() << endl;
		cin.ignore();
		cout << "Enter new Publisher:  ";
		cin.getline(publisher, STR_SIZE);
		book.setPub(publisher);
		break;

	case 5:
		cout << endl;
		cout << "Current Date Entered Into Inventory:  " << book.getDateAdded() << endl;
		cin.ignore();
		cout << "Enter new Date(MM/DD/YYYY):  ";
		cin.getline(date, STR_SIZE);
		book.setDateAdded(date);
		break;

	case 6:
		cout << endl;
		cout << "Current Quantity on Hand:  " << book.getQty() << endl;
		cin.ignore();
		cout << "Enter new Quantity on Hand:  ";
		cin >> quantity;
		book.setQty(quantity);
		break;

	case 7:
		cout << endl;
		cout << "Current Wholesale Cost:  " << book.getWholesale() << endl;
		cin.ignore();
		cout << "Enter new Wholesale Cost:  ";
		cin >> wholesale;
		book.setWholesale(wholesale);
		break;

	case 8:
		cout << endl;
		cout << "Current Retail Price:  " << book.getRetail() << endl;
		cin.ignore();
		cout << "Enter new Retail Price:  ";
		cin >> retail;
		book.setRetail(retail);
		break;

	case 9:
		// They decided not to edit this book
		break;
	}

	// Done editing the book in memory.  Changes will be written to the file
	// when we leave the inventory database menu.
}	


// Delete book in inventory 
void deleteBook(Books& allBooks)
{
	int bookIndex = findBook(allBooks);
	if (bookIndex == -1) {
		return;
	}

	Book& book = allBooks.getBook(bookIndex);
	
	// Print the book and ask if they really want to delete it
	bookInfo(book);

	Menu bookMenu;
	Check menuInput;

	do
	{
		cout << "Would you like to delete this entire record? Press Y for Yes, press N for no." << endl;
	} while (!menuInput.isValid(bookMenu.simplePrompt())); // Check input
	
	if (strcmp(menuInput.getCheck(), "Y") == 0) {
		allBooks.deleteFromInventory(bookIndex);

		cout << endl;
		cout << "Record has been deleted." << endl; // Result
	} 
	else {
		cout << endl;
		cout << "Record was not deleted." << endl;
	}
} 

void inventory() {
	// Start off by reading the inventory file into memory.
	// We will make changes to "allBooks" until the user is
	// done with the inventory menu, at which time we will
	// write changes (if any) back to the inventory file.
	Books allBooks(inventoryFileName);
	
	Menu bookMenu;
	bool done = false;

	while (!done) { // Display Inventory menu until user inputs 5
		Check menuInput;

		do	// Until item is chosen
		{
			bookMenu.invMenu();
		} while (!menuInput.isValid(bookMenu.itemListPrompt(), 1, 5)); // Validate input
		
		switch (menuInput.getIntCheck())								// Choose selected options
		{
		case 1:
			lookUpBook(allBooks);	// lookUpBook function
			break;

		case 2:
			addBook(allBooks);		// addBook function
			break;

		case 3:
			editBook(allBooks);		// editBook function
			break;

		case 4:
			deleteBook(allBooks);	// deleteBook function
			break;

		case 5:
			// Back to main menu.  Write changes, if any, back to the file now.
			done = true;
			break;
		}
	}

	allBooks.writeAllChangesToFile(inventoryFileName);
}

