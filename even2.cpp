#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << num << " is negative\n";
    } else if ((num & 1) == 0) {
        std::cout << num << " is even\n";
    } else {
        std::cout << num << " is odd\n";
    }

    return 0;
}