#include <iostream>
#include <vector>
using namespace std;

//返回最后一个出现目标值的下标 
template <typename T>
int binarySearch(const vector<T> table, int bot, int top, const T &x)
{
	int temp = -1;
    while (bot <= top)
    {
        int mid = (bot+top)/2;
        if (table[mid] == x)
        {
        	temp = mid;
        	bot = mid + 1;
        }
        else if (table[mid] < x) bot = mid + 1;
        else top = mid - 1;
    }
    if (temp != -1) return temp;
    return -1;
}

int main()
{
	int a[] = {0,1,2,3,3,5,6};
	vector<int> v(a,a+7);
	cout << binarySearch(v, 0, v.size()-1, 3);  // 输出5
	cout << binarySearch(v, 0, v.size()-1, 7);  //输出-1
	return 0;
}
