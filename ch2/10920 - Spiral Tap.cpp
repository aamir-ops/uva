#include<iostream>

using namespace std;

int n, curr;
pair<int, int> cord;
void printCord()
{
	cout << "Line = " << cord.first << ", column = " << cord.second << ".\n";
}

int stepS;

void up();
void left();
void down();
void right();

void up()
{
	if(n-curr>stepS)
	{
		curr+=stepS;
		cord.first+=stepS;
		left();
	}
	else
		cord.first += n-curr;
}

void left()
{
	if(n-curr>stepS)
	{
		curr+=stepS;
		cord.second -= stepS;
		stepS++;
		down();
	}
	else
		cord.second -= n-curr;
}

void down()
{
	if(n-curr>stepS)
	{
		curr+=stepS;
		cord.first -= stepS;
		right();
	}
	else
		cord.first -= n-curr;
}

void right()
{
	if(n-curr>stepS)
	{
		curr+=stepS;
		cord.second += stepS;
		stepS++;
		up();
	}
	else
		cord.second += n-curr;
}



int main()
{
	int SZ, P;

	while(true)
	{
		cin >> SZ >> P;

		if(SZ==0 && P==0)
			return 0;

		cord.first = cord.second = (SZ+1)/2;

		curr = 1;
		n = P;
		stepS=1;
		up();

		printCord();
	}
}


