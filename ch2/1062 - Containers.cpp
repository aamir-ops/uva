#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main()
{
	int casenum=0;
	while(true)
	{
		casenum++;
		string s;
		cin >> s;
		if(s[0] == 'e')
			return 0;
	
		stack<char> st[26];
		int max = 0, i;
		int in=0;
		bool pushed;
		while(in<s.length())
		{
			pushed = false;
			for(i=0; i<max; i++)
				if(s[in] <= st[i].top())
				{
//					cout << "s[in] is " << s[in] << " st[i].top() is " << st[i].top() << endl;
//					cout << "i is " << i << " max is " << max << endl;
					st[i].push(s[in]);
					pushed = true;
					break;
				}

			if(!pushed)
			{
				st[max].push(s[in]);
				max++;
			}
			in++;
		}
		cout << "Case " << casenum << ": " << max << endl;
	}

	return 0;
}
