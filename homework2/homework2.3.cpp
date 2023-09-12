#include <iostream>

int main() {
    for (int n = 10; n <= 25; ++n) {
        int triangularNum = 0;

        for (int i = 1; i <= n; ++i) {
            triangularNum += i;
        }

        std::cout << "T(" << n << ") = " << triangularNum << std::endl;
    }

    return 0;
}