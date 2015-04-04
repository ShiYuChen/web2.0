#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

static int i = 1;
//1->2,1->3,2->3 即132,123,213 
void move(int number, int start, int temp, int finish)  
{

	if (number > 0)
	{
		move(number - 1, start, finish, temp);              //1,3,2
		cout << "step " << left << setw(6) << i++ << ": " << start << "==>" << finish;   //1,2,3 
		if ((i - 1) % 4 == 0) cout << endl;
		else cout << "  ";
		move(number - 1, temp, start, finish);              //2,1,3
	}

}

int main()
{
	cout << "-----------------------Hanoi-----------------------" << endl;
	int a;
	cout << "please input the number of disks:";
	cin >> a;
	move(a, 1, 2, 3);
	cout << endl;
	cout<<"此次运行该程序所花费的时间为:"<<clock()<<"毫秒"<<endl;
	return 0;
}

