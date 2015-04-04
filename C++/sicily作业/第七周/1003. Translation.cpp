#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string>m;
	string str1, str2;
	while (getline(cin, str1, '\n'))
	{
		if(str1.length()==0) break;
		string str3 = str1.substr(0, str1.find(" "));
		string str4 = str1.substr(str1.find(" ") + 1, str1.length());
		m[str4] = str3;
	}
	while (cin >> str2)
	{
		if (m[str2] == "") cout << "eh" << endl;
		else cout << m[str2] << endl;
	}
	return 0;
}
