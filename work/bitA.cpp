#include <iostream>

int main() {
    int num1, num2, result;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    result = num1 ^ num2; // use bitwise XOR to add numbers
    result += (num1 & num2) << 1; // add carry bit

    std::cout << "Result: " << result << std::endl;

    return 0;
}
