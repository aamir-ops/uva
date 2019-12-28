#include<iostream>
#include<queue>
#include<stack>
#include<bitset>

using namespace std;

int main()
{
	int SET;
	cin >> SET;
	int N, S, Q;

	while(SET--)
	{
		cin >> N >> S >> Q;

		int tN=N;

		queue<int> cntry[N+1];
		stack<int> snitch;
		bitset<101> bs;
				
		int j, i=1;
		int tmp;

		while(tN--)
		{
			cin >> j;
			while(j--)
			{
				cin >> tmp;
				cntry[i].push(tmp);
				bs.set(i);
			}
			i++;
		}
		i=0;
		int c=0;
		
		while(true)
		{
			i = (i%N) +1;
			
//			cout << endl << "At station " << i << ":" << endl;

			//Unloading
			while(!snitch.empty() && (cntry[i].size()<Q || snitch.top()==i))
			{
				tmp = snitch.top();
				snitch.pop();
				if(tmp != i)
					cntry[i].push(tmp);
				c++;
//				cout << "Unloading " << tmp << endl;
			}
			while(snitch.size()<S && !cntry[i].empty())
			{
				tmp = cntry[i].front();
				cntry[i].pop();
				snitch.push(tmp);
				c++;
//				cout << "Loading " << tmp << endl;
			}
				
			if(cntry[i].empty())
				bs.reset(i);
			else
				bs.set(i);
			if(bs.count()==0 && snitch.empty())
				break;
			c+=2;
		}
		
		cout << c << endl;
	}
}
