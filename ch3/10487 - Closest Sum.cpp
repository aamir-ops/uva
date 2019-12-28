#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int casen=0, n, q, tmp, f, l, mind;
	while(true)
	{
		vector<int> num;
		cin >> n;
		if(n==0)
			return 0;
		cout << "Case " << ++casen << ":" << endl;
		while(n--)
		{
			cin >> tmp;
			num.push_back(tmp);
		}
		sort(num.begin(), num.end());
		cin >> q;
		while(q--)
		{
			cin >> tmp;
			f=0;
			l=0;
			mind=INT_MAX;
			int minS;
			for(l=1; l<num.size(); l++)
			{
				for(f=0; f<l; f++)
				{
					if(mind > abs(num[f]+num[l] - tmp))
					{
						mind = abs(num[f]+num[l] - tmp);
						minS = num[f]+num[l];
					}
				}
			}
			cout << "Closest sum to " << tmp << " is " << minS <<"." << endl;
		}
	}
}
