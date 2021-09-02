'''
Parhuam Jalalian
CIS41A Spring 2020
Unit H Exercise  
'''


# Create a StateData class with the following methods: __init__, __str__, displayState.
# The __init__ method should have the parameters self, name, abbreviation, region, and population and should store the name, abbreviation, region, and population as attributes.
# The __str__ method has the parameter self and should return the state's name.
# The displayState method has the parameter self and should print formatted state data
class StateData():
    'Print state object. Then call displayState.'
    def __init__(self, name, abbreviation, region, population):
        self.name = name
        self.abbreviation = abbreviation
        self.region = region
        self.population = population

    def __str__(self):
        return self.name

    def displayState(self):
        return '{0} ({1}) is in the {2} region and has population of {3}'.format(self.name,self.abbreviation,self.region,self.population)
    
s1 = StateData('California', 'CA', 'West', 39250000)
print(s1)
print(s1.displayState(), '\n')
 
    
# Create a StateData2 class with the following methods: __init__, setRegion, getRegion.
# The __init__ method should have the parameters self, name and should store the name as an attribute.
# The setRegion should have the parameters self, region and should store the region as an attribute.
# The getRegion should have the the parameter self and should return the the value of the region data variable.    
class StateData2():
    'Print state using following methods' 
    def __init__(self, name):
        self.name = name

    def setRegion(self, region):
        self.region = region
        
    def getRegion(self):
        return self.region

s2 = StateData2('California')
s2.setRegion('West')
s2.pop = 39250000
print(s2.name)
print(s2.getRegion())
print(s2.region)
print(s2.pop, '\n')


# Create a StateData2 class with the following method: __init__.
# The __init__ method should have the parameter self. It should store the value "Public" in an attribute called public, 
# the value " Protected" in an attribute called _protected (use a single underscore), 
# and the value " Private" in an attribute called __private (use a double underscore).
# Test the class by creating an instance of the class called test.
class StateData2():
    'Print three lines: test.public, test._protected, test.__private'
    def __init__(self, public, protected, private):
        self.public = public
        self._protected = protected
        self.__private = private
              
test = StateData2('Public', 'Protected', 'Private')
print(test.public)
print(test._protected)
print(test.__private) # Traceback error occurs, comment this out to see real execution results



def main():
    print('\n')
    
if __name__ == '__main__': 
    main()    


'''
California
California (CA) is in the West region and has population of 39250000 

California
West
West
39250000 

Public
Protected

 line 66, in <module>
  print(test.__private)

builtins.AttributeError: 'StateData2' object has no attribute '__private'

'''