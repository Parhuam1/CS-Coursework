'''
Parhuam Jalalian
CIS41A Spring 2020
Unit D Exercise assignment 
'''

# 1) Dictionary Basics:

# a. Create a dictionary of fruit and desserts made from the fruit. 
# The fruit should be the key and the dessert should be the value. Use these key value pairs:
menu = { 'apple':'sauce', 'peach':'cobbler', 'carrot':'cake', 'strawberry':'sorbet', 'banana':'cream pie'}

# b. Add the mango fruit to the dictionary. Its dessert is sticky rice.
menu['mango'] = "sticky rice"

# c. Change the strawberry dessert to shortcake.
menu['strawberry'] = "shortcake"

# d. Carrot is not a fruit, so remove carrot from the dictionary.
del menu['carrot']

# e. Print the apple dessert.
print("apple dessert is:", menu['apple'])

# f. See if a banana dessert exists.
print("banana dessert exists:", 'banana' in menu)

# g. See if a pear dessert exists.
print("pear dessert exists:", 'pear' in menu)

# h. Print the keys in the dessert dictionary.
print(menu.keys())

# i. Print the values in the dessert dictionary.
print(menu.values())

# j. Print the key-value pairs in the dessert dictionary.
print(menu.items())

# 2) Combining dictionaries:
# a. Create a dictionary named capitols1 and populate it with these key value pairs:
capitols1 = {'Alabama':'Montgomery', 'Alaska':'Juneau', 'Arizona':'Phoenix', 'Arkansas':'Little Rock', 'California':'Sacramento'}

# b. Create a dictionary named capitols2 and populate it with these key value pairs:
capitols2 = {'California':'Sac.', 'Colorado':'Denver', 'Connecticut':'Hartford'}

# c. Using the dictionary update() method, update capitols1 with capitols2.
capitols1.update(capitols2)

# d. Print the sorted capitols (values). Note the updated value of California's capitol.
print("Sorted state capitols:", sorted(capitols1.values()))

# 3) Sets Basics:
# a. Create a set named class1 and populate it with the students Li, Audry, Jia, Migel, Tanya.
class1 = {'Li', 'Audry', 'Jia', 'Migel', 'Tanya'}

# b. Create a set named class2 and populate it with the students Sasha, Migel, Tanya, Hiroto, Audry.
class2 = {'Sasha', 'Migel', 'Tanya', 'Hiroto', 'Audry'}

# c. Add John to class1.
class1.add('John')

# d. Print a sorted list of students who are in both classes.
print("All students:", sorted(class1.intersection(class2)))

# e. Print a sorted list of all students.
print("All students:", sorted(class1.union(class2)))

#f. Test to see if Sasha is in class1.
print("Sasha is in class1:", 'Sasha' in class1)


'''
apple dessert is: sauce
banana dessert exists: True
pear dessert exists: False
dict_keys(['apple', 'peach', 'strawberry', 'banana', 'mango'])
dict_values(['sauce', 'cobbler', 'shortcake', 'cream pie', 'sticky rice'])
dict_items([('apple', 'sauce'), ('peach', 'cobbler'), ('strawberry', 'shortcake'), ('banana', 'cream pie'), ('mango', 'sticky rice')])
Sorted state capitols: ['Denver', 'Hartford', 'Juneau', 'Little Rock', 'Montgomery', 'Phoenix', 'Sac.']
All students: ['Audry', 'Migel', 'Tanya']
All students: ['Audry', 'Hiroto', 'Jia', 'John', 'Li', 'Migel', 'Sasha', 'Tanya']
Sasha is in class1: False
'''