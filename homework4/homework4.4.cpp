#include <iostream>

using namespace std;

int * MergeArrays(int *a, int *b, int sizea, int sizeb) {
    int *mergedArray = new int[sizea + sizeb];  // Dynamic memory allocation
    int i = 0, j = 0, k = 0;

    while (i < sizea && j < sizeb) {
        if (a[i] < b[j]) {
            mergedArray[k++] = a[i++];
        } else {
            mergedArray[k++] = b[j++];
        }
    }

    while (i < sizea) {
        mergedArray[k++] = a[i++];
    }
    while (j < sizeb) {
        mergedArray[k++] = b[j++];
    }

    return mergedArray;
}

int main() {
    int sizea = 5;
    int sizeb = 4;

    int array1[] = {7, 5, 1, 5, 8, 4};
    int array2[] = {5, 9, 3, 8};

    int *result = MergeArrays(array1, array2, sizea, sizeb);

    cout << "Merged Array: ";
    for (int i = 0; i < sizea + sizeb; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    return 0;
}
