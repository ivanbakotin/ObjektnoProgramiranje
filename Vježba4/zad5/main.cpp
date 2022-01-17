#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void removeMatches(vector<int> &vector, int n) {
    for (int i = 0; i < n; i++) {
        if (vector.size() != 0) {
            vector.pop_back();
        }
    }

    cout << "Matches left: " << vector.size() << endl;
}

int main() {

    bool computer_move = true;

    int n;

    vector<int> vector;

    for (int i = 0; i < 21; i++) {
        vector.push_back(i);
    }

    while(1) {
        
        if (computer_move) {
            srand ( time(NULL) );

            n = rand()%(3)+1;
            
            cout << "Computer Move: "<< n << endl;

            removeMatches(vector, n);

            if(vector.size() <= 0) {
                cout << "You Won" << endl;
                break;
            }

            computer_move = false;
        } else {
            while(1) {
                cout << "Choose 1, 2 or 3!";
                cin >> n;

                if (n == 1 || n == 2 || n == 3) {
                    cout << "Player Move: "<< n << endl;
                    removeMatches(vector, n);
                    break;
<<<<<<< Updated upstream
=======
                } else {
                    cout << "Choose 1, 2 or 3!"<< endl;
>>>>>>> Stashed changes
                }
            }

            if(vector.size() <= 0) {
                cout << "You Lost" << endl;
                break;
            }

            computer_move = true;
        }
    }
}
