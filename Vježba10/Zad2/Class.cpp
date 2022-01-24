#include "Class.hpp"

#include <iostream>

using namespace std;
 
int main() {
	Stack<int> stack(10);

	stack.push(1);
	stack.push(3);

	stack.pop();


	if (stack.isEmpty()) {
		stack.print();
	}
}
