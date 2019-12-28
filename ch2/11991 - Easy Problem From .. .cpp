#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

int main()
{
	int n, m, tmp2;
	while(cin >> n)
	{
		cin >> m;

		vector<vi> pos;

		pos.assign(1000001, vi());

		int order = 1, tmp;

		while(n--)
		{
			cin >> tmp;
			pos[tmp].push_back(order);
			order++;
		}

		while(m--)
		{
			cin >> tmp >> tmp2;

			if(pos[tmp2].size() >=tmp)
				cout << pos[tmp2][tmp-1] << endl;
			else
				cout << "0" << endl;
		}
	}
	return 0;
}
