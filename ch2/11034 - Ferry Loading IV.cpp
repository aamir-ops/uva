#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int c, l, m;

	cin >> c;

	while(c--)
	{
		cin >> l >> m;

		l*=100;

		bool leftPos=true;
		int tmp;
		string str;

		queue<int> left, right;

		while(m--)
		{
			cin >> tmp >> str;
			if(str[0] == 'l')
				left.push(tmp);
			else
				right.push(tmp);
		}

		int loaded, count=0;
		while(!left.empty() || !right.empty())
		{
			loaded=0;
			if(leftPos)
			{
				while(!left.empty() && left.front()+loaded<l)
				{
					loaded+=left.front();
					left.pop();
				}
				leftPos = false;
			}
			else
			{
				while(!right.empty() && right.front()+loaded<l)
				{
					loaded+=right.front();
					right.pop();
				}
				leftPos=true;
			}
			count++;
		}
		cout << count << endl;
	}
}
