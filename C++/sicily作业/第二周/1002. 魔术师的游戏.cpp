#include <iostream>
using namespace std;
int main()
{
    int m, n, index, count;
    int card[100] = {0};
    cin >> n;
    while (n--) {
        cin >> m;
        index = 0;
        count = 0;
        for (int i = 1; i <= m; i++) {
			while (count != i)
			{
				index++;				
				if (index > m) index = 1;
				if (card[index] == 0)
				{
					count++;
				}
			}
			card[index] = i;
			count = 0;
        }
        for (int i = 1; i <= m; i++) cout << card[i] << " ";
        for (int i = 1; i <= m; i++) card[i] = 0;
        cout << endl;
    }
    return 0;
}                                 
