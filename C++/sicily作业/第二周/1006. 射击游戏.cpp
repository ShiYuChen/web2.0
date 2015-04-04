#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, a[10];
	cin >> n;
	while (n--)
	{
		string s = "Yes";
		for (int i = 0; i < 10; i++)
			cin >> a[i];
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (a[j] < a[i])
				{
					for (int k = j + 1; k < 10; k++)
					{
						if (a[k] > a[j] && a[k] < a[i])
						{
							s = "No";
						}
						
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
