#include<iostream>

using namespace std;

float round(float var)
{
	return (float)((int)(var*100 + 0.5))/100;
}

int main()
{
	long long a, b, c, d;
	for(a=1; a<2000; a++)
	{
		if(a*a*a*a > 2000000000)
			break;
		for(b=a; b<2000-a; b++)
		{
			if(a*b*b*b > 2000000000)
				break;
			for(c=b; c<2000-b-a; c++)
			{
				if(a*b*c*c > 2000000000)
					break;
				long long p=a*b*c, k=1000000;
				if(p==k)
					continue;
				if(k*((a+b+c))%(p-k) != 0)
					continue;
				d=(k*(a+b+c))/(p-k);
				if(c>d || a+b+c+d>2000 || a*b*c*d>2000000000)
					continue;
				cout << a/100.0 << " " << b/100.0 << " " << c/100.0 << " " << d/100.0 << endl;
			}
		}
	}
}
