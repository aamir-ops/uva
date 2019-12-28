#include<iostream>
#include<set>

using namespace std;

int main()
{
	int n, m, count;
	long int in;
	while(true)
	{
		cin >> n >> m;
		if(n==0 && m==0)
			return 0;

		set<long int> catalog;
		set<long int>::iterator itr;

		count = 0;
		while(n--)
		{
			cin >> in;
			catalog.insert(in);
		}

		while(m--)
		{
			cin >> in;
			itr = catalog.find(in);
			if(itr != catalog.end())
				count++;
		}
		cout << count << endl;
	}
}
