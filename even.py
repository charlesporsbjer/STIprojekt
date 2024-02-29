def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

num = int(input("Enter a number: "))

if num < 0:
    print("The number is negative and ")

if num % 2 == 0:
    print("even.")
else:
    print("odd.")

if is_prime(num):
    print("The number is also prime.")
else:
    print("The number is not prime.")