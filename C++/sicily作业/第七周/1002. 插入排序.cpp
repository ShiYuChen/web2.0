#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int time = 0;
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 1; i < n; i++)
		{
			int temp = a[i];
			int j = i - 1;
			int flag = 0;
			while (j >= 0 && temp < a[j])
			{
				flag = 1;
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = temp;
			if (flag) time += 5;
		}
		cout << time << endl;
	}

	return 0;
}
