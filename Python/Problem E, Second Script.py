'''
Parhuam Jalalian
CIS41A Spring 2020
Unit E Take-home Assignment Script 2
'''
import random

# Write a script that plays a simple guessing game.
# The script will generate a secret number from 1 to 100, inclusive, and the user will have to guess the number.
# After each guess, the script will tell the user if they are high, low, or correct.
# If they are correct, the script will congratulate the user, tell them how many guesses they took, and then end the script.
print("Welcome to the guessing game.")
print("You need to guess a number from 1 to 100.")

# This generates a random int from 1-100, inclusive
secretNum = random.randint(1,100)

# Variables
guess_total = 0
user_guess = 0

while user_guess is not secretNum:
    user_guess = int(input("What is your guess? "))
    guess_total += 1
    if user_guess < secretNum:
        print("Guess is too low.")
    elif user_guess > secretNum:
        print("Guess is too high.")
    else:
        break

print("Congratulations!")    
print("You guessed the secret number in " + str(guess_total) + " guesses!")

'''
Execution results:
Welcome to the guessing game.
You need to guess a number from 1 to 100.
What is your guess? 50
Guess is too high.
What is your guess? 25
Guess is too low.
What is your guess? 37
Guess is too high.
What is your guess? 33
Guess is too high.
What is your guess? 30
Congratulations!
You guessed the secret number in 5 guesses!
'''