#include<iostream>

using namespace std;

int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(n==0)
			return 0;
		int a,b;
		a=b=0;

		int t;
		int i;
		bool first=true;
		i=0;
		while(n)
		{
			t = n%2;
			n /= 2;
			if(t)
			{
				if(first)
				{
					a += t<< i;
					first = false;
				}
				else
				{
					b += t<<i;
					first = true;
				}
			}
			i++;
		}
		cout << a << " " << b << endl;
	}
}
