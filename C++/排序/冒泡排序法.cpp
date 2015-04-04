#include <iostream>
using namespace std;

void bubble_sort(int* a, int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
		for (int k = 0; k < 10; k++)
			cout << a[k] << " ";
		cout << endl;
	}
}





int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	bubble_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

