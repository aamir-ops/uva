#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = prod(A[L], 1);                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = prod(p1, p2);
  } }

  int prod(int a, int b){
	  if(a==0 || b==0)	return 0;
	  if((a>0 && b>0) || (a<0 && b<0)) return 1;
	  return -1;   }

  int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -2; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -2) return p2;   // if we try to access segment outside query
    if (p2 == -2) return p1;                               // same as above
    return prod(p1, p2); }          // as as in build routine

  int update_point(int p, int L, int R, int idx, int new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx, j = idx;

    // if the current interval does not intersect
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = prod(A[i], 1); // this index
    }

    // compute the minimum pition in the
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = prod(p1, p2);
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  char rmq(int i, int j) { int tmp = rmq(1, 0, n - 1, i, j); 
 	if(tmp==0) return '0';
 	if(tmp>0) return '+';
 	return '-'; }   // overloading

  int update_point(int idx, int new_value) {
    if(prod(new_value, A[idx]) > 0) return st[1];
    return update_point(1, 0, n - 1, idx, new_value); }

  void printst(){
	  for(int i=1; i<st.size(); i++)  cout << i << "\t" << st[i] << endl;  }

};

int main() {
	int n, k;
	while(cin >> n)
	{
		cin >> k;
		vi val;
		int tmp;
		char op;

		while(n--)
		{
			cin >> tmp;
			val.push_back(tmp);
		}

		SegmentTree shots(val);

//		cout << k <<endl;
		while(k--)
		{
			cin >> op >> n >> tmp;
//			cout << op << "\t" << n << "\t" << tmp << endl;
			if(op == 'C')
				shots.update_point(n-1, tmp);
			else
				cout << shots.rmq(n-1, tmp-1);
//			shots.printst();
		}
		cout << endl;
//		shots.printst();
	}

	return 0;
}
