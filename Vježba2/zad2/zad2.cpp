#include <iostream>

using namespace std;

int& returnRefElement(int* array) {
    return array[0];
}

int main() {

	int *array = new int[5];

    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

	returnRefElement(array)++;

	cout << array[0] << endl;
}
