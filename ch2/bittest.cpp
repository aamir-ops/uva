#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	bitset<1000000> b;
	int tc, m, t;
	char a;
	cin >> tc;
	b = 2;
	cout << b << endl;
	b = 8;
	cout << !b << endl;
	return 0;
	while(tc--)
	{
		string str;
		cin >> m;
		int i = 0;
		while(m--)
		{
			cin >> t;
			cin >> str;
			while(t--)
			{
				for(int j=0; j<str.length(); j++)
					b[i++] = str[j]-'0';
			}
		}
	}
	cout << b << endl;

	return 0;
}
