#include<iostream>
#include<queue>

using namespace std;

int main()
{
	while(true)
	{
		int n, in;
		long int cost=0, tfirst, tsecond;

		priority_queue<int> pq;
		cin >> n;
		if(n==0)
			return 0;
		while(n--)
		{
			cin >> in;
			pq.push((-1)*in);
		}
		while(pq.size()>1)
		{
			tfirst = pq.top()*(-1);
			pq.pop();
			tsecond = pq.top()*(-1);
			pq.pop();
			cost += tfirst+tsecond;
			pq.push((-1)*(tfirst+tsecond));
		}
		cout << cost << endl;
	}
}
