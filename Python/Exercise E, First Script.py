'''
Parhuam Jalalian
CIS41A Spring 2020
Unit E Exercise Script 1
'''

# First Script
# 1) Determining the genre of a movie.

# a. Create a list called scifi that contains the elements Alien, Solaris, Inception, Moon.
scifi = ['Alien', 'Solaris', 'Inception', 'Moon']

# b. Create a list called comedy that contains the elements Borat, Idiocracy, Superbad, Bridesmaids.
comedy = ['Borat', 'Idiocracy', 'Superbad', 'Bridesmaids']

# c. Ask the user for the name of a movie.
user_input = input("Please enter a movie title: ")

# d. Using if/elif/else, determine and print the genre of the movie.
if(user_input in scifi):
 user_msg = user_input + " is a scifi movie."
elif(user_input in comedy):
 user_msg = user_input + " is a comedy movie."
else:
 user_msg = "Sorry, I don't know what kind of movie " + user_input + " is."
print(user_msg)

# e. Test three times: first with Moon, then Superbad, then Dunkirk.
'''
Please enter a movie title: Moon
Moon is a scifi movie.
Please enter a movie title: Superbad
Superbad is a comedy movie.
Please enter a movie title: Dunkirk
Sorry, I don't know what kind of movie Dunkirk is.
'''