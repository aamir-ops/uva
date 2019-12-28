Accepted Output#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, pair<int, int>> pi;

bool cmp(pi a, pi b)
{
	if(a.first != b.first)
		return a.first < b.first;
	if(a.second.first != b.second.first)
		return a.second.first < b.second.first;
	return a.second.second < b.second.second;
}

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int i, j, k, sum=0, min, tmp, row=0, col=0;

		vector<pi> grid;

		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				cin >> tmp;
				grid.push_back(make_pair(tmp, make_pair(i, j)));
			}
		sort(grid.begin(), grid.end(), cmp);
		for(i=0; i<grid.size(); i++)
		{
			if((row & 1<<grid[i].second.first) || (col & 1<<grid[i].second.second))
				continue;
			sum += grid[i].first;
			row |= 1<<grid[i].second.first;
			col |= 1<<grid[i].second.second;
		}
		cout << sum << endl;
	}
	return 0;
}
