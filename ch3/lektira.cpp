#include<iostream>

using namespace std;

void reverseStr(string &a)
{
	char tmp;
	for(int i=0; i<a.size()/2; i++)
	{
		tmp = a[i];
		a[i] = a[a.size()-i-1];
		a[a.size()-i-1] = tmp;
	}
}

int main()
{
	string ab, first, second, third, last, tmp;
	cin >> ab;
	last = "";
	for(int i=1; i<ab.size(); i++)
	{
		first = ab.substr(0, i);
		reverseStr(first);
		for(int j=i+1; j<ab.size(); j++)
		{
			second = ab.substr(i, j-i);
			third = ab.substr(j, ab.size()-j);
			reverseStr(second);
			reverseStr(third);
			tmp=first+second+third;
//			cout << tmp << " " << i << " " << j << endl;
			if(last.size()==0 || tmp<last)
				last = tmp;
		}
	}
	cout << last << endl;
//	cout << ab << endl;
	return 0;
}

