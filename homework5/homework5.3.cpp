#include <iostream>
#include <map>
#include <vector>

int main() {
    std::cout << "Enter a set of digits: ";
    std::string input;
    std::cin >> input;

    std::map<char, int> digitCount;

    for (char digit : input) {
        if (isdigit(digit)) {
            digitCount[digit]++;
        }
    }

    std::vector<char> result;

    int maxCount = 1; 
    for (const auto& pair : digitCount) {
        if (pair.second >= 2) {
            if (pair.second > maxCount) {
                result.clear();
                maxCount = pair.second;
            }
            if (pair.second == maxCount) {
                result.push_back(pair.first);
            }
        }
    }

    if (result.empty()) {
        std::cout << "No digits have at least two occurrences." << std::endl;
    } else {
        std::cout << "Digits with the maximum number of occurrences: ";
        for (char digit : result) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
