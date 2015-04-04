#include <iostream>
using namespace std;

void quick_sort(int* a, int left, int right)
{
	if (left <= right)
	{
		int key = a[left];
		int low = left;
		int high = right;
		while (low < high)
		{
			while (low < high && a[high] > key) high--;      //��������ɨ��ֱ��������С��key���� 
			a[low] = a[high];
			while (low < high && a[low] < key) low++;        //��������ɨ��ֱ�������д���key���� 
			a[high] = a[low];
		}
		a[low] = key;
		//�ݹ� 
		quick_sort(a, left, low - 1);
		quick_sort(a,low + 1, right);
	}
}


int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	quick_sort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
