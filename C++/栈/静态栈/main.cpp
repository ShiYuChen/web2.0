#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	stack s;
	int item;
	for (int i = 0; i < 5; i++)
	{
		s.push(i);
	}
		for (int j = 0; j < 5; j++)
	{
		s.pop(item);
		cout << item << endl;
	}
	if (s.empty()) cout << "The stack is empty." << endl;
	return 0;
}
