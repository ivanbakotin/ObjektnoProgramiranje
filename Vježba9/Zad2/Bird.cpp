#include "Bird.hpp"

using namespace std;

int Bird::brojNogu() {
	return this->noge;
}

string Bird::vrstaZivotinje() {
	return this->vrsta;
}

void Bird::setVrsta(string s) {
	this->vrsta = s;
}

void Bird::setNoge(int n) {
	this->noge = n;
}