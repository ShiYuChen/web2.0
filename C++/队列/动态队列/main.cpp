#include "queue.h"

#include <iostream>
using namespace std;

int main()
{
	queue q;
	int item;
	q.append(12);
	q.append(24);
	queue q1 = q;
	q1.retrieve_and_serve(item);
	cout << item << endl;
	q1.retrieve_and_serve(item);
	cout << item << endl;
	return 0;
}
