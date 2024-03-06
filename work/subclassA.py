class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

class Poodle(Dog):
    def speak(self):
        return f"{self.name} says Woof! in a Poodle way."

my_poodle = Poodle("Fido")
print(my_poodle.speak())  # Output: Fido says Woof! in a Poodle way.