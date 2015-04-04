#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		queue<int>q;
		cin >> m;
		for (int i = 1; i <= m; i++)
			q.push(i);
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << endl;
	}
	return 0;
}
