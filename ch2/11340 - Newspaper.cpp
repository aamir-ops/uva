#include<map>
#include<cstdio>
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	int N, K, M;

	int money;
	char character, ch;

	string str;
	stringstream ss;
	ss.clear();
	getline(cin, str);
	ss << str;
	ss >> N;
	//cout << N << endl;
	while(N--)
	{
		map<char, int> m;
		map<char, int>::iterator itr;
		string line;

		ss.clear();
		getline(cin, str);
		ss << str;
		ss >> K;

	//	cout << K << endl;
		while(K--)
		{
			getline(cin, str);
			//cout << str << endl;
			ss.clear();
			ss << str;
			//ss >> money;
			ss >> character >> money;

		//	cout << character << money << endl;
			m.insert(make_pair(character, money));
		}
		

		

		getline(cin, str);
		ss.clear();
		ss << str;
		ss >> M;
		long double sum=0;
		//cin.ignore();
	//	cout << M << endl;
		while(M--)
		{
			line = "";
			getline(cin, line);
			int l = line.size();

		//	cout << line << endl;
			for(int j=0; j<l; j++)
			{
				itr = m.find(line[j]);
				if(itr != m.end())
					sum+=itr->second;
			}

		}
		printf("%.2Lf$\n", sum/100.0);
		sum=0;
		m.clear();
		
	}
	return 0;
}
