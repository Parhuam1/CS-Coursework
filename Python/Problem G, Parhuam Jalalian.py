'''
Parhuam Jalalian
CIS41A Spring 2020
Unit G Take-home Assignment
'''

# Part One Reading a data file
# Pre: No parameters
# Post: Print highest populated midwest region
def populated_midwest():
    'Find and print the state with the highest population in the Midwest region.'
    state = ''
    population = 0
    
    with open('States.txt', 'r') as state_file:
        for line in state_file:
            info = line.split()
            # Trying to find the highest population in the midwest
            # Info = [AL, South, 4863000]
            if info[1] == 'Midwest' and int(info[2]) > int(population):               
                    state = info[0]
                    population = info[2]                  
    state_file.close()
    print("Highest population state in the Midwest is: " + state + " " + str(population) + "\n")  
     
# Part Two A Dictionary of Lists
# Pre: No parameters
# Post: Print state with most presidents
def most_presidents():
    'Build dictionary, Print the state with the most presidents and how many presidents were born there'
    president_dict = {}
    state_abbreviation = ''
    count = 0   
    
    with open('USPresidents.txt ', 'r') as president_file:
        for line in president_file:
            info=line.split()
            # Info = [KY, Abraham_Lincoln]
            if info[0] in president_dict:
                # Append key
                president_dict[info[0]].append(info[1])
            else:
                # Add new key
                president_dict[info[0]] = [info[1]]
                
        # Get state and presidents
        for key in president_dict:
            if len(president_dict[key]) > count:               
                count = len(president_dict[key])
                state_abbreviation = key
    president_file.close()
    
    print("The state with the most presidents is " + state_abbreviation + " with " + str(count) + " presidents")
    for president in president_dict[state_abbreviation]:
        print(president)
    print('\n')            
  
# Part Three Dictionary Keys and Sets  
# Pre: no parameters
# Post: Print states, print presidents born in each
def presidents_in_states():
    'Build set and print states with the number of presidents born in them'
    president_dict = {}
    populous_states = set()
    count = 1
    us_states = {'CA','TX','FL','NY','IL','PA','OH','GA','NC','MI'}
    
    with open('USPresidents.txt ', 'r') as president_file:
        for line in president_file:
            info = line.split()
             # Info = [KY, Abraham_Lincoln]
            if info[0] in president_dict:
                # Append key
                president_dict[info[0]] += 1
            else:         
                # Add new key
                president_dict[info[0]] = count  
    president_file.close()  
    
    # Add states
    for state in us_states:
        if state in president_dict:
            populous_states.add(state) 
     
    # Alpha-sorted
    populous_states = sorted(populous_states)  
    
    print(str(len(populous_states)) + " of the 10 population states have had presidents born in them: ")  
    for state in populous_states:
        if state in president_dict:
            print(state + " " + str(president_dict[state]))
    
def main():
    print("Execution results:")
    populated_midwest()  
    most_presidents()
    presidents_in_states()
    
if __name__ == '__main__': 
    main()    


'''
Execution results:
Highest population state in the Midwest is: IL 12802000

The state with the most presidents is VA with 8 presidents
George_Washington
James_Madison
James_Monroe
John_Tyler
Thomas_Jefferson
William_Henry_Harrison
Woodrow_Wilson
Zachary_Taylor


8 of the 10 population states have had presidents born in them: 
CA 1
GA 1
IL 1
NC 2
NY 5
OH 7
PA 1
TX 2
'''