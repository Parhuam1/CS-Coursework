'''
Parhuam Jalalian
CIS41A Spring 2020
Unit G Exercise  
'''
import csv

# Part One Working with Files
# Create a new file called ZenOfPython.txt and write the first two lines of the Zen of Python (see The Zen of Python) to the file. Close the file.
# Reopen the file and append the 7th and the 17th lines. Then close the file.
# Open the file again and read and print the entire contents of the file (there shouldn't be any blank lines between the text).
# Then close the file.
def createfile():
    'Write a file, add new lines, print txt file'
    
    zen = open('ZenOfPython.txt', 'w') 
    zen.write("Beautiful is better than ugly.\n")
    zen.write("Explicit is better than implicit.\n")
    zen.close()
    
    zen = open('ZenOfPython.txt', 'a')
    zen.write("Readability counts.\n")
    zen.write("If the implementation is hard to explain, it's a bad idea.\n")
    zen.close()
    
    zen = open('ZenOfPython.txt', 'r')
    lines = zen.readlines()
    for line in lines:
        print(line, end = '')
    zen.close()
    print("\n")

# You will need to save this data (but not the header data) into a dictionary. 
# The dictionary key will be a tuple consisting of the name of the city and the name of the state. 
# The dictionary value will be the population.
# The reason for this structure is that there are a number of duplicate city names within the file, but no duplicate city/state pairs.
# After reading the csv file, iterate through the dictionary and print the data.
# Then, ask the user for a city and state, then print that citys population, if it exists.
# Test with Dublin, California.
def csvcity():
    'Save data from cvs file into dictionary, print users city, state, and population if it exists'
    
    dict1 = {}
    with open('Cities.csv', 'r') as csvfile:
        csv_reader = csv.DictReader(csvfile)           
        for row in csv_reader:         
            city = row['City']
            state = row['State']
            population = row['Population']
            tup1 = (city, state)                
            dict1[tup1] = population
               
    for k, v in dict1.items():
        print(*k, v, sep = ' ')
    
    user_city = input("\nPlease enter a city: ")
    user_state = input("Please enter a state: " )
    input_tuple = (user_city, user_state)
    
    if input_tuple in dict1:
        print(user_city + " " +   user_state + " has a population of " + str(dict1[input_tuple]))
    else:
        print("This does not exist.")
        

def main():
    createfile()
    csvcity()

if __name__ == '__main__':
    main()
    
'''
Beautiful is better than ugly.
Explicit is better than implicit.
Readability counts.
If the implementation is hard to explain, it's a bad idea.


Athens Georgia 115452
Athens Ohio 23832
Berlin Connecticut 19866
Berlin Wisconsin 5524
Dublin California 46036
Dublin Ohio 41751
Glasgow Connecticut 11951
Glasgow Kentucky 14028
London Kentucky 7993
London Ohio 9904
Milan Illinois 5099
Milan Michigan 5836
Milan Tennessee 7851
Paris Kentucky 8553
Paris Tennessee 10156
Paris Texas 25171
Warsaw Indiana 13559
Warsaw New York 5064

Please enter a city: Dublin
Please enter a state: California
Dublin California has a population of 46036
'''