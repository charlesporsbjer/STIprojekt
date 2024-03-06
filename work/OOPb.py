# Define a class called 'Person'
class Person:
    # Define a special method called '__init__' which is a constructor
    def __init__(self, name, age, city):
        # Initialize instance variables
        self.name = name
        self.age = age
        self.city = city

    # Define a method to display person's details
    def display_details(self):
        print(f"Name: {self.name}, Age: {self.age}, City: {self.city}")

# Create an instance of the 'Person' class
person1 = Person("John", 30, "New York")

# Call the 'display_details' method on the 'person1' instance
person1.display_details()

# Create another instance of the 'Person' class
person2 = Person("Jane", 25, "Los Angeles")

# Call the 'display_details' method on the 'person2' instance
person2.display_details()