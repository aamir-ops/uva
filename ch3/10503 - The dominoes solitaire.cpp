#include<iostream>
#include<bitset>

using namespace std;

typedef pair<int, int> ii;

ii initial, dest, space[15], domino[15];
int n, m;
bitset<15> used;
bool found;

bool check(int i)
{
	if(i==0 && space[i].first != initial.second)
		return false;
	if(i==n-1 && space[i].second != dest.first)
		return false;
	if(i==0)
		return true;
	if(space[i].first != space[i-1].second)
		return false;
	return true;
}
void backtrack(int i)
{
	if(i==n || found)
	{
		found = true;
		return;
	}
	for(int j=0; j<m && !found; j++)
	{
		if(used[j])
			continue;
		used.set(j);
		space[i] = domino[j];
		if(check(i) && !found)
			backtrack(i+1);
		space[i].first = domino[j].second;
		space[i].second = domino[j].first;
		if(check(i) && !found)
			backtrack(i+1);
		used.reset(j);
	}
}

int main()
{
	int tmp1, tmp2;
	cin >> n;
	if(n==0)
		return 0;
	while(true)
	{
		cin >> m;
		cin >> initial.first >> initial.second;
		cin >> dest.first >> dest.second;
		for(int i=0; i<m; i++)
			cin >> domino[i].first >> domino[i].second;
		found = false;
		backtrack(0);
		if(found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//After code
		cin >> n;
		if(n==0)
			return 0;
	}
}
