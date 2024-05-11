# Calculate minimum number of coins for change owed


from cs50 import get_float


# Ask how many DOLLARS the customer is owed
while True:
    dollars = get_float("Dollars owed: ")
    break
while dollars <= 0:
    dollars = get_float("Dollars owed: ")


# Convert to cents
cents = int(dollars * 100)

# Calculate the number of quarters to give the customer
quarters = cents // 25

# Calculate the number of dimes to give the customer
dimes = (cents % 25) // 10

# Calculate the number of nickels to give the customer
nickels = ((cents % 25) % 10) // 5

# Calculate the number of pennies to give the customer
pennies = (cents % 5)

# Sum coins
coins = quarters + dimes + nickels + pennies

# Print total number of coins to give the customer
print(coins)