#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a <= b;
}

int main()
{
	long int t, m, n, min, max;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		long int a[m];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		sort(a, a+m, cmp);
		if (n % 2 == 1)
		{
			min = a[n / 2];
			max = a[m - n / 2 - 1];
			cout << max - min << endl;
		}
		else
		{
			min = a[n/2] + a[n/2-1];
			max = a[m-n/2] + a[m-n/2-1];
			cout << (max - min)/2 << endl;
		}
	}
	return 0;
}
