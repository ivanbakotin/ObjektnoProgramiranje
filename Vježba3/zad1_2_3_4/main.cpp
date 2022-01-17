#include <iostream>
#include <vector>
#include "vector.hpp"

using namespace std;

int main() {
    int vector_1_size, a, b;
    vector<int> vector_1, vector_2, vector_3;

    cout << "Input vector size: ";
    cin >> vector_1_size;

    inputVectorElements(vector_1, vector_1_size);

    printVector(vector_1);

    cout << "Input vector interval: ";
    cin >> a;
    cin >> b;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    inputVectorInterval(vector_2, a, b);

    printVector(vector_2);

    vector_3 = firstNotInSecondVector(vector_1, vector_2);

    printVector(vector_3);

    sortVector(vector_1);

    printVector(vector_1);

    removeVectorElement(vector_1, 1);

    printVector(vector_1);
}
