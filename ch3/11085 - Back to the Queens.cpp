#include<iostream>
using namespace std;

int drow[8], row[8], moves, mina;

bool check(int c)
{
	for(int i=0; i<c; i++)
		if(row[i] == row[c] || abs(c-i)==abs(row[c]-row[i]))
			return false;
	return true;
}

void backtrack(int i)
{
	if(i==8)
	{
		if(mina > moves)
			mina = moves;
		return;
	}
	bool flag=false;
	row[i] = drow[i];
	for(int j=0; j<8; j++)
	{
		if(check(i))
			backtrack(i+1);
		if(!flag)
		{
			flag = true;
			moves++;
		}
		row[i] = (row[i]+1)%8;
	}
	if(flag)
		moves--;
}



int main()
{
	int casen=0;
	while(cin >> drow[0])
	{
		for(int i=1; i<8; i++)
			cin >> drow[i];
		for(int i=0; i<8; i++)
			drow[i]--;
		moves = 0;
		mina = 10;
		backtrack(0);
		cout <<"Case " << ++casen << ": "<< mina << endl;
	}
}
