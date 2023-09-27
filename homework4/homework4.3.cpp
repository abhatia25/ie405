#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int ARRAY_SIZE = 5;
    int lottery[ARRAY_SIZE];
    int user[ARRAY_SIZE];
    int count = 0;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        lottery[i] = rand() % 10;
    }

    cout << "Enter your 5 lottery numbers (0-9): ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin >> user[i];
    }

    cout << "Lottery numbers: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << lottery[i] << " ";
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (abs(lottery[i] - user[i]) <= 1) {
            count++;
        }
    }

    cout << "\nNumber of matching digits within ±1: " << count << endl;
    if (count == ARRAY_SIZE) {
        cout << "You are a big prize winner!" << endl;
    }

    return 0;
}
