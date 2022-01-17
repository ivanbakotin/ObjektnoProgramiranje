#include <iostream>
#include <vector>

#include "Animal.hpp"
#include "Counter.hpp"
#include "Parrot.hpp"
#include "Beetle.hpp"
#include "Hawk.hpp"

using namespace std;

int main() {
	Animal* zivote[3];

	zivote[0] = new Hawk;
	zivote[1] = new Parrot;
	zivote[2] = new Beetle;

	Counter brojac;

	for (auto& a : zivote) {
		brojac.sendAnimal(a);
	}

	cout << brojac.displayLegs() << endl;
}
