#include<iostream>
#include<sstream>
#include<bitset>

using namespace std;

int n, arr[20];
bitset<40> numb, prime;

void initprime()
{
	int i, j;
	bool flag;
	for(j=2; j<40; j++)
	{
		flag = false;
		for(i=2; i<j && !flag; i++)
			if(j%i==0)
				flag = true;
		if(!flag)
			prime.set(j);
	}
}

bool check(int i)
{
	if(!numb[arr[i]] && (i!=n || prime[1+arr[i]]) && prime[arr[i]+arr[i-1]])
		return true;
	return false;
}

void backtrack(int i)
{
	if(i==n+1)
	{
		for(int j=1; j<=n; j++)
		{
			cout << arr[j];
			if(j!=n)
				cout <<" ";
		}
		cout << endl;
		return;
	}
	for(int j=2; j<=n; j++)
	{
		arr[i] = j;
		if(check(i))
		{
			numb.set(arr[i]);
			backtrack(i+1);
			numb.reset(arr[i]);
		}
	}
}

int main()
{
	int casen=0;
	string str;
	stringstream ss;
	getline(cin, str);
	ss.clear();
	ss << str;
	ss >> n;
	while(true)
	{
		arr[1] = 1;
		numb.set(1);
		initprime();
		cout << "Case " << ++casen << ":" << endl;
		if(!(n&1))
			backtrack(2);
		getline(cin, str);
		if(str.length()==0)
			return 0;
		ss.clear();
		ss << str;
		ss >> n;
		cout << endl;
	}
}
