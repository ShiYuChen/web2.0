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
	cout << "请输入n的值："; 
	cin >> n;
	cout << "第" << n << "个斐波那契数为：" << fibonacci(n) << endl;
	return 0;
}
