'''
Parhuam Jalalian
CIS41A Spring 2020
Unit F Exercise  
'''

# Unit F
# This assignment has one script with three parts.

# Part One Using a main function, Docstrings
# Write a function called hello. The function has no arguments and no return value. 
# It simply prints the text "Hello World". Include a docstring that describes the function.
def hello():
    'Prints the text "Hello World"'
    print("Hello World")
    return

# Write a function called printListElement. The function has two arguments and no return value. 
# The first argument is a list, and the second argument is a list index. 
# The function will print an element from the list as determined by the list index. 
# If the list index is invalid, print an error message.
def printListElement(lst, index):
    'Try block that attempts to print the list element. Catches any errors with an except block, and prints an error message'
    try:  
        print(lst[index])              
    except:
        print("Error: bad index number.")

# Part Three How Python function arguments are treated
# create a function called byVal which has one argument. 
# In the function, add 7 to the argument. Print the ID of the argument before and after the change
def byVal(value):
    'Print ID after pass by value'
    print("Original ID of parameter in byVal " + str(id(value)))
    value += 7
    print("ID of parameter in byVal after change " + str(id(value)))
        
# Create a second function called byRef which has one argument. In the function, add 7 to the last element in the list. 
# Print the ID of the argument and the ID of the last element of the argument before and after the change.    
def byRef(ref):
    'Print ID after pass by ref'
    print("Original ID of parameter in byRef " + str(id(ref)))
    print("Original ID of parameter's last element in byRef " + str(id(ref[len(ref) - 1])))
    ref[len(ref) - 1] += 7
    print("ID of parameter in byRef after change " + str(id(ref)))
    print("ID of parameter's last element in byRef after change " + str(id(ref[len(ref) - 1])))  
    
# Write a main function, as described by the Python main function reading.
# Call main, as described by the Python main function reading.
# From main call hello and then print hellos docstring.
def main():
    print("Execution results:")
    
    # Call hello()
    hello()
    print("Help on function hello in module __main__:\n")
    
    print("hello()")
    print("\t" + hello.__doc__)
    print('\n')
    
    
    my_list = [0, 1, 2, 3]
    printListElement(my_list, 5)
    print('\n')
    
    myInt = 3
    myList = [0, 1, 2]
    
    # Print the IDs of myInt and myList. Also print the ID of the last element of myList.
    print("Original ID of myInt in main is " + str(id(myInt)))
    print("Original ID of myList in main is " + str(id(myList)))
    print("Original ID of myList's last element in main is " + str(id(myList[len(myList)-1])))
    
    # Now call byVal with myInt and then call byRef with myList. 
    byVal(myInt)
    byRef(myList)
    
    # Next, again print the IDs of MyInt, myList, and the last element of myList.
    print("ID of myInt in main after call to byVal is " + str(id(myInt)))
    print("ID of myList in main after call to byRef is " + str(id(myList)))
    print("ID of myList's last element in main after call to byRef is " + str(id(myList[len(myList)-1])))    
    
    # Finally, print myInt and MyList from main.
    print("myInt is now: " + str(myInt))
    print("myList is now: " + str(myList))
    
    # Can you explain the results?
    # If var1 refers to a mutable object and this changes var2, then these changes will be
    # visible outside of the scope of the function
    
if __name__ == '__main__': 
    main()


'''
Execution results:
Hello World
Help on function hello in module __main__:

hello()
	This function prints Hello World


Error: bad index number.


Original ID of myInt in main is 140705480342656
Original ID of myList in main is 1891138071112
Original ID of myList's last element in main is 140705480342624
Original ID of parameter in byVal 140705480342656
ID of parameter in byVal after change 140705480342880
Original ID of parameter in byRef 1891138071112
Original ID of parameter's last element in byRef 140705480342624
ID of parameter in byRef after change 1891138071112
ID of parameter's last element in byRef after change 140705480342848
ID of myInt in main after call to byVal is 140705480342656
ID of myList in main after call to byRef is 1891138071112
ID of myList's last element in main after call to byRef is 140705480342848
myInt is now: 3
myList is now: [0, 1, 9]
'''