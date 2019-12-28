#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
	int m, n, i, j, r, tmp;
	vii::iterator k;
	vector<vii>::iterator l;

	while(cin >> m)
	{
		cin >> n;
		vector<vii> mat, fmat;
		mat.assign(m, vii());

		fmat.assign(n, vii());

		for(i=0; i<m; i++)
		{
			cin >> r;
			for(j=0; j<r; j++)
			{
				cin >> tmp;
				mat[i].push_back(ii(tmp, 0));
			}
			for(k=mat[i].begin(); k!= mat[i].end(); k++)
			{
				cin >> tmp;
				k->second = tmp;
			}
		}

		for(i=0; i<m; i++)
			for(k=mat[i].begin(); k!=mat[i].end(); k++)
				fmat[k->first-1].push_back(ii(i, k->second));

		cout << n << " " << m << endl;
		for(i=0; i<n; i++)
		{
			cout << fmat[i].size() ;
			for(k=fmat[i].begin(); k!=fmat[i].end(); k++)
				cout << " " << k->first+1;
			cout << endl;
			for(k=fmat[i].begin(); k!=fmat[i].end(); k++)
			{
				cout << k->second;
				if(k+1 != fmat[i].end())
					cout << " ";
			}
			cout << endl;
		}
	}


	return 0;
}
