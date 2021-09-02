'''
Parhuam Jalalian
CIS41A Spring 2020
Unit E Take-home Assignment Script 1
'''
from collections import namedtuple

# First Script Decision Making
# Write a script that can determine where different plants can be planted.
# Each plant has a name, a type (Flower, Vegetable, Tree, etc.), and a maximum height.
Plant = namedtuple('Plant', 'name type height')
plant_name = input("Please enter the plant name: ")
plant_type = input("Please enter the plant type: ")
plant_height = int(input("Please enter the plant height: "))
current_plant = Plant(name = plant_name, type = plant_type, height = plant_height)

# There are three gardens as follows:
# 1. The Vegetable Garden can have only Vegetables, and there is no maximum height.
# 2. The Low Garden can have only Flowers, and there is a maximum height of 3.
# 3. The High Garden can have only Flowers, and there is a maximum height of 6.
vegetable_garden = False
low_garden = False   
high_garden = False
if current_plant.type == "Vegetable":
    vegetable_garden = True
if current_plant.height < 4 and current_plant.type == "Flower":
    low_garden = True
if current_plant.height < 7 and current_plant.type == "Flower":
    high_garden = True
 
# Print ONE line that identifies the one or more gardens that a given plant can be planted in. 
# If a plant does not match the criteria for any of the gardens, then say so.   
if vegetable_garden:
    print("A " + current_plant.name + " can be planted in the Vegetable Garden.")
elif low_garden and not high_garden:
    print("A " + current_plant.name + " can be planted in the Low Garden.")
elif high_garden and not low_garden:
    print("A " + current_plant.name + " can be planted in the High Garden.")
elif low_garden and high_garden:
    print("A " + current_plant.name + " can be planted in the Low Garden or the High Garden.")
else:
    print("Sorry, your plant does not match the criteria for any of the gardens.")

#Test the script six times with the following test data:
# Name: Lily, Type: Flower, Height 3
# Name: Bonsai, Type: Tree, Height 2
# Name: Carrots, Type: Vegetable, Height 1
# Name: Corn, Type: Vegetable, Height 8
# Name: Rose, Type: Flower, Height 5
# Name: Sunflower, Type: Flower, Height 8
'''
Execution results:
Please enter the plant name: Lily
Please enter the plant type: Flower
Please enter the plant height: 3
A Lily can be planted in the Low Garden or the High Garden.
Please enter the plant name: Bonsai
Please enter the plant type: Tree
Please enter the plant height: 2
Sorry, your plant does not match the criteria for any of the gardens.
Please enter the plant name: Carrots
Please enter the plant type: Vegetable
Please enter the plant height: 1
A Carrots can be planted in the Vegetable Garden.
Please enter the plant name: Corn
Please enter the plant type: Vegetable
Please enter the plant height: 8
A Corn can be planted in the Vegetable Garden.
Please enter the plant name: Rose
Please enter the plant type: Flower
Please enter the plant height: 5
A Rose can be planted in the High Garden.
Please enter the plant name: Sunflower
Please enter the plant type: Flower
Please enter the plant height: 8
Sorry, your plant does not match the criteria for any of the gardens.
'''