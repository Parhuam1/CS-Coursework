'''
Parhuam Jalalian
CIS41A Spring 2020
Unit I Exercise  
'''

# To use math.pi
import math 

# Parent class circle
class circle: 

    # Constructor
    def __init__(self, radius):  
        self.radius = radius

    # Calculate area
    def getArea(self): 
        area = math.pi * self.radius * self.radius
        return area

# Cylinder inheriting circle
class cylinder(circle): 

    # Constructor
    def __init__(self, radius, height):
        # Pass radius
        super().__init__(radius) 
        self.height = height 
        
    # Get volume   
    def getVolume(self): 
        volume = super().getArea() * self.height 
        return volume 

c1 = circle(4) 
area = c1.getArea() 
print("Circle Area: " + str(c1.getArea())) 
print("Circle Area: " + str("%.2f" % area)) 

c2 = cylinder(2, 5) 
volume = c2.getVolume() 
print("Cylinder volume: " + str("%.2f" % volume)) 