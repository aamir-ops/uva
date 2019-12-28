#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>

using namespace std;

int main()
{
	int n;
	while(true)
	{
		cin >> n;

		if(n==0)
			return 0;

		string str;

		map<string, int> mp;
		map<string, int>::iterator itr;

		int l, arr[5], i, tmp;

		while(n--)
		{
			stringstream ss;
			for(i=0; i<5; i++)
			{
				cin >> arr[i];
			}

			sort(arr, arr+5);

			for(i=0; i<5; i++)
				ss << arr[i];

			str = "";
			ss >> str;

			itr = mp.find(str);
			tmp = 1;
			if(itr != mp.end())
			{
				tmp = itr->second;
				mp.erase(itr);
				tmp++;
			}
			mp.insert(make_pair(str, tmp));

//			cout << str << endl;
		}

		int max = 0;
		for(itr = mp.begin(); itr!=mp.end(); itr++)
			if(max<itr->second)
				max = itr->second;

		int count = 0;
		for(itr = mp.begin(); itr!=mp.end(); itr++)
			if(max == itr->second)
				count+=itr->second;
		cout << count << endl;

	}
}
