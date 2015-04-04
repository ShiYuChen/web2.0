#include <iostream>
#include "list.h"
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	list s1;
	char ch;
	int pos, in, out;
 
	cout << "-----------------------------------------------" << endl;
	cout << "                     menu                      " << endl;
	cout << "0.exit" << endl;
	cout << "1.clear" << endl;
	cout << "2.size"<< endl;
	cout << "3.empty" << endl;
	cout << "4.insert"<< endl;
	cout << "5.remove"<< endl;
	cout << "6.retrieve"<< endl;
	cout << "7.replace"<< endl;
	cout << "-----------------------------------------------" << endl;
	cout << "~$:";
	while (cin >> ch)
	{
		if (!strchr("0123456789", ch)) cout << "Please input again." << endl;
		else
		{
			switch (ch)
			{
				case '0':
					exit(1);
				case '1':
					s1.clear();
					s1.display();
					break;
				case '2':
					cout << "The size is " << s1.size() << endl;
					s1.display();
					break;
				case '3':
					if (s1.empty()) cout << "The list is empty." << endl;
					else cout << "The list is not empty." << endl; 
					s1.display();
					break;
				case '4':
					cout << "please input the position and the number:";
					cin >> pos >> in;
					s1.insert(pos, in);
					s1.display();
					break;
				case '5':
					cout << "please input the position:";
					cin >> pos;
					s1.remove(pos, out);
					s1.display();
					break;
				case '6':
					cout << "please input the position:";
					cin >> pos;
					s1.retrieve(pos, out);
					cout << "The entry[" << pos << "] is " << out << endl;
					s1.display();
					break;
				case '7':
					cout << "please input the position and the number:";
					cin >> pos >> in;
					s1.replace(pos, in);
					s1.display();
					break;
			}
		}
	
	cout << "-----------------------------------------------" << endl;
	cout << "                     menu                      " << endl;
	cout << "0.exit" << endl;
	cout << "1.clear" << endl;
	cout << "2.size"<< endl;
	cout << "3.empty" << endl;
	cout << "4.insert"<< endl;
	cout << "5.remove"<< endl;
	cout << "6.retrieve"<< endl;
	cout << "7.replace"<< endl;
	cout << "-----------------------------------------------" << endl;
	cout << "~$:";
	}
 
	return 0;
}
