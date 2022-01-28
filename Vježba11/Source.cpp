#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	vector<int> vector;

	try {
		ifstream file;

		file.open("numbers.txt");

		if (file.is_open()) {
			istream_iterator<int> first(file);
			istream_iterator<int> last;

			copy(first, last, back_inserter(vector));
		} else {
			throw string("File not found!");
		}

	} catch (string errorname) {
		cout << errorname << endl;
		return 1;
	}

	int counter = count_if(vector.begin(), vector.end(), [](int i){ return i > 500; });
	cout << "Number of numbers greater than 500: " << counter << endl;

	int minElement = *min_element(vector.begin(), vector.end());
	cout << "Min element: " << minElement << endl;

	int maxElement = *max_element(vector.begin(), vector.end());
	cout << "Max element: " << maxElement << endl;

	vector.erase(remove_if(vector.begin(), vector.end(), [](int i) { return i < 300; }), vector.end());

	sort(vector.begin(), vector.end(), greater<int>());

	for (auto num : vector) {
		cout << num << endl;
	}
}
