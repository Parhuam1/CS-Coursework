'''
Parhuam Jalalian
CIS41A Spring 2020
Unit H Take-home Assignment
'''

# Within the function, see if the keyword temperature exists in kwargs. 
# If it does, and the temperature is greater than 500, print a warning with the temperature.
# Also see if the keyword CO2level exists in kwargs. If it does, and the CO2level is greater than .15, 
# print a warning with the CO2level.
# Lastly, see if the keyword miscError exists in kwargs. If it does, print a warning with the miscError number.
def overseerSystem(**kwargs):
    'Print Temperature, or CO2Levels, or miscError'
    # Check if given keyword exists or not
    if 'temperature' in kwargs:
        # Check if condition given corresponds to keyword
        if(kwargs['temperature'] > 500):
            print("Warning: temperature is " + str(kwargs['temperature']))
  
    # Check if given keyword exists or not
    if 'CO2level' in kwargs:
        # Check if condition given corresponds to keyword
        if(kwargs['CO2level'] > 0.15):
            print("Warning: CO2level is " + str(kwargs['CO2level']))
  
    # Check if given keyword exists or not
    if 'miscError' in kwargs:
        # Check if condition given corresponds to keyword
            print("Misc error #" + str(kwargs['miscError']))


# The class will allow you to initialize a BritCoins object with any given amount of pounds, 
# shillings and pennies, add and subtract BritCoins objects, and to print a string that represents the value of 
# the coins used to initialize a BritCoins object.
class BritCoins(): 
    'Manage British Money'
    __coinValues = {"pound":240, "shilling":12, "penny":1}
    
    def __init__(self , **kwargs):
        self.totalPennies = 0
        for key, value in kwargs.items():
            if key in BritCoins.__coinValues:
                self.totalPennies += BritCoins.__coinValues[key] * value

    def __add__(self, other):
        pennies = self.totalPennies + other.totalPennies
        return BritCoins(penny = pennies)

    def __sub__(self, other):
        pennies = self.totalPennies - other.totalPennies
        return BritCoins(penny = pennies)
    
    def __str__(self):
        pennies = self.totalPennies
        pound = pennies // 240
        pennies = pennies % 240
        shilling = pennies // 12
        pennies= pennies % 12
        return str(pound) + " pounds " + str(shilling) + " shillings " + str(pennies) + " pennies"
      
c1 = BritCoins(pound = 4, shilling = 24, penny = 3)
c2 = BritCoins(pound = 3, shilling = 4, penny = 5)
c3 = c1 + c2
c4 = c1 - c2
print("Execution results:")
print(c1)
print(c2)
print(c3)
print(c4)
print('\n')

def main():
    myLists = []
    
    for row in range(1,6,2):
    
        newRow = []
    
        for col in range(1,6,2):
    
            newRow.append(row*col**2)
    
        myLists.append(newRow)
    
    print(myLists[0][1])    
    overseerSystem(temperature = 550)
    overseerSystem(temperature = 475)
    overseerSystem(temperature = 450, miscError = 404)
    overseerSystem(CO2level = .18)
    overseerSystem(CO2level = .2 , miscError = 418)
    print('\n') 
if __name__ == '__main__': 
    main()    

'''
Execution results:
5 pounds 4 shillings 3 pennies
3 pounds 4 shillings 5 pennies
8 pounds 8 shillings 8 pennies
1 pounds 19 shillings 10 pennies


Warning: temperature is 550
Misc error #404
Warning: CO2level is 0.18
Warning: CO2level is 0.2
Misc error #418
'''