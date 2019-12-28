#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	int n, a, casen=0;
	cin >> n >> a;
	if(n==0 && a==0)
		return 0;
	while(true)
	{
		casen++;

		int n2=1<<n, t, count, j, tmp, tmp2, tmp3, m;
		long int max = 0;
		int finals[a];
		vi tower;
		for(int i=0; i<n; i++)
		{
			cin >> tmp;
			tower.push_back(tmp);
		}
		cin >> m;
		vvi overlaps;
		overlaps.assign(m, vi());
		for(int i=0; i<m; i++)
		{
			cin >> tmp;
			tmp++;
			while(tmp--)
			{
				cin >> tmp2;
				overlaps[i].push_back(tmp2-1);
			}
			overlaps[i][overlaps[i].size()-1]++;
		}
		//Input done in AdjList

		for(int i=0; i<n2; i++)
		{
			t=i;
			vi selected;
			j=0;
			while(t)
			{
				if((t&1))
					selected.push_back(j);
				j++;
				t = t>>1;
			}
			if(selected.size()!=a)
				continue;

			//Till this point we have a selection of towers of desired size.
			long int sum=0;

			for(int k=0; k<selected.size(); k++)
				sum+=tower[selected[k]];
			for(j=0; j<overlaps.size(); j++)
			{
				count = 0;
				for(int k=0; k<selected.size(); k++)
					if(binary_search(overlaps[j].begin(), overlaps[j].end()-1, selected[k]))
						count++;

				if(count>=2)
					sum -= (count-1) * overlaps[j][overlaps[j].size()-1];
			}
			if(max <= sum)
			{
				bool change=false;
				if(max==sum)
					for(int k=0; k<a; k++)
						if(selected[k]+1 < finals[k])
						{
							change = true;
							break;
						}
				if(max!=sum || change)
				{
					max = sum;
					for(int k=0; k<a; k++)
						finals[k] = selected[k]+1;
				}
			}
		}
		cout << "Case Number  " << casen << endl;
		cout << "Number of Customers: " << max << endl;
		cout << "Locations recommended: ";
		for(int k=0; k<a; k++)
		{
			cout << finals[k];
			if(k!=a-1)
				cout << " ";
		}
		cout << endl;
		cin >> n >> a;
		cout << endl;
		if(n==0 && a==0)
			return 0;
	}
}
