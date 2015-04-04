#include <iostream>
using namespace std;

void select_sort(int* a, int length)
{
	int i, j, k, temp;
	for (i = 0; i < length; i++)
	{
		k = i;
		for (j = i + 1; j < length; j++)
		{
			if (a[j] < a[k])
				k = j;
		}
		if (i != k)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}


int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	select_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
