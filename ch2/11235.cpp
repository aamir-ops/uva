#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

typedef vector<int> vi;

int rmq(const vi &input, const vi &count, const vi &start, int i, int j)
{
	if(i>=j)	return 1;
	if(input[i] == input[j]) return j-i+1;

	int p1, p2, p3;
	p1 = start[i] + count[i] - i;
	p3 = j - start[j] + 1;
	
//	cout << i << "\t" << j << "\t" << p1 << "\t" << p3 << endl;
	p2 = rmq(input, count, start, start[i] + count[i], start[j]-1);

	return max(p1, max(p2, p3));
}

int main()
{
	int n, q, tmp, previous, ct, st;
	while(true)
	{
		vector<int> input, count, start;

		cin >> n;
		if(n==0)
			break;
		cin >> q;
		cin >> tmp;
		
	//	cout << n << "\t" << q << endl;
		input.push_back(tmp);
		count.push_back(1);
		start.push_back(0);

		n--;
		ct = 1;
		st = 0;
		while(n--)
		{
			previous = tmp;
			cin >> tmp;
			input.push_back(tmp);
			if(tmp == previous)
			{
				ct++;
				count.push_back(ct);
				start.push_back(st);
			}
			else
			{
				st = st + ct;
				ct = 1;
				count.push_back(ct);
				start.push_back(st);
			}
		}
		int i;

		for(i=count.size()-1; i>=0; i--)
		{
			previous = tmp = count[i];
			while(--tmp)
			{
				i--;
				count[i] = previous;
			}
		}
//		for(i=0; i<count.size(); i++)
//																													cout << i << "\t" << input[i] << "\t" << count[i] << "\t" <<  start[i]  << endl;
		while(q--)
		{
			cin >> tmp >> previous;
//			rmq(tmp-1, previous-1);
			cout << rmq(input, count, start, tmp-1, previous-1) << endl;
		}

	}

	return 0;
}
