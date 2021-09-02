'''
Parhuam Jalalian
CIS41A Spring 2020
Unit B take-home assignment Script 1
'''

#String Type Tests
print("Execution results:")
print("String Type Tests")
print("----------------------------------")
userStr= input("a. Please type a string:")
print("a. isupper():", userStr.isupper())
print("b. isdigit():", userStr.isdigit())
print("c. isalpha():", userStr.isalpha())
print("\n")

#Escape Characters within a string
print("Escape Characters within a string")
print("----------------------------------")
haiku = "Type, type, type away.\nCompile. Run. Hip hip hooray! \nNo error today!"
print(haiku)
print("\n")

#Slicing a string
print("Slicing a string")
print("----------------------------------")
quote = "And now for something completely different"
print(quote[0:6])
print(quote[38:42])
print(quote[14:16])
print(quote[::2])
print(quote[::-1])
print("\n")

#Using string operators + and *
print("Using string operators + and *")
print("----------------------------------")
pattern1 = ".~*'"
pattern2 = pattern1 + pattern1[::-1]
for x in range(5):
 print(pattern2, end = '')
 
 
 
 '''
 Execution results:
String Type Tests
----------------------------------
a. Please type a string:ABC123
a. isupper(): True
b. isdigit(): False
c. isalpha(): False


Escape Characters within a string
----------------------------------
Type, type, type away.
Compile. Run. Hip hip hooray! 
No error today!


Slicing a string
----------------------------------
And no
rent
me
Adnwfrsmtigcmltl ifrn
tnereffid yletelpmoc gnihtemos rof won dnA


Using string operators + and *
----------------------------------
.~*''*~..~*''*~..~*''*~..~*''*~..~*''*~.
 '''