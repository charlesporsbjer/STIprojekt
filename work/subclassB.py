class A:
    def method_A(self):
        print("Method A")

class B(A):
    def method_B(self):
        print("Method B")

class C(B):
    def method_C(self):
        print("Method C")

obj = C()
obj.method_A()  # Output: Method A
obj.method_B()  # Output: Method B
obj.method_C()  # Output: Method C