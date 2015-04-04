#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		string str[m];
		for (int i = 0; i < m; i++)
			cin >> str[i];
		sort(str, str + m, cmp);
		for (int i = 0; i < m; i++)
			cout << str[i];
		cout << endl; 
	}
	return 0;
}
