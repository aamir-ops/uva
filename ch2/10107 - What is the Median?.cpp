#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b)
{
	return (a < b);
}

int main()
{
	vector<int> vec;
	int n, sum;

	cin>> n;
	vec.push_back(n);
	cout << n << endl;
	while(cin >> n)
	{
		vec.push_back(n);

		nth_element(vec.begin(), vec.begin()+vec.size()/2, vec.end(), comp);

		sum = vec[vec.size()/2];

		if(vec.size()%2==0)
		{
			nth_element(vec.begin(), vec.begin()+vec.size()/2-1, vec.end(), comp);
			sum+=vec[vec.size()/2 - 1];
			sum/=2;
		}
		cout << sum << endl;
	}
	return 0;
}
