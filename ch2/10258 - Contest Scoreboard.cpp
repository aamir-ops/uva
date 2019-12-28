#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

using namespace std;

struct team{
	int number;
	bool attempted;
	bool solved[10];
	int tsolved;
	int penalty[10];
	int tpenalty;
};

bool comp(team a, team b)
{
	if(a.tsolved != b.tsolved)
		return a.tsolved > b.tsolved;
	else if(a.tpenalty != b.tpenalty)
		return a.tpenalty < b.tpenalty;
	else
		return a.number < b.number;
}
	

int main()
{
	int T;
	cin >> T;
	T+=2;
	while(T--)
	{
		bool operated = false;
		team t[101];
		int team, ques, time;
		char status;
		
		for(int i=1; i<101; i++)
		{
			t[i].number = i;
			for(int j=1; j<10; j++)
			{
				t[i].solved[j] = false;
				t[i].penalty[j] = 0;
			}
			t[i].tsolved = t[i].tpenalty = 0;
			t[i].attempted = false;
		}

		string s="";
		//cin.ignore();
		while(true)
		{
			s = "";
			getline(cin, s);
			if(s.size() == 0)
			{
				break;
			}
			operated = true;

			stringstream geek(s);
			geek >> team >> ques >> time >> status;

			if(status == 'I')
			{
				t[team].penalty[ques] += 20;
				t[team].attempted = true;
			}
			else if(status == 'C')
			{
				if(!t[team].solved[ques])
				{
					t[team].attempted = true;
					t[team].solved[ques] = true;
					t[team].penalty[ques] += time;
					t[team].tsolved++;
					t[team].tpenalty += t[team].penalty[ques];
				}
			}
			else
				t[team].attempted = true;

		}
		if(!operated)
			continue;

		
		sort(t+1, t+101, comp);
		for(int i=1; i<=100; i++)
		{
			if(!t[i].attempted)
				continue;
			cout << t[i].number << " " << t[i].tsolved << " " << t[i].tpenalty << endl;
		}


		if(T)
		cout << endl;

	}
	return 0;
}
