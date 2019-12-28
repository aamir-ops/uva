#include<iostream>
#include<set>

using namespace std;

int main()
{
	int N, tmp;
	cin >> N;
	int b, sg, sb;
	while(N--)
	{
		cin >> b >> sg >> sb;
		multiset<int, greater<int>> green, blue;
		while(sg--)
		{
			cin >> tmp;
			green.insert(tmp);
		}
		while(sb--)
		{
			cin >> tmp;
			blue.insert(tmp);
		}
		int gb[b], bb[b], cg, cb;
		while(!green.empty() && !blue.empty())
		{
			cg=cb=0;
			//Getting Lemmings out in the battlefield.
			for(int i=0; i<b; i++)
			{
				if(!green.empty())
				{
					gb[i] = *(green.begin());
					green.erase(green.begin());
					cg++;
				}
				if(!blue.empty())
				{
					bb[i] = *(blue.begin());
					blue.erase(blue.begin());
					cb++;
				}
			}
			//Sending extra lemmings back to pavillion.
			while(cg>cb)
				green.insert(gb[--cg]);
			while(cb>cg)
				blue.insert(bb[--cb]);
			//Making Lemmings fight.
			for(int i=0; i<cb; i++)
			{
				if(gb[i]>bb[i])
				{
					gb[i]-=bb[i];
					bb[i] = 0;
				}
				else if(gb[i]<bb[i])
				{
					bb[i]-=gb[i];
					gb[i]=0;
				}
				else
					gb[i] = bb[i] = 0;
			}
			//Putting them back.
			for(int i=0; i<cb; i++)
			{
				if(gb[i]!=0)
					green.insert(gb[i]);
				if(bb[i]!=0)
					blue.insert(bb[i]);
			}
		}
		if(green.empty() && blue.empty())
			cout << "green and blue died" << endl;
		else if(!green.empty())
		{
			cout << "green wins" << endl;
			while(!green.empty())
			{
				cout << *(green.begin()) << endl;
				green.erase(green.begin());
			}
		}
		else
		{
			cout << "blue wins" << endl;
			while(!blue.empty())
			{
				cout << *(blue.begin()) << endl;
				blue.erase(blue.begin());
			}
		}
		if(N)
			cout << endl;
	}
	return 0;
}
