#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, n, p;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> p;
		bool found=false;

		vector<int> bars;
		int tmp;
		int p2 = 1<<p, t, sum, j;
		while(p--)
		{
			cin >> tmp;
			bars.push_back(tmp);
		}

		for(int i=0; i<p2 && !found; i++)
		{
			t = i;
			sum=0;
			j=0;
			while(t)
			{
				if(t&1)
				{
					sum += bars[j];
				}
				j++;
				t = t>>1;
			}
			if(sum==n)
				found = true;
		}
		if(found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
