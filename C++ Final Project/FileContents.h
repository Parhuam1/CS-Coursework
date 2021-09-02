#pragma once
#ifndef FILE_CONTENTS_H
#define FILE_CONTENTS_H

#include "Book.h"
#include "File.h"
// These functions read or write a book to the file.
// The File class deals with plain lines, so it wouldn't know how to do this.
static const char * inventoryFileName = "inventory.txt";

bool ReadOneBook(File& invFile, Book& book);
void WriteOneBook(File& invFile, const Book& book);

#endif
