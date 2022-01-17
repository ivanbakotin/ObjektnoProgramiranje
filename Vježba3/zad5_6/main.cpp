#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countStringInString(string str, string subStr) {

    int cnt = 0;
    size_t nPos = str.find(subStr);

    while (nPos != string::npos) {
        cnt++;
        nPos = str.find(subStr, nPos + 1);
    }

    return cnt;
}

void inputStringsIntoVector(vector<string> &vector, int num) {

    for (int i = 0; i < num; i++) {

        string s;

        cout << "Type a string: ";

        cin >> s;

        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }

        vector.push_back(s);
    }

    sort(vector.begin(), vector.end());
}

void printVector(vector<int> vector) {

    cout << "Vector: " << endl;

    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }
}

int main() {

	int counter;
    vector<string> vector;
	string str = "this is my string that has multiple strings and has a word string";
	string findMe = "string";

    counter = countStringInString(str, findMe);
    cout << "Broj Ponavljanja: " << counter << endl;

    int num;

    cout << "Number of strings: ";
    cin >> num;

    inputStringsIntoVector(vector, num);

    for (int i = 0; i < num; i++) {
        cout << vector[i] << endl;
    }
}
