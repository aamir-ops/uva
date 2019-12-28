#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int i;
	long int n;
	while(cin >> n)
	{
		int count=0;
		vector<pair<long int, long int>> sol;
		long int x, y, tmp;
		for(y=n+1; y<=2*n; y++)
		{
			if((n*y)%(y-n)==0)
			{
				sol.push_back(make_pair((n*y)/(y-n), y));
				count++;
			}
		}
		cout << count << endl;
		for(i=0; i<sol.size(); i++)
			cout << "1/" << n << " = " << "1/" << sol[i].first << " + " << "1/" << sol[i].second << endl;
	}
	return 0;
}
