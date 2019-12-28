#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<string, pair<int, int>> pdb;

bool comp(pdb a, pdb b)
{
	if(a.second.first != b.second.first)
		return (a.second.first < b.second.first);
	if(a.second.second != b.second.second)
		return (a.second.second < b.second.second);
	return a.first < b.first;
}

int bs(vector<pdb> &db, int price, int found, int l, int r)
{
	int m = (l+r)/2;
	if(db[m].second.first <= price && db[m].second.second >= price)
	{
		if(found == 0)
			found++;
		else	return 0;
	}
	return 0;
}

void search(vector<pdb> &db, int price)
{
	bool found = false;
	int pos = -1;
	for(int i=0; i<db.size(); i++)
	{
		if(price >= db[i].second.first && price <= db[i].second.second)
		{
			if(found)
			{
				cout << "UNDETERMINED" << endl;
				return;
			}
			else
			{
				pos = i;
				found = true;
			}
		}
	}
	found?cout << db[pos].first:cout << "UNDETERMINED";
	cout << endl;
}

int main()
{
	int t, d, q, p, m, l, h;
	string name;

	cin >> t;
	while(t--)
	{
		vector<pair<string,pair<int, int>>> db;
		cin >> d;
		while(d--)
		{
			cin >> name >> l >> h;
			db.push_back(make_pair(name, make_pair(l, h)));
		}
//		sort(db.begin(), db.end(), comp);
		cin >> q;

		while(q--)
		{
			cin >> p;
			search(db, p);
			
		}
		if(t)
			cout << endl;
	}
	return 0;
}
