#include <iostream>

using namespace std;

template<typename T>
void sortList(T list[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (list[i] < list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

template<>
void sortList<char>(char list[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tolower(list[i]) < tolower(list[j])) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int main() {
    int list[] = { 1, 3, 2, 4, 5, 2, 1, 6, 7, 4, 3, 5 };
 
    int sizeList = sizeof list / sizeof list[0];
   
    sortList(list, sizeList);

    for (int i = 0; i < sizeList; i++) {
        cout << list[i] << " ";
    }
    cout << endl;



    char listChar[] = { 'a', 'A', 'b', 'c', 'C', 'a', 'a', 'D', 'B', 'c', 'E', };

    int sizeListChar = sizeof listChar / sizeof listChar[0];

    sortList(listChar, sizeListChar);

    for (int i = 0; i < sizeListChar; i++) {
        cout << listChar[i] << " ";
    }
    cout << endl;
}