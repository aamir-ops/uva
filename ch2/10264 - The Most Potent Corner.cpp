#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		int M = pow(2, N);
		int weight[M], potency[M];

		int i, j, sum;

		for(i=0; i<M; i++)
			cin >> weight[i];

		for(i=0; i<M; i++)
		{
			sum = 0;
			j = 1;
			while(j<M)
			{
				sum += weight[i ^ j];
				j = j << 1;
			}
			potency[i] = sum;
		}


		int max = 0;

		for(i=0; i<M; i++)
		{
			j=1;
			while(j<M)
			{
				if(max < potency[i ^ j] + potency[i])
					max = potency[i ^ j] + potency[i];
				j = j << 1;
			}
		}
		cout << max << endl;
	}
	return 0;
}
