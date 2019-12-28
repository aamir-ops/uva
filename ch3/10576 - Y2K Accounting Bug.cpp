#include<iostream>
#include<sstream>
#include<bitset>

using namespace std;

long long int sum, maxt, s, d;
int month[12];
bool surplus;

int suma(int i, int j)
{
	long long int sumc = 0;
	for(int k=i; k<=j; k++)
	{
		if(month[k] == 1)
			sumc += s;
		else if(month[k] == 2)
			sumc -= d;
	}
	return sumc;
}

void backtrack(int i)
{
	if(i==12)
	{
		if(suma(7, 11) < 0 && maxt<suma(0, 11))
		{
			maxt = suma(0, 11);
			surplus = true;
		}
		return;
	}
	if(i<4 || suma(i-4, i-1) + s <0)
	{
		month[i] = 1;
		backtrack(i+1);
		month[i] = 0;
	}
	else if(i>=4 && suma(i-4, i-1) - d > 0)
		return;
	month[i] = 2;
	backtrack(i+1);
	month[i] = 0;
}

int main()
{
	string str;
	stringstream ss;
	while(true)
	{
		getline(cin, str);
		if(str.length() == 0)
			return 0;
		ss.clear();
		ss << str;
		ss >> s >> d;
		sum = 0;
		surplus = false;
		maxt = 0;
		for(int i=0; i<12; i++)
			month[i] = 0;
		backtrack(0);
		if(surplus)
			cout << maxt << endl;
		else
			cout << "Deficit" << endl;
	}
}
