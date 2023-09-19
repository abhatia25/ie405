#include <iostream>
#include <cstdlib>
#include <ctime>

void coinToss() {
    int result = rand() % 2 + 1;

    if (result == 1) {
        std::cout << "heads" << std::endl;
    } else {
        std::cout << "tails" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int numTosses;

    std::cout << "How many times should we toss the coin? ";
    std::cin >> numTosses;

    for (int i = 0; i < numTosses; ++i) {
        std::cout << "Toss " << (i + 1) << ": ";
        coinToss();
    }

    return 0;
}
