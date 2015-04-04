#include <iostream>
using namespace std;

void swap1(int *list,int a, int b)
{
	int temp = list[b];
	for (int i = b; i > a; i--)
		list[i] = list[i-1];
	list[a] = temp;
}

void swap2(int *list,int a, int b)
{
	int temp = list[a];
	for (int i = a; i < b; i++)
		list[i] = list[i+1];
	list[b] = temp;
}

void perm(int *list, int a, int b)
{
	if (a == b)
	{
		for (int i = 0; i <= b;i++)
		{
			cout << list[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = a; i <= b; i++)
		{
			swap1(list,a, i);
			perm(list, a+1, b);
			swap2(list,a, i);
		}
	}
}

int main()
{
	int n,m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		int list[m];
		for (int i = 0; i < m; i++)
			list[i] = i+1;
		perm(list, 0, m-1);
	}
	return 0;
}
