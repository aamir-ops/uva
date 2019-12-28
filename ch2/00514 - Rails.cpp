#include<iostream>
#include<stack>

using namespace std;

bool algo(int N)
{
	int i;

	int in;
	cin >> in;
	if(in==0)
		return true;
	int arr[N+1];
	arr[1] = in;

	for(i=2; i<=N; i++)
		cin >> arr[i];

	int j;
	j=1;
	i=1;
	stack<int> st;
	bool possible = true;
	while(i<=N)
	{
		if(!st.empty() && arr[j] == st.top())
		{
			j++;
			st.pop();
		}
		else if(!st.empty() && arr[j] < st.top())
		{
			possible = false;
			break;
		}
		else
		{
			st.push(i);
			i++;
		}
	}
	while(!st.empty())
	{
		if(st.top() != arr[j])
		{
			possible = false;
			break;
		}
		else
		{
			st.pop();
			j++;
		}
	}
	if(possible)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return false;
}

int main()
{
	int N;
	while(true)
	{
		cin >> N;
		if(N==0)
			return 0;

		while(!algo(N));
		cout << endl;
	}
}
