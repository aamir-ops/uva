#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int nc[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			nc[i][j]=0;

	int tmp, tmp2, t;
	while(m--)
	{
		cin >> tmp >> tmp2;
		nc[tmp-1][tmp2-1] = 1;
		nc[tmp2-1][tmp-1] = 1;
	}

	int n2=1<<n;
	int count=0, curp;
	bool flag;
	for(int i=0; i<n2; i++)
	{
		t=i;
		curp=0;
		vector<int> pos;
		flag = false;
		while(t)
		{
			if(t&1)
				pos.push_back(curp);
			curp++;
			t=t>>1;
		}
		for(int j=0; j<pos.size() && !flag; j++)
		{
			for(int k=j+1; k<pos.size() && !flag; k++)
			{
				if(nc[pos[j]][pos[k]])
				{
					flag = true;
					break;
				}
			}
		}
		if(flag)
			continue;
		count++;
	}
	cout << count;
}
