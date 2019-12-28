#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

vector<vector<int>> adjList;
bitset<102> black, soln;
int n;

bool check(int i)	//Node Passed to it.
{
	for(int j=0; j<adjList[i].size(); j++)
		if(black[adjList[i][j]])
			return false;
	return true;
}

void backtrack(int i)
{
	if(i==n+1)
	{
		if(black.count() >= soln.count())
			soln = black;
		return;
	}
	if(check(i))
	{
		black.set(i);
		backtrack(i+1);
		black.reset(i);
	}
	backtrack(i+1);
}

void get_graph()
{
	int k, tmp1, tmp2;
	cin >> n;
	cin >> k;
	adjList.assign((n+1), vector<int>());
	while(k--)
	{
		cin >> tmp1 >> tmp2;
		adjList[tmp1].push_back(tmp2);
		adjList[tmp2].push_back(tmp1);
	}
}

void free_graph()
{
	for(int i=0; i<adjList.size(); i++)
		adjList[i].clear();
	adjList.clear();
}

void print_soln()
{
	cout << soln.count() << endl;
	int count = soln.count();
	for(int i=0; i<102; i++)
	{
		if(soln[i])
		{
			cout << i;
			if(--count)
				cout << " ";
		}
	}
	cout << endl;
}

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		get_graph();
		black = soln = 0;
		backtrack(1);
		print_soln();
		free_graph();
	}
	return 0;
}
