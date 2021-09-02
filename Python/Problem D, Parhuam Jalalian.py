'''
Parhuam Jalalian
CIS41A Spring 2020
Unit D take-home assignment Script 
'''
from collections import namedtuple

# Part One Sets
print("Execution results:")

# a. Create a set named class1 and populate it with the students Li, Audry, Jia, Migel, Tanya.
class1 = { 'Li', 'Audry', 'Jia', 'Migel', 'Tanya'}

# b. Create a set named class2 and populate it with the students Sasha, Migel, Tanya, Hiroto, Audry.
class2 = {'Sasha', 'Migel', 'Tanya', 'Hiroto', 'Audry'}

# c. Create a set named class3 and populate it with the students Migel, Zhang, Hiroto, Anita, Jia.
class3 = {'Migel', 'Zhang', 'Hiroto', 'Anita', 'Jia'}

# d. Print a sorted list of students who are in all three classes.
print("Students in all three classes:", sorted(class1.intersection(class2, class3)))

# e. Print a sorted list of all students.
print("All students", sorted(class1.union(class2, class3)))

# f. Print a sorted list of all students in class1 but not class2 or class3.
print("Students in class1 but not class2 or class3:", sorted(class1.difference(class2, class3)))

# Part Two Swap
# a. Create a list containing elements 1, 2, 3
list1 = [1,2,3]

# b. Swap the second and third elements of the list. Do this with one line of code.
list1[2], list1[1] = list1[1] , list1[2]

# c. Print the list.
print("List after swap:", list1)

# Part Three Tuple Basics
# a. Create a tuple that contains the elements Casablanca, 1942, romantic drama.
tuple1 = ('Casablanca', 1942, 'romantic drama')

# b. Unpack the tuple into variables title, year, genre.
title = tuple1[0]
year = tuple1[1]
genre = tuple1[2]

# c. Print the title.
print("My favorite movie is:", title)

# Part Four Named Tuple
# a. Define a named tuple called Movie that contains the fields title, year, genre.
Movie = namedtuple('Movie', 'title year genre')

# b. Create a Movie tuple that contains the elements Casablanca, 1942, romantic drama.
casab = Movie(title = 'Casablanca', year = 1942, genre = 'romantic drama')

# c. Print the title
print("My favorite movie is:", casab.title)

# Part Five Named Tuple Containing a List
# a. Define a named tuple called Moviestars that contains the fields title, year, genre, stars.
Moviestars = namedtuple('Moviestars', 'title year genre stars')

# b. Create a Moviestars tuple called favoritemovie that contains the elements Casablanca, 1942, romantic drama, 
#    and a list containing elements Humphrey Bogart, Ingrid Bergman.
list2 = ['Humphrey Bogart', 'Ingrid Bergman']
favoritemovie = Moviestars('Casablanca', 1942, 'romantic drama', list2)

# c. Append Claude Rains to the stars list. Hint: Use the syntax favoritemovie.stars.append
favoritemovie.stars.append('Claude Rains')

# d. Print star Ingrid Bergman.
print("My favorite star is:", favoritemovie[3][1])

# e. Print favoritemovie.
print(favoritemovie)

'''
Execution results:
Students in all three classes: ['Migel']
All students ['Anita', 'Audry', 'Hiroto', 'Jia', 'Li', 'Migel', 'Sasha', 'Tanya', 'Zhang']
Students in class1 but not class2 or class3: ['Li']
List after swap: [1, 3, 2]
My favorite movie is: Casablanca
My favorite movie is: Casablanca
My favorite star is: Ingrid Bergman
Moviestars(title='Casablanca', year=1942, genre='romantic drama', stars=['Humphrey Bogart', 'Ingrid Bergman', 'Claude Rains'])
'''