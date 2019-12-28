#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

long int poly(vector<int> &coef, int n)
{
	long int sum=0;
	int i;
	long int tn = 1;

	for(i=0; i<coef.size(); i++)
	{
		sum += tn * coef[i];
		tn *= n;
	}
	return sum;
}

int main()
{
	int tc, i, tmp, d, k;
	
	cin >> tc;
	while(tc--)
	{
		vector<int> coef;

		cin >> i;
		i++;
		while(i--)
		{
			cin >> tmp;
			coef.push_back(tmp);
		}

		cin >> d;
		cin >> k;

		int td=d;

		i=1;
		while(k>td)
		{
			k-=td;
			td+=d;
			i++;
		}
		cout << poly(coef, i) << endl;
	}
}
