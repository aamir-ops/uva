#include<iostream>
#include<climits>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

typedef vector<int> vi;

int main()
{
	int K,k, n, m, tmp, i, j;
	string str;
	stringstream ss;
	getline(cin, str);
	ss.clear();
	ss<<str;
	ss>>K;
	while(K--)
	{
		getline(cin, str);
		ss.clear();
		ss<<str;
		ss>>n >> m;

		vector<vi> subsets;
		map<int, int> elements;
		subsets.assign(m, vi());
		j = 0;
		for(i=0; i<m; i++)
		{
			getline(cin, str);
			ss.clear();
			ss << str;
			while(ss.rdbuf()->in_avail())
			{
				ss>>tmp;
				if(elements.find(tmp) == elements.end())
					elements.insert(make_pair(tmp, j++));
				subsets[i].push_back(tmp);
			}
		}

		//Till This point input is in the adjacency list.
		getline(cin, str);
		int co = 1<<n, first;
		bool flag1=false, flag2;
		for(i=0; i<subsets.size(); i++)
		{
	//		for(j=0; j<subsets[i].size(); j++)
	//			cout << subsets[i][j] << "\t";
	//		cout << endl;
		}
		for(i=0; i<co && !flag1; i++)
		{
			flag1 = true;
			for(j=0; j<subsets.size() && flag1; j++)
			{
				if(subsets[j].size()<2)
					continue;
				flag2 = false;
				first = (i>>(elements.find(subsets[j][0])->second)) & 1;
//				cout << first << endl;
				for(k=1; k<subsets[j].size() && !flag2; k++)
				{
				       if((i>>(elements.find(subsets[j][k])->second) & 1) ^ first)
					       flag2 = true;
				}
				if(!flag2)
					flag1 = false;
			}
		}
//		cout << "input done." << endl;

//		for(map<int, int>::iterator itr=elements.begin(); itr != elements.end(); itr++)
//			cout << itr->first << "\t" << itr->second << endl;
//		cout << endl;
/*		for(i=0; i<co && !flag1; i++)
		{
			flag1 = true;
			for(j=0; j<subsets.size() && flag1; j++)
			{
				if(subsets[j].size()<2)
					continue;
				flag2 = false;
				first = (i>>subsets[j][0]) & 1;
//				cout << first << endl;
				for(k=1; k<subsets[j].size() && !flag2; k++)
				{
				       if(((i>>subsets[j][k]) & 1) ^ first)
					       flag2 = true;
				}
				if(!flag2)
					flag1 = false;
			}
		}
*/		if(flag1)
			cout << "Y";
		else
			cout << "N";
//		cout << endl;
	}
		
	return 0;
}
