#include<iostream>
#include<vector>
#include<bitset>
#include<sstream>

using namespace std;

vector<int> cd;
bitset<30> tracks;
bitset<30> finalt;
int sum, maxt;
int n;

void backtrack(int i)
{
//	cout << "i is " << i << endl;
	if(i==cd.size())
	{
		if(maxt < sum)
		{
			maxt = sum;
			finalt = tracks;
		}
		return;
	}
	if(sum+cd[i]<=n)
	{
		tracks.set(i);
		sum += cd[i];
		backtrack(i+1);
	}
	if(tracks[i])
		sum-=cd[i];
	tracks.reset(i);
	backtrack(i+1);
}

int main()
{
	string str;
	stringstream ss;
	while(true)
	{
		getline(cin, str);
		if(str.length()==0)
			return 0;

		int t, tmp;
		ss.clear();
		ss << str;
		ss >> n>> t;
		sum = 0;
		maxt = 0;
		cd.clear();
		for(int i=0; i<30; i++)
			tracks.reset(i);
		while(t--)
		{
			ss>>tmp;
			cd.push_back(tmp);
		}
		backtrack(0);
		if(finalt.count())
		{
			for(int i=0; i<30; i++)
			{
				if(finalt[i])
					cout << cd[i] << " ";
			}
		}
		cout << "sum:" << maxt << endl;
	}
}
