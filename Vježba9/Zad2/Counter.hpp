#pragma once

#include "Animal.hpp"

using namespace std;

class Counter {
private:
	int legs = 0;

public:
	void sendAnimal(Animal* animal) {
		cout << "Dodan: " << animal->vrstaZivotinje() << endl;
		this->legs += animal->brojNogu();
	};

	int displayLegs() {
		return this->legs;
	}
};
