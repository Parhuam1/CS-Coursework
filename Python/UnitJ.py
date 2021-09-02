'''
Parhuam Jalalian
CIS41A Spring 2020
Unit J Exercise Part 1, UnitJ Script   
'''

import LibraryBook
import LibraryPatron

def main():
    print("Execution results:")
    b1 = LibraryBook.Book("Alice in Wonderland", "Juvenile")
    b2 = LibraryBook.Book("The Cat in the Hat", "Juvenile")
    b3 = LibraryBook.Book("Harry Potter and the Sorcerer's Stone", "Juvenile")
    b4 = LibraryBook.Book("The Hobbit", "Juvenile")
    b5 = LibraryBook.Book("The Da Vinci Code", "Adult")
    b6 = LibraryBook.Book("The Girl with the Dragon Tattoo", "Adult")
    
    p1 = LibraryPatron.JuvenilePatron("Jimmy")
    p2 = LibraryPatron.AdultPatron("Sophia")

    p1.checkOutBook(b6)
    p1.checkOutBook(b1)
    p1.checkOutBook(b2)
    p1.printCheckedOutBooks()
    p1.checkOutBook(b3)
    p1.returnBook(b1)
    p1.checkOutBook(b3)
    p1.printCheckedOutBooks()
    p2.checkOutBook(b5)
    p2.checkOutBook(b4)
    p2.printCheckedOutBooks()
if __name__ == '__main__': 
    main()    

'''
Execution results:
Sorry Jimmy The Girl with the Dragon Tattoo is an adult book
Jimmy has checked out Alice in Wonderland
Jimmy has checked out The Cat in the Hat
Jimmy has the following books checked out:
Alice in Wonderland
The Cat in the Hat
Sorry Jimmy you are at your limit of 2 books
Jimmy has returned Alice in Wonderland
Jimmy has checked out Harry Potter and the Sorcerer's Stone
Jimmy has the following books checked out:
The Cat in the Hat
Harry Potter and the Sorcerer's Stone
Sophia has checked out The Da Vinci Code
Sophia has checked out The Hobbit
Sophia has the following books checked out:
The Da Vinci Code
The Hobbit
'''