#pragma once

#include "Animal.hpp"

class Bird : public Animal {
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};
