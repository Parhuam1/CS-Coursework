'''
Parhuam Jalalian
CIS41A Spring 2020
Unit J Exercise Part 3, LibraryPatron.py module   
'''

import LibraryBook

class LibraryPatron(): 
    def __init__(self, name):
        self.name = name
        self.booksCheckedOut = []
        
    def checkOutBook(self, checkOutLimit, book):
        if len(self.booksCheckedOut) < self.checkOutLimit:
            print(self.name, "has checked out", book)
            self.booksCheckedOut.append(book)
        else:
            print("Sorry", self.name, "you are at your limit of", checkOutLimit, "books")
        
    def returnBook(self, book): 
        self.booksCheckedOut.remove(book.title)
        print(self.name, "has returned", book.title)
        
    def printCheckedOutBooks(self):
        print(self.name, "has the following books checked out:")
        for book in self.booksCheckedOut:
            print(book)
            
class AdultPatron(LibraryPatron):
    def __init__(self, name):
        super().__init__(name)
        self.checkOutLimit = 4
        
    def checkOutBook(self, book): 
        super().checkOutBook(self.checkOutLimit, book.title)
        
class JuvenilePatron(LibraryPatron):
    def __init__(self, name):
        super().__init__(name)
        self.checkOutLimit = 2
        
    def checkOutBook(self, book): 
        if book.bookType is 'Adult':
            print("Sorry", self.name, book.title, "is an adult book")
        else:
            super().checkOutBook(self.checkOutLimit, book.title)

