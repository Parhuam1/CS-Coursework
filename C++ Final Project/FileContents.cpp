#define _CRT_SECURE_NO_WARNINGS

// This file deals with reading and writing the contents of our database file
#include "FileContents.h"
#include "File.h"


// The format of a single book entry is as follows:
// Title
// ISBN
// Author
// Publisher
// Date
// Quantity
// Wholesale price
// Retail price

bool ReadOneBook(File& invFile, Book& book) {
	char line[MAX_LINE_SIZE];
	
	// TODO: some error checking below, such as an unexpected end of file.  Return false if so.
	invFile.readOneLine(line);
	book.setTitle(line);

	invFile.readOneLine(line);
	book.setISBN(line);

	invFile.readOneLine(line);
	book.setAuthor(line);

	invFile.readOneLine(line);
	book.setPub(line);

	invFile.readOneLine(line);
	book.setDateAdded(line);

	invFile.readOneLine(line);
	book.setQty(atoi(line));

	invFile.readOneLine(line);
	book.setWholesale(atof(line));

	invFile.readOneLine(line);
	book.setRetail(atof(line));

	return !invFile.eof();
}

void WriteOneBook(File& invFile, const Book& book) {
	// Given a file that is already opened for writing, and a book, append
	// the book's contents to the file.
	invFile.writeOneLine(book.getTitle());
	invFile.writeOneLine(book.getISBN());
	invFile.writeOneLine(book.getAuthor());
	invFile.writeOneLine(book.getPub());
	invFile.writeOneLine(book.getDateAdded());
	invFile.writeOneLine(book.getQty());
	invFile.writeOneLine(book.getWholesale());
	invFile.writeOneLine(book.getRetail());
}
