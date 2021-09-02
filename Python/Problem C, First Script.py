'''
Parhuam Jalalian
CIS41A Spring 2020
Unit C take-home assignment Script 1
'''

# First Script Working with Lists

print("Execution results:")
#a,b. Create list1, Populate list1 with the values 1, 3, 5
list1 = []
for x in range(0,5):
 if x%2 == 0:
  list1.append(x+1)
 
#c. Create list2, Populate list2 with the values 1, 2, 3, 4
list2 = []
for x in range(0,4):
  list2.append(x+1)

#d. Create list3 by using + (a plus sign) to combine list1 and list2. Print list3.
list3 = list1 + list2
print("d) list3 is:", list3)

#e. Use sequence operator in to test list3 to see if it contains a 3, 
# print True/False result (do with one line of code).
print("e) list3 contains a 3: True") if 3 in list3 else print("e) list3 contains a 3: False" )

#f. Count the number of 3s in list3, print the result.
print("f) list3 contains:", list3.count(3), "3s")

#g. Determine the index of the first 3 in list3, print the result.
print("g) The index of the first 3 contained in list3 is", list3.index(3))

#h. Pop this first 3 and assign it to a variable called first3, print first3.
# Loop made to handle any values in list
for i in range(len(list3)):
 if list3[i] is 3:
  first3=list3.pop(i)
  break
print("h) first3 =", first3)
 
#i. Create list4, populate it with list3's sorted values, using the sorted built-in function.
list4 = sorted(list3)

#j. Print list3 and list4.
print("j) list3 is now:", list3)
print("j) list4 now:", list4)

#k. Slice list3 to obtain a list of the values 1,2,3 from the middle of list3, print the result.
print("k) Slice of list3 is:", list3[2:5])

#l. Determine the length of list3, print the result.
print("l) Length of list3 is", len(list3))

#m. Determine the max value of list3, print the result.
print("m) The max value in list3 is", max(list3))

#n. Sort list3 (use the list sort method), print list3.
list3.sort()
print("n) Sorted list3 is:", list3)

#o. Create list5, a list of lists, using list1 and list2 as elements of list5, print list5.
list5 = [list1, list2]
print("o) list5 is:", list5)

#p. Print the value 4 contained within list5.
# Loop made to handle any values in list
for l in list5:
 if 4 in l:
  print("p) Value 4 from list5:", 4)


'''
Execution results:
d) list3 is: [1, 3, 5, 1, 2, 3, 4]
e) list3 contains a 3: True
f) list3 contains: 2 3s
g) The index of the first 3 contained in list3 is 1
h) first3 = 3
j) list3 is now: [1, 5, 1, 2, 3, 4]
j) list4 now: [1, 1, 2, 3, 4, 5]
k) Slice of list3 is: [1, 2, 3]
l) Length of list3 is 6
m) The max value in list3 is 5
n) Sorted list3 is: [1, 1, 2, 3, 4, 5]
o) list5 is: [[1, 3, 5], [1, 2, 3, 4]]
p) Value 4 from list5: 4
'''