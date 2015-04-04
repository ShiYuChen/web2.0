#include <iostream>
using namespace std;

void insert_sort(int* a, int length)
{
	int i, j, temp;
	for (i = 1; i < length; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	insert_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
