#include <iostream>
using namespace std;

int binary_search(int* a, int size, int data)
{
	if (a == NULL) return -1;
	int low = 0, high = size - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data == a[mid]) return mid;
		else if (data > a[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int index = binary_search(a, 10, 8);
	if (index != -1) cout << "index:" << index << endl << "a[" << index << "]:" << a[index] << endl;
	else cout << "NOT found." << endl;
	return 0;
}
