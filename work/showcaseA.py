# Python program that showcases some features not present in C

# List Comprehension
numbers = [1, 2, 3, 4, 5]
squared_numbers = [number ** 2 for number in numbers]
print(squared_numbers)  # Output: [1, 4, 9, 16, 25]

# Dictionary
person = {'name': 'John', 'age': 30, 'city': 'New York'}
print(person['name'])  # Output: John

# Lambda Function
add = lambda x, y: x + y
print(add(5, 3))  # Output: 8

# Map Function
numbers = [1, 2, 3, 4, 5]
squared_numbers = list(map(lambda x: x ** 2, numbers))
print(squared_numbers)  # Output: [1, 4, 9, 16, 25]

# Filter Function
numbers = [1, 2, 3, 4, 5]
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # Output: [2, 4]

# Reduce Function
from functools import reduce
numbers = [1, 2, 3, 4, 5]
product = reduce(lambda x, y: x * y, numbers)
print(product)  # Output: 120

# Exception Handling
try:
    x = 5 / 0
except ZeroDivisionError:
    print("You can't divide by zero!")

# Generators
def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1

seq = infinite_sequence()
for _ in range(10):
    print(next(seq))