#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

typedef pair<char, char> cc;
typedef vector<int> vi;

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
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
	int N, M;

	while(cin >> N)
	{
		cin >> M;

		char a, b, c, ta, tb;
		cin >> a >> b >> c;
		UnionFind brain(26);

		vector<vi> adjList;

		adjList.assign(26, vi());

		while(M--)
		{
			cin >> ta >> tb;
			adjList[ta-'A'].push_back(tb-'A');
			adjList[tb-'A'].push_back(ta-'A');
		}

		vector<int>::iterator itr;
		brain.unionSet(a-'A', b-'A');
		brain.unionSet(a-'A', c-'A');


		bool update = true;
		int count;
		int years = 0;
		while(update)
		{
			bitset<26> wakeIt;
			update = false;
			for(int i=0; i<26; i++)
			{
				if(brain.isSameSet(i, a-'A'))
					continue;
				count = 0;
				for(itr = adjList[i].begin(); itr != adjList[i].end() && count<3; itr++)
				{
					if(brain.isSameSet(*itr, a-'A'))
					{
						count++;
					}
				}
				if(count == 3)
				{
					update = true;
					wakeIt.set(i);
				}
			}
			for(int i=0; i<26; i++)
			{
				if(wakeIt.test(i))
				{
					brain.unionSet(i, a-'A');
				}
			}
			if(update)
				years++;
		}
		if(brain.sizeOfSet(a-'A') == N)
			cout << "WAKE UP IN, " << years << ", YEARS" << endl;
		else
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
	}
}


