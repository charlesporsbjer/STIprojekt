# Python program that demonstrates some advanced features

# Dictionary: A dictionary is a collection of key-value pairs.
# This is not available in C.
person = {
    "name": "John",
    "age": 30,
    "city": "New York"
}

print(f"Person's name: {person['name']}")
print(f"Person's age: {person['age']}")
print(f"Person's city: {person['city']}")

# List Comprehension: This is a concise way to create lists.
# Not available in C.
numbers = [1, 2, 3, 4, 5]
squares = [num**2 for num in numbers]
print(f"Squares: {squares}")

# Lambda function: A small anonymous function.
# Not available in C.
double = lambda x: x * 2
print(f"Double of 10: {double(10)}")

# Using built-in functions
print("Hello, World!")

# Object-Oriented Programming: Python supports OOP.
# Although C supports structs, it does not have full OOP support like Python.
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        print(f"Hello, my name is {self.name} and I am {self.age} years old.")

john = Person("John", 30)
john.greet()