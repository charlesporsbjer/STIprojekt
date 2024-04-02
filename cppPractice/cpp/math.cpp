/*1. Write a C++ program to check whether a given number is a power of two or not.
Is 8 is power of 2: True
Is 256 is power of 2: True
Is 124 is power of 2: False*/

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <stack>

using namespace std;

class Math {
public:
    static bool isPowerOfTwo(int x) {
        int mult = 1;
        while (mult < x) {
            mult *= 2;
            if (mult == x)
                return true;
        }
        return false;
    }
    static int additivePersistence(int x) {
        // Say input is 9876
        // then we check 9 + 8 + 7 + 6 = 30
        // 3 + 0 = 3
        // Additive persistence == 2
        vector<int8_t> numbers;
        string str = to_string(x);
        int sum = 0;
        int iterations = 0;
        int iterationSum;
        do {
            for (int i = 0; i < str.length(); i++) {
                int digit = str[i] - '0';
                cout << digit << std::endl;
                numbers.push_back(digit);
                sum +=numbers[i];
            }
            iterations++;
            str = to_string(sum);
            iterationSum = sum; 
            cout << "\n" << "Sum of this iteration = " << iterationSum << "\n";
            sum = 0;
            numbers.clear();
        } while (iterationSum > 9);
        cout << "\n" << iterations << " iterations.\n";
        return iterations;
    }

    static int reverseDigits(int x) {
        string str = to_string(x);
        stack<int> reverse;
        int digit;
        int reversed;
        for (int i = 0; i < str.length(); i++) {
            reverse.push(str[i]);
        }
        for (int i = 0; i < str.length(); i++) {
            str[i] = reverse.top();
            reverse.pop();
        } 
        reversed = stoi(str);
        return reversed;
    }
    
    // This method is not finished until it also takes divisor as argument and divides by it.
    static int noOperandDivision(int dividend) {

        return dividend >> 1;
    }
};

int main() {
    if (Math::isPowerOfTwo(64))
        std::cout << "true \n";
    else
        std::cout << "false \n";

    int persistence = Math::additivePersistence(9876);
    cout << "Additive Persistence: " << persistence << endl;

    int notReversed = 123;
    int reversedInt = Math::reverseDigits(notReversed);
    cout << notReversed << " reversed = " << reversedInt << "\n";

    int toDivide = 44;
    int with = 4;
    int divided = Math::noOperandDivision(toDivide);
    cout << toDivide << " divided and truncated = " << divided << "\n";

    int toDivide2 = 61;
    int with2 = 6;
    int divided2 = Math::noOperandDivision(toDivide2);
    cout << toDivide2 << " divided and truncated = " << divided2 << "\n";


    return 0;
}