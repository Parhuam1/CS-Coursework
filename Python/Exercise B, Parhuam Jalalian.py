'''
Parhuam Jalalian
CIS41A Spring 2020
Unit B In-class assignment 
'''

#First Script - Working with Strings
#String Methods

print("Execution results:")
print("String Methods")
userStr = input("1. Please type a name:")
print("2.", userStr.upper())
print("3.", len(userStr))
print("4.", userStr[3])
name2 = userStr.replace('o', 'x')
print("5.", name2)
print("6.", userStr)

#Counting and Finding
print("\nCounting and Finding")
quote = "Believe you can and you're halfway there."
print("1.", quote.count('a'))
counter=0
print("2. Index of all the 'a' characters:")
for i in quote:
 if i == 'a':
  print(counter)
 counter += 1


'''
Execution results:
String Methods
1. Please type a name:George Washington
2. GEORGE WASHINGTON
3. 17
4. r
5. Gexrge Washingtxn
6. George Washington

Counting and Finding
1. 4
2. Index of all the 'a' characters:
13
16
28
32
'''