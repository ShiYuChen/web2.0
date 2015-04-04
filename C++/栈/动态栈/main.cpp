#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	stack s1;
	int item;
	s1.push(1);
	s1.push(2);
	stack s2(s1);
	s2.top(item);
	cout << item << endl;
	return 0;
}
