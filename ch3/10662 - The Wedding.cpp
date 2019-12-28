#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int t, r, h;
	while(cin >> t)
	{
		cin >> r >> h;
		int T[t], R[r], H[h];
		int TR[t][r], RH[r][h], HT[h][t];

		int tmp, i, j, k;

		for(i=0; i<t; i++)
		{
			cin >> T[i];
			for(j=0; j<r; j++)
				cin >> TR[i][j];
		}
		for(i=0; i<r; i++)
		{
			cin >> R[i];
			for(j=0; j<h; j++)
				cin >> RH[i][j];
		}
		for(i=0; i<h; i++)
		{
			cin >> H[i];
			for(j=0; j<t; j++)
				cin >> HT[i][j];
		}

		bool flag = false;
		int minPrice = INT_MAX, mint, minr, minh;
		for(i=0; i<t; i++)
		{
			for(j=0; j<r; j++)
			{
				for(k=0; k<h; k++)
				{
					if(TR[i][j] || RH[j][k] || HT[k][i])
						continue;
					flag = true;
					if(minPrice > T[i]+R[j]+H[k])
					{
						minPrice = T[i]+R[j]+H[k];
						mint = i;
						minr= j;
						minh = k;
					}
				}
			}
		}
		if(!flag)
			cout << "Don't get married!" << endl;
		else
			cout << mint << " " << minr << " " << minh << ":" << minPrice << endl;
	}
}
