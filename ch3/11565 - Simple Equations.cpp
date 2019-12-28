#include<iostream>
#include<math.h>

using namespace std;

int min(int a, int b)
{
	return (a<b) ? a : b;
}
int main()
{
	int n, a, b, c, x, y, z, mini, x2, y2, z2;
	bool flag;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		x2=0;
		flag = false;
		for(x=(-1)*sqrt(c); x2<=c && !flag; x++)
		{
			x2 = x*x;
			for(y=x+1, y2=y*y; x2+y2<=c && !flag; y++)
			{
				y2=y*y;
				for(z=y+1, z2=z*z; x2+y2+z2<=c && !flag; z++)
				{
					z2=z*z;
					if(x+y+z==a && x*y*z==b && x2+y2+z2==c)
					{
						flag = true;
						cout << x << " " << y << " " << z << endl;
					}
				}
			}
		}
		if(!flag)
			cout << "No solution." << endl;
	}
	return 0;
}
