// Implement dfiles
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "Cashier.h"
#include "Book.h"				
#include "File.h"	
#include "FileContents.h"
#include "Check.h"	
using namespace std;

const double SALES_TAX = 0.06;					// Sales tax rate
const int    STR_SIZE = 51;						// MAX SIZE OF STRING


// Ask the user to type in an ISBN and return the array index of
// the book, if found.  If not found, give them a chance to re-enter
// the ISBN if desired.  If the user doesn't want to enter an ISBN,
// we return -1.
static int GetISBN(const Books& allBooks) {
	char isbn[MAX_LINE_SIZE];
	while (true) {
		cout << "ISBN(###-###-###): ";					// Ask user to input ISBN number

		cin.getline(isbn, MAX_LINE_SIZE);

		int bookIndex = allBooks.FindBookByISBN(isbn);
		if (bookIndex != -1) {
			// The ISBN was successfully found
			return bookIndex;
		}

		// The ISBN was not found.  Ask user if they want to try again
		// If they don't, we'll return -1.
		cout << endl;
		cout << "ISBN was not found" << endl << endl;

		while (true) {
			cout << "Re-enter ISBN?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl << endl;
			
			Check menuInput;
			
			char line[MAX_LINE_SIZE];
			cin.getline(line, MAX_LINE_SIZE);

			bool ok = menuInput.isValid(line, 1, 2);

			if (!ok) {
				// They didn't type 1 or 2
				continue;
			}
			else if (menuInput.getIntCheck() == 2) {
				// They don't want to enter another ISBN
				return -1;
			}
			else {
				// They do want to try again
				break;
			}
		}
	}
}

int GetQuantityToPurchase(const Book& book) {
	// Ask user how many copies of this book they want to purchase
	if (book.getQty() <= 0) {
		cout << "Sorry, there are no copies of this book in stock currently.  Cannot purchase any." << endl;
		return 0;
	}

	cout << "There ";
	if (book.getQty() == 1) {
		cout << "is 1 copy";
	}
	else {
		cout << "are " << book.getQty() << " copies";
	}
	cout << " in stock." << endl;

	Check menuInput;

	while (true) {
		cout << "Enter number to purchase : ";
		char line[CHECK_INPUT_SIZE];
		cin >> line;
		cin.ignore();

		if (!menuInput.isValid(line, 0, book.getQty())) {
			cout << "Invalid number of books to purchase" << endl;
			continue;
		}

		break;
	}

	// Return the number purchased.  It will either be 0 if the customer
	// changed their minds, or it will be <= the quantity of this book
	// in stock.
	return menuInput.getIntCheck();
}

static void StoreCashierChanges(const Books& allBooks) {
	allBooks.writeAllChangesToFile(inventoryFileName);
}

static bool GetContinueWithCashierMenu() {
	Check menuInput;
	char line[MAX_LINE_SIZE];

	do {
		cout << endl;
		cout << "Add another title to this order?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl << endl;
		cin.getline(line, MAX_LINE_SIZE);
	} while (!menuInput.isValid(line, 1, 2)); // Check input

	return (menuInput.getIntCheck() == 1);
}


class ShoppingCart {
private:
	// For each distinct book, keep track of the book's index and how many of that
	// book are in the shopping cart.

	// The following is a dynamic array.  The array index is the book index,
	// the same as in class Books.  The value is the number of that book
	// currently in the shopping cart.
	int* bookIndexToNumInCart;
	int numDistinctBooks;

public:
	ShoppingCart(int numBooks) {
		numDistinctBooks = numBooks;

		bookIndexToNumInCart = new int[numDistinctBooks];

		for (int i = 0; i < numDistinctBooks; i++) {
			bookIndexToNumInCart[i] = 0;
		}
	};

	void addBook(int bookIndex, int quantity) {
		bookIndexToNumInCart[bookIndex] += quantity;
	}

	int numberInCart(int bookIndex) const {
		return bookIndexToNumInCart[bookIndex];
	}
};

