#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
bool abc(int *a, int *b)
{
	sort(a, b);
	return true;
}
int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int i, j, k, l, sum=0, tmp, grid[n][n], minwin=INT_MAX, maxlose=INT_MAX, bobm, alicem;
		bool bobw= false;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin >> grid[i][j];

		int permb[n], perma[n];

		for(i=0; i<n; i++)
			permb[i] = perma[i] = i;

		sort(perma, perma+n);
		sort(permb, permb+n);

		for(i=0; i<n; i++)
		{
//			cout << permb[i];
//			for(j=0; j<n; j++)
//				cout << grid[i][j] << "\t";
//			cout << endl;
		}
//		cout << endl;

//		cout << maxlose;
//		cout << "input done." << endl;
		do
		{
				sum=0;
				bobm=alicem=0;
				for(i=0; i<n; i++)
				{
		//			alicem |= 1<<perma[i];
		//			bobm |= 1<<permb[i];
					sum+=grid[perma[i]][permb[i]];
				}
//				cout << bobm << "\t" << alicem << endl;
		//		if(bobm != (1<<n)-1 || alicem != (1<<n)-1)
		//			continue;
				if(sum>0 && minwin > sum)
					minwin = sum;
				else if(sum<=0 && maxlose>sum)
				{
					bobw = true;
					maxlose = sum;
				}
//				cout << "sum is " << sum << endl;
		}while(next_permutation(permb, permb+n));
		if(!bobw)
		{
//			cout << "alice wins." << endl;
			cout << minwin << endl;
		}
		else
			cout << maxlose << endl;
	}
}
