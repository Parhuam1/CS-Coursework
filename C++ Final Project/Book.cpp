// Implement files
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include "File.h"
#include "FileContents.h"
#include "strUpper.h"

#include <string.h> // for strstr()

// Constructor, bookTitle set to c-string
Book::Book()
{
	strcpy(bookTitle, "\0");
}


// bookTitle set to c-string now stored into new book title
void Book::setTitle(char* newBookTitle)
{
	strcpy(bookTitle, newBookTitle);
}

// Return new booktitle
const char* Book::getTitle() const
{
	return bookTitle;
}

// ISBN set to c-string now stored into new ISBN
void Book::setISBN(char* newISBN)
{
	strcpy(isbn, newISBN);
}

// Return new ISBN
const char* Book::getISBN() const
{
	return isbn;
}

// Author set to c-string now stored into new Author
void Book::setAuthor(char* newAuthor)
{
	strcpy(author, newAuthor);
}

// Return new Author
const char* Book::getAuthor() const
{
	return author;
}

// Publisher set to c-string now stored into new Publisher
void Book::setPub(char* newPublisher)
{
	strcpy(publisher, newPublisher);
}

// Return new Publisher
const char* Book::getPub() const
{
	return publisher;
}

// Date added set to c-string now stored into new Date added
void Book::setDateAdded(char* newDateAdded)
{
	strcpy(dateAdded, newDateAdded);
}

// Return new Date added
const char* Book::getDateAdded() const
{
	return dateAdded;
}

// Quantity set to integer now stored into new Quantity
void Book::setQty(int newQuanityOnHand)
{
	qtyOnHand = newQuanityOnHand;
}

// Return new Quantity
int Book::getQty()	const
{
	return qtyOnHand;
}

// Wholesale set to double now stored into new Wholesale
void Book::setWholesale(double newWholesale)
{
	wholesale = newWholesale;
}

// Return new Wholesale
double Book::getWholesale()	const
{
	return wholesale;
}

// Retail set to double now stored into new Retail
void Book::setRetail(double newRetail)
{
	retail = newRetail;
}

// Return new retail
double Book::getRetail() const
{
	return retail;
}

bool Book::match(const char* partial) const {	// Returns true if a match is found (title search)
	// We assume that "partial" is already all uppercase, which
	// makes searching easier.  We make a scratch copy of the book title
	// and put it in all caps too.
	int len = strlen(bookTitle);
	char* capsTitle = new char[len + 1];
	strcpy(capsTitle, bookTitle);
	strUpper(capsTitle);

	return (strstr(capsTitle, partial) != nullptr);
}

int Book::getPurchaseYear() const {
	// The year string format is "MM/DD/YYYY".
	// So, all we need to do is skip past the first 2 '/' characters,
	// and then atoi() what is left.
	const char* ptr = strchr(dateAdded, '/');
	if (ptr == nullptr) {
		// malformed date
		return 0;
	}

	ptr++;
	ptr = strchr(ptr, '/');
	if (ptr == nullptr) {
		// malformed.  Could not find second /
		return 0;
	}

	ptr++;
	return atoi(ptr);
}

int Book::getPurchaseMonth() const {
	// The year string format is "MM/DD/YYYY".
	// So we can atoi right from the beginning, which will
	// stop when it hits the first '/'
	return atoi(dateAdded);
}

int Book::getPurchaseDay() const {
	// Search for and skip by the first '/', then atoi.
	const char* ptr = strchr(dateAdded, '/');
	if (ptr == nullptr) {
		// Malformed date.  Could not find first /
		return 0;
	}

	ptr++;
	return atoi(ptr);
}

Books::Books(const char* inventoryFileName) {
	numDistinctBooks = 0;
	bookArray = nullptr;

	ReadOnlyMode m;
	try {
		File invFile(inventoryFileName, m);

		while (!invFile.eof()) {
			// Read the next book from the file
			Book b;
			if (ReadOneBook(invFile, b)) {
				// b is now filled in with contents from the file
				appendToInventory(b);
			}
			else {
				// Failed to read book, so we either hit eof or
				// some kind of error	
			}
		}
	}
	catch (const char * errMsg) {
		cout << errMsg << endl;
	}
}

// Get num books
int Books::getNumBooks() const {
	return numDistinctBooks;
}

// Get book
Book& Books::getBook(int index) {
	return bookArray[index];
}

