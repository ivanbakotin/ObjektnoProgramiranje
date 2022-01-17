#include "vector.hpp"

using namespace std;

int main() {
    MyVector mv;
    mv.vector_new();
    
    int m;
    cout << "Input element, Ctrl+d (linux) or Ctrl+z (win) to end input." << endl;
    while(cin >> m) {
        mv.vector_push_back(m);
    };
    
    cout << "First element: " << mv.vector_front() << endl;
    cout << "Last element: " << mv.vector_back() << endl;
    mv.print_vector();    
    cout << "Removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "Size: " << mv.vector_size() << endl;
    cout << "Capacity: " << mv.capacity << endl;

    mv.print_vector();
    mv.vector_delete();
    mv.print_vector();
};