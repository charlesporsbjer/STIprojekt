# Create right aligned half-pyramid of (input) height


from cs50 import get_int


# Prompt user for height until satisfied, ignore alfabeticals
while True:
    height = get_int("Set height, 1-8: ")
    break
while height > 8 or height < 1:
    height = get_int("Set height, 1-8: ")
  # height = int(input("Set height, 1-8: "))


# Initialize width for easy incrementing
width = 1
# Initialize spacers for easy decrementing
spacers = height - 1


# Decrement height
for _ in range(height):
    height -= 1

    # Print and decrement spacers
    for _ in range(spacers):
        print(" ", end="")
    spacers -= 1

    # Print and increment blocks
    for _ in range(width):
        print("#", end="")
    width += 1
    
    # New line when done
    print("")