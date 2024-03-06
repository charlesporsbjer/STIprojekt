class A:
    def foo(self):
        print("A")

class B(A):
    def foo(self):
        super().foo()
        print("B")

class C(A):
    def foo(self):
        super().foo()
        print("C")

class D(B, C):
    pass

d = D()
d.foo()