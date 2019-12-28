#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int n, m;
	while(true)
	{
		cin >> n >> m;

		if(n==0 && m==0)
			return 0;

		bitset<1000000> bset;

		bool conflict=false;
		int start, end, repeat;
		while(n--)
		{
			cin >> start >> end;
			if(conflict)
				continue;

			for(int i=start; i<end; i++)
			{
				if(!bset[i])
					bset.set(i);
				else
				{
					conflict = true;
					break;
				}
			}
		}

		while(m--)
		{
			cin >> start >> end >> repeat;
			if(conflict)
				continue;
			int i=start;
			while(true)
			{
				if(i>=1000000 || conflict)
					break;
				while(i<end)
				{
					if(!bset[i])
						bset.set(i);
					else
					{
						conflict = true;
						break;
					}
					i++;
				}
				start += repeat;
				end += repeat;
				i = start;
			}
		}

		if(conflict)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;
	}
}


