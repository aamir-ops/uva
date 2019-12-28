#include<iostream>
#include<queue>

using namespace std;

int main()
{
	string str;
	pair<long int,pair<int, int>> tmp;
	int q, p, k;

	priority_queue<pair<long int,pair<int, int>>> que;
	priority_queue<int> qnum;
	long int curr;
	while(true)
	{
		cin >> str;
		if(str[0] == '#')
			break;
		cin >> q >> p;
		que.push(make_pair((-1)*p, make_pair(p, q)));
	}
	cin >> k;

	while(k)
	{
		curr = que.top().first;
		while(curr == que.top().first)
		{
			tmp = que.top();
			qnum.push((-1)*tmp.second.second);
			que.pop();
			tmp.first -= tmp.second.first;
			que.push(tmp);
		}
		while(!qnum.empty())
		{
			k--;
			cout << qnum.top()*(-1) << endl;
			qnum.pop();
			if(k==0)
				break;
		}
	}
	return 0;
}
