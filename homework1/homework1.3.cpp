#include <iostream>

int main() {
    double value1, value2;
    char operat;
    std::cout << "Type in a simple expression: ";
    std::cin >> value1 >> operat >> value2;
    double result;

    switch (operat) {
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            if (value2 == 0) {
                std::cout << "Division by zero is not allowed" << std::endl;
                return 1;
            }
            result = value1 / value2;
            break;
        case '%':
            if (value2 == 0) {
                std::cout << "Division by zero is not allowed" << std::endl;
                return 1;
            }
            result = static_cast<int>(value1) % static_cast<int>(value2);
            break;
        default:
            std::cout << "Invalid operator" << std::endl;
            return 1;
    }
    std::cout << "Result: " << result << std::endl;
    return 0;
}