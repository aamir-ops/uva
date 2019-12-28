#include<iostream>
#include<map>

using namespace std;

int main()
{
	int T, n, max;
	cin >> T;
	while(T--)
	{
		map<long int, int> mp;
		map<long int, int>::iterator itr;

		long int in;

		cin >> n;
		int order = 0;
		max = 0;
		int maxmo=0;

		while(n--)
		{
			cin >> in;
			order++;

			itr = mp.find(in);
			if(itr != mp.end())
			{
				if(maxmo<itr->second)
					maxmo=itr->second;

				mp.erase(itr);
			}
			if(max<order-maxmo)
				max = order-maxmo;
			mp.insert(make_pair(in, order));
		}

		cout << max << endl;
	}
	return 0;
}
