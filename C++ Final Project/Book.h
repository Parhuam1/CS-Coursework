#pragma once
#ifndef BOOKDATA_H
#define BOOKDATA_H

// Implement Files
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

const int CSTR_SIZE = 51;				    // MAX SIZE OF STRING
class File;

class Book{
private:									// Book requirements
	char bookTitle[CSTR_SIZE];				// Title
	char isbn[CSTR_SIZE];					// ISBN 
	char author[CSTR_SIZE];					// Author
	char publisher[CSTR_SIZE];				// Publisher 
	char dateAdded[CSTR_SIZE];				// Date a book was added into inventory
	int	 qtyOnHand;							// Quantity on hand 
	double	wholesale;						// Wholesale cost
	double	retail;							// Retail price 
public:
	Book();							// Constructor

											// Sets book's requirements
	void setTitle(char*);					// Set title
	void setISBN(char*);					// Set ISBN
	void setAuthor(char*);					// Set author
	void setPub(char*);						// Set publisher
	void setDateAdded(char*);				// Set date a book was added into inventory
	void setQty(int);						// Set quantity on hand 
	void setWholesale(double);				// Set wholesale cost
	void setRetail(double);					// Set retail price

											// Return book's requirements
	const char* getTitle() const;			// Return title
	const char* getISBN() const;			// Return ISBN
	const char* getAuthor() const;			// Returns author
	const char* getPub() const;				// Returns publisher
	const char* getDateAdded() const;		// Returns date a book was added into inventory
	int getQty() const;						// Returns quantity on hand 
	double getWholesale() const;			// Returns wholesale cost
	double getRetail() const;			    // Returns retail price

	bool match(const char* partial) const;	// Returns true if a match is found (title search - partial matches allowed)

	int getPurchaseYear() const;
	int getPurchaseMonth() const;
	int getPurchaseDay() const;
};

// Dynamically allocated number of books in the inventory.
// There cannot be a fixed number because the inventory menu
// lets us add or delete books.
class Books {
private:
	int numDistinctBooks;
	Book* bookArray; // allocated with new[], deleted with delete[]

	// Sort the books using a generic "less than" function supplied by
	// the caller.  This lets us sort by different fields.
	void sort(bool(*lessThan)(const Book& left, const Book& right));

public:
	// This constructor initializes the book array by reading the file
	Books(const char *inventoryFileName);
	
	int getNumBooks() const;
	void writeAllChangesToFile(const char *inventoryFileName) const;
	int FindBookByISBN(const char *isbn) const;

	Book& getBook(int index);

	// Add a new distinct book to the inventory of all books.
	void appendToInventory(const Book& book);	

	// Delete a book, by book index, from the inventory.
	void deleteFromInventory(int index);

	void sortByQuantity();
	void sortByCost();
	void sortByAge();
};
#endif