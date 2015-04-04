#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, count = 0;
		cin >> a;
		int temp = a;
			count += temp / 100;
			temp %= 100;
			count += temp / 50;
			temp %= 50;
			count += temp / 20;
			temp %= 20;
			count += temp / 10;
			temp %= 10;
			count += temp / 5;
			temp %= 5;
			count += temp;
			cout << count << endl;
	}
} 
