#include <iostream>
using namespace std;

void select_sort(int *a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int p = a[i],q = i;
		for (int j = i + 1; j < size; j++)
		{
			if (p > a[j])
			{
				p = a[j];
				q = j;
			}
		}
		int temp = a[i];
		a[i] = a[q];
		a[q] = temp;
		for (int k = 0; k < size - 1; k++)
			cout << a[k] << " ";
		cout << a[size-1] << endl;
	}
}

int main()
{
	int n,m;
	cin >> n;
	while (n--)
	{
		cin >> m; 
		int a[m];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		select_sort(a,m);
	}
	return 0;
}
