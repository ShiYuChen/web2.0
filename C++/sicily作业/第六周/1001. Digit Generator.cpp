#include <iostream>
#include<algorithm>
using namespace std;

long int get(long int a)
{
	long int sum = a, temp = a;
	while (temp / 10 != 0)
	{
		sum += temp % 10;
		temp = temp / 10;
	}
	sum += temp;
	return sum;
}

long int all(long int a)
{
	long int temp = a;
	int count = 1;
	while (temp / 10 != 0)
	{
		temp = temp / 10;
		count++;
	}
	return count;
}

int main()
{
	long int n, m;
	cin >> n;
	while (n--)
	{
		int flag = 1, count = 0;
		cin >> m;
		int j = all(m);
		for (int i = m - j * 10; i <= m; i++)
		{
			if (m == get(i))
			{
				flag = 0;
				cout << i << endl;
				break;
			}
		}
		if (flag) cout << 0 << endl;
	}
	return 0;
}
