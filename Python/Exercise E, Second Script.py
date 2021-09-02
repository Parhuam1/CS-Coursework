'''
Parhuam Jalalian
CIS41A Spring 2020
Unit E Exercise Script 2
'''

# Second Script two parts
# 1) Using range with a for loop.
# a. Use a for loop to print the even integers in descending order from 10 to 0 inclusive.
for x in range(0, 11):
 if(x % 2 == 0):
  print(10 - x)

# 2) Looping through dictionary items.
# a. Create a dictionary named movies and populate it with these key value pairs:
# The Wizard of Oz:1939
# The Godfather:1972
# Lawrence of Arabia:1962
# Raging Bull:1980
movies = {'Wizard of Oz':1939, 'The Godfather':1972, 'Lawrence of Arabia':1962, 'Raging Bull':1980}

# b. Loop through the dictionary items and print the year in which each movie was made. Output should be alpha sorted by movie title.
for key in sorted(movies.keys()):
 print(key + " was made in " + str(movies.get(key)))

'''
10
8
6
4
2
0
Lawrence of Arabia was made in 1962
Raging Bull was made in 1980
The Godfather was made in 1972
Wizard of Oz was made in 1939
'''