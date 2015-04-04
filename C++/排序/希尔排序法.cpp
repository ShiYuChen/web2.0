#include <iostream>
using namespace std;

void shell_sort(int* a, int length)
{
	int r, j, k, temp;
	for (r = length / 2; r >= 1; r /= 2)
	{
		for (j = r; j < length; j++)            //²åÈëÅÅÐò·¨ 
		{
			k = j - r;
			temp = a[j];
			while (k >= 0 && temp < a[k])
			{
				a[k + r] = a[k];
				k -= r;
			}
			a[k + r] = temp;
		}
	}
}


int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	shell_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
