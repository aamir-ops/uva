#include<iostream>

using namespace std;

int main()
{
	string str, str2;
	cin >> str >> str2;
	
	for(int i=0; i<str.length(); i++)
		if(str[i] != str2[i])
		{
			cout << i + 1 << endl;
			cout << str[i] << endl << str2[i] << endl;
		}
}
