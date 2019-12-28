#include<iostream>
#include<bitset>

using namespace std;

int arr[12], sum, t, n, l, j;
bitset<12> used;
bool found;

void printsol()
{
	int count = used.count();
	for(int i=0; i<12; i++)
		if(used[i])
		{
			count--;
			cout << arr[i];
			if(count)
				cout << "+";
		}
	cout << endl;
}

void backtrack(int i)
{
	if(i>=n)
		return;
	j=i;
	if(sum + arr[i] == t)
	{
		used.set(i);
		printsol();
		used.reset(i);
		found = true;
	}
	else if(sum + arr[i] < t)
	{
		used.set(i);
		sum += arr[i];
		backtrack(i+1);
		sum -= arr[i];
		used.reset(i);
	}
	j=i;
	l = arr[i];
	while(j<n && l== arr[j])
		j++;
	backtrack(j);
}

int main()
{
	while(true)
	{
		cin >> t >> n;
		if(n==0)
			return 0;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sum = 0;
		used = 0;
		found = false;
		cout << "Sums of " << t << ":" << endl;
		backtrack(0);
		if(!found)
			cout << "NONE" << endl;
	}
}
