#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	list l;
	int item;
	l.insert(0, 12);
	l.insert(1,34);
	l.insert(2,56);
	l.remove(1,item);
	cout << item << endl;
	l.retrieve(1,item);
	cout << item << endl;
	l.replace(0,1111);
	l.retrieve(0,item);
	cout << item << endl;
	if (!l.empty()) cout << "The list is not empty." << endl;
}
