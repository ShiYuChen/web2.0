#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str; 
	int n; 
	cin>>n;
	getline(cin, str);
	while (n--)
	{
		getline(cin, str);
		int len = str.length();		
		int flag = 1;
		stack<int> s;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '{' || str[i] == '[' || str[i] == '(')
				s.push(str[i]);
			else if (str[i] == '}')
			{
				if (s.empty() || s.top() == '[' || s.top() == '(')
				{
					flag = 0;
					break;
				}
				s.pop();
			}
			else if (str[i] == ']')
			{
				if (s.empty() || s.top() == '{' || s.top() == '(')
				{
					flag = 0;
					break;
				}
				s.pop();
			}
			else if (str[i] == ')')
			{
				if (s.empty() || s.top() == '[' || s.top() == '{')
				{
					flag = 0;
					break;
				}
				s.pop();
			}
		}
		if (flag == 0) cout << "False" << endl;
		else
		{
			if (!s.empty()) cout << "False" << endl;
			else cout << "True" << endl;
		}
	}
	return 0;
} 
