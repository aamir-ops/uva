#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int n;
	int in, inn;
	while(cin >> n)
	{
		queue<int> que;
		stack<int> st;
		priority_queue<int> pq;

		bool bque, bst, bpq;

		bque = bst = bpq = true;

		int ctrue = 3;

		while(n--)
		{
			cin >> in >> inn;
			if(in == 1)
			{
				que.push(inn);
				st.push(inn);
				pq.push(inn);
			}
			else if(in==2)
			{
				if(bque && (que.empty() ||  inn != que.front()))
				{
					bque=false;
					ctrue--;
				}
				else if(bque && !que.empty())
					que.pop();
				if(bst && (st.empty() || inn != st.top()))
				{
					bst = false;
					ctrue--;
				}
				else if(bst && !st.empty())
					st.pop();
				if(bpq && (pq.empty() ||  inn != pq.top()))
				{
					bpq = false;
					ctrue--;
				}
				else if(bpq && !pq.empty())
					pq.pop();
			}
		}

		if(ctrue > 1)
			cout << "not sure" << endl;
		else if(ctrue==0)
			cout << "impossible" << endl;
		else if(ctrue == 1)
		{
			if(bque)
				cout << "queue" << endl;
			else if(bst)
				cout << "stack" << endl;
			else if(bpq)
				cout << "priority queue" << endl;
		}
	}
	return 0;
}
