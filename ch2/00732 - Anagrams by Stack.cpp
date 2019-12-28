#include<iostream>
#include<stack>
#include<algorithm>
#include<map>

using namespace std;
string in, out;

void printmap(map<char, int> mp)
{
	map<char, int>::iterator it;

	for(it = mp.begin(); it != mp.end(); it++)
		cout << it->first << "\t" << it->second << endl;
}
bool isPerm(string a, string b)
{
	if(a.length() != b.length())
		return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	string::iterator it, it2;
	
	for(it=a.begin(), it2=b.begin(); it!=a.end() && it2!=b.end(); it++, it2++)
		if(*it != *it2)
			return false;
	return true;

	/*
	map<char, int> mp;

	map<char,int>::iterator mpIt;
	int temp;

	//Inserting a into map
	for(it=a.begin(); it != a.end(); it++)
	{
		mpIt = mp.find(*it);

		if(mpIt == mp.end())
			mp.insert(make_pair(*it, 1));
		else
		{
			temp = mpIt->second+1;
			mp.erase(*it);
			mp.insert(make_pair(*it, temp));
		}
	}
	//Checking b from map
	for(it = b.begin(); it != b.end(); it++)
	{
		mpIt = mp.find(*it);

		if(mpIt == mp.end())
			return false;
		
		if(mpIt->second == 1)
			mp.erase(*it);
		else
		{
			temp = mpIt->second-1;
			mp.erase(*it);
			mp.insert(make_pair(*it, temp));
		}
	}

	return true;
	*/
}
void algo(string in, int inPos, string out, int outPos, bool push,stack<char> st, string seq, int numPush, int numPop)
{
	if(push)
	{
		seq.append("i ");
		st.push(in[inPos]);
		inPos++;
		numPush++;
	}
	else
	{
		if(st.empty())
			return;
		char tmp = st.top();
		if(tmp != out[outPos])
			return;
		st.pop();
		seq.append("o ");
		numPop++;
		outPos++;
	}
	if(seq.length() == 4*in.length())
	{
		seq.erase(seq.end()-1);
		cout << seq << endl;
		return;
	}
	if(numPush<in.length())
		algo(in, inPos, out, outPos, true, st, seq, numPush, numPop);
	if(numPop<in.length())
		algo(in, inPos, out, outPos, false, st, seq, numPush, numPop);
}

int main()
{
	while(cin>>in>>out)
	{
		stack<char> st;
		cout << '[' << endl;
		if(isPerm(in, out))
			algo(in, 0, out, 0, true, st, "", 0, 0);
		cout << ']' << endl;
	}
}
