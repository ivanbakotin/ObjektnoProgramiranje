#include <iostream>
#include <vector>
#include "vector.hpp"
#include <algorithm>
#include <numeric>

using namespace std;

void inputVectorElements(vector<int> &vector, int n) {

    int num;

    for (int i = 0; i < n; i++) {
        cout << "Input vector element: ";
        cin >> num;
        vector.push_back(num);
    }
}

void inputVectorInterval(vector<int> &vector, int a, int b) {

    int num;

    while(1) {

        cout << "Input vector element: ";
        cin >> num;

        if ((num > a) && (num < b)) {
            vector.push_back(num);
        } else {
            break;
        }
    }
}

void printVector(vector<int> vector) {

    cout << "Vector: " << endl;

    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }
}

vector<int> firstNotInSecondVector(vector<int> vector_1, vector<int> vector_2) {

    int num;
    int n = vector_1.size();
    vector<int> vector_new;
    
    for (int i = 0; i < n; i++) {
        if (!(find(vector_2.begin(), vector_2.end(), vector_1[i]) != vector_2.end())) {
            vector_new.push_back(vector_1[i]);
        }
    }
    return vector_new;
}

void sortVector(vector<int> &vector) {
    
    sort(vector.begin(), vector.end());

    vector.insert(vector.begin(), 0);

    int sum = accumulate(vector.begin(), vector.end(), 0);

    vector.insert(vector.end(), sum);
}

void removeElement(vector<int> &vector, int n) {
    swap(vector[n], vector.back());
    vector.pop_back();
}
