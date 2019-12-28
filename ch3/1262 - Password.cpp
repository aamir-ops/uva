#include<iostream>
#include<algorithm>

using namespace std;

char grid1[6][5], grid2[6][5], soln[5];
int k, solcount;
bool found;

void backtrack(int i1, int i2, int j)
{
	if(j==5)
	{
		solcount++;
		if(solcount==k)
		{
			found = true;
		}
		return;
	}
	if(i1 > 5 || i2 > 5)
		return;

	if(grid1[i1][j] == grid2[i2][j] && !found)
	{
		soln[j] = i1;
		backtrack(0, 0, j+1);
		int tmp = grid1[i1][j];
		while(tmp == grid1[i1][j])
			i1++;
		while(tmp == grid2[i2][j])
			i2++;
		backtrack(i1, i2, j);
	}
	else if(!found && grid1[i1][j] < grid2[i2][j])
	{
		backtrack(i1+1, i2, j);
	}
	else if(!found)
	backtrack(i1, i2+1, j);
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> k;
		for(int i=0; i<6; i++)
			for(int j=0; j<5; j++)
				cin >> grid1[i][j];
		for(int i=0; i<6; i++)
			for(int j=0; j<5; j++)
				cin >> grid2[i][j];
		char arr[6];
		for(int j=0; j<5; j++)
		{
			for(int i=0; i<6; i++)
				arr[i] = grid1[i][j];
			sort(arr, arr+6);
			for(int i=0; i<6; i++)
				grid1[i][j] = arr[i];
		}
		for(int j=0; j<5; j++)
		{
			for(int i=0; i<6; i++)
				arr[i] = grid2[i][j];
			sort(arr, arr+6);
			for(int i=0; i<6; i++)
				grid2[i][j] = arr[i];
		}
		solcount = 0;
		found = false;
	
		backtrack(0, 0, 0);
	
		if(found)
		{
			for(int i=0; i<5; i++)
				cout << grid1[soln[i]][i];
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
}
