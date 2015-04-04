#include <iostream>
using namespace std;

void merge_array(int* a, int left, int right)     //�ϲ�  
{
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = 0;
	int temp[right + 1];
	while (i <= mid && j <= right)                 //��С�Ŀ�ʼ�������Ƚ� 
	{
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	while (i <= mid) temp[k++] = a[i++];          //���������ʣ�µ� 
	while (j <= right) temp[k++] = a[j++];
	for (i = 0; i < k; i++)                       //����a�����left~right 
		a[left + i] = temp[i];
}


void merge_sort(int* a, int left, int right)     //���� 
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge_array(a, left, right);
	}
}


int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	merge_sort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
