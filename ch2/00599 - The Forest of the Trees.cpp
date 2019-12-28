#include<iostream>
#include<bitset>
#include<sstream>

using namespace std;

int main()
{
	int n;
	string str;
	getline(cin, str);
	stringstream sst;
	
	sst << str;
	sst >> n;

	while(n--)
	{
		int v, e=0;
		bitset<26> nacorn;

		while(true)
		{
			getline(cin, str);
			if(str[0] == '*')
				break;
			nacorn.set(str[1]-'A');
			nacorn.set(str[3]-'A');
			e++;
		}
		getline(cin, str);
		
		int comma=0;

		for(int i=0; i<str.length(); i++)
			if(str[i]==',')
				comma++;
		v = comma+1;

		cout << "There are " << nacorn.count()-e << " tree(s) and " << v-nacorn.count() << " acorn(s)." << endl;
	}
	return 0;
}
