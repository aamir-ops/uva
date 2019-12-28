#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string str;
		int tmp;
		float count=0;
		map<string, int> mp;
		map<string, int>::iterator itr;

		str="";
		while(str.length()==0)
			getline(cin, str);
		while(true)
		{
			if(str.length()==0)
				break;
			itr=mp.find(str);
			tmp=1;
			if(itr != mp.end())
			{
				tmp = itr->second;
				mp.erase(itr);
				tmp++;
			}
			mp.insert(make_pair(str, tmp));
			count++;
			getline(cin, str);
		}


		for(itr = mp.begin(); itr!=mp.end(); itr++)
		{
			cout << itr->first << " " ;
			printf("%.4f\n", (itr->second)*100.0/count);
		}
		if(T)
			cout << endl;
	}

	return 0;

}
