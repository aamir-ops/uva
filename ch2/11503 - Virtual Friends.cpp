#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
public:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		string stra, strb;
		int a, b;
		int F;

		map<string, int> mp;

		map<string, int>::iterator itr;


		UnionFind friends(0);
		int ind = 0;
		cin >> F;

		while(F--)
		{
			cin >> stra >> strb;
			
			itr = mp.find(stra);
			if(itr==mp.end())
			{
				mp.insert(make_pair(stra, ind));
				itr = mp.find(stra);
				friends.p.push_back(ind);
				friends.rank.push_back(0);
				friends.setSize.push_back(1);
				friends.numSets++;
				ind++;
			}
			a = itr->second;
			itr = mp.find(strb);
			if(itr==mp.end())
			{
				mp.insert(make_pair(strb, ind));
				itr = mp.find(strb);
				friends.p.push_back(ind);
				friends.rank.push_back(0);
				friends.setSize.push_back(1);
				friends.numSets++;
				ind++;
			}
			b = itr->second;
			friends.unionSet(a, b);
			cout << friends.sizeOfSet(a) << endl;
		}
	}
	return 0;
}

