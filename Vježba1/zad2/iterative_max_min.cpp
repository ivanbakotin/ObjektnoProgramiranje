#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getMaxInArray() {
    int n, max, num[30];

     cout << "Enter number of elements you want to enter (Max 30): ";
     cin>>n;

     srand ( time(NULL) );

     for(int i = 0; i < n; i++) {
        num[i] = rand();
     };

     max = num[0];

     for(int i = 0; i < n; i++) {
        cout << num[i] << endl;
        if(max < num[i]) {
            max = num[i];
        };
     };

    return max;
}

int getMinInArray() {
    int n, min, num[30];

   cout << "Enter number of elements you want to enter (Max 30): ";
   cin>>n;

   srand ( time(NULL) );

   for(int i = 0; i < n; i++) {
      num[i] = rand();
   };

   min = num[0];

   for(int i = 0; i < n; i++) {
        cout << num[i] << endl;
        if(min > num[i]) {
            min = num[i];
        };
   };

   return min;
}

int main() {
    int max, min;
    max = getMaxInArray();
    min = getMinInArray();

    cout << "Biggest number in array is: " << max << endl;
    cout << "Smallest number in array is: " << min << endl;
};
