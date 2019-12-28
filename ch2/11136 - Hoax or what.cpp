#include<iostream>
#include<climits>
#include<set>

using namespace std;

int main()
{
	int n, k, tmp;
	long int cost;
	while(true)
	{
		cin >> n;
		if(n==0)
			return 0;
		cost=0;
		multiset<int, greater<int>> urn;
		multiset<int, greater<int>>::iterator itr;
		while(n--)
		{
			cin >> k;
			while(k--)
			{
				cin >> tmp;
				urn.insert(tmp);
			}
			itr = urn.end();
			itr--;
			cost += *(urn.begin()) - *(itr);
			urn.erase(urn.begin());
			urn.erase(itr);
		}
		cout << cost << endl;
	}
}
