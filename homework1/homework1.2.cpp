#include <iostream>

int main() {
    int year;
    std::cout << "Enter the year to be tested: ";
    std::cin >> year;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << "Yes, it’s a leap year." << std::endl;
    } else {
        std::cout << "No, it’s not a leap year." << std::endl;
    }
    
    return 0;
}