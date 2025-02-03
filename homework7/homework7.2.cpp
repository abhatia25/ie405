#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int finish;
    int index; 
};

bool compareIntervals(const Interval &a, const Interval &b) {
    return a.finish < b.finish;
}

bool* IntervalScheduling(int *s, int *f, int n) {
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        intervals[i].start = s[i];
        intervals[i].finish = f[i];
        intervals[i].index = i;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    bool* output = new bool[n];
    fill(output, output + n, false);
    output[intervals[0].index] = true;
    int lastFinishTime = intervals[0].finish;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= lastFinishTime) {
            output[intervals[i].index] = true;
            lastFinishTime = intervals[i].finish;
        }
    }
    return output;
}

int main() {
    ifstream input_file("input-scheduling.txt");
    if (!input_file.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    int n;
    input_file >> n;
    int* s = new int[n];
    int* f = new int[n];

    for (int i = 0; i < n; i++) {
        input_file >> s[i] >> f[i];
    }

    input_file.close();
    bool* output = IntervalScheduling(s, f, n);

    cout << "Accepted Intervals: ";
    for (int i = 0; i < n; i++) {
        if (output[i]) {
            cout << "(" << s[i] << ", " << f[i] << ") ";
        }
    }
    cout << endl;

    delete[] s;
    delete[] f;
    delete[] output;
    return 0;
}
