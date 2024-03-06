# Define a class called "Person"
class Person:
    # Constructor method
    def __init__(self, name, age):
        # Initialize instance variables
        self.name = name
        self.age = age

    # Method to display person's details
    def display_details(self):
        print(f"Name: {self.name}, Age: {self.age}")

# Create an object of the Person class
person1 = Person("John", 30)

# Call the display_details method on the person1 object
person1.display_details()  # Output: Name: John, Age: 30

# Define a subclass of Person called "Employee"
class Employee(Person):
    def __init__(self, name, age, employee_id):
        # Call the constructor of the superclass (Person)
        super().__init__(name, age)
        self.employee_id = employee_id

    # Method to display employee's details
    def display_details(self):
        print(f"Name: {self.name}, Age: {self.age}, Employee ID: {self.employee_id}")

# Create an object of the Employee class
employee1 = Employee("Jane", 35, "E123")

# Call the display_details method on the employee1 object
employee1.display_details()  # Output: Name: Jane, Age: 35, Employee ID: E123