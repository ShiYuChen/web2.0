#include <iostream>
#include<algorithm>
using namespace std;

struct Node{
	int x;
	int y;
};

bool cmp(Node a, Node b)
{
	return (a.y <= b.y); 
}

int main()
{
	int n, m, start, end, count;
	cin >> n;
	Node node[200];
	while (n--)
	{
		cin >> m;

		for (int i = 0; i < m; i++)
			cin >> node[i].x >> node[i].y;
		sort(node, node + m, cmp);
		start = node[0].x;
		end = node[0].y;
		count = 1;
		for (int i = 0; i < m;i++)
		{
			if (i == 0)
			{
				start = node[0].x;
				end = node[0].y;
				count++;	
			}
			if (node[i].x > end)
			{
				start = node[i].x;
				end = node[i].y;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
