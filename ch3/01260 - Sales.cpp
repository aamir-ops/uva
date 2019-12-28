#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		int tmp;
		vector<int> sales;
		cin >> n;
		while(n--)
		{
			cin >> tmp;
			sales.push_back(tmp);
		}
		int count = 0;

		for(int i=1; i<sales.size(); i++)
		{
			for(int j=i-1; j>=0; j--)
				if(sales[j]<=sales[i])
					count++;
		}

		cout << count << endl;
	}
}
