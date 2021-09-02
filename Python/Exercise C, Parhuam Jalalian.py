'''
Parhuam Jalalian
CIS41A Spring 2020
Unit C Exercise assignment 
'''
import copy

# List Script
list1 = [2, 4.1, 'hello']
list2 = list1
list3 = copy.deepcopy(list1)

# Use ==
print("list1 == list2:", list1 == list2)
print("list1 == list3:", list1 == list3)
print("list2 == list3:", list2 == list3)

# Use is
print("list1 == list2:", list1 is list2)
print("list1 == list3:", list1 is list3)
print("list2 == list3:", list2 is list3)

# Print ID
print("list1 ID:", id(list1))
print("list2 ID:", id(list2))
print("list3 ID:", id(list3))

# Change List
list1.append(8)
list2.insert(1, 'goodbye')
list3.pop(0)

# Print lists
print("list1 printed:", list1)
print("list2 printed:", list2)
print("list3 printed:", list3)

'''
list1 == list2: True
list1 == list3: True
list2 == list3: True
list1 == list2: True
list1 == list3: False
list2 == list3: False
list1 ID: 2281586414920
list2 ID: 2281586414920
list3 ID: 2281586417480
list1 printed: [2, 'goodbye', 4.1, 'hello', 8]
list2 printed: [2, 'goodbye', 4.1, 'hello', 8]
list3 printed: [4.1, 'hello']

'''