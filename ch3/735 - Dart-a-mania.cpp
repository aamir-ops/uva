#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef pair<int, pair<int, int>> pi;

int main()
{
	int score;
	int scoreboard[62];
	for(int i=0; i<62; i++)
		scoreboard[i] = 0;
	for(int i=1; i<=20; i++)
	{
		scoreboard[i] = i;
		scoreboard[2*i] = 2*i;
		scoreboard[3*i] = 3*i;
	}
	scoreboard[61] = 50;
	int arr[3];
	while(true)
	{
		cin >> score;
		if(score<1)
		{
			cout << "END OF OUTPUT\n";
			return 0;
		}
		int i, j, k;
		pi temp;
		set<pair<int, pair<int, int>>> comb;
		set<pair<int, pair<int, int>>> perm;
		for(i=0; i<62; i++)
		{
			for(j=0; j<62; j++)
			{
				for(k=0; k<62; k++)
				{
					arr[0] = scoreboard[i];
					arr[1] = scoreboard[j];
					arr[2] = scoreboard[k];

					if(arr[0] + arr[1] + arr[2] != score)
						continue;
					temp = make_pair(arr[0], make_pair(arr[1], arr[2]));
					if(perm.empty() || perm.find(temp) == perm.end())
						perm.insert(temp);

					sort(arr, arr+3);
					temp = make_pair(arr[0], make_pair(arr[1], arr[2]));
					if(comb.empty() || comb.find(temp) == comb.end())
						comb.insert(temp);
				}
			}
		}
		if(perm.empty())
			cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
		else
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << comb.size() << "." << endl;
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << perm.size() << "." << endl;
		}
		for(i=1; i<=70; i++)
			cout << "*";
		cout << endl;


	}
}
