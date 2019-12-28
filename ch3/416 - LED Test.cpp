#include<iostream>
#include<bitset>
#include<map>

using namespace std;

bitset<7> table[10], input[10], arr[10], soln;
int n, faulty[7];
bool match, match2;
map<int, int> tab;

int give_n(int i)
{
	for(int j=0; j<10; j++)
		if(table[j] == arr[i])
			return j;
	return -1;
}
bool check(int i)
{
	int m = give_n(i);
	if(m == -1)
		return false;
	if(i==0)
		return true;
	if(give_n(i-1) != m+1)
		return false;
	return true;
}
void backtrack2(int i, int j, bool &match2)
{
	if(j==7 || match2)
	{
		if(check(i))
		{
			soln = arr[i];
			match2=true;
		}
		return;
	}
	if(faulty[j])
	{
		arr[i].set(j);
		backtrack2(i, j+1, match2);
		arr[i].reset(j);
	}
	backtrack2(i, j+1, match2);
}

void backtrack(int i, int j)
{
	if(i==n || match)
	{
		match = true;
		return;
	}
	if(j==7)
		return;
	if(j==0)
		arr[i] = input[i];
	if(faulty[j]<=i)
	{
		arr[i].set(j);
		if(check(i))
			backtrack(i+1, 0);
		backtrack(i, j+1);
		arr[i].reset(j);
	}
	if(check(i))
		backtrack(i+1, 0);
	backtrack(i, j+1);
	/*
	for(int j=0; j<7 && !match; j++)
	{
		if(faulty[j])
		{
			arr[i].set(j);
			if(check(i))
				backtrack(i+1);
			arr[i].reset(j);
		}
		if(check(i))
			backtrack(i+1);
	}*/
}

void find_faulty()
{
	for(int j=0; j<7; j++)
		faulty[j] = n;
	for(int i=n-1; i>=0; i--)
		for(int j=0; j<7; j++)
			if(!input[i][j] && faulty[j] == i+1)
				faulty[j] = i;
}


void set_table()
{
	table[0] = 126;
	table[1] = 48;
	table[2] = 109;
	table[3] = 121;
	table[4] = 51;
	table[5] = 91;
	table[6] = 95;
	table[7] = 112;
	table[8] = 127;
	table[9] = 123;
	tab.insert(make_pair(126, 0));	tab.insert(make_pair(48, 1));	tab.insert(make_pair(109, 2));
	tab.insert(make_pair(121, 3));	tab.insert(make_pair(51, 4));	tab.insert(make_pair(91, 5));
	tab.insert(make_pair(95, 6));	tab.insert(make_pair(112, 7));	tab.insert(make_pair(127, 8));
	tab.insert(make_pair(123, 9));
}
void take_input()
{
	string str;
	for(int i=0; i<n; i++)
	{
		cin >> str;
		input[i] = 0;
		for(int j=0; j<str.length(); j++)
		{
			if(str[j] == 'Y')
				input[i].set(6-j);
		}
	}
}

int main()
{
	set_table();
	while(true)
	{
		cin >> n;
		if(n==0)
			return 0;
		take_input();
		find_faulty();
		match = false;
		backtrack(0, 0);
		if(match)
			cout << "MATCH" << endl;
		else
			cout << "MISMATCH" << endl;
	}
}
