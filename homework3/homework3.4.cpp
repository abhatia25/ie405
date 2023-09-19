#include <iostream>

std::string digitToEnglish(int digit) {
    switch (digit) {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default: return "";
    }
}

int main() {
    int number;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    if (number == 0) {
        std::cout << "zero" << std::endl;
    } else {
        while (number != 0) {
            int digit = number % 10; 
            std::string digitName = digitToEnglish(digit);
            std::cout << digitName << " ";
            number /= 10;
        }
        std::cout << std::endl;
    }

    return 0;
}
