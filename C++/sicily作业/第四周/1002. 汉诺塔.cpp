#include <iostream>
using namespace std;

void hanoi(int a, int s, int t, int f)
{
	if (a > 0)
	{
	hanoi(a-1,s,f,t);
	cout << "move disk " << a << " from peg " << s << " to peg " << f << endl;
	hanoi(a-1,t,s,f);		
	} 

}
int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		hanoi(m, 1,2,3);
	}
	return 0;
} 
