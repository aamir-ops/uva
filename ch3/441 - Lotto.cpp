#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int K;
	cin >> K;
	while(true)
	{

		if(K==0)
			return 0;
		int tmp;

		vector<int> num;

		while(K--)
		{
			cin >> tmp;
			num.push_back(tmp);
		}
		sort(num.begin(), num.end());

		for(int i=0; i<num.size(); i++)
		{
			for(int j=i+1; j<num.size(); j++)
			{
				for(int k=j+1; k<num.size(); k++)
				{
					for(int l=k+1; l<num.size(); l++)
					{
						for(int m=l+1; m<num.size(); m++)
						{
							for(int n=m+1; n<num.size(); n++)
								cout << num[i] << " " << num[j] << " " << num[k] << " " << num[l] << " " << num[m] << " " << num[n] << endl;
						}
					}
				}
			}
		}


		cin >> K;
		if(K==0)
			return 0;
		cout << endl;
	}
}
