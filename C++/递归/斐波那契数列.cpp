#include <iostream>
using namespace std;

//F0=0,F1=1,Fn = Fn-1 + Fn-2
int  fibonacci(int n)
{
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main()
{
	int n;
	cout << "������n��ֵ��"; 
	cin >> n;
	cout << "��" << n << "��쳲�������Ϊ��" << fibonacci(n) << endl;
	return 0;
}
