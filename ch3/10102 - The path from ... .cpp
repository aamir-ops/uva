#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m;
	while(cin >> m)
	{
		int i, j;
		vector<pair<int, int>> pos1;
		vector<pair<int, int>> pos3;
		char in;

		for(i=1; i<=m; i++)
		{
			for(j=1; j<=m; j++)
			{
				cin >> in;
				if(in=='1')
					pos1.push_back(make_pair(i, j));
				else if(in=='3')
					pos3.push_back(make_pair(i, j));
			}
		}

		int mind, maxd=0, curd;
		for(i=0; i<pos1.size(); i++)
		{
			mind=3*m;
			for(j=0; j<pos3.size(); j++)
			{
				curd = abs(pos1[i].first-pos3[j].first) + abs(pos1[i].second-pos3[j].second);
				if(mind > curd)
					mind = curd;
			}
			if(maxd < mind)
				maxd = mind;
		}
		cout << maxd << endl;
	}
}
