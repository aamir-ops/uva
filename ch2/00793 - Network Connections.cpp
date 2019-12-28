#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class UnionFind{
	private:
	       	vector<int> p, rank, setSize;
		int numSets;

	public:
	UnionFind(int N)
	{
		p.assign(N, 0);
		rank.assign(N, 0);
		setSize.assign(N, 0);

		numSets = N;

		for(int i=0; i<N; i++)
		{
			p[i]= i;
			rank[i] = 0;
			setSize[i] = 1;
		}
	}

	int findSet(int i){	return (p[i] == i) ? i : (p[i] = findSet(p[i]));	}

	bool isSameSet(int i, int j){	return findSet(i) == findSet(j);	}

	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			numSets--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y])
			{
				p[y] = x;
				setSize[x] += setSize[y];
			}
			else
			{
				p[x] = y;
				setSize[y] += setSize[x];
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}

	int numDisjointSet(){	return numSets;	}

	int sizeOfSet(int i){	return setSize[findSet(i)];	}
};

int main()
{
	string str;
	int n, s, u, N;

	int a, b;
	char c;

	stringstream strprocess;
	getline(cin, str);
	strprocess << str;
	strprocess >> n;
	getline(cin, str);

	while(n--)
	{
		stringstream ss;
		getline(cin, str);

			ss << str;
		ss >> N;

		ss.clear();
		UnionFind network(N);

		s = u = 0;
		while(true)
		{
			str = "";
			getline(cin, str);
			if(str.length()==0)
				break;

			ss.clear();
			ss << str;
			ss >> c >> a >> b;

			if(c=='c')
				network.unionSet(a-1, b-1);
			else if(c == 'q')
			{
				if(network.isSameSet(a-1, b-1))
					s++;
				else
					u++;
			}
		}
		cout << s <<"," << u << endl;
		if(n)
			cout << endl;
	}
	return 0;
}

