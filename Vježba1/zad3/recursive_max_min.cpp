#include <iostream>

using namespace std;

int findMinRec(int array_ran[], int n) {
    if (n == 1) return array_ran[0];
    return min(array_ran[n-1], findMinRec(array_ran, n-1));
};

int findMaxRec(int array_ran[], int n) {
    if (n == 1) return array_ran[0];
    return max(array_ran[n-1], findMaxRec(array_ran, n-1));
};

int main() {
    int array_ran[] = {14, -33, 99, 14, -466, 3, 78};
    int n = sizeof(array_ran)/sizeof(array_ran[0]);
    cout <<  findMaxRec(array_ran, n) << endl;
    cout <<  findMinRec(array_ran, n) << endl;
};
