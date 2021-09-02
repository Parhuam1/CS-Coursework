'''
Parhuam Jalalian
CIS41A Spring 2020
Unit F In-class assignment 
'''

# The two required arguments are unitPrice and quantity.
# The first keyword argument is shipping, and it has a default value of 10.
# The second keyword argument is handling, and it has a default value of 5.
def invoice(unitPrice, quantity, shipping = 10, handling = 5):
     'The function will generate a simple invoice and will have two required arguments and two keyword arguments'
     print("Cost (unitPrice x quantity) = " + str(unitPrice * quantity))
     print("Shipping = " + str(shipping))
     print("Handling = " + str(handling))
     print("Total = " + str(unitPrice * quantity + shipping + handling) + "\n")

# The function prints a list of students who are working together on a group project, as well as the group name.
# The function has one required argument, the group name, and one 
# variable-length argument that contains the student names.
def  printGroupMembers(group_name, *args):
     'The function prints a list of students who are working together on a group project, as well as the group name'
     print("Members of " + group_name)
     for arg in args:
          if type(arg) is list:
               for item in arg:
                    print(item)
          else:
               print(arg)

# The first function should be called buildBell. 
# It has one argument, the number of rows, and returns a ragged table (a list of lists).
def buildBell(rows):  
     'Build Bell Triangle'
     lst = []
     for i in range(0, rows):
          lst.append([])
     lst[0].append(1)
     if rows > 1:
          lst[1].append(1)
          lst[1].append(2)
     for i in range(2, rows):
          for j in range(0, i+1):
               if j == 0:                               
                    lst[i].append(lst[i-1][i-1])
               else:
                    x = lst[i-1][j-1]
                    y = lst[i][j-1]
                    lst[i].append(x + y)
     return lst

# The second function should be called printBell. It has one argument, a ragged table (a list of lists). 
# Generate formatted output where each number is right justified within a fixed field size, so that the numbers in each column are aligned.
def printBell(lst):
     'Print Bell Triangle'
     for current_list in lst:
          for item in current_list:
               print("{:4d}".format(item), end = ' ')
          print()
     
def main():
     print("Execution results:")
     
     # Part One Keyword Arguments and Default Values
     unitPrice = 20
     quantity = 4
     invoice(unitPrice, quantity, shipping = 8)   
     
     unitPrice = 15
     quantity = 3
     invoice(unitPrice, quantity, handling = 15)     
 
     # Part Two args (Variable-Length Arguments)
     printGroupMembers("Group A", "Li", "Audry", "Jia")
     
     groupB = ["Group B", "Sasha", "Migel", "Tanya", "Hiroto"]
     printGroupMembers(groupB[0], groupB[1:])
     print('\n')
     
     # Part Three Non-Rectangular (Ragged) 2D lists
     rows = 8     
     printBell(buildBell(rows))
     
        
if __name__ == '__main__': 
     main()    
     
     
'''
Execution results:
Cost (unitPrice x quantity) = 80
Shipping = 8
Handling = 5
Total = 93

Cost (unitPrice x quantity) = 45
Shipping = 10
Handling = 15
Total = 70

Members of Group A
Li
Audry
Jia
Members of Group B
Sasha
Migel
Tanya
Hiroto


   1 
   1    2 
   2    3    5 
   5    7   10   15 
  15   20   27   37   52 
  52   67   87  114  151  203 
 203  255  322  409  523  674  877 
 877 1080 1335 1657 2066 2589 3263 4140 
'''