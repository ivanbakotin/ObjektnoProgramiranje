
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void getMaxMin(int *array, int n, int &max, int &min) {

    for(int i = 0; i < n; i++) {
        if(max < array[i]) {
            max = array[i];
        };
        if(min > array[i]) {
            min = array[i];
        };
    };
};

int main() {
    int max, min, n;

    cout << "Enter number of elements you want to enter (Max 30): ";
    cin >> n;

    int *array = new int(n);

    srand ( time(NULL) );

    for(int i = 0; i < n; i++) {
        array[i] = rand();
    };

    max = min = array[0];

    getMaxMin(array, n, max, min);
   
    cout << "Biggest number in array is: " << max << endl;
    cout << "Smallest number in array is: " << min << endl;
};
