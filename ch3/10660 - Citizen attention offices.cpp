#include<iostream>
#include<vector>
#include<climits>
#include<utility>

using namespace std;

int min2(int a, int b)
{
	return (a<b) ? a : b;
}
int dist(int x1, int y1, int x, int y, int w)
{
	return (abs(x1-x) + abs(y1-y))*w;
}
bool find(int arr[], int n)
{
	for(int i=0; i<5; i++)
		if(arr[i] == n)
			return true;
	return false;
}
int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;

		int pop[5][5];
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
				pop[i][j] = 0;
		}

		int posx, posy, tmp;
		while(n--)
		{
			cin >> posx >> posy >> tmp;
			pop[posx][posy] = tmp;
		}
		int i, j, k, l, m,min=INT_MAX,sum, di, dj, dk, dm, dl;
		int mini[5]={25,26,27,28,29};

		for(i=0; i<25; i++)
		{
			for(j=i+1; j<25; j++)
			{
				for(k=j+1; k<25; k++)
				{
					for(l=k+1; l<25; l++)
					{
						for(m=l+1; m<25; m++)
						{
							sum=0;
							for(n=0; n<25; n++)
							{
								di=dist(n/5, n%5, i/5, i%5, pop[n/5][n%5]);
								dj=dist(n/5, n%5, j/5, j%5, pop[n/5][n%5]);
								dk=dist(n/5, n%5, k/5, k%5, pop[n/5][n%5]);
								dl=dist(n/5, n%5, l/5, l%5, pop[n/5][n%5]);
								dm=dist(n/5, n%5, m/5, m%5, pop[n/5][n%5]);
								sum += min2(di, min2(dj, min2(dk, min2(dl, dm))));
							}
							if(min>sum)
							{
								min=sum;
								mini[0] = i;
								mini[1] = j;
								mini[2] = k;
								mini[3] = l;
								mini[4] = m;
							}
						}
					}
				}
			}
		}

		for(i=0; i<5; i++)
		{
			cout << mini[i];
			if(i!=4)
				cout << " ";
		}
		cout << endl;
	}
}
