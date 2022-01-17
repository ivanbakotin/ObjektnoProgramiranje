#pragma once
#include <string>
#include <iostream>

using namespace std;

class Animal {
public:
	virtual int brojNogu() = 0;
	virtual string vrstaZivotinje() = 0;
	virtual ~Animal();
};