void cashier()
{
	char	transDate[STR_SIZE];				// Transaction date
	
	double	subTotal = 0;						// Total before sales tax

	Check menuInput;							// Check class
	Menu bookMenu;								// Menu class								

	// First initialize book[] from the contents of the file.
	Books allBooks(inventoryFileName);

	// Display the Cashier Module welcome screen once, no matter how
	// many books are being entered.  That also means we only have
	// to enter today's date once.  We assume that the store is not open
	// past midnight.  If this store is open past midnight, we can
	// move the date into the loop.
	cout << endl << endl;
	cout << "Serendipity Booksellers" << endl;	// Display Header
	cout << " Cashier Module" << endl << endl;

	cin.ignore();								// Input date of purchase
	cout << "Enter Today's Date: ";
	cin.getline(transDate, STR_SIZE);

	ShoppingCart cart(allBooks.getNumBooks());

	bool firstTimeThrough = true;

	while (true) {
		cout << "\n\nSerendipity Book Sellers" << endl << endl;	    // Display Header
		cout << "Date: " << transDate << endl << endl;				// Display Date
		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal" << endl; // Display Header 2	
		cout << "________________________________________";
		cout << "________________________________________";
		cout << endl;

		// Print out what's currently in the cart, if anything.
		for (int i = 0; i < allBooks.getNumBooks(); i++) {
			int numInCart = cart.numberInCart(i);
			if (numInCart == 0) {
				continue;
			}

			const Book& book = allBooks.getBook(i);

			cout << fixed << showpoint << right << setprecision(2); // Display order information
			cout << numInCart << "\t";
			cout << left << setw(14) << book.getISBN() << "\t";
			cout << left << setw(26) << book.getTitle() << "\t$ ";
			cout << fixed << showpoint << right;
			cout << setw(6) << book.getRetail() << "\t$ ";
			cout << setw(6) << book.getRetail() * numInCart;
			cout << endl;
		}

		cout << endl << endl << endl;

		cout << "\t\t\tSubtotal\t\t\t\t\t$ " << setw(6) << setprecision(2) << fixed << subTotal << endl; // Display final information
		cout << "\t\t\tTax\t\t\t\t\t\t$ " << setw(6) << setprecision(2) << fixed << subTotal * SALES_TAX << endl;
		cout << "\t\t\tTotal\t\t\t\t\t\t$ " << setw(6) << setprecision(2) << fixed << subTotal * (1.0 + SALES_TAX) << endl << endl;

		// Done printing the cart's contents.

		if (firstTimeThrough) {
			firstTimeThrough = false;
		}
		else {
			// Ask if they want to continue, or check out now
			if (!GetContinueWithCashierMenu()) {
				break;
			}
		}

		// Ask for an ISBN for a book to purchase
		int bookIndex = GetISBN(allBooks);
		if (bookIndex == -1) {
			// The user didn't want to enter the ISBN, so leave the cashier module.
			// First, write any changes to the file.
			StoreCashierChanges(allBooks);
			break;
		}

		// This is the book we will work with.  We use a reference so changes we make
		// to book are also reflected in the array.
		Book & book = allBooks.getBook(bookIndex);
		cout << "Title: " << book.getTitle() << endl;
		cout << fixed << showpoint << setprecision(2) << "Price: " << book.getRetail() << endl;

		// The following call returns the number to purchase, or 0 if they don't want
		// to purchase anything (or if there was bad input)
		int quantity = GetQuantityToPurchase(book);
		if (quantity > 0) {
			// Purchase this book now.  Update the book array in memory and add to
			// the shopping cart.  We don't yet write to the file - that waits
			// until we check out.
			subTotal += quantity * book.getRetail();
			// We have already done sufficient checks so that the quanity won't
			// go negative here.
			book.setQty(book.getQty() - quantity);
			cart.addBook(bookIndex, quantity);

			cout << "Purchase completed for this book." << endl;
		}
	}

	// We have exited the main loop for the cashier.
	// Print a goodbye message, and update the file based on
	// the contents of allBooks.
	cout << "Thank You for Shopping at Serendipity!" << endl;
	StoreCashierChanges(allBooks);
}
