'''
Parhuam Jalalian
CIS41A Spring 2020
Unit J Take-home Assignment
'''
import random

# Write a script that simulates a simple dice gambling game
# Run 10,000 simulations of the game (Monte Carlo method)
games = 10000
x = 0

# Score
total = 0

while games > 0:
    amount = 0
    
    # Roll
    rolled = random.randint(1, 6)
    
    # You roll a 1, 2 or a 3, the game is over.
    while rolled not in (1, 2, 3):
        # Calculate amount
        amount = amount + rolled
        rolled = random.randint(1, 6)
        
    # Find total and max
    total = total + (amount)
    x = max(x, amount)
    games -= 1
    
# Find average
average = total / 10000
print("Execution results:")
print("Average Amount won = " + str("%.2f" % average))
print("Max amount won = " + str(x))

'''
Execution results:
Average Amount won = 4.99
Max amount won = 61
'''