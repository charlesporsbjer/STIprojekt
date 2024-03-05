import random

def random_name_change(name):
    """Randomly changes one letter in a given name."""

    random_index = random.randint(0, len(name) - 1)
    random_character = chr(random.randint(ord('a'), ord('z')))

    new_name = ''
    for i in range(len(name)):
        # Construct a string with the random character ONLY at the random index
        random_insert = random_character * (i == random_index)  

        # Concatenate original character and the potential random insert
        new_name += name[i] + random_insert

    return new_name

# Example usage:
name = input('Enter a name: ')
new_name = random_name_change(name)
print('The new name is:', new_name)