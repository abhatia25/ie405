#include <iostream>
#include <fstream>

using namespace std;

int *RodCut(int *p, int n) {
    int *r = new int[n + 1]; 
    int *cut = new int[n + 1];

    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int maxRevenue = -1;
        for (int i = 1; i <= j; i++) {
            if (maxRevenue < p[i] + r[j - i]) {
                maxRevenue = p[i] + r[j - i];
                cut[j] = i;
            }
        }
        r[j] = maxRevenue;
    }

    cout << "Optimal Revenue: " << r[n] << endl;
    delete[] r;
    return cut;
}

int main() {
    ifstream inputFile("input.txt");

    int n;
    inputFile >> n;
    int *p = new int[n + 1]; 
    for (int i = 1; i <= n; i++) {
        inputFile >> p[i];
    }

    inputFile.close();
    int *cut = RodCut(p, n);
    cout << "Pieces to sell: ";
    while (n > 0) {
        cout << cut[n] << " ";
        n -= cut[n];
    }
    cout << endl;

    delete[] p;
    delete[] cut;
    return 0;
}
