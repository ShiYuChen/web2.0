#include <iostream>
using namespace std;

void find_max(int* a, int size) {                     //找到最大值并放在根节点a[0] 
	for (int j = size - 1; j > 0; j--) {
		int parent = j / 2;
		int child = j;
		if (j < size - 1 && a[j] < a[j + 1]) child++;
		if (a[child] > a[parent]) {
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
		}
	}
}

void heap_sort(int* a, int size)                    //将最大值a[0]放在最后 
{
	for (int j = size; j > 1; j--){
		find_max(a, j);
		int temp = a[0];
		a[0] = a[j - 1];
		a[j - 1] = temp;
	}
}





int main() {
	int a[10] = {3,2,5,7,8,4,6,9,1,10};
	heap_sort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