// Change File
void Books::writeAllChangesToFile(const char* inventoryFileName) const {
	WriteOnlyMode m;
	File invFile(inventoryFileName, m);
	
	for (int i = 0; i < numDistinctBooks; i++) {
		WriteOneBook(invFile, bookArray[i]);
	}
}

// Returns book index by ISBN number.  Returns -1 if not found.
int Books::FindBookByISBN(const char *isbn) const {
	for (int index = 0; index < numDistinctBooks; index++) {
		if (strcmp(bookArray[index].getISBN(), isbn) == 0) {
			return index;
		}
	}

	return -1;
}

	

void Books::appendToInventory(const Book& book) {
	// Allocate a new book array that is 1 larger than the old number of distinct books
	Book* newBookArray = new Book[numDistinctBooks + 1];

	// Copy the existing distinct books into the new larger array
	for (int i = 0; i < numDistinctBooks; i++) {
		newBookArray[i] = bookArray[i]; // copy a book (structure copy)
	}

	newBookArray[numDistinctBooks] = book; // fill in the new book

	delete[] bookArray;
	bookArray = newBookArray;
	numDistinctBooks++;
}

void Books::deleteFromInventory(int deleteIndex) {
	// index must be from 0 to numDistinctBooks-1
	// We make a newly allocated (smaller) array, and copy
	// over all items except the one being deleted.
	if (deleteIndex >= numDistinctBooks) {
		throw "Attempted to delete a bad book index";
	}

	Book* newBookArray = new Book[numDistinctBooks - 1];
	
	// When we write an item that isn't deleted, it goes here
	// within the new array.
	Book* destPtr = &newBookArray[0];

	for (int i = 0; i < numDistinctBooks; i++) {
		// So long as this isn't the book we're deleting,
		// copy it into newBookArray at the appropriate
		// position.
		if (i == deleteIndex) {
			continue;
		}
		
		// We are keeping this book.  Copy it.
		*destPtr = this->bookArray[i];
		destPtr++;
	}
	
	delete[] this->bookArray;
	this->bookArray = newBookArray;
	this->numDistinctBooks--;
}

void Books::sort(bool (*lessThan)(const Book& left, const Book& right)) {
	if (getNumBooks() <= 1) {
		// There is nothing to sort
		return;
	}

	// We use a selection sort

	for (int j = 0; j < getNumBooks() - 1; j++) {
		// Items [0, j) are already sorted.  We still need to sort
		// items [j, n).
		
		// Find the smallest item among indexes j through n-1, inclusive
		int minIndex = j;

		for (int i = j + 1; i < getNumBooks(); i++) {
			// Compare item with index i against minIndex
			// Use the lessThan function pointer.
			if (lessThan(getBook(i), getBook(minIndex))) {
				minIndex = i;
			}
		}

		if (minIndex != j) {
			Book temp = getBook(j);
			getBook(j) = getBook(minIndex);
			getBook(minIndex) = temp;
		}
	}
}

static bool quantityGreaterThan(const Book& left, const Book& right) {
	return (left.getQty() > right.getQty());
}

void Books::sortByQuantity() {
	// Sort order: Highest quantity first
	sort(quantityGreaterThan);
}

static bool wholesaleCostGreaterThan(const Book& left, const Book& right) {
	double leftCost = left.getQty() * left.getWholesale();
	double rightCost = right.getQty() * right.getWholesale();
	return leftCost > rightCost;
}

void Books::sortByCost() {
	// Sort order: total wholesale cost (number of this distinct book multiplied
	// by the wholesale cost of one of those books)
	sort(wholesaleCostGreaterThan);
}

static bool ageGreaterThan(const Book& left, const Book& right) {
	if (left.getPurchaseYear() < right.getPurchaseYear()) {
		return true;
	}
	else if (left.getPurchaseYear() > right.getPurchaseYear()) {
		return false;
	}

	// The years are equal.  Try the months.
	if (left.getPurchaseMonth() < right.getPurchaseMonth()) {
		return true;
	}
	else if (left.getPurchaseMonth() > right.getPurchaseMonth()) {
		return false;
	}

	// Both years and months are equal.  Try day of the month.
	if (left.getPurchaseDay() < right.getPurchaseDay()) {
		return true;
	}
	else if (left.getPurchaseDay() > right.getPurchaseDay()) {
		return false;
	}

	// Everything is equal with regards to the purchase date!
	return false;
}

void Books::sortByAge() {
	sort(ageGreaterThan);
}