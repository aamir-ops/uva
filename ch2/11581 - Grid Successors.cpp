#include<iostream>

using namespace std;

int grid[3][3];
int grid2[3][3];
void printGrid()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout << grid[i][j] << "\t" ;
		cout << endl;
	}
}
bool isEnd()
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(grid[i][j] != 0)
				return false;
	return true;
}
int modul(int i, int j)
{
	int sum=0;
	if(i-1>=0)
		sum+=grid[i-1][j];
	if(i+1<3)
		sum+=grid[i+1][j];
	if(j-1>=0)
		sum+=grid[i][j-1];
	if(j+1<3)
		sum+=grid[i][j+1];
	return sum%2;
}

void f()
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			grid2[i][j] = modul(i, j);

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			grid[i][j] = grid2[i][j];
}

int k()
{
	int a = -1;
	while(!isEnd())
	{
		a++;
		f();
	}
	return a;
}

void takeInput()
{
	for(int i=0; i<3; i++)
	{
		int a;
		cin >> a;
		for(int j=2; j>=0; j--)
		{
			grid[i][j] = a%10;
			a/=10;
		}
	}
}


int main()
{
	int T;
	cin >> T;
	while(T--)
	{

		takeInput();
		cout << k() << endl;
	}
	return 0;
}
