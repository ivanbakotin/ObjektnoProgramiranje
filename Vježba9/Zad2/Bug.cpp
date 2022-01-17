#include "Bug.hpp"

using namespace std;

int Bug::brojNogu() {
	return this->noge;
}

string Bug::vrstaZivotinje() {
	return this->vrsta;
}

void Bug::setVrsta(string s) {
	this->vrsta = s;
}

void Bug::setNoge(int n) {
	this->noge = n;
}