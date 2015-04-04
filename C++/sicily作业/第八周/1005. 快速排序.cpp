#include <iostream>
using namespace std;


template <class Record> 
void quick_sort(Record* s, Record* e)
{
	if (s < e)
	{
		Record key = *s;
		Record *low = s;
		Record *high = e;
		while (low < high)
		{
			while (low < high && *high > key) high--;
			*low = *high;
			while (low < high && *low <= key) low++;
			*high = *low;
		}
		*low = key;
		quick_sort(s, low - 1);
		quick_sort(low + 1, s);
	}
}




int main()
{
int arr[10] = {1,2,5,6,4,3,9,7,8,10};
quick_sort (arr, arr+10);
for (int i = 0; i < 10; i++)
cout << arr[i] << " ";
cout << endl;
return 0;
}

