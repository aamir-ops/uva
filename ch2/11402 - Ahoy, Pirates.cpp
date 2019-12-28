#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st; bitset<1024002> A; vector<bitset<2>> action;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = A[L];                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
  } }
  void flip(int p){
	  if(action[p] == 0) action[p] = 3;
	  else if(action[p] == 1) action[p] = 2;
	  else if(action[p] == 2) action[p] = 1;
	  else	action[p] = 0;  }

  void propagate(int p, bitset<2> x){  action[p] = 0;
	  if(left(p) >=4*n)
		  return;
	  if(x==1 || x==2)  
		  action[left(p)] = action[right(p)] = x;
	  else if(x==3){
		  flip(left(p));	flip(right(p));	  } 
  }

  void clear(int L, int R, int p, bitset<2> x){
	  if(x==1)    st[p] = R - L +1;
	  else if(x==2) st[p] = 0;
	  else if(x==3) st[p] = (R-L+1) - st[p]; 
	  propagate(p, x); }

  int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range

    clear(L, R, p, action[p]);
    if (L >= i && R <= j){
		     return st[p];
	    }

     // compute the min position in the left and right part of the interval
    int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
    int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return p1 + p2; }          // as as in build routine


  int update_point(int p, int L, int R, int idxb, int idxe, bitset<2> todo) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idxb, j = idxe;
//    cout << L << "\t" << R << endl;

    // if the current interval does not intersect
    // the update interval, return this st node value!
    if(p>=0 && p <4*n)
	    clear(L, R, p, action[p]);
    if (i > R || j < L)
      return st[p];
    if(L>=i && R<=j){
//      cout << endl << "L-- " << L << " R--- " << R << " updated. Set to ";
      action[p] = todo;
      clear(L, R, p, action[p]);
//	    cout << st[p];
//	    cout << endl;
	    return st[p];
    }

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == R) { 	
  //    cout << endl << "L-- " << L << " R--- " << R << " updated. Set to ";
      action[p] = todo;
      clear(L, R, p, action[p]);
//	    cout << st[p] << endl;
      return st[p]; // this index
    }

    // compute the minimum pition in the
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idxb, idxe, todo);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idxb, idxe, todo);

    // return the pition where the overall minimum is
  //    cout << endl << "L-- " << L << " R--- " << R << " updated. Set to ";
   // cout << p1 + p2 << endl;
    return st[p] = p1 + p2;
  }

public:
  SegmentTree(const bitset<1024002> &_A, int _n) {
    A = _A; n = _n;              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    action.assign(4*n, 0);
    build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

  int update_point(int idxb, int idxe, char todo) {
	bitset<2> x;
	if(todo == 'F') x = 1;
	else if(todo == 'E') x = 2;
	else if (todo == 'I') x=3;
    return update_point(1, 0, n - 1, idxb, idxe, x); }

  void printst(){
	  for(int i=0; i<st.size(); i++)
		  cout << i << "\t" << st[i] << "\t" << action[i] << endl;
  }
  void clearv(){
	  action.clear(); action.shrink_to_fit();
	  st.clear(); st.shrink_to_fit();
  }
};

int main()
{
	int tc;
	cin >> tc;
	int TC = tc;
	while(tc--)
	{
		int m, times, n=0;
		string str, str2;
		bitset<1024002> b;

		cin >> m;
		int i = 0;
		while(m--)
		{
			cin >> times >> str2;
			n += times*str2.length();
			while(times--)
				str.append(str2);
		}

//		cout << n << endl;
//		cout << str << endl;
		for(int j=0; j<str.length(); j++)
			b[i++] = str[j]-'0';

		SegmentTree pirates(b, n);
//		cout << endl;
//		cout << b[0] << b[1] << endl;
//		pirates.printst();
		int q;
		cin >> q;
		char todo;
		int idxb, idxe;
		cout << "Case " << TC-tc << ":" <<endl;
		i=1;
//				cout << pirates.rmq(0, n-1) << endl;
		while(q--)
		{
//			pirates.printst();
			cin >> todo >> idxb >> idxe;
			if(todo == 'S')
				cout << "Q" << i++ << ": " << pirates.rmq(idxb, idxe) << endl;
			else
			{
//				cout << "Trying update" << endl;
//				cout << pirates.rmq(idxb, idxe) << endl;
				pirates.update_point(idxb, idxe, todo);
//				cout << pirates.rmq(idxb, idxe) << endl;
			}
		}
		pirates.clearv();
	}
	return 0;
}
