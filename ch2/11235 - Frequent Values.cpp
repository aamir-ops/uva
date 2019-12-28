#include<iostream>
#include<vector>

using namespace std;

typedef  pair<int, pair<pair<int, int>, pair<int, int>>> ii; 

void printii(ii x){
	cout << x.first <<"\t" << x.second.first.first << "\t" << x.second.first.second << "\t" << x.second.second.first << "\t" << x.second.second.second << endl ;
}


ii merge(ii x,ii y)
{
	int maxf;
	maxf = max(x.first, y.first);
//	cout << "Max is " << maxf << endl;
	if(x.second.second.second == y.second.first.second)
		maxf = max(maxf, x.second.second.first + y.second.first.first);
	if(x.second.first.second == y.second.first.second)
		x.second.first.first += y.second.first.first;
	if(x.second.second.second == y.second.second.second)
		y.second.second.first += x.second.second.first;
//	cout << x.first << "\t" << y.first <<endl;
//	cout << x.second.second.first << "\t" << y.second.first.first << endl;
//	cout << "Max is " << maxf << endl;
	return make_pair(maxf, make_pair(make_pair(x.second.first.first, x.second.first.second), make_pair(y.second.second.first, y.second.second.second)));
}

class SegmentTree {         // the segment tree is stored like a heap array
private: vector<ii> st; vector<int> A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
    {
	    ii x;
	    x.first = x.second.first.first = x.second.second.first = 1;
	    x.second.first.second = x.second.second.second = A[L];
	    st[p] = x;
    }
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      ii p1 = st[left(p)], p2 = st[right(p)];
//      cout << "Merge called on L -- " << L << " R-- " << R << endl;
      st[p] = merge(p1, p2);
  } }

  ii rmq(int p, int L, int R, int i, int j) {                  // O(log n)
//	  cout << "rmq called on L-- " << L << " R-- " << R << endl;
    if (i >  R || j <  L) return make_pair(-1, make_pair(make_pair(0, 0), make_pair(0, 0))); // current segment outside query range
    if (L >= i && R <= j){  
  // cout << "Max value that is returned at L-- " << L << " R-- " << R << " is " << st[p].first << endl;
   //printii(st[p]);
	    return st[p];               // inside query range
    }

     // compute the min position in the left and right part of the interval
    ii p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    ii p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    //cout << "p1 p2 at L-- " << L << " R-- " << R << " is " << endl;
  //  printii(p1);
   // printii(p2);
    if (p1.first == -1) return p2;   // if we try to access segment outside query
    if (p2.first == -1) return p1;                               // same as above
    p1 = merge(p1, p2);
    return p1; }          // as as in build routine


public:
  SegmentTree(const vector<int> &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, make_pair(0, make_pair(make_pair(0, 0), make_pair(0, 0))));            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  ii rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading
  
  void prst(){
	for(int i=0; i<st.size(); i++){
		printii(st[i]);
	}
  }

};

int main()
{
	ii x, y;

	int n, q;
	
	while(true)
	{
		cin >> n;
		if(n==0)
			return 0;
		cin >> q;
		int tmp, tmp2;
		vector<int> vec;
		while(n--)
		{
			cin >> tmp;
			vec.push_back(tmp);
		}
		SegmentTree st(vec);
//		st.prst();
		while(q--)
		{
			cin >> tmp >> tmp2;
			cout << st.rmq(tmp-1, tmp2-1).first << endl;
		}
	}
/*
	cin >> x.first >> x.second.first.first >> x.second.first.second >> x.second.second.first >> x.second.second.second ;
	cin >> y.first >> y.second.first.first >> y.second.first.second >> y.second.second.first >> y.second.second.second ;
	x = merge(x, y);
	cout << x.first <<"\t" << x.second.first.first << "\t" << x.second.first.second << "\t" << x.second.second.first << "\t" << x.second.second.second ;
*/
	return 0;
}
