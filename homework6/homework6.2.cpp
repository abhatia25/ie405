#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate random preference lists for men and women
void GenerateRandomPreferences(int **mPrefList, int **wPrefList, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mPrefList[i][j] = j; // Initialize with preferences 1, 2, ..., n

            // Randomly swap two indices to shuffle the preferences
            int randIndex1 = rand() % n + 1;
            int randIndex2 = rand() % n + 1;
            swap(mPrefList[i][randIndex1], mPrefList[i][randIndex2]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            wPrefList[i][j] = j; // Initialize with preferences 1, 2, ..., n

            // Randomly swap two indices to shuffle the preferences
            int randIndex1 = rand() % n + 1;
            int randIndex2 = rand() % n + 1;
            swap(wPrefList[i][randIndex1], wPrefList[i][randIndex2]);
        }
    }
}

// StableMatching function
int *StableMatching(int **mPrefList, int **wPrefList, int n) {
    int *mEngaged = new int[n + 1];
    int *wEngaged = new int[n + 1];
    vector<int> curPos(n + 1, 1); // Use a vector to store curPos

    for (int i = 1; i <= n; i++) {
        mEngaged[i] = -1;
        wEngaged[i] = -1;
    }

    int m = 1; // Start with the first man

    while (m <= n) {
        int w = mPrefList[m][curPos[m]];

        if (wEngaged[w] == -1) {
            mEngaged[m] = w;
            wEngaged[w] = m;
        } else {
            int m2 = wEngaged[w];
            if (wPrefList[w][m] < wPrefList[w][m2]) {
                mEngaged[m2] = -1;
                mEngaged[m] = w;
                wEngaged[w] = m;
            }
        }

        curPos[m]++;
        m++;
    }

    return mEngaged;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

    int n = 100; // Number of men and women
    int **mPrefList, **wPrefList;

    // Allocate memory for preference lists
    mPrefList = new int *[n + 1];
    wPrefList = new int *[n + 1];
    for (int i = 1; i <= n; i++) {
        mPrefList[i] = new int[n + 1];
        wPrefList[i] = new int[n + 1];
    }

    int totalProposals = 0;
    int minProposals = n * n; // Initialize with a large value
    int maxProposals = 0;

    for (int instance = 0; instance < 1000; instance++) {
        // Generate random preference lists
        GenerateRandomPreferences(mPrefList, wPrefList, n);

        // Call StableMatching and count proposals
        int *output = StableMatching(mPrefList, wPrefList, n);

        int proposals = 0;
        for (int i = 1; i <= n; i++) {
            if (output[i] != -1) {
                proposals++; // Count proposals for each man
            }
        }

        totalProposals += proposals;
        minProposals = min(minProposals, proposals);
        maxProposals = max(maxProposals, proposals);

        // Deallocate memory for the current preference lists
        for (int i = 1; i <= n; i++) {
            delete[] mPrefList[i];
            delete[] wPrefList[i];
        }
    }

    // Print statistics
    cout << "Minimum proposals: " << minProposals << endl;
    cout << "Average proposals: " << totalProposals / 1000 << endl;
    cout << "Maximum proposals: " << maxProposals << endl;

    // Deallocate memory for preference lists
    delete[] mPrefList;
    delete[] wPrefList;

    return 0;
}
