// 从大到小排列 
#include <iostream>
using namespace std;

void find_min(int* a, int size) {                     //找到最小值并放在根节点a[0] 
	for (int j = size - 1; j > 0; j--) {
		int parent = j / 2;
		int child = j;
		if (j < size - 1 && a[j] > a[j + 1]) child++;
		if (a[child] < a[parent]) {
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
		}
	}
}

void heap_sort(int* a, int size)                    //将最小值a[0]放在最后 
{
	for (int j = size; j > 0; j--){
		find_min(a, j);
		int temp = a[0];
		a[0] = a[j - 1];
		a[j - 1] = temp;
	}
}





int main() {
	int a[10] = {4,7,8,3,2,9,5,6,1,10};
	heap_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

