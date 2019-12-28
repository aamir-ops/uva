#include<iostream>

using namespace std;

int main()
{
	int s, b;
	while(true)
	{

		cin >> s >> b;
		if(s==0 && b==0)
			return 0;

		int left[s+1], right[s+1];

		for(int i=0; i<=s; i++)
		{
			left[i] = i-1;
			right[i] = i+1;
//			cout << left[i] << " " << right[i] << endl;
		}
		left[0] = 0;
		right[s] = 0;

		int l, r;

		while(b--)
		{
			cin >> l >> r;

			if(left[l])
				cout << left[l] << " ";
			else
				cout << "* ";
			if(right[r])
				cout << right[r] << endl;
			else
				cout << "*" << endl;

			right[left[l]] = (right[r]);
			left[right[r]] = (left[l]);
		}
		cout << "-" << endl;
	}
}
