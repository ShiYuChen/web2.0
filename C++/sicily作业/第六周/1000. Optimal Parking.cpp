#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a <= b; 
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n], sum = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n, cmp);
		for (int i = 1; i < n; i++)
		{
			sum += a[i] - a[i-1];
		}
		cout << sum * 2 << endl;
	}
	return 0;
}
