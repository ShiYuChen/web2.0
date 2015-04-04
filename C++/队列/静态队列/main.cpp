#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
	queue q;
	int item;
	q.append(12);
	q.retrieve(item);
	cout << item << endl;
	q.retrieve_and_serve(item);
	cout << item << endl;
	if (q.empty()) cout << "The queue is empty." << endl;
	return 0;
}
