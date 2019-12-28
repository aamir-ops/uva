#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int f, r, tmp;
	while(true)
	{
		cin >> f;
		if(f==0)
			return 0;

		cin >> r;

		vector<float> front;
		vector<int> rear;

		while(f--)
		{
			cin >> tmp;
			front.push_back(tmp);
		}
		while(r--)
		{
			cin >> tmp;
			rear.push_back(tmp);
		}

		vector<float> dr;

		for(int i=0; i<front.size(); i++)
		{
			for(int j=0; j<rear.size(); j++)
			{
//				cout << rear[j]/front[i] << endl;
				dr.push_back(rear[j]/front[i]);
			}
		}
		sort(dr.begin(), dr.end());

		float maxS = dr[1]/dr[0];

		for(int i=2; i<dr.size(); i++)
		{
			if(maxS < dr[i] / dr[i-1])
				maxS = (dr[i] / dr[i-1]);
		}

		printf("%.2f\n", maxS);
	}
}
