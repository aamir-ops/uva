#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int min(queue<pair<int, int>> a, queue<pair<int, int>> b)
{
	if(a.empty())
	{
		if(b.empty())
			return -1;
		return b.front().second;
	}
	if(b.empty())
		return a.front().second;
	if(a.front().second<b.front().second)
		return a.front().second;
	return b.front().second;
}
bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{
	int c;
	int n, t, m;

	cin >> c;

	while(c--)
	{
		cin >> n >> t >> m;

		queue<pair<int, int>> left, right, ferry;

		int tmp;
		string str;
		int order = 0;
		while(m--)
		{
			order++;
			cin >> tmp >> str;
			if(str[0] == 'l')
				left.push(make_pair(order, tmp));
			else
				right.push(make_pair(order, tmp));
		}

		int time=0, cars=0;
		bool leftPos=true;

		vector<pair<int, int>> lst;

		while(!left.empty() || !right.empty())
		{
			//Unloading
			while(!ferry.empty())
			{
				lst.push_back(ferry.front());
				ferry.pop();
			}
			//Loading
			if(min(left, right) <= time)
			{
				if(leftPos)
				{
					while(ferry.size()<n && !left.empty() && left.front().second<=time)
					{
						ferry.push(make_pair(left.front().first, time));
						left.pop();
					}
					leftPos=false;
				}
				else
				{
					while(ferry.size()<n && !right.empty() && right.front().second<=time)
					{
						ferry.push(make_pair(right.front().first, time));
						right.pop();
					}
					leftPos=true;
				}
				time+=t;
			}
			else 			//Waiting
			{
				time = min(left, right);
			}
		}
		while(!ferry.empty())
		{
			lst.push_back(make_pair(ferry.front().first, time-t));
			ferry.pop();
		}
		sort(lst.begin(), lst.end(), comp);
		vector<pair<int, int>>::iterator itr;
		for(itr = lst.begin(); itr!=lst.end(); itr++)
			cout<< (*itr).second+t << endl;
		if(c)
			cout << endl;
	}
	return 0;
}
