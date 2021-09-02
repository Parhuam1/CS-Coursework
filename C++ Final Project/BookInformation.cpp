// Implement files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "BookInformation.h"
using namespace std;

// Book info function
void bookInfo(const Book& book) {
	// Display header
	cout << "\t\t\tSerendipity Booksellers" << endl;
	cout << "\t\t\t    Book Information" << endl << endl;

	// Display book information
	cout << "ISBN: " << book.getISBN() << endl;
	cout << "Title: " << book.getTitle() << endl;
	cout << "Author: " << book.getAuthor() << endl;
	cout << "Publisher: " << book.getPub() << endl;
	cout << "Date Added: " << book.getDateAdded() << endl;
	cout << "Quantity-On-Hand: " << book.getQty() << endl;
	cout << "Wholesale Cost: " << fixed << showpoint << setprecision(2) << book.getWholesale() << endl;
	cout << "Retail Price: " << fixed << showpoint << setprecision(2) << book.getRetail() << endl << endl << endl;
}	
