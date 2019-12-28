#include<math.h>
#include<iostream>

using namespace std;


int main()
{
	int n, curr, prev, temp, i;
	bool flagJolly;
	while(cin >> n)
	{
		bool check[n] = {false};
		cin >> curr;
		i=1;

		while(i<n)
		{
			prev = curr;
			cin >> curr;

			if(abs(prev-curr)<n)
				check[abs(prev-curr)]=true;
			else
			{
			}
			i++;

		}

		flagJolly=true;
		for(i=1;i<n;i++)
			if(!check[i])
			{
				flagJolly=false;
				break;
			}

		if(flagJolly)
			cout << "Jolly";
		else
			cout << "Not jolly";
		cout << endl;

	}

	return 0;
}


