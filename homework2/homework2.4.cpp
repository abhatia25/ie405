#include <iostream>

int main() {
    int num;
    int sum = 0;
    int product = 1;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    int originalNum = num;
    while (num != 0) {
        int digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }

    std::cout << "Sum is " << sum << " and Product is " << product << std::endl;

    return 0;
}