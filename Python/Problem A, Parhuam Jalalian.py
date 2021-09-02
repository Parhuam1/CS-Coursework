'''
Parhuam Jalalian
CIS41A Spring 2020
Unit A take-home assignment
'''

import math

# Basic math and string operations
a = 3 ** 2.5
b = 2
b += 3
c = 12
c /= 4
d = 5%3

# Print basic math
print("Execution results:" )
print("Basic math and string operations")
print("a.", a)
print("b.", b)
print("c.", c)
print("d.", d)
print("\n")

# Built-in functions abs, round, and min
print("Built-in functions abs, round, and min")
print("a.", abs(5-7))
print("b.", round(3.14159,4))
print("c.", round(186282,  -2))
print("d.", min(6, -9, -3, 0))
print("\n")

# Functions from the math module
print("Functions from the math module")
userInput = input("a. Please type a number: ")
newNumber = float(userInput)
newNumber2 =  newNumber
newNumber = math.sqrt(newNumber)
print("b. Square root of", userInput, "is", round(newNumber, 2))
print("c. Base-10 log of", userInput, "is", round(math.log10(newNumber2), 2))
print("\n")

# Complex numbers
print("Complex numbers")
z1 = 4 + 3j
z2 = 2 + 2j
z3 = z1 * z2
print("d. ", z3)

'''
Execution results:
Basic math and string operations
a. 15.588457268119896
b. 5
c. 3.0
d. 2


Built-in functions abs, round, and min
a. 2
b. 3.1416
c. 186300
d. -9


Functions from the math module
a. Please type a number: 7.6
b. Square root of 7.6 is 2.76
c. Base-10 log of 7.6 is 0.88


Complex numbers
d.  (2+14j)
'''