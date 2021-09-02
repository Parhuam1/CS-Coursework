'''
Parhuam Jalalian
CIS41A Spring 2020
Unit B In-class assignment Script 2
'''

#Second Script:
#Printing a well formatted invoice
print("Execution results:")
print("Printing a well formatted invoice")
print("----------------------------------")
print("\n")

#Box of Bead Prices, constants
SMALLPRICE = 9.20
MEDIUMPRICE = 8.52
LARGEPRICE = 7.98

#Ask user for Qty, convert user input str to int
smallQty = float(input("How many boxes of small beads do you want? "))
mediumQty = float(input("How many boxes of medium beads do you want? "))
largeQty = float(input("How many boxes of large beads do you want? "))

#Calculate total and round to 2 decimals
smallTotal = round(smallQty * SMALLPRICE, 2)
mediumTotal = round(mediumQty * MEDIUMPRICE, 2)
largeTotal = round(largeQty * LARGEPRICE, 2)
totalCost = round(smallTotal + mediumTotal + largeTotal, 2)

#Convert float to int for Qty format
smallQty = int(smallQty)
mediumQty = int(mediumQty)
largeQty = int(largeQty)

#Print format
print("\nSIZE      QTY    COST PER BOX      TOTALS")
print('%s %7d %15.2f %11.2f' % ("Small",smallQty, SMALLPRICE, smallTotal))
print('%s %6d %15.2f %11.2f' % ("Medium", mediumQty, MEDIUMPRICE, mediumTotal))
print('%s %7d %15.2f %11.2f' % ("Large",largeQty, LARGEPRICE, largeTotal))
print('%s %35.2f' % ("TOTAL", totalCost))

'''
Execution results:
Printing a well formatted invoice
----------------------------------


How many boxes of small beads do you want? 10
How many boxes of medium beads do you want? 9
How many boxes of large beads do you want? 8

SIZE      QTY    COST PER BOX      TOTALS
Small      10            9.20       92.00
Medium      9            8.52       76.68
Large       8            7.98       63.84
TOTAL                              232.52
'''

'''
Execution results:
Printing a well formatted invoice
----------------------------------


How many boxes of small beads do you want? 5
How many boxes of medium beads do you want? 10
How many boxes of large beads do you want? 15

SIZE      QTY    COST PER BOX      TOTALS
Small       5            9.20       46.00
Medium     10            8.52       85.20
Large      15            7.98      119.70
TOTAL                              250.90

'''