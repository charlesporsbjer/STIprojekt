#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "The number is negative and ";
    }

    if ((num & 1) == 0) {
        std::cout << "even." << std::endl;
    } else {
        std::cout << "odd." << std::endl;
    }

    return 0;
}